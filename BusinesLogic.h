#pragma once
#include "pch.h"
#include "Registration.h"
#include "Exceptions.h"

class BusinesLogic
{
public:
	BusinesLogic() noexcept = default;
	void CreateAdapters(Registration const& reg);
	void StartAdapters();

	//Method to get a specific adapter from the list and cast it accordingly
	template <InAndOutAdapter T>
	std::shared_ptr<T> AdapterInstance()
	{
		String adapterId = typeid(T).name();
		auto httpAdapter = AdapterList.find(adapterId);
		if (httpAdapter != AdapterList.end())
		{
			auto adapter = std::dynamic_pointer_cast<T>(httpAdapter->second);
			if (adapter) {
				return adapter;
			}
			else {
				BaseException ex(__FILE__, "Casting Adapter failed.");
				throw(&ex);
			}
		}
	}

	AdapterPtrMap AdapterList;
};
