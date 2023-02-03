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

void HttpInputAdapter::Receive()
{
	//Receive data
	std::cout << "HttpInputAdapter::Receive" << std::endl;
	try
	{
		//Do receiving of data
	}
	catch (std::exception const& e) {
		InvalidMessageException ex(__FILE__, "Received invalid message.", MessageTypes::MsgTyp1);
		throw(&ex);
	}
}