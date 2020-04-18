#include "pch.h"
#include "main_form.h"
#include "output.h"
#include <array>

using namespace std;   
using namespace System;
using namespace System::Windows::Forms;

Simulator simulator;
UserProgram userProgram;

[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    UVSimForm::main_form main_form;
    Application::Run(% main_form);
    return 0;
}


