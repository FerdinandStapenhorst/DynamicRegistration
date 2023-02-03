#pragma once
#include "pch.h"

class Registration
{
public:
	Registration();
	AdapterFunctorMap Adapters() const;

private:
	void RegisterAdapters() noexcept;
	AdapterFunctorMap RegisteredAdapters;

	template <InAndOutAdapter T>
	void Register() noexcept
	{
		String className = typeid(T).name();
		auto func = []() -> AdapterPtr { return std::make_shared<T>(); };
		auto pair = std::make_pair(className, func);
		RegisteredAdapters.insert(pair);
	}
};
