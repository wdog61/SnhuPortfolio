#pragma once

#include <map>
#include <string> 


//Tracks the items purchased for a corner store
class ItemTracker
{
	private:

		//dictionary that stores our dataset
		std::map<std::string, int> m_itemCounter;

		//Writes the dat file
		void writeDatFile();

		//Loads the datafile
		void loadDataSet();

		//Lets user search to see instances of specific word
		void searchForItem();

		//Outputs a list of items and the count of each instance
		void displayListOfItems();

		//Outputs a visual representation of the item count
		void displayHistogramOfItems();



	public:
		void run(); //Application Driver
		ItemTracker(); //default constructor

};

