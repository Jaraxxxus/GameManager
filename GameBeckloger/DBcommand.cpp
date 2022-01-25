#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include "MyForm.h"
#include <windows.h>
#include <string>
#include <vector>
#include "func.h"
#include "parser.h"

#define alredy_exist 2
#define error 1


using namespace std;
using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;



int addtoDB(vector<string> res, string link, string curDB) {
	String^ ID;
	String^ database = ConvertToString(curDB);
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + database;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	int flag;
	//dbConnection->Open();
	String^ query = "SELECT * FROM [MyBD] WHERE URL = '" + ConvertToString(link) +"'";
//	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	//OleDbDataReader^ dbReader = dbComand->ExecuteReader();//читаю данные
	
	/*if (dbReader->HasRows == true) {
		flag = alredy_exist;
		dbConnection->Close();
		return flag;
	}
	//else {
	//	while (dbReader->Read()) {
	//		  ID = dbReader[0]->ToString();
	//	}*/
		//dbConnection->Close();
		//delete dbComand;
		dbConnection->Open();
		//String^ query = "INSERT INTO [MyBD] (URL, Game, Cost, SteamRate, Metacritic Metascore) VALUES ('" + ConvertToString(link) + "', '" + ConvertToString(res[0]) + "', " + ConvertToString(res[1]) + ", '" + ConvertToString(res[2]) + ", '" + ConvertToString(res[2]) + "')";
		string time = GetTime();
		query = "INSERT INTO [MyBD] (URL, Game, Cost, SteamRate, Metascore, Userscore, Lmain, Lall, AddDate, refData)  VALUES ('" + ConvertToString(link) + "', '" + ConvertToString(res[0]) + "', " + ConvertToString(res[1]) + ", '" + ConvertToString(res[2]) + "', '" + ConvertToString(res[3]) + "', '" + ConvertToString(res[4]) + "', '" + ConvertToString(res[5]) + "', " + " '" + ConvertToString(res[6]) + "', '" + ConvertToString(time) + "', '" + ConvertToString(time) + "')";
		OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

		//ловить ошибку 
		if (dbComand->ExecuteNonQuery() != 1)
			flag = error;
		else
			flag = 0;

		dbConnection->Close();

		return flag;
}




int updateDB(vector<string> res, string link, string curDB, string ID) {

	String^ database = ConvertToString(curDB);
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + database;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	int flag;
	
	dbConnection->Open();
	//String^ query = "INSERT INTO [MyBD] (URL, Game, Cost, SteamRate, Metacritic Metascore) VALUES ('" + ConvertToString(link) + "', '" + ConvertToString(res[0]) + "', " + ConvertToString(res[1]) + ", '" + ConvertToString(res[2]) + ", '" + ConvertToString(res[2]) + "')";
	string time = GetTime();
	String^ query = "UPDATE [MyBD] SET Game= '" + ConvertToString(res[0]) + "', Cost = " + ConvertToString(res[1]) + ", SteamRate ='" + ConvertToString(res[2]) + "' , Metascore = '" + ConvertToString(res[3]) + "', Userscore = '" + ConvertToString(res[4]) + "', Lmain = '" + ConvertToString(res[5]) + "', Lall = '" + ConvertToString(res[6]) + "', refData = '" + ConvertToString(time) + "'  WHERE ID = " + ConvertToString(ID);
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

	//ловить ошибку 
	if (dbComand->ExecuteNonQuery() != 1)
		flag = error;
	else
		flag = 0;

	dbConnection->Close();

	return flag;
}

/*String^ GetLink(String^ DBName, String^ id)
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

*/