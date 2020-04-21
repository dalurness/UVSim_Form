#pragma once
#include <cstddef>
#include <type_traits>
#include <iostream>
#include "simulator.h"
#include "UserProgram.h"
#include <msclr\marshal_cppstd.h>
#include <string.h>
#include <iomanip>
#include <sstream>
#include <fstream>

//comemnt out if merge
extern Simulator simulator;
extern UserProgram userProgram;

using namespace std;

namespace UVSimForm {
	using namespace System::Reflection;
	using namespace System::IO;
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
	//private: int numberedLineCount = 1;
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Button^ edit_button;
	public: System::Windows::Forms::ListBox^ listBox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ run_button;
	private: System::Windows::Forms::Button^ delete_button;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RichTextBox^ location_txt;
	private: System::Windows::Forms::RichTextBox^ instruction_txt;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ upload_btn;

	private: System::Windows::Forms::ComboBox^ sign_txt;
	private: System::Windows::Forms::ContextMenuStrip^ menu_strip;
	private: System::Windows::Forms::ToolStripMenuItem^ close;
	private: System::Windows::Forms::Button^ reset_button;
	private: System::Windows::Forms::RichTextBox^ error_txt;
	private: System::Windows::Forms::GroupBox^ error_box;
	public: System::Windows::Forms::RichTextBox^ output_txt;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ input_txt;
	private: System::Windows::Forms::Button^ submit_btn;
	private: System::Windows::Forms::Button^ unselect_btn;
	private: System::Windows::Forms::GroupBox^ input_groupbox;
	private: System::Windows::Forms::Button^ break_btn;
	private: System::Windows::Forms::GroupBox^ break_groupbox;
	private: System::Windows::Forms::TextBox^ break_txt;
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
			this->upload_btn = (gcnew System::Windows::Forms::Button());
			this->sign_txt = (gcnew System::Windows::Forms::ComboBox());
			this->menu_strip = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->close = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reset_button = (gcnew System::Windows::Forms::Button());
			this->error_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->error_box = (gcnew System::Windows::Forms::GroupBox());
			this->output_txt = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->input_txt = (gcnew System::Windows::Forms::TextBox());
			this->submit_btn = (gcnew System::Windows::Forms::Button());
			this->unselect_btn = (gcnew System::Windows::Forms::Button());
			this->input_groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->break_btn = (gcnew System::Windows::Forms::Button());
			this->break_groupbox = (gcnew System::Windows::Forms::GroupBox());
			this->break_txt = (gcnew System::Windows::Forms::TextBox());
			this->menu_strip->SuspendLayout();
			this->error_box->SuspendLayout();
			this->input_groupbox->SuspendLayout();
			this->break_groupbox->SuspendLayout();
			this->SuspendLayout();
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(200, 203);
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
			this->edit_button->Location = System::Drawing::Point(198, 271);
			this->edit_button->Name = L"edit_button";
			this->edit_button->Size = System::Drawing::Size(153, 28);
			this->edit_button->TabIndex = 4;
			this->edit_button->Text = L"Save Edits";
			this->edit_button->UseVisualStyleBackColor = true;
			this->edit_button->Click += gcnew System::EventHandler(this, &main_form::edit_button_Click);
			// 
			// listBox
			// 
			this->listBox->FormattingEnabled = true;
			this->listBox->ItemHeight = 16;
			this->listBox->Location = System::Drawing::Point(13, 115);
			this->listBox->Name = L"listBox";
			this->listBox->Size = System::Drawing::Size(179, 244);
			this->listBox->TabIndex = 8;
			this->listBox->SelectedIndexChanged += gcnew System::EventHandler(this, &main_form::listBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(338, 85);
			this->label1->TabIndex = 3;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// run_button
			// 
			this->run_button->Location = System::Drawing::Point(13, 365);
			this->run_button->Name = L"run_button";
			this->run_button->Size = System::Drawing::Size(75, 30);
			this->run_button->TabIndex = 6;
			this->run_button->Text = L"Run";
			this->run_button->UseVisualStyleBackColor = true;
			this->run_button->Click += gcnew System::EventHandler(this, &main_form::run_button_Click);
			// 
			// delete_button
			// 
			this->delete_button->Location = System::Drawing::Point(200, 237);
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
			this->label2->Location = System::Drawing::Point(197, 174);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Location";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(197, 145);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Instruction";
			// 
			// location_txt
			// 
			this->location_txt->Location = System::Drawing::Point(276, 174);
			this->location_txt->Name = L"location_txt";
			this->location_txt->Size = System::Drawing::Size(75, 23);
			this->location_txt->TabIndex = 2;
			this->location_txt->Text = L"";
			// 
			// instruction_txt
			// 
			this->instruction_txt->Location = System::Drawing::Point(276, 145);
			this->instruction_txt->Name = L"instruction_txt";
			this->instruction_txt->Size = System::Drawing::Size(75, 23);
			this->instruction_txt->TabIndex = 1;
			this->instruction_txt->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(197, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Sign";
			// 
			// upload_btn
			// 
			this->upload_btn->Location = System::Drawing::Point(94, 365);
			this->upload_btn->Name = L"upload_btn";
			this->upload_btn->Size = System::Drawing::Size(98, 30);
			this->upload_btn->TabIndex = 7;
			this->upload_btn->Text = L"Upload File";
			this->upload_btn->UseVisualStyleBackColor = true;
			this->upload_btn->Click += gcnew System::EventHandler(this, &main_form::upload_btn_Click);
			// 
			// sign_txt
			// 
			this->sign_txt->FormattingEnabled = true;
			this->sign_txt->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"+", L"-" });
			this->sign_txt->Location = System::Drawing::Point(276, 112);
			this->sign_txt->MaxDropDownItems = 2;
			this->sign_txt->Name = L"sign_txt";
			this->sign_txt->Size = System::Drawing::Size(75, 24);
			this->sign_txt->TabIndex = 0;
			this->sign_txt->Text = L"+";
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
			this->reset_button->Location = System::Drawing::Point(13, 401);
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
			this->error_txt->Size = System::Drawing::Size(145, 69);
			this->error_txt->TabIndex = 13;
			this->error_txt->Text = L"";
			// 
			// error_box
			// 
			this->error_box->Controls->Add(this->error_txt);
			this->error_box->Location = System::Drawing::Point(200, 339);
			this->error_box->Name = L"error_box";
			this->error_box->Size = System::Drawing::Size(151, 90);
			this->error_box->TabIndex = 14;
			this->error_box->TabStop = false;
			this->error_box->Text = L"Error Message";
			this->error_box->Visible = false;
			// 
			// output_txt
			// 
			this->output_txt->Location = System::Drawing::Point(399, 63);
			this->output_txt->Name = L"output_txt";
			this->output_txt->Size = System::Drawing::Size(638, 334);
			this->output_txt->TabIndex = 16;
			this->output_txt->Text = L"";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(396, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 17);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Program Output";
			// 
			// input_txt
			// 
			this->input_txt->Location = System::Drawing::Point(6, 4);
			this->input_txt->Name = L"input_txt";
			this->input_txt->Size = System::Drawing::Size(100, 22);
			this->input_txt->TabIndex = 18;
			// 
			// submit_btn
			// 
			this->submit_btn->Location = System::Drawing::Point(119, 4);
			this->submit_btn->Name = L"submit_btn";
			this->submit_btn->Size = System::Drawing::Size(75, 23);
			this->submit_btn->TabIndex = 19;
			this->submit_btn->Text = L"Submit";
			this->submit_btn->UseVisualStyleBackColor = true;
			this->submit_btn->Click += gcnew System::EventHandler(this, &main_form::submit_btn_Click);
			// 
			// unselect_btn
			// 
			this->unselect_btn->Enabled = false;
			this->unselect_btn->Location = System::Drawing::Point(198, 305);
			this->unselect_btn->Name = L"unselect_btn";
			this->unselect_btn->Size = System::Drawing::Size(153, 28);
			this->unselect_btn->TabIndex = 21;
			this->unselect_btn->Text = L"Unselect Instruction";
			this->unselect_btn->UseVisualStyleBackColor = true;
			this->unselect_btn->Click += gcnew System::EventHandler(this, &main_form::unselect_btn_Click);
			// 
			// input_groupbox
			// 
			this->input_groupbox->Controls->Add(this->input_txt);
			this->input_groupbox->Controls->Add(this->submit_btn);
			this->input_groupbox->Location = System::Drawing::Point(399, 401);
			this->input_groupbox->Name = L"input_groupbox";
			this->input_groupbox->Size = System::Drawing::Size(200, 26);
			this->input_groupbox->TabIndex = 22;
			this->input_groupbox->TabStop = false;
			this->input_groupbox->Visible = false;
			// 
			// break_btn
			// 
			this->break_btn->Location = System::Drawing::Point(113, 10);
			this->break_btn->Name = L"break_btn";
			this->break_btn->Size = System::Drawing::Size(76, 23);
			this->break_btn->TabIndex = 23;
			this->break_btn->Text = L"Submit";
			this->break_btn->UseVisualStyleBackColor = true;
			this->break_btn->Click += gcnew System::EventHandler(this, &main_form::break_btn_Click);
			// 
			// break_groupbox
			// 
			this->break_groupbox->Controls->Add(this->break_txt);
			this->break_groupbox->Controls->Add(this->break_btn);
			this->break_groupbox->Location = System::Drawing::Point(405, 433);
			this->break_groupbox->Name = L"break_groupbox";
			this->break_groupbox->Size = System::Drawing::Size(200, 32);
			this->break_groupbox->TabIndex = 24;
			this->break_groupbox->TabStop = false;
			this->break_groupbox->Visible = false;
			// 
			// break_txt
			// 
			this->break_txt->Location = System::Drawing::Point(0, 10);
			this->break_txt->Name = L"break_txt";
			this->break_txt->Size = System::Drawing::Size(100, 22);
			this->break_txt->TabIndex = 24;
			// 
			// main_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1047, 482);
			this->ContextMenuStrip = this->menu_strip;
			this->Controls->Add(this->break_groupbox);
			this->Controls->Add(this->input_groupbox);
			this->Controls->Add(this->unselect_btn);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->output_txt);
			this->Controls->Add(this->error_box);
			this->Controls->Add(this->reset_button);
			this->Controls->Add(this->sign_txt);
			this->Controls->Add(this->upload_btn);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"main_form";
			this->Text = L"UVSim";
			this->menu_strip->ResumeLayout(false);
			this->error_box->ResumeLayout(false);
			this->input_groupbox->ResumeLayout(false);
			this->input_groupbox->PerformLayout();
			this->break_groupbox->ResumeLayout(false);
			this->break_groupbox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//function that clears the textboxes
		private: void clearText() {
			sign_txt->Text = "";
			instruction_txt->Text = "";
			location_txt->Text = "";
		}

		private: void resetProgram() {
			clearText();
			listBox->ClearSelected();
			add_button->Enabled = true;
			run_button->Enabled = true;
			upload_btn->Enabled = true;
			delete_button->Enabled = true;
			edit_button->Enabled = false;
			error_box->Visible = false;
			unselect_btn->Enabled = false;
		}

		//method that will display the error message
		public: void showError(String^ message)
		{
			if (message != "") {
				error_txt->Text = message;
				error_box->Visible = true;
				return;
			}
			error_box->Visible = false;
		}

		private: bool checkNumber(String^ str) {
			System::String^ managedString = str;
			msclr::interop::marshal_context context;
			std::string constr = context.marshal_as<std::string>(managedString);
			for (int i = 0; i < constr.length(); i++)
				if (isdigit(str[i]) == false)
					return false;
			return true;
		}

		private: bool is_number(const string& s) {
			std::string::const_iterator it = s.begin();
			while (it != s.end() && std::isdigit(*it)) ++it;
			return !s.empty() && it == s.end();
		}


		//method that validates the program
		private: string validate() {
			String^ message = "";

			if (instruction_txt->Text->Length != 2) {
				message = "Instruction input must be two digits";
				showError(message);
			}

			if (location_txt->Text->Length < 2 || location_txt->Text->Length > 2) {
				message = "Location input must be two digits";
				showError(message);
			}

			if (input_txt->Text->Length < 4 || location_txt->Text->Length > 4) {
				message = "Input must be four digits";
				showError(message);
			}

			if (input_txt->Text->Length < 4 || location_txt->Text->Length > 4) {
				message = "Input must be four digits";
				showError(message);
			}

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

			if (input_txt->Text->Length == 0) {
				message = "All fields must have input";
				showError(message);
			}

			if (break_txt->Text->Length == 0) {
				message = "All fields must have input";
				showError(message);
			}

			if (sign_txt->Text != "+" && sign_txt->Text != "-") {
				message = "The sign must be + or -";
				showError(message);
			}

			if (checkNumber(instruction_txt->Text) == false) {
				message = instruction_txt->Text + " is not a number";
				showError(message);
			}

			if (checkNumber(location_txt->Text) == false) {
				message = location_txt->Text + " is not a number";
				showError(message);
			}

			System::String^ managedString = message;
			msclr::interop::marshal_context context;
			std::string message_basic = context.marshal_as<std::string>(managedString);

			return message_basic;
		}

