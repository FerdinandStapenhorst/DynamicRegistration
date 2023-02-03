#include "pch.h"
#include "Registration.h"

//Adapter includes
#include "DbOutputAdapter.h"
#include "HttpInputAdapter.h"

Registration::Registration()
{
	RegisterAdapters();
}

void Registration::RegisterAdapters() noexcept
{
	//Insert new adapters here:
	Register<HttpInputAdapter>();
	Register<DbOutputAdapter>();
}

AdapterFunctorMap Registration::Adapters() const
{
	return RegisteredAdapters;
}