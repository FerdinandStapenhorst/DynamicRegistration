#pragma once
#include "IOutputAdapter.h"

class DbOutputAdapter : public IOutputAdapter
{
public:

	DbOutputAdapter() noexcept
	{
		std::cout << "DbOutputAdapter::Ctor" << std::endl;
	}
	virtual ~DbOutputAdapter() noexcept
	{
		std::cout << "DbOutputAdapter::Dtor" << std::endl;
	}

	// Inherited via IAdapter
	virtual void Init(IAdapterConfig const& config) override;
	virtual void Start() override;

	// Inherited via IOutputAdapter
	virtual void Store() override;
};
