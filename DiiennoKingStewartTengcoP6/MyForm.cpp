/* Group 3:
 *   Donald Diienno
 *   Christopher (Sean) King
 *   Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 *
 * File: MyForm.cpp
 * Last modified: 3 Nov 2020
*/


#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	DiiennoKingStewartTengcoP6 ::MyForm form;
	Application::Run(% form);
}
