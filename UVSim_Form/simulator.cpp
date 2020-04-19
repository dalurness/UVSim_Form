#include "pch.h"
#include "simulator.h"
#include "main_form.h"

#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace UVSimForm;

//Dallin
void Simulator::loadCommandIntoMemory(std::string command) {
	if (this->memory.size() == SIZE_OF_MEMORY) {
		throw std::runtime_error("Memory overflow");
	}
	if (command[0] == '#')
		return;
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

//Shaun
void Simulator::clearProgram() {
	this->memory.clear();
}

//Shaun
void Simulator::clearLast() {
	if (this->memory.size() > 0) {
		this->memory.pop_back();
	}
}

void Simulator::printMemory(System::Windows::Forms::RichTextBox^ output_txt) {
	//Print Register contents.
	output_txt->AppendText("REGISTERS: \n");
	output_txt->AppendText("Accumulator: " + this->Accumulator + "\n");
	output_txt->AppendText("Instruction Counter: " + this->InstructionCounter + "\n");
	String^ managedInstReg = gcnew String(this->InstructionRegister.c_str());
	output_txt->AppendText("Instruction Register: " + managedInstReg + "\n");
	output_txt->AppendText("Operand Code: " + this->OperationCode + "\n");
	output_txt->AppendText("Operand: " + this->Operand + "\n\n");

	//Print Memory Table (10x10).
	output_txt->AppendText("MEMORY: \n");

	//output_txt->AppendText(" ");
	for (int i = 0; i < 10; i++) {
		output_txt->AppendText("        ");
		if (i < 10)
			output_txt->AppendText("0" + i);
	}

	int j = 0;

	for (int i = 0; i < (int)this->memory.size(); ++i) {
		if (i % 10 == 0 /*&& i != 0*/) {
			output_txt->AppendText("\n");
			if (i < 10)
				output_txt->AppendText("0");
			output_txt->AppendText(j + "  ");
			j += 10;
		}

		std::string vectMemory = this->memory.at(i);
		String^ managedVectMemory = gcnew String(vectMemory.c_str());
		output_txt->AppendText(managedVectMemory + "  ");
	}
	output_txt->AppendText("\n\n");
}

//Kristen
bool Simulator::scanForSeparator(int& memoryLocation) {
	bool done = false;
	while (!done) {
		if (memoryLocation >= SIZE_OF_MEMORY) {
			return false;
		}
		std::string cmd = (memory.at(memoryLocation)).substr(1, 3);
		std::string sepvalue = std::to_string(PROGSEP);
		if (cmd == sepvalue) {
			return true;
		}
		memoryLocation++;
	}
	return false;
}

//Kristen
void Simulator::executeProgram(System::Windows::Forms::RichTextBox^ output_txt) {
	//Fill vector with emtpy data to fill table.
	for (size_t i = this->memory.size(); i < SIZE_OF_MEMORY; i++) {
		this->memory.push_back("00000");
	}
	while (true) {
		this->InstructionRegister = this->memory.at(this->InstructionCounter);
		//if (nextCommand.substr(0, 3) == ("0" + std::to_string(HALT)))
		//return;

		bool goOn = this->executeInstruction(output_txt);
		this->InstructionCounter++;
		if (!goOn)
			return;
	}
}

//Dallin
bool Simulator::executeInstruction(System::Windows::Forms::RichTextBox^ output_txt) {
	int memoryLocation = stoi(this->InstructionRegister.substr(3, 5));
	this->OperationCode = stoi(this->InstructionRegister.substr(1, 2));

	//check if command is positive or negative
	switch (this->InstructionRegister[0]) {
	case '1':
		break;
	case '0':
		switch (this->OperationCode) {
		case EXTRACT:
			this->OperationCode = stoi(this->InstructionRegister.substr(3, 5));
			this->InstructionCounter++;
			this->InstructionRegister = this->memory.at(this->InstructionCounter);
			memoryLocation = stoi(this->InstructionRegister.substr(1, 5));
		case READ:
			this->read(memoryLocation, output_txt);
			break;
		case WRITE:
			this->write(memoryLocation, output_txt);
			break;
		case LOAD:
			this->load(memoryLocation);
			break;
		case STORE:
			this->store(memoryLocation);
			break;
		case ADD:
			this->add(memoryLocation);
			break;
		case SUBTRACT:
			this->subtract(memoryLocation);
			break;
		case DIVIDE:
			this->divide(memoryLocation);
			break;
		case MULTIPLY:
			this->multiply(memoryLocation);
			break;
		case BRANCH:
			this->branch(memoryLocation);
			break;
		case BRANCHNEG:
			this->branchNeg(memoryLocation);
			break;
		case BRANCHZERO:
			this->branchZero(memoryLocation);
			break;
		case HALT:
			if (!scanForSeparator(memoryLocation)) {
				this->printOutDetails();
				this->printMemory(output_txt);
				return (false);
			}
			break;
		case MEMDUMP:
			this->memDump(output_txt);
			break;
		case BREAK:
			this->breakExecution(output_txt);
			break;
		case CONTINUE:
			this->continueExecution(output_txt);
			break;
		case PROGSEP:
			break;
		default:
			throw std::logic_error("Invalid command found in memory at location: " + std::to_string(this->InstructionCounter));
		}
		break;
	default:
		throw std::invalid_argument("First digit in each word must be a 1 or 0(- or +)");
	}

	return true;
}

//Dallin
void Simulator::read(int memoryLocation, System::Windows::Forms::RichTextBox^ output_txt) {

	UVSimForm::output output;
	output.ShowDialog();
	output.Show();


	bool isNumber = false;
	std::string stringNumber;
	while (!isNumber) {
		output_txt->AppendText("Please enter a number four digits or less to insert into location " + memoryLocation + ": ");
		//important
		std::cin >> stringNumber;

		isNumber = true;
		if (stringNumber[0] == '+' || stringNumber[0] == '-') {
			for (int i = 1; i < stringNumber.size(); ++i) {
				if (!isdigit(stringNumber[i])) { isNumber = false; };
			}
		}
		else {
			for (char x : stringNumber)
				if (!isdigit(x)) { isNumber = false; };
		}
		if (isNumber && (stoi(stringNumber) > 9999 || stoi(stringNumber) < -9999)) {
			isNumber = false;
			output_txt->AppendText("Number needs to be four digits or less \n\n");
		}
	}
	//take out sign
	char sign = '+';
	if (stringNumber[0] == '-' || stringNumber[0] == '+') {
		sign = stringNumber[0];
		stringNumber = stringNumber.substr(1, stringNumber.size());
	}
	//add leading zeroes for shorter numbers
	for (size_t i = stringNumber.size(); i < 5; ++i)
		stringNumber = "0" + stringNumber;
	//put sign back in
	if (sign == '-')
		stringNumber[0] = '1';
	//insert number into memory location
	this->memory.at(memoryLocation) = stringNumber;
}

//Dallin
void Simulator::load(int memoryLocation) {
	this->Accumulator = stoi(this->memory.at(memoryLocation));
}

//Dallin
void Simulator::add(int memoryLocation) {
	this->Accumulator = this->Accumulator + stoi(this->memory.at(memoryLocation).substr(1, 5));
	while (this->Accumulator > 9999) {
		this->Accumulator = this->Accumulator - 10000;
	}
	while (this->Accumulator < -9999) {
		this->Accumulator = this->Accumulator + 10000;
	}
}

//Dallin
void Simulator::subtract(int memoryLocation) {
	this->Accumulator = this->Accumulator - stoi(this->memory.at(memoryLocation).substr(1, 5));
	while (this->Accumulator < -9999) {
		this->Accumulator = this->Accumulator + 10000;
	}
	while (this->Accumulator > 9999) {
		this->Accumulator = this->Accumulator - 10000;
	}
}

//Dallin
void Simulator::multiply(int memoryLocation) {
	this->Accumulator = this->Accumulator * stoi(this->memory.at(memoryLocation).substr(1, 5));
	while (this->Accumulator > 9999) {
		this->Accumulator = this->Accumulator - 10000;
	}
	while (this->Accumulator < -9999) {
		this->Accumulator = this->Accumulator + 10000;
	}
}

//Dallin
void Simulator::divide(int memoryLocation) {
	if (stoi(this->memory.at(memoryLocation).substr(1, 5)) == 0) {
		throw std::runtime_error("Attempt to divide by zero");
	}
	this->Accumulator = this->Accumulator / stoi(this->memory.at(memoryLocation).substr(1, 5));
	while (this->Accumulator > 9999) {
		this->Accumulator = this->Accumulator - 10000;
	}
	while (this->Accumulator < -9999) {
		this->Accumulator = this->Accumulator + 10000;
	}
}

//Kristen
//Write word from memoryLocation to console
void Simulator::write(int memoryLocation, System::Windows::Forms::RichTextBox^ output_txt) {
	String^ managedMemLoc = gcnew String(this->memory.at(memoryLocation).c_str());
	output_txt->AppendText(managedMemLoc + "\n");
	std::cout << this->memory.at(memoryLocation);
	std::cout << std::endl;
}

//Kristen
//pause the execution
void Simulator::breakExecution(System::Windows::Forms::RichTextBox^ output_txt) {
	std::string cmd = "";

	while (cmd != "+5100") {
		//important
		output_txt->AppendText("Execution Paused, (to continue click 'Continue Execution'): ");
		std::cin >> cmd;

		char sign = cmd[0];
		std::string com = cmd.substr(1, 5);
		for (char x : com) {
			if (!isdigit(x)) {
				throw std::invalid_argument("Command must be a signed four-digit decimal number (+1234 or -5678)");
			}
		}
		std::string trueCmd = "";
		switch (sign) {
		case '-':
			trueCmd = ("1" + com);
			break;
		case '+':
			trueCmd = ("0" + com);
			break;
		default:
			throw std::invalid_argument("Command must be a signed four-digit decimal number (+1234 or -5678)");
		}

		if (std::stoi(trueCmd) == HALT) {
			exit(0);
		}
		this->InstructionRegister = trueCmd;
		this->executeInstruction(output_txt);
	}
}

//Kristen
//continue executing
void Simulator::continueExecution(System::Windows::Forms::RichTextBox^ output_txt) {
	output_txt->AppendText("\n ~ Continuing Execution ~ \n");
}

//Dallin
void Simulator::store(int memoryLocation) {
	if (this->Accumulator < 0) {
		this->Accumulator = 0;
	}
	else if (this->Accumulator > 9999) {
		while (this->Accumulator > 9999) {
			this->Accumulator = this->Accumulator - 10000;
		}
	}
	std::string value = std::to_string(this->Accumulator);
	for (size_t i = value.size(); i < 5; ++i)
		value = "0" + value;
	if (this->Accumulator < 0)
		value[0] = '1';
	this->memory.at(memoryLocation) = value;
}

//Caleb
void Simulator::branch(int memoryLocation) {
	if (this->Accumulator > 0) {
		this->InstructionCounter = memoryLocation - 1;
	}
}

//Caleb
void Simulator::branchNeg(int memoryLocation) {
	if (this->Accumulator < 0) {
		this->InstructionCounter = memoryLocation - 1;
	}
}

//Caleb
void Simulator::branchZero(int memoryLocation) {
	if (this->Accumulator == 0) {
		this->InstructionCounter = memoryLocation - 1;
	}
}

void Simulator::memDump(System::Windows::Forms::RichTextBox^ output_txt) {
	printMemory(output_txt);
}