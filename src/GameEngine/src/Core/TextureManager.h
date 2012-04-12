/*
 * TextureManager.h
 *
 *  Created on: 11/04/2012
 *      Author: Vitor
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Core/VideoManager.h"
#include <vector>

class Texture2D;

class TextureManager {
public:
	virtual ~TextureManager();
	static TextureManager* getInstance();
	bool loadTexture(std::string file_name);
	Texture2D*	getTexture(std::string file_name);
	Texture2D* getTexture(unsigned int m_id);
	Texture2D* getLastLoadedTexture();
private:
	TextureManager();
	std::vector<Texture2D*> m_textures;
	static TextureManager* m_tex_mng_ptr;
};

class Texture2D
{
public:
	Texture2D() {};
//private:
	unsigned int m_id;
	unsigned int m_width;
	unsigned int m_height;
	bool m_border;
	GLenum m_target;
	GLint m_level;
	GLint m_internal_format;
	GLenum m_format;
	GLenum m_type;
	GLuint m_texture_handle;
	std::string m_texture_name;

};

#endif /* TEXTUREMANAGER_H_ */
