/* Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 *
 * File: Logger.cpp
 * Purpose: Create log of game outcome
 * Last modified: 5 Nov 2020
 */


#include "Logger.h"
#include <ctime>
#include <chrono>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

Logger::Logger()
{
	// create log file name from date & time
	FileName();
	// find time right now
	Time();

	// attempt to open file
	output.open(filename.c_str());

	// check if open
	if (output.is_open())
	{
		// if open, set bLogOpen
		bLogOpen = true;
		// start log with an introductory sentence
		// and the time right now
		Time();
		output << "Welcome to Blackjack!"
			<< endl << "Time started: " << timeRightNow;	
	}
	
	else
	{
		bLogOpen = false;
	}
}

// called when a game is started
void Logger::StartLog(double initialBalance)
{
	// add user's initial balance
	output << endl << "Player's starting balance: $" << initialBalance
		<< endl;

}

// called when a game is completed
void Logger::WriteLog(string s)
{
	Time();
	// write time right now
	output << endl 
		<< endl << "--------------------" 
		<< endl << "This round ended at: " << timeRightNow;
	// write string
	output << endl << s;
}

// called when EndGame() is called in Game class
void Logger::CloseLog(string s)
{
	// write string & goodbye
	output << endl << endl << s;
	output << endl << endl << "Thank you for playing!";
	// close ofstream
	output.close();
	// open file in Notepad
	string openFile = "Notepad.exe " + filename;
	system(openFile.c_str());
}

void Logger::Time()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%X");
	timeRightNow = ss.str();

}

void Logger::FileName()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%m-%d-%Y_%I.%M.%S");

	dateTimeRightNow = ss.str();

	// set filename
	filename = "Log_" + dateTimeRightNow + ".txt";
}
