#include"pch.h"
#include "DbOutputAdapter.h"

void DbOutputAdapter::Store()
{
	//Store to db
}

void DbOutputAdapter::Init(IAdapterConfig const& config)
{
	std::cout << "DbOutputAdapter::Init" << std::endl;
}

void DbOutputAdapter::Start()
{
	std::cout << "DbOutputAdapter::Start" << std::endl;
}