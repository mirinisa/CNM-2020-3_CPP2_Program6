/* Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 *
 * File: Logger.h
 * Purpose: Create log of game outcome (header file)
 * Last modified: 5 Nov 2020
 */

#ifndef _LOGGER_H
#define _LOGGER_H

#include <string>
#include <fstream>
using namespace std;

class Logger
{
public:
	Logger();
	void StartLog(double initialBalance);
	void WriteLog(string s);
	void CloseLog(string s);
	bool IsLogOpen() const { return bLogOpen; }
private:
	string filename;
	bool bLogOpen{ false };
	string timeRightNow;
	string dateTimeRightNow;
	ofstream output;
	void Time();
	void FileName();
};

#endif /* _LOGGER_H */






/* Mirinisa's notes from class 10/29 11/3

Bet:
	Initialize the game
	Bet:
		int bet;
	Need a bool for if bet is valid:
		bet = Convert::ToInt32(txtBet->Text);
		isValidBet = myGame.bet(bet);
	
	if bet is valid:
	may want a message saying new hands being dealt
		myGame.InitialDeal();
	display initial cards for player and dealer
	check for blackjack
	if blackjack, display in status box
	else, display hit-or-stay group and hide bet group

	if bet is not valid:
	put in status box that the bet is not valid and make them do it over


Hit button:
	if player can contniue
		mygame.PlayerHits();
		Show card in hand

	If player is busted, 
		show result in status box

Stay button:
	Switch to Dealer. Dealer must hit until busted or over 16
	While mygame.DealerContinues(),
		display dealer's hand

Play again button:
	clear text boxes
	reset anything else to beginning status
	make correct groups visible/invisible

Quit button:
	mygame.endgame()
	Application::Exit();


Form load event:
	check if log was opened
	if not, report but don't quit
*/
