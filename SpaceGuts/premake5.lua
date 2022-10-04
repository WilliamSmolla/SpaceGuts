project "SpaceGuts"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("../binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("../binaries-intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "src/pch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"game/**.h",
		"game/**.cpp",
		"dependencies/Box2D/include",
		"dependencies/imgui",
		"dependencies/entt/include",
		"dependencies/SDL_FontCache-master",
		"dependencies/SDL2_image-2.0.5/include",
		"dependencies/SDL2_mixer-2.0.4/include",
		"dependencies/SDL2_ttf-2.0.18/include",
		"dependencies/SDL2-2.0.18/include"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.Box2D}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.Entt}",
		"%{IncludeDir.FontCache}",
		"%{IncludeDir.SDL_Image}",
		"%{IncludeDir.SDL_Mixer}",
		"%{IncludeDir.SDL_TTF}",
		"%{IncludeDir.SDL}"
	}

	links 
	{ 
		"Box2D",
		"ImGui",
		"opengl32.lib",
		"dependencies/SDL2-2.0.18/lib/x64/SDL2.lib",
		"dependencies/SDL2-2.0.18/lib/x64/SDL2main.lib",
		"dependencies/SDL2_image-2.0.5/lib/x64/SDL2_image.lib",
		"dependencies/SDL2_mixer-2.0.4/lib/x64/SDL2_mixer.lib",
		"dependencies/SDL2_ttf-2.0.18/lib/x64/SDL2_ttf.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CORE_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "CORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CORE_RELEASE"
		runtime "Release"
		optimize "on"