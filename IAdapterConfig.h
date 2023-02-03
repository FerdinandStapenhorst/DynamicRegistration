#pragma once
#include "pch.h"

class IAdapterConfig
{
public:
	virtual void Save() = 0;
	virtual void Load() = 0;
};