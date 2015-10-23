#pragma once

#include <FreeImage.h>
#include <gl\glew.h>
#include <string>
#include "ImageLoader.h"

namespace spacey{ namespace graphics{

	class Texture{
	private: 
		GLuint load();
	public:
		Texture(const std::string& filename);
		~Texture();
		void bind() const;
		void unbind() const;
		inline unsigned int getWidth() { return m_Width; }
		inline unsigned int getHeight() { return m_Height; }
	private:
		std::string m_FileName;
		GLuint m_TID;
		GLsizei m_Width, m_Height;
	};

} }