/*
 * TextureManager.cpp
 *
 *  Created on: 11/04/2012
 *      Author: Vitor
 */

#include "TextureManager.h"

TextureManager* TextureManager::m_tex_mng_ptr;

TextureManager* TextureManager::getInstance()
{
	if(m_tex_mng_ptr == nullptr){
		m_tex_mng_ptr = new TextureManager();
	}
	return m_tex_mng_ptr;
}

TextureManager::TextureManager()
{

}

TextureManager::~TextureManager() {
}

bool TextureManager::loadTexture(std::string file_name)
{
	SDL_Surface *tex_surface = nullptr;
	tex_surface = SDL_LoadBMP(file_name.c_str());
	if(tex_surface != nullptr){
		Texture2D *tex = new Texture2D();
		tex->m_target = GL_TEXTURE_2D;
		tex->m_width = tex_surface->w;
		tex->m_height = tex_surface->h;
		tex->m_internal_format = tex_surface->format->BitsPerPixel/8;
		if(tex->m_internal_format == 3){
			if(tex_surface->format->Rmask == 0xff0000){
				tex->m_format = GL_BGR;
			}else{
				tex->m_format = GL_RGB;
			}
		}
		if(tex->m_internal_format == 4){
			if(tex_surface->format->Rmask == 0xff0000ff){
				tex->m_format = GL_BGRA;
			}else{
				tex->m_format = GL_RGBA;
			}
		}

		tex->m_texture_name = file_name;
		tex->m_id = 0;

		glGenTextures( 1, &tex->m_texture_handle );
		glBindTexture(GL_TEXTURE_2D, tex->m_texture_handle);
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		glTexImage2D(tex->m_target, 0, tex->m_internal_format, tex->m_width, tex->m_height,
				0, tex->m_format, GL_UNSIGNED_BYTE, tex_surface->pixels);

		m_textures.push_back(tex);
		SDL_FreeSurface(tex_surface);
		return true;
	}
	std::cout << "Failed to open file." << std::endl;
	return false;

}

Texture2D* TextureManager::getTexture(std::string file_name)
{

}

Texture2D* TextureManager::getTexture(unsigned int m_id)
{

}

Texture2D* TextureManager::getLastLoadedTexture()
{
	Texture2D* texture = nullptr;
	if(this->m_textures.size() > 0){
		texture = m_textures.front();
	}
	return texture;
}


