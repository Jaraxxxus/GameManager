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
#include "parser.h"
#include "DBcommand.h"


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
		return;
	}
	else {

		while (dbReader->Read()) {
			dataGridView1->Rows->Add(dbReader["Id"], dbReader["Game"], dbReader["Cost"], dbReader["SteamRate"], dbReader["Metascore"], dbReader["Userscore"],  dbReader["Lmain"], dbReader["Lall"], dbReader["AddDate"], dbReader["refData"]);
		}
	}
	dbReader->Close();
	dbConnection->Close();
    saveBD(ConvertToString(DBName));
	return;
}



System::Void GameManager::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void GameManager::MyForm::buttonDell_Click(System::Object^ sender, System::EventArgs^ e)
{
	int selectedRowIndex = -1;
	if (dataGridView1->SelectedRows->Count == 0 && dataGridView1->SelectedCells->Count > 0) {
		selectedRowIndex = dataGridView1->SelectedCells[0]->RowIndex;
	}
	else if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("выберите одну строку!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	

	
	if (dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value == nullptr)
	{
		MessageBox::Show("Выбранная вами строка пуста", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	
	String^ id = dataGridView1->Rows[selectedRowIndex]->Cells[0]->Value->ToString();

	
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ curDB;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	
	dbConnection->Open();
	String^ query = "DELETE FROM [MyBD] WHERE ID = " + id;
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	if (dbComand->ExecuteNonQuery() != 1)
		MessageBox::Show("Что то пошло не так!", "ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		MessageBox::Show("Строка успешно удалена!", "Готово!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		dataGridView1->Rows->RemoveAt(selectedRowIndex);
	}

	dbConnection->Close();
	return System::Void();
}



System::Void GameManager::MyForm::buttonAdd_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!isOpen) {
		MessageBox::Show("Сначало откройте БД!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	String^ link = textBox1->Text;
	textBox1->Clear();
	std::string strlink = ConvertToString(link);

	if (strlink.find("https://store.steampowered.com/app/") == -1)
		MessageBox::Show("Невалидная ссылка Steam!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		vector<string> parseres = parseall(strlink);
		if (parseres[0] == "-1") {

			MessageBox::Show("Невалидная ссылка Steam, залогиньтесь в Steam в браузере по умолчанию и повторите попытку", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (parseres[0] == "-2") {

			MessageBox::Show("Неполная ссылка Steam", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int signal;
		try { 
			 signal = addtoDB(parseres, strlink, ConvertToString(curDB)); 


		}
		catch (OleDbException^ ex) // обработчик исключений типа const char*
		{
			MessageBox::Show("Данная страница уже добавлена", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		if (signal == 1) MessageBox::Show("Что то пошло не так!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else MessageBox::Show("Добавлено", "Готово!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		dataGridView1->Rows->Clear();
		readDB(curDB);
		

	}
	return;
}

System::Void GameManager::MyForm::buttonOpen_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!isOpen) {
		MessageBox::Show("Сначало откройте БД!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
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
	String^ Surl = GetLink(curDB, id);
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
	return;
}

System::Void GameManager::MyForm::ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	String^ FileName = "";
	isOpen = 0;
	openFileDialogSearch->Filter = "MDB|*.mdb";
	if (openFileDialogSearch->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = openFileDialogSearch->FileName;
		dataGridView1->Rows->Clear();
		readDB(FileName);
		curDB = FileName;
		
	}
	isOpen = 1;
	return;

}

System::Void GameManager::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	isOpen = 0;
	try {
		readDB(ConvertToString(getDB()));
		curDB = ConvertToString(getDB());
	}
	catch (OleDbException^ ex) {
		
		String^ errorMessages = "";
		
		for (int i = 0; i < ex->Errors->Count; i++)
		{
			errorMessages += "Index #" + i + "\n" +
				"Message: " + ex->Errors[i]->Message + "\n" +
				"NativeError: " + ex->Errors[i]->NativeError + "\n" +
				"Source: " + ex->Errors[i]->Source + "\n" +
				"SQLState: " + ex->Errors[i]->SQLState + "\n";
		}
		MessageBox::Show(errorMessages, "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	
	isOpen = 1;
	//MessageBox::Show("Не удалось найти myDB.mdb в данной папке", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	return;
}






System::Void GameManager::MyForm::CreateBD_Click(System::Object^ sender, System::EventArgs^ e)
{


	system("start https://github.com/Jaraxxxus/GameManager/raw/main/myDB.mdb");
	MessageBox::Show("Используйте этот файл как БД", "Инфо!", MessageBoxButtons::OK, MessageBoxIcon::Information);






	String^ FileName = "";







	       
	/*saveFileDialogSearch->Filter = "MDB|*.mdb";
	if (saveFileDialogSearch->ShowDialog() == Windows::Forms::DialogResult::OK) {
		FileName = saveFileDialogSearch->FileName;

		//-------------------------------using curl. Breaks the file
		//DownloadBD(ConvertToString(FileName));
		//-------------------------------------


		
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
		 //using properties, breaks the file too
	}*/
	
}

System::Void GameManager::MyForm::buttonrefresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!isOpen) {
		MessageBox::Show("Сначало откройте БД!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int selectedrowindex = -1;
	if (dataGridView1->SelectedRows->Count == 0 && dataGridView1->SelectedCells->Count > 0) {
		selectedrowindex = dataGridView1->SelectedCells[0]->RowIndex;
	}
	else if (dataGridView1->SelectedRows->Count != 1) {
		MessageBox::Show("выберите одну строку!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int index;
	int signal;

	if (selectedrowindex != -1) {
		index = selectedrowindex;
	}
	else index = dataGridView1->SelectedRows[0]->Index;
	String^ id = dataGridView1->Rows[index]->Cells[0]->Value->ToString();
	String^ Surl = GetLink(curDB, id);
	string url = ConvertToString(Surl);
	vector<string> parseres = parseall(url);
	signal = updateDB(parseres, url, ConvertToString(curDB), ConvertToString(id));
	if (signal == 1) MessageBox::Show("Что то пошло не так!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else MessageBox::Show("Обновлено", "Готово!", MessageBoxButtons::OK, MessageBoxIcon::Information);
	dataGridView1->Rows->Clear();
	readDB(curDB);
}





