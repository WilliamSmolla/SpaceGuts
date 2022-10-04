#include "pch.h"
#include "InputManager.h"

void InputManager::init()
{
	_keycodes[Keycode::A] = false;
	_keycodes[Keycode::B] = false;
	_keycodes[Keycode::C] = false;
	_keycodes[Keycode::D] = false;
	_keycodes[Keycode::E] = false;
	_keycodes[Keycode::F] = false;
	_keycodes[Keycode::G] = false;
	_keycodes[Keycode::H] = false;
	_keycodes[Keycode::I] = false;
	_keycodes[Keycode::J] = false;
	_keycodes[Keycode::K] = false;
	_keycodes[Keycode::L] = false;
	_keycodes[Keycode::M] = false;
	_keycodes[Keycode::N] = false;
	_keycodes[Keycode::O] = false;
	_keycodes[Keycode::P] = false;
	_keycodes[Keycode::Q] = false;
	_keycodes[Keycode::R] = false;
	_keycodes[Keycode::S] = false;
	_keycodes[Keycode::T] = false;
	_keycodes[Keycode::U] = false;
	_keycodes[Keycode::V] = false;
	_keycodes[Keycode::W] = false;
	_keycodes[Keycode::X] = false;
	_keycodes[Keycode::Y] = false;
	_keycodes[Keycode::Z] = false;

	// implement these in updateInputs.
	_keycodes[Keycode::ESCAPE] = false;
	_keycodes[Keycode::LEFT_SHIFT] = false;
	_keycodes[Keycode::RIGHT_SHIFT] = false;
	_keycodes[Keycode::LEFT_CTRL] = false;
	_keycodes[Keycode::RIGHT_CTRL] = false;
	_keycodes[Keycode::LEFT_ALT] = false;
	_keycodes[Keycode::RIGHT_ALT] = false;
	_keycodes[Keycode::SPACE] = false;
	_keycodes[Keycode::ENTER] = false;
	_keycodes[Keycode::LEFT] = false;
	_keycodes[Keycode::RIGHT] = false;
	_keycodes[Keycode::UP] = false;
	_keycodes[Keycode::DOWN] = false;

	_mousecodes[Mousecode::LEFT_MOUSE] = false;
	_mousecodes[Mousecode::RIGHT_MOUSE] = false;	
}

void InputManager::updateInputs(const SDL_Event& event)
{
	switch (event.type)
	{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_a:
					setKey(Keycode::A, true);
					break;
				case SDLK_b:
					setKey(Keycode::B, true);
					break;
				case SDLK_c:
					setKey(Keycode::C, true);
					break;
				case SDLK_d:
					setKey(Keycode::D, true);
					break;
				case SDLK_e:
					setKey(Keycode::E, true);
					break;
				case SDLK_f:
					setKey(Keycode::F, true);
					break;
				case SDLK_g:
					setKey(Keycode::G, true);
					break;
				case SDLK_h:
					setKey(Keycode::H, true);
					break;
				case SDLK_i:
					setKey(Keycode::I, true);
					break;
				case SDLK_j:
					setKey(Keycode::J, true);
					break;
				case SDLK_k:
					setKey(Keycode::K, true);
					break;
				case SDLK_l:
					setKey(Keycode::L, true);
					break;
				case SDLK_m:
					setKey(Keycode::M, true);
					break;
				case SDLK_n:
					setKey(Keycode::N, true);
					break;
				case SDLK_o:
					setKey(Keycode::O, true);
					break;
				case SDLK_p:
					setKey(Keycode::P, true);
					break;
				case SDLK_q:
					setKey(Keycode::Q, true);
					break;
				case SDLK_r:
					setKey(Keycode::R, true);
					break;
				case SDLK_s:
					setKey(Keycode::S, true);
					break;
				case SDLK_t:
					setKey(Keycode::T, true);
					break;
				case SDLK_u:
					setKey(Keycode::U, true);
					break;
				case SDLK_v:
					setKey(Keycode::V, true);
					break;
				case SDLK_w:
					setKey(Keycode::W, true);
					break;
				case SDLK_x:
					setKey(Keycode::X, true);
					break;
				case SDLK_y:
					setKey(Keycode::Y, true);
					break;
				case SDLK_z:
					setKey(Keycode::Z, true);
					break;		
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_a:
				setKey(Keycode::A, false);
				break;
			case SDLK_b:
				setKey(Keycode::B, false);
				break;
			case SDLK_c:
				setKey(Keycode::C, false);
				break;
			case SDLK_d:
				setKey(Keycode::D, false);
				break;
			case SDLK_e:
				setKey(Keycode::E, false);
				break;
			case SDLK_f:
				setKey(Keycode::F, false);
				break;
			case SDLK_g:
				setKey(Keycode::G, false);
				break;
			case SDLK_h:
				setKey(Keycode::H, false);
				break;
			case SDLK_i:
				setKey(Keycode::I, false);
				break;
			case SDLK_j:
				setKey(Keycode::J, false);
				break;
			case SDLK_k:
				setKey(Keycode::K, false);
				break;
			case SDLK_l:
				setKey(Keycode::L, false);
				break;
			case SDLK_m:
				setKey(Keycode::M, false);
				break;
			case SDLK_n:
				setKey(Keycode::N, false);
				break;
			case SDLK_o:
				setKey(Keycode::O, false);
				break;
			case SDLK_p:
				setKey(Keycode::P, false);
				break;
			case SDLK_q:
				setKey(Keycode::Q, false);
				break;
			case SDLK_r:
				setKey(Keycode::R, false);
				break;
			case SDLK_s:
				setKey(Keycode::S, false);
				break;
			case SDLK_t:
				setKey(Keycode::T, false);
				break;
			case SDLK_u:
				setKey(Keycode::U, false);
				break;
			case SDLK_v:
				setKey(Keycode::V, false);
				break;
			case SDLK_w:
				setKey(Keycode::W, false);
				break;
			case SDLK_x:
				setKey(Keycode::X, false);
				break;
			case SDLK_y:
				setKey(Keycode::Y, false);
				break;
			case SDLK_z:
				setKey(Keycode::Z, false);
				break;
			}
			break;	

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				setButton(Mousecode::LEFT_MOUSE, true);
				break;
			case SDL_BUTTON_RIGHT:
				setButton(Mousecode::RIGHT_MOUSE, true);
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				setButton(Mousecode::LEFT_MOUSE, false);
				break;
			case SDL_BUTTON_RIGHT:
				setButton(Mousecode::RIGHT_MOUSE, false);
				break;
			}
			break;
	}
}

void InputManager::setKey(Keycode keycode, bool isKeyDown)
{
	_keycodes[keycode] = isKeyDown;
}

void InputManager::setButton(Mousecode mousecode, bool isButtonDown)
{
	_mousecodes[mousecode] = isButtonDown;
}

bool InputManager::isKeyDown(Keycode keycode)
{
	if (_keycodes[keycode])	return true;

	return false;
}

bool InputManager::isMouseButtonDown(Mousecode mousecode)
{
	if (_mousecodes[mousecode]) return true;

	return false;
}


