/* Group 3:
 *   Donald Dilenno
 *   Christopher (Sean) King
 *   Mirinisa Stewart-Tengco mstewarttengco@cnm.edu
 * CIS 2275-R01: C++ 2 Fall 2020
 * Project: Program 6, Blackjack
 * 
 * File: MyForm.h
 * Last modified: 3 Nov 2020
*/


#pragma once

#include "Hand.h"

namespace DilennoKingStewartTengcoP6 {

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
	private: System::Windows::Forms::TextBox^ tbTest;
	private: System::Windows::Forms::MenuStrip^ msRules;
	private: System::Windows::Forms::ToolStripMenuItem^ msDropDownFile;
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
			this->tbTest = (gcnew System::Windows::Forms::TextBox());
			this->msRules = (gcnew System::Windows::Forms::MenuStrip());
			this->msDropDownFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msFileRules = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->msRules->SuspendLayout();
			this->SuspendLayout();
			// 
			// tbTest
			// 
			this->tbTest->Location = System::Drawing::Point(12, 27);
			this->tbTest->Multiline = true;
			this->tbTest->Name = L"tbTest";
			this->tbTest->Size = System::Drawing::Size(260, 222);
			this->tbTest->TabIndex = 0;
			// 
			// msRules
			// 
			this->msRules->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->msDropDownFile });
			this->msRules->Location = System::Drawing::Point(0, 0);
			this->msRules->Name = L"msRules";
			this->msRules->Size = System::Drawing::Size(284, 24);
			this->msRules->TabIndex = 1;
			this->msRules->Text = L"menuStrip1";
			// 
			// msDropDownFile
			// 
			this->msDropDownFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->msFileRules });
			this->msDropDownFile->Name = L"msDropDownFile";
			this->msDropDownFile->Size = System::Drawing::Size(37, 20);
			this->msDropDownFile->Text = L"File";
			// 
			// msFileRules
			// 
			this->msFileRules->Name = L"msFileRules";
			this->msFileRules->Size = System::Drawing::Size(180, 22);
			this->msFileRules->Text = L"Rules of the Game";
			this->msFileRules->ToolTipText = L"Click to see the game rules.";
			this->msFileRules->Click += gcnew System::EventHandler(this, &MyForm::msFileRules_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->tbTest);
			this->Controls->Add(this->msRules);
			this->MainMenuStrip = this->msRules;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dilenno, King, Stewart-Tengco Project 6: Blackjack";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->msRules->ResumeLayout(false);
			this->msRules->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		
		/* Testing */
		Hand hand;
		hand.AddCard(0);
		hand.AddCard(2);
		hand.AddCard(3);

		tbTest->Text = gcnew String(hand.Show(false, false).c_str());
	}
	private: System::Void msFileRules_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ rules = "Rules of the game:\r\nStart with 2 cards. Each card value is the face number value for 2-9; Jack-King are 10 points each; Aces can be 1 or 11 depending on what works better.";
		MessageBox::Show(rules);
	}
};
}
