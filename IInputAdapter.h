#pragma once
#include "pch.h"
#include "IAdapter.h"

class IInputAdapter : public IAdapter
{
public:

	virtual void Receive() = 0;
};
