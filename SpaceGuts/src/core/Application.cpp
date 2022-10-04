#include "pch.h"
#include "Application.h"
#include "Log.h"

Application::Application()
    : _isRunning{ true }
{
    srand(static_cast<unsigned>(time(0)));

	Log::Init();
	initSDL();
    Window::Init();
    Renderer::Init();
    ResourceManager::Init();
    InputManager::Init();
    PhysicsManager::Init();
    SceneManager::Init();
}

Application::~Application()
{
    Shutdown();
}

void Application::Run()
{
    SDL_Event event;

    float lastFrameTime = SDL_GetTicks() - _frameTime;
    float timeAccumulator = 0;

    while (_isRunning)
    {
        float frameTime = SDL_GetTicks();
        float deltaTime = frameTime - lastFrameTime;

        if (InputManager::IsKeyDown(Keycode::Q))
        {
            _isRunning = false;
            return;
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT || (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
                    && event.window.windowID == SDL_GetWindowID(Window::GetNativeWindow())))
            {
                Shutdown();
            }
            
            HandleEvents(event);
        }

        if (deltaTime > 100) deltaTime = 100;

        timeAccumulator += deltaTime;

        while (timeAccumulator >= _frameTime)
        {
            Update(_frameTime);
            timeAccumulator -= _frameTime;
        }

        Update(timeAccumulator);

        timeAccumulator = 0;

        Render();       

        int wait = frameTime + _frameTime - SDL_GetTicks();

        if (wait < 0)
        {
            std::string waitTime = std::to_string(-wait);
            Log::Warning("Lag of " + waitTime + " ms");
        }
        else
        {
            SDL_Delay(wait);
        }

        lastFrameTime = frameTime;
    }

    Log::Quit();
}

void Application::Shutdown()
{
    _isRunning = false;
    _scene->OnDestroy();
    PhysicsManager::Shutdown();
    delete _scene;
    Log::Info("Shutting down");
    Log::SaveToDisc();
}

void Application::HandleEvents(const SDL_Event& event)
{
    _scene->HandleEvents(event);   
}

void Application::Update(float deltaTime)
{
    _scene->Update(deltaTime);
}

void Application::Render()
{
    _scene->Render();
}

void Application::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
		Log::Critical("Failed to initialize SDL " + std::string(SDL_GetError()));
		exit(EXIT_FAILURE);
	}
	else
	{
		Log::Info("SDL_VID initialized successfully.");
	}

	if (IMG_Init(IMG_INIT_PNG) < 0)
	{
        Log::Critical("Failed to initialize SDL_IMG: " + std::string(IMG_GetError()));
        exit(EXIT_FAILURE);
	}
    else
    {
        Log::Info("SDL_IMG initialized successfully.");
    }

    if (SDL_Init(SDL_INIT_AUDIO) < 0 || Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        Log::Critical("Failed to initialize SDL_MIX: " + std::string(SDL_GetError()));
        exit(EXIT_FAILURE);
    }

    else
    {
        Log::Info("SDL_MIX initialized successfully");
    }

    if (TTF_Init() < 0)
    {
        Log::Critical("Failed to initialize SDL_TTF: " + std::string(TTF_GetError()));
        exit(EXIT_FAILURE);
    }

    else
    {
        Log::Info("SDL_TTF initialized successfully");
    }
}
