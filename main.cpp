// DynamicRegistration.cpp
// Example how to dynamically use instances of objects (here Adapters) using some sort or 
// registration concept

#include"pch.h"
#include "Exceptions.h"
#include "HttpInputAdapter.h"
#include "AdapterConfig.h"
#include "BusinesLogic.h"
#include "Registration.h"

int main()
{
	//Register all adapters
	Registration reg;
	//The main business logic
	BusinesLogic bl;

	try
	{
		bl.CreateAdapters(reg);
		bl.StartAdapters();
		//Do something with a specific adapter
		auto httpAdpt = bl.AdapterInstance<HttpInputAdapter>();
		httpAdpt->ProcessMessage("A new message");

		//Throw example exception when attempting to process an empty message
		httpAdpt->ProcessMessage("");

		//do what the business logig does
		//
		//...
		// 
		//end
		return 0;
	}
	catch (ConfigurationLoadException const& e) {
		std::cerr << "A Configuration Load Exception  happened: " << e.SourceFile() << " " << e.what() << std::endl;
	}
	catch (FileNotFoundException const& e) {
		std::cerr << "File not found: " << e.FilePath() << " " << e.what() << std::endl;
	}
	catch (AccessDeniedException const& e)
	{
		if (e.LogLevel() == LogLevels::Error)
		{
			std::cerr << "An std:exception happened: " << e.what() << std::endl;
		}
	}
	catch (InvalidMessageException const& e) {
		std::cerr << "Invalid Message Exception  happened: " << e.SourceFile() << " " << e.what() << std::endl;
	}
	catch (BaseException const& e) {
		std::cerr << "An exception happened: " << e.SourceFile() << " " << e.what() << std::endl;
	}
	catch (std::exception const& e) {
		std::cerr << "An std:exception happened: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown exception happened: " << std::endl;
	}

	return 1;
}