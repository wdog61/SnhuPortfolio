#include "OutputSupport.h"
#include "OutputSupport.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string> 
using namespace std;
//A support class that contains methods that write to the console

//writes a line of only the charector specified.
void OutputSupport::generateOutputLine(char t_charectorToWrite, int t_numberOfCharsToWrite, bool t_writeEndline)
{
	//loop through the number of chars to write
	for (int i = 0; i < t_numberOfCharsToWrite; i++)
	{
		//write the charector
		cout << t_charectorToWrite;
	}

	if (t_writeEndline)
	{
		//new line
		cout << endl;
	}
};



//writes a line of text to the console
void OutputSupport::writeLine(string t_lineToWrite)
{
	cout << t_lineToWrite << endl;
};

//asks the user to provide a value and converts it to double
double OutputSupport::getDouble(std::string t_instruction, double t_initialValue)
{
	//buffer variable
	string userInput;

	//output variable
	double parsedValue;

	//initialize value
	parsedValue = 0.0;

	bool parseFailed = false;

	//continue looking for valid input.
	//valid will be a positive double greater then 0
	while (parsedValue <= 0.0)
	{
		parseFailed = false;
		try
		{
			//write instruction
			cout << t_instruction;

			//output the current value of the parameter if not zero.
			//This allows the user to remember the previous value.
			if (t_initialValue != 0.0)
				cout << " [" << t_initialValue << "] ";

			//get input
			cin >> userInput;

			//parse input to obtain value
			parsedValue = stod(userInput.c_str());
		}
		catch (...) //parse has failed.
		{
			//Inform user that the parse has failed.
			OutputSupport::notifyUserOfBadValue(userInput);
			parseFailed = true;
		}

		//check for invalid value
		if (parsedValue <= 0 && !parseFailed)
		{
			//Inform user that the parse has failed.
			OutputSupport::notifyUserOfBadValue(userInput);
		}
	}

	return parsedValue;


};


//asks the user to provide a value and converts it to double
int OutputSupport::getInt(std::string t_instruction, int t_initialValue)
{
	//buffer variable
	string userInput;

	//output variable
	int parsedValue;

	//initialize value
	parsedValue = 0;


	bool parseFailed = false;

	//continue looking for valid input.
	//valid will be a positive int greater then 0
	while (parsedValue <= 0)
	{
		try
		{
			//write instruction
			cout << t_instruction;

			//output the current value of the parameter if not zero.
			//This allows the user to remember the previous value.
			if (t_initialValue != 0)
				cout << " [" << t_initialValue << "] ";

			//get input
			cin >> userInput;

			//parse input to obtain value
			parsedValue = stoi(userInput.c_str());
		}
		catch (...) //parse has failed.
		{
			//Inform user that the parse has failed.
			OutputSupport::notifyUserOfBadValue(userInput);
			parseFailed = true;
		}

		//check for invalid value
		if (parsedValue <= 0 && !parseFailed)
		{
			//Inform user that the parse has failed.
			OutputSupport::notifyUserOfBadValue(userInput);
		}
	}

	return parsedValue;


};


//inform user of invalid value
void OutputSupport::notifyUserOfBadValue(string input)
{
	cout << endl;
	cout << "The value " << input << " is invalid.  ";
	cout << "Please enter a positive non-zero value." << endl;
	system("pause");//waits for user to press a key
	OutputSupport::eraseLine();
	OutputSupport::eraseLine();
	OutputSupport::eraseLine();
	OutputSupport::eraseLine();
};



//erases current console line
void OutputSupport::eraseLine()
{
	printf("\33[2K"); //erased current line
	printf("\033[A"); //mover cursor up line
	printf("\r"); //returns cursor to start of line
	//For refrence see this article: https://stackoverflow.com/questions/1508490/erase-the-current-printed-console-line
};