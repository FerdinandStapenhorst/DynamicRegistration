#include"pch.h"
#include "HttpInputAdapter.h"
#include "Exceptions.h"
#include <iostream>

void  HttpInputAdapter::Init(IAdapterConfig const& config)
{
	//Init some stuff...
	std::cout << "HttpInputAdapter::Init" << std::endl;
}

void HttpInputAdapter::Start()
{
	//Do validation
	std::cout << "HttpInputAdapter::Start" << std::endl;
}

void HttpInputAdapter::ProcessMessage(String const& msg)
{
	//ProcessMessage data
	std::cout << "HttpInputAdapter::ProcessMessage" << std::endl;
	if (msg.length() == 0)
		throw InvalidMessageException(__FILE__, "The message was empty!", MessageTypes::MsgTyp1);

	try
	{
		//Do receiving of data
	}
	catch (std::exception const& e) {
		throw InvalidMessageException(__FILE__, "Received invalid message.", MessageTypes::MsgTyp1);
	}
}