#pragma once
#include "IAdapter.h"

class IOutputAdapter : public IAdapter
{
public:

	virtual void Store() = 0;
};