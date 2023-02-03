#pragma once
#include "pch.h"
#include "IAdapterConfig.h"

class AdapterConfig : public IAdapterConfig
{
public:
	AdapterConfig() noexcept = delete;
	AdapterConfig(AdapterConfig const& other) noexcept = delete;

	AdapterConfig(String const& path) noexcept;
	virtual void Load() override;
	virtual void Save() override;

private:
	String _Path;
};

static_assert(IsAdapterConfiguration<AdapterConfig>);