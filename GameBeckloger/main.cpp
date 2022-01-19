#include "MyForm.h"
#include <windows.h>
#include <ShellAPI.h>
#include <thread>
#include <vector>



using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;



[STAThread]
int main(array<String^>^ arg) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	GameManager::MyForm form;

	Application::Run(% form);
}



