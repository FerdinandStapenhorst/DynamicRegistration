#pragma once
#include "pch.h"
#include "IAdapterConfig.h"

class IAdapter
{
public:

	virtual void Init(IAdapterConfig const& config) = 0;
	virtual void Start() = 0;
};

//static_assert(InAndOutAdapter<IAdapter>);