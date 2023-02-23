#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> 
#include "itemTracker.h"

using namespace std;

//Main entry point for app
int main()
{
	try
	{
		//creates an instance of the calculator and returns a pointer.
		auto tracker = make_unique<ItemTracker>();

		//executes buisness logic
		tracker.get()->run();
	}
	catch (...)
	{
		//Inform user that there was a catastrophic issue
		cout << "There was an issue with the app that caused it to close.  Pleaes try again";

		return 1; //indicates global error
	}

	return 0; //indicates no issues
}

