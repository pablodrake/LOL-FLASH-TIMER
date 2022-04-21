#pragma once
#pragma comment(lib, "user32.lib")
#include <string>
#include "resource.h"
#include <Windows.h>
#include <winuser.h>
#include <msclr/marshal_cppstd.h>
using namespace msclr::interop;


namespace FlashTimer1 {
	INPUT ip;
	HWND handle = FindWindowA(NULL, "ALEJANDRO DEJA INSTAGRAM");

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	/// 
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: bool dragging;
	private: Point offset;
		   static const int CD_BOTH = 230;
		   static const int CD_BOOTS = 268;
		   static const int CD_RUNES = 254;
		   static const int CD_DEFAULT = 300;
	public: System::Drawing::Image^ cosmicoff = getImageFromRes(IDB_PNG1);
		System::Drawing::Image^ cosmic = getImageFromRes(IDB_PNG2);
		System::Drawing::Image^ flash = getImageFromRes(IDB_PNG3);
		System::Drawing::Image^ flashoff = getImageFromRes(IDB_PNG4);
		System::Drawing::Image^ bootsoff = getImageFromRes(IDB_PNG5);
		System::Drawing::Image^ boots = getImageFromRes(IDB_PNG6);
		System::String^ topUp = "TOP UP";
		System::String^ jngUp = "JNG UP";
		System::String^ midUp = "MID UP";
		System::String^ adcUp = "ADC UP";
		System::String^ suppUp = "SUPP UP";
		bool isVisible = true;
		int flashCd1 = 0;
		int flashCd2 = 0;
		int flashCd3 = 0;
		int flashCd4 = 0;
		int flashCd5 = 0;
		int flashCd6 = 0;
	public: bool isButton1Off = false;
		bool isButton2Off = false;
		bool isButton3Off = false;
		bool isButton4Off = false;
		bool isButton5Off = false;
		bool isButton6Off = false;
		bool isButton7Off = false;
		bool isButton8Off = false;
		bool isButton9Off = false;
		bool isButton10Off = false;
		bool isButton11Off = false;
		bool isButton12Off = false;
		bool isButton13Off = false;
		bool isButton14Off = false;
	private: System::Windows::Forms::Label^ label5;
	public:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button16;

		   bool isButton15Off = false;

		   void pressKey(CHAR key)
		   {

			   Sleep(10);
			   ip.type = INPUT_KEYBOARD;
			   ip.ki.time = 0;
			   ip.ki.dwFlags = KEYEVENTF_UNICODE;
			   ip.ki.wScan = key;
			   ip.ki.wVk = 0;
			   ip.ki.dwExtraInfo = 0;
			   SendInput(1, &ip, sizeof(INPUT));
		   }

		   int calculateCd(bool boots, bool runes) {
			   if (boots && runes) {
				   return CD_BOTH;
			   }
			   else if (runes) {
				   return CD_RUNES;
			   }
			   else if (boots) {
				   return CD_BOOTS;
			   }
			   else {
				   return CD_DEFAULT;
			   }
			   
		   }


