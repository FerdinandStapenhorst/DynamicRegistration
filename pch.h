#pragma once
#include <concepts>
#include <functional>
#include <string>
#include <filesystem>
#include <type_traits>
#include <filesystem>
#include <exception>
#include <stdexcept>
#include <iostream>
#include <memory>
#include <map>
#include <typeinfo>
#include <typeindex>

#include "IAdapter.h"

#pragma region Concepts

template <typename T>
concept IsAdapterConfiguration = std::is_object_v<T>;

template<typename T>
concept InAndOutAdapter = requires(T t, IAdapterConfig & config)
{
	t.Init(config);
	t.Start();
};

#pragma endregion

#pragma region Enums

enum class MessageTypes
{
	MsgTyp1 = 0,
	MsgTyp2 = 1
};

enum class LogLevels {
	Info,
	Warn,
	Error,
	Fatal
};

#pragma endregion

#pragma region Usings

//Standard string
using String = std::string;
//Shared pointer to IAdapter - the base class of all adapters
using AdapterPtr = std::shared_ptr<IAdapter>;
//Functor to an instance of IAdapter
using IAdapterFunctor = std::function<AdapterPtr()>;
//List of functors used a s a central adapter registration list
using AdapterFunctorMap = std::map<std::string, IAdapterFunctor>;
//List with instances to ech adapter
using AdapterPtrMap = std::map<String, AdapterPtr>;

#pragma endregion
