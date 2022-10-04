#pragma once
#include "pch.h"
#include "../core/Log.h"

class FileUtils
{
public:
	static std::string ReadFile(const char* filepath)
	{
		std::string result;
		std::ifstream fileStream(filepath, std::ios::in);

		if (!fileStream.good())
		{
			Log::Error("File not found: " + std::string(filepath));
			return "";
		}

		if (!fileStream.is_open())
		{
			Log::Error("Could not read file: " + std::string(filepath));
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) {
			std::getline(fileStream, line);
			result += line + "\n";
		}

		fileStream.close();

		return result;
	}

	static void WriteFile(std::string content, const char* filepath)
	{
		std::ofstream fileStream(filepath, std::ofstream::out);

		if (!fileStream.is_open())
		{
			Log::Error("Could not write to file: " + std::string(filepath));
			return;
		}

		fileStream << content;
		fileStream.close();
	}
};