	public: void imageController(System::Windows::Forms::Button^ butt, bool %isButton, System::Drawing::Image^ imageon, System::Drawing::Image^ imageoff){

		if (isButton == false) {
			butt->BackgroundImage = imageoff;
			isButton = true;
		}
		else if (isButton == true) {
			butt->BackgroundImage = imageon;
			isButton = false;

		}
	}
		  void timerController()
		  {
			  if (isButton1Off) {
				  if (flashCd1 == 0) {
					  flashCd1 = calculateCd(isButton6Off, isButton7Off);
					  label6->Text = flashCd1.ToString() + "s";
				  }
				  else {
					  flashCd1--;
					  label6->Text = flashCd1.ToString() + "s";
				  }
			  }
			  else {
				  label6->Text = topUp;
				  flashCd1 = 0;
			  }
			  if (isButton2Off) {
				  if (flashCd2 == 0) {
					  flashCd2 = calculateCd(isButton8Off, isButton9Off);
					  label7->Text = flashCd2.ToString() + "s";
				  }
				  else {
					  flashCd2--;
					  label7->Text = flashCd2.ToString() + "s";
				  }
			  }
			  else {
				  label7->Text = jngUp;
				  flashCd2 = 0;
			  }
			  if (isButton3Off) {
				  if (flashCd3 == 0) {
					  flashCd3 = calculateCd(isButton10Off, isButton11Off);
					  label8->Text = flashCd3.ToString() + "s";
				  }
				  else {
					  flashCd3--;
					  label8->Text = flashCd3.ToString() + "s";
				  }
			  }
			  else {
				  label8->Text = midUp;
				  flashCd3 = 0;
			  }
			  if (isButton4Off) {
				  if (flashCd4 == 0) {
					  flashCd4 = calculateCd(isButton12Off, isButton13Off);
					  label9->Text = flashCd4.ToString() + "s";
				  }
				  else {
					  flashCd4--;
					  label9->Text = flashCd4.ToString() + "s";
				  }
			  }
			  else {
				  label9->Text = adcUp;
				  flashCd4 = 0;
			  }
			  if (isButton5Off) {
				  if (flashCd5 == 0) {
					  flashCd5 = calculateCd(isButton14Off, isButton15Off);
					  label10->Text = flashCd5.ToString() + "s";
				  }
				  else {
					  flashCd5--;
					  label10->Text = flashCd5.ToString() + "s";
				  }
			  }
			  else {
				  label10->Text = suppUp;
				  flashCd5 = 0;
			  }
			  if (flashCd1 == 1) {
				  imageController(button1, isButton1Off, flash, flashoff);
			  }
			  if (flashCd2 == 1) {
				  imageController(button2, isButton2Off, flash, flashoff);
			  }
			  if (flashCd3 == 1) {
				  imageController(button3, isButton3Off, flash, flashoff);
			  }
			  if (flashCd4 == 1) {
				  imageController(button4, isButton4Off, flash, flashoff);
			  }
			  if (flashCd5 == 1) {
				  imageController(button5, isButton5Off, flash, flashoff);
			  }
		  }


	private: System::Windows::Forms::Timer^ timer1;



		public: System::Drawing::Image^  getImageFromRes(long resource_ID) {
    // Function getImageFromRes
    // A function for loading PNG images from resources in C++ CLR/CLI
    // Copyright (C) Giuseppe Pischedda 2007 for most code
    // and a little part of this code by Bordon and adapted by me for PNG images in C++ CLR/CLI.

    //Load the resource module:
    HMODULE hInst = NULL;

    // Find the resource using the resource ID from file "resource.h"
    HRSRC hResource = ::FindResource(hInst, MAKEINTRESOURCE(resource_ID), L"PNG");
    if (!hResource) return nullptr;

    // Load the resource and save the total size.
    DWORD Size = SizeofResource(hInst, hResource);
    HGLOBAL MemoryHandle = LoadResource(hInst, hResource);
    if (MemoryHandle == NULL) return nullptr;

    //Create a cli::array of byte with size = total size + 2
    cli::array<BYTE>^  MemPtr = gcnew array<BYTE>(Size + 2);

    //Cast from LPVOID to char *
    char *lkr = (char *) (LockResource(MemoryHandle));

    //Copy from unmanaged memory to managed array
    System::Runtime::InteropServices::Marshal::Copy((IntPtr) lkr, MemPtr, 0, Size);

    // Create a new MemoryStream with size = MemPtr
    System::IO::MemoryStream^  stream = gcnew System::IO::MemoryStream(MemPtr);

    //Write in the MemoryStream
    stream->Write(MemPtr, 0, Size);

    //Set the position for read the stream
    stream->Position = 0;

    //Free allocated resources
    FreeLibrary(hInst);

    //Create an Image abstract class pointer
    System::Drawing::Image^  ptrPNG;

    //Assign the stream to abstract class pointer
    ptrPNG = System::Drawing::Image::FromStream(stream);
    return ptrPNG;
}


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}







	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;

	private: System::Windows::Forms::Button^ button14;

	private: System::Windows::Forms::Button^ button12;

	private: System::Windows::Forms::Button^ button10;

	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button6;

	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Button^ button4;
	public: System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button9;
	public: System::Windows::Forms::Button^ button1;
