#pragma once

#include <string>

//A support class that contains methods that write to the console
class OutputSupport
{
public:
	//writes a line of only the charector specified.
	void generateOutputLine(char t_charectorToWrite, int t_numberOfCharsToWrite, bool t_writeEndline);

	//writes a line of text to the console
	void writeLine(std::string t_lineToWrite);

	//asks the user to provide a value and converts it to double
	double getDouble(std::string t_instruction, double t_initialValue);

	//asks the user to provide a value and converts it to int
	int getInt(std::string t_instruction, int t_initialValue);


	//erases current console line
	static void eraseLine();

	//inform user of invalid value
	static void notifyUserOfBadValue(std::string input);

};

