#pragma once
#include <cstddef>
#include <type_traits>
#include <iostream>
//comment out if merge
#include "simulator.h"
#include "UserProgram.h"
#include "output.h"
#include <msclr\marshal_cppstd.h>

//comemnt out if merge
extern Simulator simulator;
extern UserProgram userProgram;

using namespace std;

namespace UVSimForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for main_form
	/// </summary>
	public ref class main_form : public System::Windows::Forms::Form
	{
	public:
		main_form(void)
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
		~main_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Button^ edit_button;
	private: System::Windows::Forms::ListBox^ listBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ run_button;
	private: System::Windows::Forms::Button^ delete_button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ location_txt;
	private: System::Windows::Forms::RichTextBox^ instruction_txt;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ sign_txt;
	private: System::Windows::Forms::ContextMenuStrip^ menu_strip;
	private: System::Windows::Forms::ToolStripMenuItem^ close;
	private: System::Windows::Forms::Button^ reset_button;
	private: System::Windows::Forms::RichTextBox^ error_txt;
	private: System::Windows::Forms::GroupBox^ error_box;

	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(main_form::typeid));
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->edit_button = (gcnew System::Windows::Forms::Button());
			this->listBox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->run_button = (gcnew System::Windows::Forms::Button());
			this->delete_button = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->location_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->instruction_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->sign_txt = (gcnew System::Windows::Forms::ComboBox());
			this->menu_strip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->close = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reset_button = (gcnew System::Windows::Forms::Button());
			this->error_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->error_box = (gcnew System::Windows::Forms::GroupBox());
			this->menu_strip->SuspendLayout();
			this->error_box->SuspendLayout();
			this->SuspendLayout();
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(208, 177);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(151, 28);
			this->add_button->TabIndex = 3;
			this->add_button->Text = L"Add Instruction";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &main_form::add_button_Click);
			// 
			// edit_button
			// 
			this->edit_button->Enabled = false;
			this->edit_button->Location = System::Drawing::Point(208, 211);
			this->edit_button->Name = L"edit_button";
			this->edit_button->Size = System::Drawing::Size(151, 28);
			this->edit_button->TabIndex = 4;
			this->edit_button->Text = L"Save Edits";
			this->edit_button->UseVisualStyleBackColor = true;
			this->edit_button->Click += gcnew System::EventHandler(this, &main_form::edit_button_Click);
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->ItemHeight = 16;
			this->listBox->Location = System::Drawing::Point(21, 84);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(179, 244);
			this->listBox->TabIndex = 8;
			this->listBox->SelectedIndexChanged += gcnew System::EventHandler(this, &main_form::listBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(480, 68);
			this->label1->TabIndex = 3;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// run_button
			// 
			this->run_button->Location = System::Drawing::Point(21, 334);
			this->run_button->Name = L"run_button";
			this->run_button->Size = System::Drawing::Size(75, 30);
			this->run_button->TabIndex = 6;
			this->run_button->Text = L"Run";
			this->run_button->UseVisualStyleBackColor = true;
			this->run_button->Click += gcnew System::EventHandler(this, &main_form::run_button_Click);
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(208, 245);
			this->delete_button->Name = L"delete_button";
			this->delete_button->Size = System::Drawing::Size(151, 28);
			this->delete_button->TabIndex = 5;
			this->delete_button->Text = L"Delete Instruction";
			this->delete_button->UseVisualStyleBackColor = true;
			this->delete_button->Click += gcnew System::EventHandler(this, &main_form::delete_button_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(205, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Location";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(205, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Instruction";
			// 
			// location_txt
			// 
			this->location_txt->Location = System::Drawing::Point(284, 143);
			this->location_txt->Name = L"location_txt";
			this->location_txt->Size = System::Drawing::Size(75, 23);
			this->location_txt->TabIndex = 2;
			this->location_txt->Text = L"";
			this->location_txt->TextChanged += gcnew System::EventHandler(this, &main_form::location_txt_Click);
			// 
			// instruction_txt
			// 
			this->instruction_txt->Location = System::Drawing::Point(284, 114);
			this->instruction_txt->Name = L"instruction_txt";
			this->instruction_txt->Size = System::Drawing::Size(75, 23);
			this->instruction_txt->TabIndex = 1;
			this->instruction_txt->Text = L"";
			this->instruction_txt->TextChanged += gcnew System::EventHandler(this, &main_form::instruction_txt_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(205, 84);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Sign";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(102, 334);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 30);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Upload File";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// sign_txt
			// 
			this->sign_txt->AllowDrop = true;
			this->sign_txt->FormattingEnabled = true;
			this->sign_txt->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->sign_txt->Location = System::Drawing::Point(284, 84);
			this->sign_txt->MaxDropDownItems = 2;
			this->sign_txt->Name = L"sign_txt";
			this->sign_txt->Size = System::Drawing::Size(75, 24);
			this->sign_txt->TabIndex = 0;
			this->sign_txt->Text = L"+";
			this->sign_txt->SelectedIndexChanged += gcnew System::EventHandler(this, &main_form::sign_txt_SelectedIndexChanged);
			// 
			// menu_strip
			// 
			this->menu_strip->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu_strip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->close });
			this->menu_strip->Name = L"contextMenuStrip1";
			this->menu_strip->Size = System::Drawing::Size(184, 28);
			// 
			// close
			// 
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(183, 24);
			this->close->Text = L"Exit Application";
			this->close->Click += gcnew System::EventHandler(this, &main_form::menu_strip_Click);
			// 
			// reset_button
			// 
			this->reset_button->Location = System::Drawing::Point(21, 370);
			this->reset_button->Name = L"reset_button";
			this->reset_button->Size = System::Drawing::Size(179, 28);
			this->reset_button->TabIndex = 8;
			this->reset_button->Text = L"Reset Program";
			this->reset_button->UseVisualStyleBackColor = true;
			this->reset_button->Click += gcnew System::EventHandler(this, &main_form::reset_button_Click);
			// 
			// error_txt
			// 
			this->error_txt->Location = System::Drawing::Point(6, 21);
			this->error_txt->Name = L"error_txt";
			this->error_txt->Size = System::Drawing::Size(188, 67);
			this->error_txt->TabIndex = 13;
			this->error_txt->Text = L"";
			// 
			// error_box
			// 
			this->error_box->Controls->Add(this->error_txt);
			this->error_box->Location = System::Drawing::Point(206, 288);
			this->error_box->Name = L"error_box";
			this->error_box->Size = System::Drawing::Size(200, 100);
			this->error_box->TabIndex = 14;
			this->error_box->TabStop = false;
			this->error_box->Text = L"Error Message";
			this->error_box->Visible = false;
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(806, 424);
			this->ContextMenuStrip = this->menu_strip;
			this->Controls->Add(this->error_box);
			this->Controls->Add(this->reset_button);
			this->Controls->Add(this->sign_txt);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->instruction_txt);
			this->Controls->Add(this->location_txt);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->delete_button);
			this->Controls->Add(this->run_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox);
			this->Controls->Add(this->edit_button);
			this->Controls->Add(this->add_button);
			this->Name = L"main_form";
			this->Text = L"UVSim";
			this->Load += gcnew System::EventHandler(this, &main_form::main_form_Click);
			this->menu_strip->ResumeLayout(false);
			this->error_box->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//function that clears the textboxes
		private: void clearText() {
			sign_txt->Text = "";
			instruction_txt->Text = "";
			location_txt->Text = "";
		}

		//method that will display the error message
		public: void showError(String^ message)
		{
			error_txt->Text = message;
			error_box->Visible = true;
			return;
		}
		
		//method that validates the program
	private: string validate() {
		String^ message = "peepeepoopoo";

		if (sign_txt->Text->Length == 0) {
			message = "All fields must have input";
			showError(message);
		}

		if (instruction_txt->Text->Length == 0) {
			message = "All fields must have input";
			showError(message);
		}

		if (location_txt->Text->Length == 0) {
			message = "All fields must have input";
			showError(message);
		}

		//message = hoursWorkedText.Text + " is not a number";

		System::String^ managedString = message;
		msclr::interop::marshal_context context;
		std::string message_basic = context.marshal_as<std::string>(managedString);

		return message_basic;
	}

