/*
 * GameManager.cpp
 *
 *  Created on: 08/03/2012
 *      Author: Vitor
 */

#include "GameManager.h"
#include <ctime>

#define FRAMES_PER_SECOND 60
#define DROP_TIME 500

GameManager* GameManager::m_game_mng = nullptr;

SDL_Event event;

GameManager::GameManager() {
	m_running = true;
	m_video_mng = VideoManager::getInstance();
	m_video_mng->setupVideo();

	m_input_mng = InputManager::getInstance();

	m_fps_timer = new Timer();
	m_drop_timer = new Timer();

	m_curr_piece = nullptr;
	m_preview_piece = nullptr;

	srand(time(NULL));
	m_next_piece_type = rand() % 7;

	m_tetris_blocks.resize(20);
	std::vector<std::vector<TetrisBlock*>>::iterator it;
	for(it = m_tetris_blocks.begin(); it != m_tetris_blocks.end(); it++){
		(*it).resize(10,nullptr);
	}
}

GameManager::~GameManager() {
	std::list<GameObject*>::iterator it;
	GameObject* curr_obj = nullptr;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		curr_obj = (*it);
		it = m_game_objs_list.erase(it);
		delete curr_obj;
	}
	delete m_fps_timer;
	delete m_drop_timer;
}

void GameManager::run() {
	setup();
	while(m_running){
		m_fps_timer->start();
		input(event);
		logic();
		render();
	}
}

void GameManager::setup()
{
	generatePiece();
	m_drop_timer->start();
	createBorders(0);
	createBorders(1);
	createBorders(2);
}

void GameManager::logic() {
	if(m_curr_piece != nullptr){
		if(checkCollision()){
			m_curr_piece->undoMovement();
		}
	}
	manageDropPiece();
	checkTetrisLines();
}

void GameManager::input(SDL_Event event) {

	if(m_input_mng->checkQuitApp()){
		m_running = false;
		return;
	}
	m_input_mng->handleInput(event);
	if(m_curr_piece != nullptr){
		if(m_input_mng->checkKey("DOWN"))
		{
			m_curr_piece->movePiece(DOWN);
		}
		if(m_input_mng->checkKey("UP"))
		{
//			m_curr_piece->movePiece(UP);
			m_curr_piece->rotatePiece(LEFT);
		}
		if(m_input_mng->checkKey("LEFT"))
		{
			m_curr_piece->movePiece(LEFT);
		}
		if(m_input_mng->checkKey("RIGHT"))
		{
			m_curr_piece->movePiece(RIGHT);
		}
		if(m_input_mng->checkKey("SPACE"))
		{
			m_curr_piece->rotatePiece(RIGHT);
		}
	}



}

GameManager* GameManager::getInstance() {
	if(m_game_mng == nullptr){
		m_game_mng = new GameManager();
	}
	return m_game_mng;
}

void GameManager::render() {

	m_video_mng->clearScreen();
	std::list<GameObject*>::iterator it;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		(*it)->render();
	}
	m_video_mng->updateScreen();
	manageFps();
}

void GameManager::addGameObj(GameObject* obj) {
		m_game_objs_list.push_back(obj);
}

void GameManager::manageFps() {
	if(m_fps_timer->getElapsed() < (1000 / FRAMES_PER_SECOND))
	{
			SDL_Delay((1000 / FRAMES_PER_SECOND) - m_fps_timer->getElapsed());
	}
}

void GameManager::manageDropPiece() {
	if(m_curr_piece != nullptr){
		if(m_drop_timer->getElapsed() > DROP_TIME){
			m_curr_piece->movePiece(DOWN);
			if(checkCollision()){
				m_curr_piece->undoMovement();
				TetrisBlock* curr_block;
				int row;
				int column;
				for(int i = 0; i < 4; i++){
					curr_block = m_curr_piece->getTetrisBlock(i);
					column = curr_block->getFrame().getCenter().x;
					row = curr_block->getFrame().getCenter().y;
					curr_block->getFrame().resetTranslation();
					curr_block->getFrame().setCenter(glm::vec3(column,row,0.0f));
					row = row -1;
					column = column + 5;
					if((row < 20)){
						m_tetris_blocks[row][column] = curr_block;
					}
					addGameObj(dynamic_cast<GameObject*>(curr_block));
					std::cout << "center x: " << column << std::endl;
					std::cout << "center y: " << row << std::endl;
				}
				m_curr_piece->clearChildren();
				removeGameObj(m_curr_piece);
				generatePiece();
			}
			m_drop_timer->start();
		}
	}
}

void GameManager::removeGameObj(GameObject *obj) {
	std::list<GameObject*>::iterator it;
	for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
		if(obj == (*it)){
			m_game_objs_list.erase(it);
			return;
		}
	}
}

bool GameManager::checkCollision(){
	if(m_curr_piece != nullptr){
		std::list<GameObject*>::iterator it;
		long int curr_piece_address = (long int)m_curr_piece;
		long int other_piece_address;
		for(it = m_game_objs_list.begin(); it != m_game_objs_list.end(); it++){
			other_piece_address = (long int)(*it);
			if(curr_piece_address != other_piece_address){
				if(m_curr_piece->checkCollision((*it))){
					return true;
				}
			}
		}
	}
	return false;
}

