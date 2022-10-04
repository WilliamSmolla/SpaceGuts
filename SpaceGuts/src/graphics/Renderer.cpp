#include "pch.h"
#include "Renderer.h"
#include "../core/Log.h"
#include "core/Window.h"
#include "../scene/Components.h"
#include "scene/GameObject.h"
#include "scene/Scene.h"
#include "maths/MathConstants.h"

void Renderer::init()
{  
    _renderer = SDL_CreateRenderer(Window::GetInstance().GetNativeWindow(),
        -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) 
    {
        Log::Critical("Failed to create Renderer.");
        exit(EXIT_FAILURE);
    }
    else
    {
        Log::Info("Renderer created successfully.");
    }

    SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
}

void Renderer::shutdown()
{
    SDL_DestroyRenderer(_renderer);
}

void Renderer::render(entt::registry& registry, Scene* scene)
{
    registry.sort<Tag>([](const auto& lhs, const auto& rhs)
    {
        return lhs.layer < rhs.layer;
    });
    auto view = registry.view<Transform, Tag>();
    for (auto& go : view)
    {
        GameObject gameObject = { go, scene };
        auto& transform = gameObject.GetComponent<Transform>();      

        if (gameObject.HasComponent<SpriteRenderer>())
        {
            auto& spriteRenderer = gameObject.GetComponent<SpriteRenderer>();
            auto m2p = Window::GetM2PRatio();

            SDL_Rect renderQuad;
            renderQuad.w = transform.scale.x * m2p;
            renderQuad.h = transform.scale.y * m2p;
            renderQuad.x = ((Window::GetScaledSize().x / 2) + 
                transform.position.x - scene->_camera.GetPosition().x) * m2p - renderQuad.w / 2;
            renderQuad.y = ((Window::GetScaledSize().y / 2) + 
                transform.position.y - scene->_camera.GetPosition().y) * m2p - renderQuad.h / 2;

            if (gameObject.HasComponent<Animator>())
            {
                auto& animator = gameObject.GetComponent<Animator>().controller;         
                SDL_Rect sourceQuad = animator.GetSourceQuad();
                SDL_RenderCopyEx(Renderer::GetNativeRenderer(), spriteRenderer.sprite->NativeTexture(),
                    &sourceQuad, &renderQuad, transform.angle, NULL, static_cast<SDL_RendererFlip>(spriteRenderer.isFlipped));       
                continue;
            }

            SDL_RenderCopyEx(Renderer::GetNativeRenderer(), spriteRenderer.sprite->NativeTexture(),
                NULL, &renderQuad, transform.angle, NULL, static_cast<SDL_RendererFlip>(spriteRenderer.isFlipped));      
        }
    }   
}
   
SDL_Renderer* Renderer::getNativeRenderer()
{
	return _renderer;
}

void Renderer::renderClear(Vec4 color)
{
    SDL_SetRenderDrawColor(_renderer, color.x, color.y, color.z, color.w);
    SDL_RenderClear(_renderer);   
}

void Renderer::renderPresent()
{
    SDL_RenderPresent(_renderer);
}