/*
	//Kristen
	private: void executeProgram() {
		//Fill vector with emtpy data to fill table.
		for (size_t i = this->memory.size(); i < SIZE_OF_MEMORY; i++) {
			this->memory.push_back("00000");
		}
		while (true) {
			this->InstructionRegister = this->memory.at(this->InstructionCounter);

			bool goOn = this->executeInstruction();
			this->InstructionCounter++;
			if (!goOn)
				return;
		}
	}

	//Dallin
	private: void loadCommandIntoMemory(std::string command) {
		if (this->memory.size() == SIZE_OF_MEMORY) {
			throw std::runtime_error("Memory overflow");
		}
		if (command.size() != 5) {
			throw std::runtime_error("Command must be a signed four-digit decimal number (+1234 or -5678)");
		}
		char sign = command[0];
		std::string com = command.substr(1, 5);
		for (char x : com) {
			if (!isdigit(x)) {
				throw std::runtime_error("Command must be a signed four-digit decimal number (+1234 or -5678)");
			}
		}
		switch (sign) {
		case '-':
			if (com == "9999")
				return;
			this->memory.push_back("1" + com);
			break;
		case '+':
			this->memory.push_back("0" + com);
			break;
		default:
			throw std::runtime_error("Command must be a signed four-digit decimal number (+1234 or -5678)");
		}
	}
	*/
			 

