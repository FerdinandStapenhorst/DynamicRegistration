#pragma once
#include "IInputAdapter.h"

class HttpInputAdapter : public IInputAdapter
{
public:
	HttpInputAdapter() noexcept
	{
		std::cout << "HttpInputAdapter::Ctor" << std::endl;
	}
	virtual ~HttpInputAdapter() noexcept
	{
		std::cout << "HttpInputAdapter::Dtor" << std::endl;
	}

	// Inherited via IAdapter
	virtual void Init(IAdapterConfig const& config) override;
	virtual void Start() override;
	//Inherited from IInputAdapter
	virtual void Receive() override;
};