#pragma endregion
	int nextInstruction = 0;

	//add button
	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
		string message = validate();
		if (message != "")
		{
			return;
		}

		//String^ lineNumber = System::Convert::ToString(numberedLineCount) + ": ";
		String^ instruction = instruction_txt->Text;
		String^ location = location_txt->Text;
		String^ sign = sign_txt->Text;
		listBox->Items->Add(/*lineNumber +*/ sign + instruction + location);
		resetProgram();
		//numberedLineCount++;
	}

	//edit button
	private: System::Void edit_button_Click(System::Object^ sender, System::EventArgs^ e) {	
		string message = validate();
		if (message != "")
		{
			return;
		}

		int index = listBox->SelectedIndex;

		String^ instruction = instruction_txt->Text;
		String^ location = location_txt->Text;
		String^ sign = sign_txt->Text;

		listBox->Items->RemoveAt(index);
		listBox->Items->Insert(index, (sign + instruction + location));

		resetProgram();
	}

	private: System::Void run_button_Click(System::Object^ sender, System::EventArgs^ e) {
		resetProgram();
		run_button->Enabled = false;
		upload_btn->Enabled = false;
		add_button->Enabled = false;
		edit_button->Enabled = false;
		delete_button->Enabled = false;
		unselect_btn->Enabled = false;
		input_groupbox->Visible = false;
		break_groupbox->Visible = false;

		int count = listBox->Items->Count;
		vector<string> instructions;

		for (int i = 0; i < count; i++) {
			Object ^itemObj = listBox->Items[i];
			String ^item = itemObj->ToString();
			string unmanaged = msclr::interop::marshal_as<string>(item);
			//unmanaged = unmanaged.substr(unmanaged.size() - 5, unmanaged.size());
			instructions.push_back(unmanaged);
			simulator.loadCommandIntoMemory(unmanaged);
		}		
		this->nextInstruction = simulator.executeProgram(output_txt, 0, input_groupbox, break_groupbox);
	}

	//delete button functionality
	private: System::Void delete_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBox->Items->Count > 0)
			listBox->Items->RemoveAt(listBox->SelectedIndex);
		else {
			return;
		}
		resetProgram();
		//numberedLineCount--;
	}

	private: System::Void listBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = true;
		unselect_btn->Enabled = true;
		add_button->Enabled = false;

		//int index = listBox->SelectedIndex;
		////string value = to_string(listBox->Items);

		//if (index != NULL) {
		//	//String^ value = index->ToString();
		//	//sign_txt->Text = value;
		//}
	}

	//reset everything to start a new program	
	private: System::Void reset_button_Click(System::Object^ sender, System::EventArgs^ e) {
		resetProgram();
		listBox->Items->Clear();
		output_txt->Text = "";
		simulator.InstructionCounter = 0;
		simulator.Accumulator = 0;
		simulator.InstructionRegister = "0";
		simulator.OperationCode = 0;
		simulator.Operand = 0;
		simulator.memory.clear();
	}

	private: System::Void menu_strip_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void unselect_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		edit_button->Enabled = false;
		add_button->Enabled = true;
		unselect_btn->Enabled = false;
	}

	private: System::Void submit_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ instruction = input_txt->Text;
		std::string unmanagedInstruction = msclr::interop::marshal_as<std::string>(instruction);
		int intInstruction = std::stoi(unmanagedInstruction);

		simulator.storeAfterRead(intInstruction);
		input_groupbox->Visible = false;
		simulator.executeProgram(output_txt, this->nextInstruction, input_groupbox, break_groupbox);
	}

	private: System::Void break_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ instruction = break_txt->Text;
		std::string unmanagedInstruction = msclr::interop::marshal_as<std::string>(instruction);
	
		bool cnt = simulator.breakExecution(output_txt, input_groupbox, break_groupbox, unmanagedInstruction);
		if (cnt) {
			break_groupbox->Visible = false;
			simulator.executeProgram(output_txt, this->nextInstruction, input_groupbox, break_groupbox);
		}
	}
	private: System::Void upload_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		resetProgram();

		//other dude
		IO::Stream^ myStream;
		OpenFileDialog^ file = gcnew OpenFileDialog;

		file->InitialDirectory = "c:\\";
		file->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		file->FilterIndex = 2;
		file->RestoreDirectory = true;

		if (file->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = file->OpenFile()) != nullptr)
			{
				listBox->Items->Clear();
				String^ filename = "";
				filename = file->FileName;
				String^ path = Assembly::GetExecutingAssembly()->Location;
				path = Path::Combine(Path::GetDirectoryName(path), filename);
				String^ text = File::ReadAllText(path);
				listBox->DataSource = File::ReadAllLines(path);

				myStream->Close();

				resetProgram();
				listBox->ClearSelected();
			}
		}
		else {
			error_box->Visible = true;
			error_txt->Text = "Cancelled file opening";
		}

		edit_button->Enabled = false;
		add_button->Enabled = true;
		listBox->ClearSelected();
	}
};
}