private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 2);
			this->tableLayoutPanel1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->tableLayoutPanel1->Location = System::Drawing::Point(10, 22);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(102, 202);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label5->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 160);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 38);
			this->label5->TabIndex = 5;
			this->label5->Text = L"SUPP";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 38);
			this->label2->TabIndex = 1;
			this->label2->Text = L"JNG";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TOP";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label3->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 38);
			this->label3->TabIndex = 4;
			this->label3->Text = L"ADC";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Myanmar Text", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(3, 80);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 38);
			this->label4->TabIndex = 3;
			this->label4->Text = L"MID";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tableLayoutPanel2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->tableLayoutPanel2->ColumnCount = 3;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel2->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button7, 2, 0);
			this->tableLayoutPanel2->Controls->Add(this->button15, 2, 4);
			this->tableLayoutPanel2->Controls->Add(this->button14, 1, 4);
			this->tableLayoutPanel2->Controls->Add(this->button13, 2, 3);
			this->tableLayoutPanel2->Controls->Add(this->button12, 1, 3);
			this->tableLayoutPanel2->Controls->Add(this->button11, 2, 2);
			this->tableLayoutPanel2->Controls->Add(this->button10, 1, 2);
			this->tableLayoutPanel2->Controls->Add(this->button9, 2, 1);
			this->tableLayoutPanel2->Controls->Add(this->button8, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->button6, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->button3, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->button4, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->button5, 0, 4);
			this->tableLayoutPanel2->Controls->Add(this->button2, 0, 1);
			this->tableLayoutPanel2->Location = System::Drawing::Point(98, 22);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 5;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(127, 205);
			this->tableLayoutPanel2->TabIndex = 3;
			this->tableLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tableLayoutPanel2_Paint);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 35);
			this->button1->TabIndex = 15;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Transparent;
			this->button7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.BackgroundImage")));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button7->Location = System::Drawing::Point(97, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(27, 35);
			this->button7->TabIndex = 14;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button15
			// 
			this->button15->BackColor = System::Drawing::Color::Transparent;
			this->button15->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button15.BackgroundImage")));
			this->button15->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button15->FlatAppearance->BorderSize = 0;
			this->button15->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button15->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button15->Location = System::Drawing::Point(97, 167);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(27, 35);
			this->button15->TabIndex = 13;
			this->button15->UseVisualStyleBackColor = false;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button14
			// 
			this->button14->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button14.BackgroundImage")));
			this->button14->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button14->FlatAppearance->BorderSize = 0;
			this->button14->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button14->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Location = System::Drawing::Point(66, 167);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(25, 35);
			this->button14->TabIndex = 12;
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button13
			// 
			this->button13->BackColor = System::Drawing::Color::Transparent;
			this->button13->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button13.BackgroundImage")));
			this->button13->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button13->FlatAppearance->BorderSize = 0;
			this->button13->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button13->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button13->Location = System::Drawing::Point(97, 126);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(27, 35);
			this->button13->TabIndex = 11;
			this->button13->UseVisualStyleBackColor = false;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button12
			// 
			this->button12->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button12.BackgroundImage")));
			this->button12->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button12->FlatAppearance->BorderSize = 0;
			this->button12->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button12->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Location = System::Drawing::Point(66, 126);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(25, 35);
			this->button12->TabIndex = 10;
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::Color::Transparent;
			this->button11->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button11.BackgroundImage")));
			this->button11->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button11->FlatAppearance->BorderSize = 0;
			this->button11->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button11->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button11->Location = System::Drawing::Point(97, 85);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(27, 35);
			this->button11->TabIndex = 9;
			this->button11->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button10
			// 
			this->button10->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button10.BackgroundImage")));
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button10->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Location = System::Drawing::Point(66, 85);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(25, 35);
			this->button10->TabIndex = 8;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::Transparent;
			this->button9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.BackgroundImage")));
			this->button9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button9->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button9->Location = System::Drawing::Point(97, 44);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(27, 35);
			this->button9->TabIndex = 7;
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Location = System::Drawing::Point(66, 44);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(25, 35);
			this->button8->TabIndex = 6;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button6
			// 
			this->button6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(66, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(25, 35);
			this->button6->TabIndex = 4;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(3, 85);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(45, 35);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.BackgroundImage")));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(3, 126);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(45, 35);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(3, 167);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(45, 35);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(3, 44);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(45, 35);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(225, 34);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(63, 16);
			this->label6->TabIndex = 4;
			this->label6->Text = L"TOP UP";
			this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(225, 75);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(62, 16);
			this->label7->TabIndex = 5;
			this->label7->Text = L"JNG UP";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(225, 116);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 16);
			this->label8->TabIndex = 6;
			this->label8->Text = L"MID UP";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(225, 157);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 16);
			this->label9->TabIndex = 7;
			this->label9->Text = L"ADC UP";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(226, 198);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(73, 16);
			this->label10->TabIndex = 8;
			this->label10->Text = L"SUPP UP";
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(286, 3);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(18, 20);
			this->button16->TabIndex = 9;
			this->button16->Text = L"X";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(307, 247);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ALEJANDRO DEJA INSTAGRAM";
			this->TopMost = true;
			this->TransparencyKey = System::Drawing::SystemColors::ButtonFace;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->dragging = false;

	}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button7, isButton7Off, cosmicoff, cosmic);
}	
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button11, isButton11Off, cosmicoff, cosmic);
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button9, isButton9Off, cosmicoff, cosmic);
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button13, isButton13Off, cosmicoff, cosmic);
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button15, isButton15Off, cosmicoff, cosmic);
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	imageController(button1, isButton1Off, flash, flashoff);
}
private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button2, isButton2Off, flash, flashoff);
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	if (GetKeyState(VK_SHIFT) && GetKeyState(VK_F1) & 0x8000) {
		imageController(button1, isButton1Off, flash, flashoff);
		Sleep(130);
	}
	if (GetKeyState(VK_SHIFT) && GetKeyState(VK_F2) & 0x8000) {
		imageController(button2, isButton2Off, flash, flashoff);
		Sleep(130);
	}
	if (GetKeyState(VK_SHIFT) && GetKeyState(VK_F3) & 0x8000) {
		imageController(button3, isButton3Off, flash, flashoff);
		Sleep(130);
	}
	if (GetKeyState(VK_SHIFT) && GetKeyState(VK_F4) & 0x8000) {
		imageController(button4, isButton4Off, flash, flashoff);
		Sleep(130);
	}
	if (GetKeyState(VK_SHIFT) && GetKeyState(VK_F5) & 0x8000) {
		imageController(button5, isButton5Off, flash, flashoff);
		Sleep(130);
	}
	if (GetKeyState(VK_CONTROL) && GetKeyState('X') & 0x8000) {
		System::String^ phrase = label6->Text + ", " + label7->Text + ", " + label8->Text + ", " + label9->Text + ", " + label10->Text;
		char chars[40] = { 0 };
		if (phrase->Length < sizeof(chars)) // make sure it fits & allow space for null terminator
		{
			for (int i = 0; i < phrase->Length; i++)
				chars[i] = static_cast<CHAR>(phrase[i]);
		}
		for (CHAR i : chars) {
			pressKey(i);
		}
		Sleep(50);
		keybd_event(VK_RETURN, 0, 0, 0);
		Sleep(50);
		keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	}




	if (GetKeyState(VK_CONTROL) && GetKeyState(VK_F10) & 0x8000) {
		if (isVisible) {
			MyForm::Hide();
			isVisible = false;
		}
		else {
			
			MyForm::Show();
			MyForm::TopLevel = true;
			isVisible = true;
		}
		Sleep(130);
	}

	if (GetKeyState(VK_CONTROL) && GetKeyState(VK_F12) & 0x8000){
		Close();
	}


}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button3, isButton3Off, flash, flashoff);
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button4, isButton4Off, flash, flashoff);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button5, isButton5Off, flash, flashoff);
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button6, isButton6Off, bootsoff, boots);
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button8, isButton8Off, bootsoff, boots);
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button10, isButton10Off, bootsoff, boots);
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button12, isButton12Off, bootsoff, boots);
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
	imageController(button14, isButton14Off, bootsoff, boots);
}
private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = true;
	this->offset = Point(e->X, e->Y);
}
private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (this->dragging) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - this->offset.X, currentScreenPos.Y - this->offset.Y);
	}
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	this->dragging = false;
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {

	timerController();

}

private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
};
}
