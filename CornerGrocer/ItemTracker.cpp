#include "ItemTracker.h"
#include "OutputSupport.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> 
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

//Declare output support object
OutputSupport outputSupport;

ItemTracker::ItemTracker() {};

//Writes the dat file
void ItemTracker::writeDatFile()
{
	//create buffer
	string fileContent;

	//iterate through the map to generate file content
	for (auto itr = m_itemCounter.begin(); itr != m_itemCounter.end(); ++itr) {			
			fileContent = fileContent + itr->first + " " + std::to_string(itr->second) + "\n";
	}

	//creates a stream
	std::ofstream outputstream;

	//opens the stream
	outputstream.open("C:\\DataInputFiles\\frequency.dat");

	//places contents into file
	outputstream << fileContent;

	//release the output file
	outputstream.close();
};

//Loads the datafile
void ItemTracker::loadDataSet()
{
	//creates a stream
	std::ifstream inputstream;

	//create buffer var
	string buffer;

	//opens the stream
	inputstream.open("C:\\DataInputFiles\\cs210ProjectInputFile.txt");	

	//verifies if the stream is open.  If it is continue working
	if (inputstream.is_open())
	{
		//keep reading until the end of file
		while (!inputstream.eof())
		{
			inputstream >> buffer; //Read file line

			//inserts into the map randomly
			//if the result is false add to the count
			auto ret = m_itemCounter.insert({ buffer,1 });

			if (!ret.second)
				m_itemCounter[buffer]++;
		}

		//release the input file
		inputstream.close();
	}
};

//Lets user search to see instances of specific word
void ItemTracker::searchForItem()
{
	string buffer;

	system("cls"); //clear screen

	//ask the user what they want to look for?
	outputSupport.writeLine("What item would you like to see the count for ?");

	//get user input
	cin >> buffer;

	//get thet count for the value.
	auto result = m_itemCounter[buffer];

	//output to the user
	cout << "There are " << result << " instances of " << buffer << endl;

	system("pause");//waits for user to press a key
};

//Outputs a list of items and the count of each instance
void ItemTracker::displayListOfItems()
{
	system("cls"); //clear screen

	//iterate through the map and display the data to the user
	for (auto itr = m_itemCounter.begin(); itr != m_itemCounter.end(); ++itr) {
		cout <<  itr->first << " " << itr->second << endl;
	}

	system("pause");//waits for user to press a key
};

//Outputs a visual representation of the item count
void ItemTracker::displayHistogramOfItems()
{
	system("cls"); //clear screen

	//iterate through the map and display the data to the user
	for (auto itr = m_itemCounter.begin(); itr != m_itemCounter.end(); ++itr) {
		cout << itr->first << " : ";
		outputSupport.generateOutputLine('*', itr->second, true);
	}

	system("pause");//waits for user to press a key
};

//executes main working loop for the application
void ItemTracker::run()
{
	bool keepRunning = true;
	//app will keep running until user exits

	//load data
	loadDataSet();

	//write backup file
	writeDatFile();

	//user selection for menu option
	int menuItemSelection = 0;

	//start of work loop
	while (keepRunning)
	{
		outputSupport.generateOutputLine( '*', 60, true);
		outputSupport.generateOutputLine(' ', 20, false);
		cout << " Item Tracker ";
		outputSupport.generateOutputLine(' ', 20, true);
		outputSupport.generateOutputLine('*', 60, true);

		outputSupport.writeLine("1: Get a count for a specific item");
		outputSupport.writeLine("2: Get a list of all items and their counts");
		outputSupport.writeLine("3: Get a visual representation of item coutns");
		outputSupport.writeLine("4: Exit");

		outputSupport.generateOutputLine('-', 60, true);

		menuItemSelection = outputSupport.getInt("What would you like to do?", 0);

		switch (menuItemSelection)
		{
			//allows user to lookup item
			case 1: searchForItem(); break;

			//allows user to view list of items and their counts
			case 2: displayListOfItems(); break;

			//displays a visual representation of the data
			case 3: displayHistogramOfItems(); break;

			//exit program
			case 4: keepRunning = false; break;

			//user didnt enter a good value
			default:
				outputSupport.writeLine("Please enter in a value between 1 - 4");
				system("pause");//waits for user to press a key
				
				//erases the last line in the event we need to ask again.
				outputSupport.eraseLine();
				break;

		}

		system("cls");
	}

	outputSupport.writeLine("good bye!!");

};