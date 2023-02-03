#pragma once
#include "pch.h"

class BaseException : public std::exception
{
public:
	BaseException() noexcept = default;
	BaseException(String const& sourceFile, String const& what) : std::exception(what.c_str())
	{
		_SourceFile = sourceFile;
	}

	String SourceFile() const
	{
		return _SourceFile;
	}

private:
	String _SourceFile;
};

class ConfigurationLoadException : public BaseException
{
public:
	ConfigurationLoadException() noexcept = default;
	ConfigurationLoadException(String const& sourceFile, String const& what) : BaseException(sourceFile, what.c_str())
	{}
};

class FileNotFoundException : public BaseException
{
public:
	FileNotFoundException() noexcept = default;
	FileNotFoundException(String const& sourceFile, String const& what, String const& filePath) : BaseException(sourceFile, what.c_str())
	{
		_Path = filePath;
	}

	String FilePath() const
	{
		return _Path;
	}

private:
	String _Path;
};

class InvalidMessageException : public BaseException
{
public:
	InvalidMessageException() noexcept = default;
	InvalidMessageException(String const& sourceFile, String const& what,
		MessageTypes const& msgType) : BaseException(sourceFile, what.c_str())
	{}
};

class AccessDeniedException : public BaseException
{
public:
	AccessDeniedException() noexcept = default;
	AccessDeniedException(String const& sourceFile, String const& what, String const& target)
		: BaseException(sourceFile, what.c_str())
	{
		_Target = target;
	}
	AccessDeniedException(String const& sourceFile, String const& what, String const& target, LogLevels logLevel)
		: BaseException(sourceFile, what.c_str())
	{
		_Target = target;
		_Loglevel = logLevel;
	}

	String Target() const
	{
		return _Target;
	}

	LogLevels LogLevel() const
	{
		return _Loglevel;
	}

private:
	String _Target;
	LogLevels _Loglevel;
};
