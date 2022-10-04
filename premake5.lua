workspace "GameEngine"
	architecture "x64"
	startproject "SpaceGuts"

	configurations
	{
		"Debug",
		"Release"
	}
	
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["Box2D"] = "dependencies/Box2D/include"
IncludeDir["ImGui"] = "dependencies/imgui"
IncludeDir["Entt"] = "dependencies/entt/include"
IncludeDir["FontCache"] = "dependencies/SDL_FontCache-master"
IncludeDir["SDL_Image"] = "dependencies/SDL2_image-2.0.5/include"
IncludeDir["SDL_Mixer"] = "dependencies/SDL2_mixer-2.0.4/include"
IncludeDir["SDL_TTF"] = "dependencies/SDL2_ttf-2.0.18/include"
IncludeDir["SDL"] = "dependencies/SDL2-2.0.18/include"

group "Dependencies"
	include "SpaceGuts/dependencies/Box2D"
	include "SpaceGuts/dependencies/imgui"
	
group ""

include "SpaceGuts"



