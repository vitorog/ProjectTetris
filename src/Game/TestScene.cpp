/*
 * TestScene.cpp
 *
 *  Created on: 11/04/2012
 *      Author: Vitor
 */

#include "TestScene.h"

#include <SDL/SDL_opengl.h>
#include "GameEngine/src/Core/InputManager.h"
#include "GameEngine/src/Core/TextureManager.h"
#include <iostream>


SDL_Surface *surface;
GLenum texture_format;
GLint nOfColors;
GLuint texture1;
GLuint texture2;

TestScene::TestScene() {
	m_input_mng = InputManager::getInstance();
}

TestScene::~TestScene() {
}

void TestScene::render() {
	glBindTexture( GL_TEXTURE_2D, texture1  );
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-1.0f,0.0f,0.0f);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1.0f,0.0f,0.0f);
	glTexCoord2f(0.5f,1.0f);
	glVertex3f(0.0f,1.0f,0.0f);
	glEnd();

	glBindTexture( GL_TEXTURE_2D, texture2 );
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-1.0f,-0.5f,0.0f);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(1.0f,-0.5f,0.0f);
	glTexCoord2f(0.5f,1.0f);
	glVertex3f(0.0f,0.0f,0.0f);
	glEnd();
}

GLuint loadTexture(std::string file)
{
	GLuint texture;
	if(surface = SDL_LoadBMP(file.c_str() ) ){
	std::cout << "IMG Loaded OK" << std::endl;
		nOfColors = surface->format->BytesPerPixel;
		if(nOfColors == 4){
			if(surface->format->Rmask == 0x000000ff)
				texture_format = GL_RGBA;
			else
				texture_format = GL_BGRA;
		}else{
			if(nOfColors == 3){
				if(surface->format->Rmask == 0x000000ff){
					texture_format = GL_RGB;
				}else{
					texture_format = GL_BGR;
				}
			}
		}
	}else{
			std::cout << "Failed to load img" << std::endl;
		}
	glGenTextures( 1, &texture);
	glBindTexture( GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D( GL_TEXTURE_2D, 0, nOfColors, surface->w, surface->h, 0, texture_format, GL_UNSIGNED_BYTE, surface->pixels );
	return texture;
}

void TestScene::setup()
{
	m_running = true;
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,5.0f,0.0f,0.0f,-1.0f,0.0f,1.0f,0.0f);
	TextureManager *tex_mng = TextureManager::getInstance();
	tex_mng->loadTexture("test.bmp");
	//texture1 = loadTexture("test.bmp");
	texture1 = tex_mng->getLastLoadedTexture()->m_texture_handle;
	//tex_mng->loadTexture("test2.bmp");
	//texture2 = tex_mng->getLastLoadedTexture()->m_texture_handle;
	texture2 = loadTexture("test2.bmp");
	glEnable(GL_TEXTURE_2D);
}

void TestScene::input(){
	 m_input_mng->handleInput(input_event);
}


