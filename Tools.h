#pragma once
#include "pch.h"

class Tools {
public:

	static bool FileExist(String path)
	{
		std::filesystem::path p{ path };
		return std::filesystem::exists(p);
	}
};