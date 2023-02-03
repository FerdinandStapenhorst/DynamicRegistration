#include"pch.h"
#include "AdapterConfig.h"
#include "Tools.h"
#include "Exceptions.h"

bool somethingWentWrong = true;

AdapterConfig::AdapterConfig(String const& path) noexcept
{
	_Path = path;
}

void AdapterConfig::Load()
{
	if (!Tools::FileExist(_Path))
		throw FileNotFoundException(__FILE__, "Invalid configuration path", _Path);

	//Load file...
	if (somethingWentWrong)
		throw ConfigurationLoadException(__FILE__, "Loading of config failed.");

	//Keep going
	//do what you need to do
}

void AdapterConfig::Save()
{
	//Save config
	String folder;
	if (somethingWentWrong)
		throw AccessDeniedException(__FILE__, "Cannot access folder.", folder, LogLevels::Warn);
}