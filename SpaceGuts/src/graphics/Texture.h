#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Texture
{
public:
	Texture() = default;
	Texture(SDL_Texture* texture);
	~Texture();

	SDL_Texture* NativeTexture() const { return _texture; }
	int Width() const { return _width; }
	int Height() const { return _height; }

private:
	SDL_Texture* _texture;
	int _width;
	int _height;
};

