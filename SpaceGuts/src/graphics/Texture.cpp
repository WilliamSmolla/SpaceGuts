#include "pch.h"
#include "Texture.h"

Texture::Texture(SDL_Texture* texture)
	: _texture{ texture }, _width{ 0 }, _height{ 0 }
{
	SDL_QueryTexture(texture, NULL, NULL, &_width, &_height);
}

Texture::~Texture()
{
	SDL_DestroyTexture(_texture);
}
