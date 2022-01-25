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
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Button^ buttonrefresh;


	private: System::Windows::Forms::Button^ buttonOpen;
	private: System::Windows::Forms::Button^ buttonDell;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ChoseBD;
	public: String^ curDB;
	public: bool isOpen;



	private: System::Windows::Forms::OpenFileDialog^ openFileDialogSearch;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialogSearch;
	private: System::Windows::Forms::ToolStripMenuItem^ CreateBD;




	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ buttonAdd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Game;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SteamRate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_Metascore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Metacritic_UsersCore;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2b_main;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Hl2b_all;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Add;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Update;














	protected:







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->buttonrefresh = (gcnew System::Windows::Forms::Button());
			this->buttonOpen = (gcnew System::Windows::Forms::Button());
			this->buttonDell = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ChoseBD = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CreateBD = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialogSearch = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialogSearch = (gcnew System::Windows::Forms::SaveFileDialog());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Game = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SteamRate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Metacritic_Metascore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Metacritic_UsersCore = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hl2b_main = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Hl2b_all = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Add = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Update = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->Id, this->Game,
					this->Cost, this->SteamRate, this->Metacritic_Metascore, this->Metacritic_UsersCore, this->Hl2b_main, this->Hl2b_all, this->Add,
					this->Update
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 55);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(1138, 364);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonAdd);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->buttonrefresh);
			this->groupBox1->Controls->Add(this->buttonOpen);
			this->groupBox1->Controls->Add(this->buttonDell);
			this->groupBox1->Location = System::Drawing::Point(12, 425);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1132, 71);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Действия";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(971, 19);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(155, 46);
			this->buttonAdd->TabIndex = 7;
			this->buttonAdd->Text = L"Добавить";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(531, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 20);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Вставьте ссылку на страницу игры в Steam";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->textBox1->Location = System::Drawing::Point(535, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(429, 29);
			this->textBox1->TabIndex = 5;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// buttonrefresh
			// 
			this->buttonrefresh->Location = System::Drawing::Point(6, 19);
			this->buttonrefresh->Name = L"buttonrefresh";
			this->buttonrefresh->Size = System::Drawing::Size(156, 46);
			this->buttonrefresh->TabIndex = 4;
			this->buttonrefresh->Text = L"Обновить";
			this->buttonrefresh->UseVisualStyleBackColor = true;
			this->buttonrefresh->Click += gcnew System::EventHandler(this, &MyForm::buttonrefresh_Click);
			// 
			// buttonOpen
			// 
			this->buttonOpen->Location = System::Drawing::Point(330, 19);
			this->buttonOpen->Name = L"buttonOpen";
			this->buttonOpen->Size = System::Drawing::Size(156, 46);
			this->buttonOpen->TabIndex = 2;
			this->buttonOpen->Text = L"Открыть в браузере";
			this->buttonOpen->UseVisualStyleBackColor = true;
			this->buttonOpen->Click += gcnew System::EventHandler(this, &MyForm::buttonOpen_Click);
			// 
			// buttonDell
			// 
			this->buttonDell->Location = System::Drawing::Point(168, 19);
			this->buttonDell->Name = L"buttonDell";
			this->buttonDell->Size = System::Drawing::Size(156, 46);
			this->buttonDell->TabIndex = 1;
			this->buttonDell->Text = L"Удалить";
			this->buttonDell->UseVisualStyleBackColor = true;
			this->buttonDell->Click += gcnew System::EventHandler(this, &MyForm::buttonDell_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->infoToolStripMenuItem,
					this->ChoseBD, this->CreateBD
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
			this->ChoseBD->Text = L"Выбрать БД";
			this->ChoseBD->Click += gcnew System::EventHandler(this, &MyForm::ToolStripMenuItem_Click);
			// 
			// CreateBD
			// 
			this->CreateBD->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateBD->Name = L"CreateBD";
			this->CreateBD->Size = System::Drawing::Size(112, 27);
			this->CreateBD->Text = L"Создать БД";
			this->CreateBD->Click += gcnew System::EventHandler(this, &MyForm::CreateBD_Click);
			// 
			// openFileDialogSearch
			// 
			this->openFileDialogSearch->FileName = L"openFileDialogSerch";
			this->openFileDialogSearch->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialogSearch_FileOk);
			// 
			// Id
			// 
			this->Id->HeaderText = L"Номер";
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			this->Id->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Id->Width = 70;
			// 
			// Game
			// 
			this->Game->HeaderText = L"Игра";
			this->Game->Name = L"Game";
			this->Game->ReadOnly = true;
			this->Game->Width = 120;
			// 
			// Cost
			// 
			this->Cost->HeaderText = L"Цена";
			this->Cost->Name = L"Cost";
			this->Cost->ReadOnly = true;
			this->Cost->Width = 80;
			// 
			// SteamRate
			// 
			this->SteamRate->HeaderText = L"Рейтинг в стим";
			this->SteamRate->Name = L"SteamRate";
			this->SteamRate->ReadOnly = true;
			// 
			// Metacritic_Metascore
			// 
			this->Metacritic_Metascore->FillWeight = 150;
			this->Metacritic_Metascore->HeaderText = L"Оценка Критиков";
			this->Metacritic_Metascore->Name = L"Metacritic_Metascore";
			this->Metacritic_Metascore->ReadOnly = true;
			this->Metacritic_Metascore->Width = 120;
			// 
			// Metacritic_UsersCore
			// 
			this->Metacritic_UsersCore->HeaderText = L"Оценка пользователей";
			this->Metacritic_UsersCore->Name = L"Metacritic_UsersCore";
			this->Metacritic_UsersCore->ReadOnly = true;
			this->Metacritic_UsersCore->Width = 120;
			// 
			// Hl2b_main
			// 
			this->Hl2b_main->HeaderText = L"Длительность";
			this->Hl2b_main->Name = L"Hl2b_main";
			this->Hl2b_main->ReadOnly = true;
			this->Hl2b_main->Width = 120;
			// 
			// Hl2b_all
			// 
			this->Hl2b_all->HeaderText = L"Длительность (Полное прохождение)";
			this->Hl2b_all->Name = L"Hl2b_all";
			this->Hl2b_all->ReadOnly = true;
			this->Hl2b_all->Width = 130;
			// 
			// Add
			// 
			this->Add->HeaderText = L"Добавленно";
			this->Add->Name = L"Add";
			this->Add->ReadOnly = true;
			this->Add->Width = 120;
			// 
			// Update
			// 
			this->Update->HeaderText = L"Обновленно";
			this->Update->Name = L"Update";
			this->Update->ReadOnly = true;
			this->Update->Width = 120;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 501);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1194, 540);
			this->MinimumSize = System::Drawing::Size(1194, 540);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Game Backloger";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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
	private: System::Void buttonDell_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonOpen_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: void readDB(String^ DBName);
	private: System::Void infoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {};
	private: System::Void openFileDialogSearch_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {};
	private:  String^ GetLink(String^ DBName, String^ id);
	
private: System::Void CreateBD_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}

private: System::Void buttonrefresh_Click(System::Object^ sender, System::EventArgs^ e);
};
}
