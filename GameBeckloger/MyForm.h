#pragma once
#define CURL_STATICLIB

#include <string>
#include<curl\curl.h>

namespace GameManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:


		MyForm(void)
		{

			InitializeComponent();

		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Steam_rate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_Meta;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_user;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2B_time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Refrash_date;

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::Button^ buttondell;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ChoseBD;












	private: System::Windows::Forms::OpenFileDialog^ openFileDialogSearch;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^ �������;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Game;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SteamRate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_Metascore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_UsersCore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2b_rate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2b_main;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2b_all;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Add_Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Refresh_Date;
	private: System::Windows::Forms::ToolStripMenuItem^ CreateToolStripMenuItem;







	protected:







	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->������� = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Game = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SteamRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Metacritic_Metascore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Metacritic_UsersCore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hl2b_rate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hl2b_main = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hl2b_all = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Add_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Refresh_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->buttondell = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChoseBD = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialogSearch = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(12) {
				this->�������,
					this->Id, this->Game, this->Cost, this->SteamRate, this->Metacritic_Metascore, this->Metacritic_UsersCore, this->Hl2b_rate, this->Hl2b_main,
					this->Hl2b_all, this->Add_Date, this->Refresh_Date
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 55);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1160, 364);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// �������
			// 
			this->�������->Frozen = true;
			this->�������->HeaderText = L"Chose";
			this->�������->Name = L"�������";
			this->�������->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->�������->Width = 40;
			// 
			// Id
			// 
			this->Id->Frozen = true;
			this->Id->HeaderText = L"�����";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			// 
			// Game
			// 
			this->Game->Frozen = true;
			this->Game->HeaderText = L"����";
			this->Game->Name = L"Game";
			// 
			// Cost
			// 
			this->Cost->Frozen = true;
			this->Cost->HeaderText = L"����";
			this->Cost->Name = L"Cost";
			// 
			// SteamRate
			// 
			this->SteamRate->Frozen = true;
			this->SteamRate->HeaderText = L"������� � ����";
			this->SteamRate->Name = L"SteamRate";
			// 
			// Metacritic_Metascore
			// 
			this->Metacritic_Metascore->Frozen = true;
			this->Metacritic_Metascore->HeaderText = L"������ ��������";
			this->Metacritic_Metascore->Name = L"Metacritic_Metascore";
			// 
			// Metacritic_UsersCore
			// 
			this->Metacritic_UsersCore->Frozen = true;
			this->Metacritic_UsersCore->HeaderText = L"������ �������������";
			this->Metacritic_UsersCore->Name = L"Metacritic_UsersCore";
			// 
			// Hl2b_rate
			// 
			this->Hl2b_rate->Frozen = true;
			this->Hl2b_rate->HeaderText = L"Hl2B ������";
			this->Hl2b_rate->Name = L"Hl2b_rate";
			// 
			// Hl2b_main
			// 
			this->Hl2b_main->Frozen = true;
			this->Hl2b_main->HeaderText = L"������������";
			this->Hl2b_main->Name = L"Hl2b_main";
			// 
			// Hl2b_all
			// 
			this->Hl2b_all->Frozen = true;
			this->Hl2b_all->HeaderText = L"������������ (������ �����������)";
			this->Hl2b_all->Name = L"Hl2b_all";
			// 
			// Add_Date
			// 
			this->Add_Date->Frozen = true;
			this->Add_Date->HeaderText = L"����";
			this->Add_Date->Name = L"Add_Date";
			// 
			// Refresh_Date
			// 
			this->Refresh_Date->Frozen = true;
			this->Refresh_Date->HeaderText = L"���������";
			this->Refresh_Date->Name = L"Refresh_Date";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->buttonOpen);
			this->groupBox1->Controls->Add(this->buttondell);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(12, 425);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1154, 71);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"��������";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(992, 19);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(156, 46);
			this->button5->TabIndex = 4;
			this->button5->Text = L"��������";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(330, 19);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(156, 46);
			this->buttonOpen->TabIndex = 2;
			this->buttonOpen->Text = L"������� � ��������";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MyForm::buttonOpen_Click);
			// 
			// buttondell
			// 
			this->buttondell->Location = System::Drawing::Point(168, 19);
			this->buttondell->Name = L"buttondell";
			this->buttondell->Size = System::Drawing::Size(156, 46);
			this->buttondell->TabIndex = 1;
			this->buttondell->Text = L"�������";
			this->buttondell->UseVisualStyleBackColor = true;
			this->buttondell->Click += gcnew System::EventHandler(this, &MyForm::buttondell_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"��������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->infoToolStripMenuItem,
					this->ChoseBD, this->CreateToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1178, 31);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(54, 27);
			this->infoToolStripMenuItem->Text = L"Info";
			this->infoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::infoToolStripMenuItem_Click);
			// 
			// ChoseBD
			// 
			this->ChoseBD->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ChoseBD->Name = L"ChoseBD";
			this->ChoseBD->Size = System::Drawing::Size(116, 27);
			this->ChoseBD->Text = L"������� ��";
			this->ChoseBD->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItem_Click);
			// 
			// CreateToolStripMenuItem
			// 
			this->CreateToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateToolStripMenuItem->Name = L"CreateToolStripMenuItem";
			this->CreateToolStripMenuItem->Size = System::Drawing::Size(112, 27);
			this->CreateToolStripMenuItem->Text = L"������� ��";
			//this->CreateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::CreateBDToolStripMenuItem_Click);
			// 
			// openFileDialogSearch
			// 
			this->openFileDialogSearch->FileName = L"openFileDialogSerch";
			this->openFileDialogSearch->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialogSearch_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 501);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game Backloger";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {};
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {};

	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttondell_Click(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: void readDB(String^ DBName);
	private: System::Void infoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void openFileDialogSearch_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {};
	private: String^ GetLink(String^ DBName, String^ id);
	//private: System::Void CreateBDToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
