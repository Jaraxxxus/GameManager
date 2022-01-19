#include "MyForm.h"
#include <windows.h>
#include <ShellAPI.h>
#include <thread>

#include <msclr/marshal.h>
#include <string>
#include <vector>
#include "func.cpp"



using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;

//Ws2_32.lib
//Crypt32.lib
//Wldap32.lib; Normaliz.lib;












System::Void GameManager::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

}


System::Void GameManager::MyForm::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e)
{

	int selectedrowindex = -1;
	if (dataGridView1->SelectedRows->Count == 0 && dataGridView1->SelectedCells->Count > 0) {
		 selectedrowindex = dataGridView1->SelectedCells[0]->RowIndex;
	}else if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("выберите одну строку!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int index;


	if (selectedrowindex!=-1) {
		index = selectedrowindex;
	}else index = dataGridView1->SelectedRows[0]->Index;
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Surl = GetLink("myDB.mdb", id);
	msclr::interop::marshal_context oMarshalContext;

	//const char* Murl = oMarshalContext.marshal_as<const char*>(Surl);
	std::string url = "start ";

	std::string Murl = ConvertToString(Surl);
	url.append(Murl);
	system(url.c_str());
	//ShellExecute(NULL, TEXT("open"), url, NULL, NULL, SW_SHOWNORMAL);
}

System::Void GameManager::MyForm::ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ FileName = "";
	if (openFileDialogSearch->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialogSearch->FileName;
		dataGridView1->Rows->Clear();
		readDB(FileName);
	}


}

System::Void GameManager::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	readDB("myDB.mdb");

}





