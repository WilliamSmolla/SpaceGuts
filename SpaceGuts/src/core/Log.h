#pragma once
#include <Windows.h>

// shitty logging class. Meaby use spdlog in the future...
// or code better shit.
class Log
{
public:
	static Log& GetInstance()
	{
		static Log instance;
		return instance;
	}

	static void Init();
	static void Quit();
	static void SaveToDisc();

	static void Trace(std::string text);
	static void Info(std::string text);
	static void Error(std::string text);
	static void Warning(std::string text);
	static void Critical(std::string text);
	
private:
	Log(){}
	static HANDLE m_Console;
	static std::vector<std::string> m_LogBuffer;
	static std::string getHMSTime();
};

