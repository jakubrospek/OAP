#pragma once

namespace WindowsFormApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(892, 388);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
		{
			 Form^ okno = gcnew Form;
             okno->Height=200;
             okno->Width=200;
             okno->FormClosing+=
             gcnew FormClosingEventHandler(this,&Form1::okno_FormClosing);
			 TextBox^ login = gcnew TextBox;
             TextBox^ haslo = gcnew TextBox;
             login->Location=Point(80,30);
			 haslo->Location=Point(80,60);
             haslo->PasswordChar='*';
             Button^ przycisk1 = gcnew Button;
             przycisk1->Click += gcnew EventHandler(this,&Form1::przycisk1_Click);
             przycisk1->Location=Point(10,100);
             przycisk1->Text="OK";
			 Button^ przycisk2 = gcnew Button;
             przycisk2->Click += gcnew EventHandler(this,&Form1::przycisk2_Click);
             przycisk2->Location=Point(100,100);
             przycisk2->Text="WyjdŸ";
             Label^ etykieta1 = gcnew Label;
			 Label^ etykieta2 = gcnew Label;
             etykieta1->Text="Login:";
             etykieta1->Location=Point(10,30);
			 etykieta2->Text="Haslo:";
             etykieta2->Location=Point(10,60);
			 okno->Controls->Add(login);
			 okno->Controls->Add(haslo);
             okno->Controls->Add(etykieta1);
			 okno->Controls->Add(etykieta2);
			 okno->Controls->Add(przycisk1);
			 okno->Controls->Add(przycisk2);
             okno->ShowDialog();
		}

		private: System::Void okno_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
             if (((((Form^)sender)->Controls[1]->Text)!="Haslo")||((((Form^)sender)->Controls[0]->Text)!="Login"))
			 {
                e->Cancel=true;
				MessageBox::Show("B³êdny Login lub Has³o!"); 
         
			 }
             else
			 {
                e->Cancel=false;
			 }
		}

		private: System::Void przycisk1_Click(System::Object^  sender, System::EventArgs^  e)
		{
				((Form^)((Button^)sender)->Parent)->Close();
		}

		private: System::Void przycisk2_Click(System::Object^  sender, System::EventArgs^  e)
		{
				 Close();
		}

	};
}

