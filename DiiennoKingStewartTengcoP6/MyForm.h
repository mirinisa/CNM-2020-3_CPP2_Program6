/* Group 3:
 *   Donald Diienno
 *   Christopher (Sean) King
 *   Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 * 
 * File: MyForm.h
 * Last modified: 5 Nov 2020
*/


#pragma once

#include "Game.h"

namespace DiiennoKingStewartTengcoP6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^ msRules;


	private: System::Windows::Forms::ToolStripMenuItem^ msFileRules;


	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->msRules = (gcnew System::Windows::Forms::MenuStrip());
			this->msFileRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msRules->SuspendLayout();
			this->SuspendLayout();
			// 
			// msRules
			// 
			this->msRules->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->msRules->ImageScalingSize = System::Drawing::Size(22, 22);
			this->msRules->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->msFileRules });
			this->msRules->Location = System::Drawing::Point(0, 0);
			this->msRules->Name = L"msRules";
			this->msRules->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
			this->msRules->Size = System::Drawing::Size(831, 31);
			this->msRules->TabIndex = 1;
			this->msRules->Text = L"menuStrip1";
			// 
			// msFileRules
			// 
			this->msFileRules->Name = L"msFileRules";
			this->msFileRules->Size = System::Drawing::Size(166, 27);
			this->msFileRules->Text = L"Rules of the Game";
			this->msFileRules->ToolTipText = L"Click to see the game rules.";
			this->msFileRules->Click += gcnew System::EventHandler(this, &MyForm::msFileRules_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::OliveDrab;
			this->ClientSize = System::Drawing::Size(831, 410);
			this->Controls->Add(this->msRules);
			this->MainMenuStrip = this->msRules;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Diienno, King, Stewart-Tengco Project 6: Blackjack";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->msRules->ResumeLayout(false);
			this->msRules->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void msFileRules_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ rules = "Rules of the game:";
		rules += "\r\n\nThe goal is to get to 21 points without going over (busting). Cards 2-9 are worth their face value, Jack-King are 10 points each, and Aces can be 1 or 11 depending on what works better.";
		rules += "\r\n\nTo start, you and the dealer are both dealt two cards. The dealer shows one of the cards. You may opt to \"hit\" to be dealt more cards until you either have twelve cards in your hand or you bust.";
		rules += "\r\n\nYou do not have to hit, regardless of the number of points you hold. The dealer is required to hit if their hand is 16 points or less.";
		rules += "\r\n\nEach round, you are allowed to bet as much money as you currently have. If either player goes over 21 points, they bust and lose that round and any money bet. If neither player busts, the one with a hand closer to 21 wins.";
		rules += "\r\nIf there is a tie, you get your money back. If you hit 21 points exactly, you win that round. If you have 21 points with just 2 cards, you achieved \"Blackjack\" and you get 1.5x the money on the table!";
		rules += "\r\n\nHave fun!";

		MessageBox::Show(rules);
	}
};
}
