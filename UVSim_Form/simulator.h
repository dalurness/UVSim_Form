#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "main_form.h"

#include <vector>
#include <string>

enum Instructions { READ = 10, WRITE = 11, LOAD = 20, STORE = 21, EXTRACT = 22, ADD = 30, SUBTRACT = 31, DIVIDE = 32, MULTIPLY = 33, BRANCH = 40, BRANCHNEG = 41, BRANCHZERO = 42, HALT = 43, MEMDUMP = 52, BREAK = 50, CONTINUE = 51, PROGSEP = 66 };

//Dallin
class Simulator
{
	const int SIZE_OF_MEMORY = 1000;
public:
	Simulator() {};
	Simulator(std::string filename) {}; //initialize a simulator with a textfile to load the program into the machine
	void printMemory(System::Windows::Forms::RichTextBox^ output_txt);
	void loadCommandIntoMemory(std::string command);
	void loadProgramFromFile(std::string filename) {};
	void executeProgram(System::Windows::Forms::RichTextBox^ output_txt);
	bool executeInstruction(System::Windows::Forms::RichTextBox^ output_txt);
	void clearProgram();
	void clearLast();
	bool scanForSeparator(int& memoryLocation);
private:
	//registers
	int Accumulator = 0;
	int InstructionCounter = 0;
	std::string InstructionRegister = "0";
	int OperationCode = 0;
	int Operand = 0;

	//memory
	std::vector<std::string> memory = {};

	//internal functions
	void read(int memoryLocation, System::Windows::Forms::RichTextBox^ output_txt); //Read a word from the keyboard into a specific location in memory.
	void write(int memoryLocation, System::Windows::Forms::RichTextBox^ output_txt); //Write word from memoryLocation to console
	void load(int memoryLocation); //Load from memoryLocation to Accumulator
	void store(int memoryLocation); //Store from Accumulator to memoryLocation
	void add(int memoryLocation); //add word from memoryLocation to Accumulator and leave in Accumulator
	void subtract(int memoryLocation); //subtract word from memoryLocation to Accumulator and leave in Accumulator
	void multiply(int memoryLocation); //multiply word from memoryLocation to Accumulator and leave in Accumulator
	void divide(int memoryLocation); //truncating division from memoryLocation to Accumulator and leave in Accumulator
	void branch(int memoryLocation); //branch to specific memory location
	void branchNeg(int memoryLocation); //branch at negative
	void branchZero(int memoryLocation); //branch at zero
	void halt() {}; //end program
	void memDump(System::Windows::Forms::RichTextBox^ output_txt); //dump memory onto screen for debugging
	void breakExecution(System::Windows::Forms::RichTextBox^ output_txt); //pause the execution
	void continueExecution(System::Windows::Forms::RichTextBox^ output_txt); //continue executing

	//extra functions
	void printOutDetails() {}; //go through and print out the registers and run memDump() at the end of execution
};
#endif