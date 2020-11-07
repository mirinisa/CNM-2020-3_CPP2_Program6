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

	Game mygame;
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
			lblHitOrStay->Visible = false;
			btnHit->Visible = false;
			btnStay->Visible = false;
			if (!mygame.IsLogOpened())
				txtGameStatus->Text = "No log file is being written to. But we can still play the game.";
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
	private: System::Windows::Forms::Label^ lblWelcome;
	private: System::Windows::Forms::Label^ lblBet;
	private: System::Windows::Forms::TextBox^ txtBet;
	private: System::Windows::Forms::Button^ btnBet;
	private: System::Windows::Forms::ToolStripMenuItem^ msAboutProgram;
	private: System::Windows::Forms::TextBox^ txtPlayersHand;
	private: System::Windows::Forms::Label^ lblPlayersHand;
	private: System::Windows::Forms::Label^ lblDealersHand;
	private: System::Windows::Forms::TextBox^ txtDealersHand;
	private: System::Windows::Forms::TextBox^ txtGameStatus;
	private: System::Windows::Forms::Label^ lblGameStatus;
	private: System::Windows::Forms::Button^ btnPlayAgain;
	private: System::Windows::Forms::Label^ lblHitOrStay;
	private: System::Windows::Forms::Button^ btnHit;
	private: System::Windows::Forms::Button^ btnStay;


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
			this->msAboutProgram = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msFileRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lblWelcome = (gcnew System::Windows::Forms::Label());
			this->lblBet = (gcnew System::Windows::Forms::Label());
			this->txtBet = (gcnew System::Windows::Forms::TextBox());
			this->btnBet = (gcnew System::Windows::Forms::Button());
			this->txtPlayersHand = (gcnew System::Windows::Forms::TextBox());
			this->lblPlayersHand = (gcnew System::Windows::Forms::Label());
			this->lblDealersHand = (gcnew System::Windows::Forms::Label());
			this->txtDealersHand = (gcnew System::Windows::Forms::TextBox());
			this->txtGameStatus = (gcnew System::Windows::Forms::TextBox());
			this->lblGameStatus = (gcnew System::Windows::Forms::Label());
			this->btnPlayAgain = (gcnew System::Windows::Forms::Button());
			this->lblHitOrStay = (gcnew System::Windows::Forms::Label());
			this->btnHit = (gcnew System::Windows::Forms::Button());
			this->btnStay = (gcnew System::Windows::Forms::Button());
			this->msRules->SuspendLayout();
			this->SuspendLayout();
			// 
			// msRules
			// 
			this->msRules->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->msRules->ImageScalingSize = System::Drawing::Size(22, 22);
			this->msRules->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->msAboutProgram, this->msFileRules });
			this->msRules->Location = System::Drawing::Point(0, 0);
			this->msRules->Name = L"msRules";
			this->msRules->Padding = System::Windows::Forms::Padding(12, 3, 0, 3);
			this->msRules->Size = System::Drawing::Size(1033, 33);
			this->msRules->TabIndex = 1;
			this->msRules->Text = L"menuStrip1";
			// 
			// msAboutProgram
			// 
			this->msAboutProgram->Name = L"msAboutProgram";
			this->msAboutProgram->Size = System::Drawing::Size(179, 27);
			this->msAboutProgram->Text = L"About This Program";
			this->msAboutProgram->Click += gcnew System::EventHandler(this, &MyForm::msAboutProgram_Click);
			// 
			// msFileRules
			// 
			this->msFileRules->Name = L"msFileRules";
			this->msFileRules->Size = System::Drawing::Size(166, 27);
			this->msFileRules->Text = L"Rules of the Game";
			this->msFileRules->ToolTipText = L"Click to see the game rules.";
			this->msFileRules->Click += gcnew System::EventHandler(this, &MyForm::msFileRules_Click);
			// 
			// lblWelcome
			// 
			this->lblWelcome->AutoSize = true;
			this->lblWelcome->BackColor = System::Drawing::Color::Transparent;
			this->lblWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblWelcome->ForeColor = System::Drawing::Color::White;
			this->lblWelcome->Location = System::Drawing::Point(93, 72);
			this->lblWelcome->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lblWelcome->Name = L"lblWelcome";
			this->lblWelcome->Size = System::Drawing::Size(847, 120);
			this->lblWelcome->TabIndex = 2;
			this->lblWelcome->Text = L"Welcome to the C++ BlackJack Table!\r\nYou will begin with $1,000 for your gambling"
				L" pleasure.\r\nYou may view the rules by clicking on \"Rules of the Game\".";
			this->lblWelcome->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lblBet
			// 
			this->lblBet->AutoSize = true;
			this->lblBet->BackColor = System::Drawing::Color::Transparent;
			this->lblBet->Font = (gcnew System::Drawing::Font(L"Noto Serif", 13.97015F, System::Drawing::FontStyle::Bold));
			this->lblBet->ForeColor = System::Drawing::Color::White;
			this->lblBet->Location = System::Drawing::Point(94, 238);
			this->lblBet->Name = L"lblBet";
			this->lblBet->Size = System::Drawing::Size(293, 37);
			this->lblBet->TabIndex = 3;
			this->lblBet->Text = L"Enter your bet here:";
			// 
			// txtBet
			// 
			this->txtBet->Location = System::Drawing::Point(401, 242);
			this->txtBet->Name = L"txtBet";
			this->txtBet->Size = System::Drawing::Size(353, 36);
			this->txtBet->TabIndex = 4;
			// 
			// btnBet
			// 
			this->btnBet->BackColor = System::Drawing::Color::ForestGreen;
			this->btnBet->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBet->ForeColor = System::Drawing::Color::White;
			this->btnBet->Location = System::Drawing::Point(821, 230);
			this->btnBet->Name = L"btnBet";
			this->btnBet->Size = System::Drawing::Size(119, 58);
			this->btnBet->TabIndex = 5;
			this->btnBet->Text = L"BET";
			this->btnBet->UseVisualStyleBackColor = false;
			// 
			// txtPlayersHand
			// 
			this->txtPlayersHand->BackColor = System::Drawing::Color::White;
			this->txtPlayersHand->Location = System::Drawing::Point(100, 327);
			this->txtPlayersHand->Multiline = true;
			this->txtPlayersHand->Name = L"txtPlayersHand";
			this->txtPlayersHand->ReadOnly = true;
			this->txtPlayersHand->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtPlayersHand->Size = System::Drawing::Size(358, 163);
			this->txtPlayersHand->TabIndex = 6;
			// 
			// lblPlayersHand
			// 
			this->lblPlayersHand->AutoSize = true;
			this->lblPlayersHand->BackColor = System::Drawing::Color::Transparent;
			this->lblPlayersHand->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPlayersHand->ForeColor = System::Drawing::Color::White;
			this->lblPlayersHand->Location = System::Drawing::Point(93, 284);
			this->lblPlayersHand->Name = L"lblPlayersHand";
			this->lblPlayersHand->Size = System::Drawing::Size(218, 40);
			this->lblPlayersHand->TabIndex = 7;
			this->lblPlayersHand->Text = L"Player\'s Hand:";
			// 
			// lblDealersHand
			// 
			this->lblDealersHand->AutoSize = true;
			this->lblDealersHand->BackColor = System::Drawing::Color::Transparent;
			this->lblDealersHand->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDealersHand->ForeColor = System::Drawing::Color::White;
			this->lblDealersHand->Location = System::Drawing::Point(94, 508);
			this->lblDealersHand->Name = L"lblDealersHand";
			this->lblDealersHand->Size = System::Drawing::Size(222, 40);
			this->lblDealersHand->TabIndex = 8;
			this->lblDealersHand->Text = L"Dealer\'s Hand:";
			// 
			// txtDealersHand
			// 
			this->txtDealersHand->BackColor = System::Drawing::Color::White;
			this->txtDealersHand->Location = System::Drawing::Point(100, 551);
			this->txtDealersHand->Multiline = true;
			this->txtDealersHand->Name = L"txtDealersHand";
			this->txtDealersHand->ReadOnly = true;
			this->txtDealersHand->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtDealersHand->Size = System::Drawing::Size(358, 183);
			this->txtDealersHand->TabIndex = 9;
			// 
			// txtGameStatus
			// 
			this->txtGameStatus->BackColor = System::Drawing::Color::White;
			this->txtGameStatus->Location = System::Drawing::Point(582, 551);
			this->txtGameStatus->Multiline = true;
			this->txtGameStatus->Name = L"txtGameStatus";
			this->txtGameStatus->ReadOnly = true;
			this->txtGameStatus->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtGameStatus->Size = System::Drawing::Size(358, 183);
			this->txtGameStatus->TabIndex = 10;
			// 
			// lblGameStatus
			// 
			this->lblGameStatus->AutoSize = true;
			this->lblGameStatus->BackColor = System::Drawing::Color::Transparent;
			this->lblGameStatus->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblGameStatus->ForeColor = System::Drawing::Color::White;
			this->lblGameStatus->Location = System::Drawing::Point(575, 508);
			this->lblGameStatus->Name = L"lblGameStatus";
			this->lblGameStatus->Size = System::Drawing::Size(201, 40);
			this->lblGameStatus->TabIndex = 11;
			this->lblGameStatus->Text = L"Game Status:";
			// 
			// btnPlayAgain
			// 
			this->btnPlayAgain->BackColor = System::Drawing::Color::ForestGreen;
			this->btnPlayAgain->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPlayAgain->ForeColor = System::Drawing::Color::White;
			this->btnPlayAgain->Location = System::Drawing::Point(582, 437);
			this->btnPlayAgain->Name = L"btnPlayAgain";
			this->btnPlayAgain->Size = System::Drawing::Size(358, 53);
			this->btnPlayAgain->TabIndex = 12;
			this->btnPlayAgain->Text = L"PLAY AGAIN";
			this->btnPlayAgain->UseVisualStyleBackColor = false;
			// 
			// lblHitOrStay
			// 
			this->lblHitOrStay->AutoSize = true;
			this->lblHitOrStay->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 13.97015F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHitOrStay->ForeColor = System::Drawing::Color::White;
			this->lblHitOrStay->Location = System::Drawing::Point(576, 314);
			this->lblHitOrStay->Name = L"lblHitOrStay";
			this->lblHitOrStay->Size = System::Drawing::Size(165, 35);
			this->lblHitOrStay->TabIndex = 13;
			this->lblHitOrStay->Text = L"Hit or Stay\?";
			// 
			// btnHit
			// 
			this->btnHit->BackColor = System::Drawing::Color::ForestGreen;
			this->btnHit->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHit->ForeColor = System::Drawing::Color::White;
			this->btnHit->Location = System::Drawing::Point(582, 360);
			this->btnHit->Name = L"btnHit";
			this->btnHit->Size = System::Drawing::Size(172, 53);
			this->btnHit->TabIndex = 14;
			this->btnHit->Text = L"Hit";
			this->btnHit->UseVisualStyleBackColor = false;
			// 
			// btnStay
			// 
			this->btnStay->BackColor = System::Drawing::Color::ForestGreen;
			this->btnStay->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 16.1194F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnStay->ForeColor = System::Drawing::Color::White;
			this->btnStay->Location = System::Drawing::Point(768, 360);
			this->btnStay->Name = L"btnStay";
			this->btnStay->Size = System::Drawing::Size(172, 53);
			this->btnStay->TabIndex = 15;
			this->btnStay->Text = L"Stay";
			this->btnStay->UseVisualStyleBackColor = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(134, 134);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::OliveDrab;
			this->ClientSize = System::Drawing::Size(1033, 757);
			this->Controls->Add(this->btnStay);
			this->Controls->Add(this->btnHit);
			this->Controls->Add(this->lblHitOrStay);
			this->Controls->Add(this->btnPlayAgain);
			this->Controls->Add(this->lblGameStatus);
			this->Controls->Add(this->txtGameStatus);
			this->Controls->Add(this->txtDealersHand);
			this->Controls->Add(this->lblDealersHand);
			this->Controls->Add(this->lblPlayersHand);
			this->Controls->Add(this->txtPlayersHand);
			this->Controls->Add(this->btnBet);
			this->Controls->Add(this->txtBet);
			this->Controls->Add(this->lblBet);
			this->Controls->Add(this->lblWelcome);
			this->Controls->Add(this->msRules);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft New Tai Lue", 11.8209F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->msRules;
			this->Margin = System::Windows::Forms::Padding(6, 7, 6, 7);
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
	private: System::Void msAboutProgram_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ about = "C++ BlackJack Table";
		about += "\r\n\nProgrammers: Sean King, Mirinisa Stewart-Tengco, and Donald Diienno";
		about += "\r\nCourse: CIS 2275-R01: C++ 2 Fall 2020";
		about += "\r\nProject: Program 6, Blackjack";
		about += "\r\n\nThis program is a game of Black Jack written in C++ with Windows CLI Forms.";

		MessageBox::Show(about);
	}
};
}
