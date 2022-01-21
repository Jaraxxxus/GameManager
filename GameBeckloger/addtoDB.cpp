#include <string>
#include <vector>
#include "MyForm.h"
#include <windows.h>
#include <string>
#include <vector>
#include "func.h"
#include "parser.h"


using namespace std;
using  namespace System;
using  namespace System::Windows::Forms;
using  namespace System::Data::OleDb;



bool addtoDB(vector<string> res, string link, string curDB) {
	String^ ID;
	String^ database = ConvertToString(curDB);
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + database;
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);
	dbConnection->Open();
	String^ query = "SELECT MAX(`ID`) FROM [MyBD] ";
	OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//читаю данные
	bool flag;
	if (dbReader->HasRows == false) {
		flag == 1;
		return flag;
	}
	else {

		while (dbReader->Read()) {
			
		
			  ID = dbReader[0]->ToString();
			
			
		}
		dbConnection->Close();
		ID = plusOne(ID);
		dbConnection->Open();
		String^ query = "INSERT INTO [MyBD] VALUES ([" + ID + "], '[" + ConvertToString(link) + "]', '[" + ConvertToString(res[0]) + "]', [" + ConvertToString(res[1]) + "], '[" + ConvertToString(res[2]) + "]', '[" + ConvertToString(res[3]) + "]', '[" + ConvertToString(res[4]) + "]', '[" + ConvertToString(res[5]) + "]', " + " '[" + ConvertToString(res[6]) + "]')";
		OleDbCommand^ dbComand = gcnew OleDbCommand(query, dbConnection);

		//String myQuery = "INSERT INTO Users ( name, surname, login, password, action) VALUES ('" + textBox1.Text + "', '" + textBox2.Text + "', '" + textBox3.Text + "', '" + textBox4.Text + "', '" + textBox5.Text + "')";
		if (dbComand->ExecuteNonQuery() != 1)
			flag = 1;
		else
			flag = 0;

		dbConnection->Close();

		
	}
	return flag;
}