void GameManager::generatePiece()
{
	int color_id = rand()%6;
	glm::vec3 color;
	switch(color_id){
	case 0:
		color = glm::vec3(1.0f,0.0f,0.0f);
		break;
	case 1:
		color = glm::vec3(0.0f,1.0f,0.0f);
		break;
	case 2:
		color = glm::vec3(0.0f,0.0f,1.0f);
		break;
	case 3:
		color = glm::vec3(1.0f,1.0f,0.0f);
		break;
	case 4:
		color = glm::vec3(0.0f,1.0f,1.0f);
		break;
	default:
		color = glm::vec3(1.0f,1.0f,1.0f);
		break;
	}
	if(m_preview_piece == nullptr){
		m_next_piece_type = TETRIS_LINE_PIECE;
		m_curr_piece = createTetrisPiece(TetrisPieceType(m_next_piece_type));
		m_curr_piece->setMaterial(color);
		addGameObj(m_curr_piece);
	}else{
		m_curr_piece = m_preview_piece;
	}
	m_curr_piece->setPosition(glm::vec3(0.0f,20.0f,0.0f));
	if(checkCollision()){
		std::cout << "GAME OVER" << std::endl;
	}
	color_id = rand()%6;
	switch(color_id){
		case 0:
			color = glm::vec3(1.0f,0.0f,0.0f);
			break;
		case 1:
			color = glm::vec3(0.0f,1.0f,0.0f);
			break;
		case 2:
			color = glm::vec3(0.0f,0.0f,1.0f);
			break;
		case 3:
			color = glm::vec3(1.0f,1.0f,0.0f);
			break;
		case 4:
			color = glm::vec3(0.0f,1.0f,1.0f);
			break;
		default:
			color = glm::vec3(1.0f,1.0f,1.0f);
			break;
	}
	m_next_piece_type = rand() % 7;
	m_next_piece_type = TETRIS_LINE_PIECE;
	m_preview_piece = createTetrisPiece(TetrisPieceType(m_next_piece_type));
	m_preview_piece->setPosition(glm::vec3(10.0f,15.0f,0.0f));
	m_preview_piece->setMaterial(color);
	addGameObj(m_preview_piece);
}

void GameManager::createBorders(int pos)
{
	GameObject* block = new GameObject();
	GameObjComponent *collision_component;
	glm::vec2 bbox_size;
	glm::vec2 position;
	switch(pos){
	case 0:
		bbox_size = glm::vec2(12.0f,1.0f);
		position = glm::vec2(-0.5f,0.0f);
		break;
	case 1:
		bbox_size = glm::vec2(1.0f,20.0f);
		position = glm::vec2(-6.0f,10.5f);
		break;
	case 2:
		bbox_size = glm::vec2(1.0f,20.0f);
		position = glm::vec2(5.0f,10.5f);
		break;
	default:
		break;
	}

	collision_component = new CollisionComponent(&block->getFrame(),bbox_size.x,bbox_size.y);
	block->addComponent(collision_component);

	GameObjComponent *renderer_component = new RendererComponent();
	block->addComponent(renderer_component);

	GameObjComponent *mesh_component = new MeshComponent();
	block->addComponent(mesh_component);

	std::vector<glm::vec3> vertices;
	CollisionComponent* cc = dynamic_cast<CollisionComponent*>(collision_component);
	MeshComponent* mc = dynamic_cast<MeshComponent*>(mesh_component);

	vertices.push_back(cc->getBoundingBox()->getBorderPoint(0));
	vertices.push_back(cc->getBoundingBox()->getBorderPoint(1));
	vertices.push_back(cc->getBoundingBox()->getBorderPoint(2));
	vertices.push_back(cc->getBoundingBox()->getBorderPoint(3));
	mc->setMesh(vertices);

	addGameObj(block);
	block->move(position.x,position.y);
}



void GameManager::checkTetrisLines()
{
	int block_count;
	for(int i = 0; i < 20; i++){
		block_count = 0;
		for(int j = 0; j < 10; j++){
			if(m_tetris_blocks[i][j] != nullptr){
				block_count++;
			}else{
				break;
			}
		}
		if(block_count == 10){
			clearLine(i);
			dropLine(i+1);
			i--;
		}
	}
//	for(int i = 19; i >= 0; i--){
//		for(int j = 0; j < 10; j++){
//			if(m_tetris_blocks[i][j] != nullptr){
//				std::cout << " 1 " << " ";
//			}else{
//				std::cout << " 0 " << " ";
//			}
//		}
//		std::cout << std::endl;
//	}
//	std::cout << std::endl;
}

void GameManager::clearLine(unsigned int line)
{
	TetrisBlock* block = nullptr;
	for(int i = 0; i < 10; i++){
		block = m_tetris_blocks[line][i];
		if(block != nullptr){
			removeGameObj(block);
			delete block;
		}
	}
	m_tetris_blocks[line].clear();
	m_tetris_blocks[line].resize(10,nullptr);
}

void GameManager::dropLine(unsigned int line)
{
	TetrisBlock* block = nullptr;
	for(int i = line; i < 20; i++){
		for(int j = 0; j < 10; j++){
			block = m_tetris_blocks[i][j];
			m_tetris_blocks[i-1][j] = block;
			if(block != nullptr){
				block->move(0.0f,-1.0f);
			}
		}
		m_tetris_blocks[i].clear();
		m_tetris_blocks[i].resize(10,nullptr);
	}
}

TetrisPiece* GameManager::createTetrisPiece(TetrisPieceType type) {
	GameObject* tetris_piece = new TetrisPiece(type);
	TetrisPiece* tp = dynamic_cast<TetrisPiece*>(tetris_piece);
	return tp;
}

