#pragma once
#include "MyForm.h"
#include <windows.h>
#include <ShellAPI.h>
#include <thread>
#include <fstream>
#include <msclr/marshal.h>
#include <string>
#include <vector>
#include "func.h"
#include "resource.h"



using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;

//Ws2_32.lib
//Crypt32.lib
//Wldap32.lib; Normaliz.lib;




String^ GameManager::MyForm::GetLink(String^ DBName, String^ id)
{



	String^ url = "";
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source = " + DBName;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//запрос
	dbConnection->Open();//соединение
	String^ query = "SELECT URL FROM [MyBD] WHERE ID = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//читаю данные


	if (dbReader->HasRows == false) {
		MessageBox::Show("data reading error!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		while (dbReader->Read()) {
			url = dbReader["URL"]->ToString();
		}

	}
	dbReader->Close();
	dbConnection->Close();
	return url;
}



void GameManager::MyForm::readDB(String^ DBName)
{
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source = " + DBName;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	//запрос
	dbConnection->Open();//соединение
	String^ query = "SELECT * FROM [MyBD] ";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//читаю данные

	if (dbReader->HasRows == false) {
		MessageBox::Show("data reading error!", "Error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {

		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["Id"], dbReader["Game"], dbReader["Cost"], dbReader["SteamRate"], dbReader["Metacritic Metascore"], dbReader["Metacritic Userscore"],  dbReader["Length main"], dbReader["Length all"], dbReader["Add Date"], dbReader["Refresh Date"]);
		}
	}
	dbReader->Close();
	dbConnection->Close();
}









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
	if (url.find("store.steampowered.com") !=-1) {
		system(url.c_str());
	}
	else MessageBox::Show("Bad Steam link", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
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






System::Void GameManager::MyForm::CreateBD_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ FileName = "";
	saveFileDialogSearch->Filter = "MDB|*.mdb";
	if (saveFileDialogSearch->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = saveFileDialogSearch->FileName;
		HMODULE handle = GetModuleHandle(NULL);
		HRSRC rc = FindResource(handle, MAKEINTRESOURCE(BD), MAKEINTRESOURCE(BDfile));
		HGLOBAL rcData = LoadResource(handle, rc);
		DWORD size = SizeofResource(handle, rc);
		const char* data = static_cast<const char*>(LockResource(rcData));
		std::string result;
		result.assign(data, size);
		std::ofstream out(ConvertToString(FileName)); //output file
		if (out.is_open())
		{
			
			
		
				out << result;

			
		}


	}


	

}



