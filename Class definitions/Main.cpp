#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    breeze::MyForm form;
    Application::Run(% form);
}

/*DO NOT TOUCH THIS FILE PLEASE*/