#pragma endregion
	//add button
	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
		validate();

		String^ instruction = instruction_txt->Text;
		String^ location = location_txt->Text;
		String^ sign = sign_txt->Text;
		listBox->Items->Add(sign + instruction + location);
		clearText();
	}

	//edit button
	private: System::Void edit_button_Click(System::Object^ sender, System::EventArgs^ e) {	
		int index = listBox->SelectedIndex;

		String^ instruction = instruction_txt->Text;
		String^ location = location_txt->Text;
		String^ sign = sign_txt->Text;

		listBox->Items->RemoveAt(index);
		listBox->Items->Insert(index, (sign + instruction + location));

		clearText();
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}

	private: System::Void run_button_Click(System::Object^ sender, System::EventArgs^ e) {
		UVSimForm::output output;
		output.ShowDialog();
		this->Show();

		int count = listBox->Items->Count;
		vector<string> instructions;

		for (int i = 0; i < count; i++) {
			Object ^itemObj = listBox->Items[i];
			String ^item = itemObj->ToString();
			string unmanaged = msclr::interop::marshal_as<string>(item);
			instructions.push_back(unmanaged);
		}		
		userProgram.loadProgram(&simulator, instructions);
		simulator.executeProgram();
	}

	//public: System::Void getInput() {
		   //
	//}

	private: System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBox->Items->Count > 0)
			listBox->Items->RemoveAt(listBox->SelectedIndex);
		else {

		}
		clearText();
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}

	private: System::Void listBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = true;
		add_button->Enabled = false;

		int index = listBox->SelectedIndex;
		//string value = to_string(listBox->Items);

		if (index != NULL) {
			//String^ value = index->ToString();
			//sign_txt->Text = value;
		}
	}

	private: System::Void reset_button_Click(System::Object^ sender, System::EventArgs^ e) {
		clearText();
		listBox->Items->Clear();
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}

	private: System::Void menu_strip_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void main_form_Click(System::Object^ sender, System::EventArgs^ e) {
		clearText();
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}
	private: System::Void sign_txt_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}
	private: System::Void instruction_txt_Click(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}
	private: System::Void location_txt_Click(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = false;
		add_button->Enabled = true;
	}
};
}
