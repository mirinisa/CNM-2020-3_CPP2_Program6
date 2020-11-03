#pragma once

#include "Hand.h"

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
	private: System::Windows::Forms::TextBox^ tbTest;
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
			this->SuspendLayout();
			// 
			// tbTest
			// 
			this->tbTest->Location = System::Drawing::Point(12, 12);
			this->tbTest->Multiline = true;
			this->tbTest->Name = L"tbTest";
			this->tbTest->Size = System::Drawing::Size(260, 237);
			this->tbTest->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->tbTest);
			this->Name = L"MyForm";
			this->Text = L"Diienno, King, Stewart-Tengco Project 6: Blackjack";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
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
	};
}
