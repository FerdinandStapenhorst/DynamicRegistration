#include"pch.h"
#include "BusinesLogic.h"
#include "AdapterConfig.h"
#include "HttpInputAdapter.h"
#include "DbOutputAdapter.h"
#include "AdapterFactory.h"

void BusinesLogic::CreateAdapters(Registration const& reg)
{
	//Create instances of all adapters
	AdapterFactory::CreateAdapters(reg, AdapterList);
}

void BusinesLogic::StartAdapters()
{
	//Adapter config
	AdapterConfig adapterConfig("./config.json");

	//Init and start Adapters
	for (auto const& [name, adapterPtr] : AdapterList)
	{
		adapterPtr->Init(adapterConfig);
		adapterPtr->Start();
	}

	//How to get a specific adapter
}

static_assert(InAndOutAdapter<HttpInputAdapter>);
static_assert(InAndOutAdapter<DbOutputAdapter>);