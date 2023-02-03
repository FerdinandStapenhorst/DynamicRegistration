#pragma once
#include "pch.h"
#include "Registration.h"

class AdapterFactory
{
public:

	static void CreateAdapters(Registration const& registration, AdapterPtrMap& AdapterList)
	{
		//Create instances of all registered adapters
		for (auto& [key, adapter] : registration.Adapters())
		{
			auto functor = adapter(); //here the default constructor of the respective adapter is called
			AdapterList.insert(std::pair<String, AdapterPtr>(key, functor));
		}
	}
};
