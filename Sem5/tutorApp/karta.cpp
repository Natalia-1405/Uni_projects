//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "karta.h"
#include "projekt.h"
#include "finanse.h"
#include "statystyki.h"
#include "wizyty.h"
#include "datastructures.h"
#include "karta_dodaj.h"
#include "karta_szczegoly.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKartyForm *KartyForm;
//---------------------------------------------------------------------------
__fastcall TKartyForm::TKartyForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::menuClick(TObject *Sender)
{
    this->Close();
	MenuForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::wizytyClick(TObject *Sender)
{
    this->Close();
	WizytyForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::finanseClick(TObject *Sender)
{
	this->Close();
	FinanseForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::statystykiClick(TObject *Sender)
{
	this->Close();
	StatystykiForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    students.saveStudents();
}
//---------------------------------------------------------------------------

void TKartyForm::loadStudents()
{
	ListBox1->Items->Clear();
	for(int i=0; i<students.size(); i++)
	{
		Student s = students.get(i);
		String fullName = String(s.getFirstName()) + " " + String(s.getLastName());
		ListBox1->Items->Add(fullName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::nowakartaClick(TObject *Sender)
{
	KartaNowaForm->setStudents(&students);
	KartaNowaForm->ShowModal();
	loadStudents();
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::FormShow(TObject *Sender)
{
	students.loadStudents();
    loadStudents();
}
void __fastcall TKartyForm::ListBox1Click(TObject *Sender)
{
	int i = ListBox1->ItemIndex;
	if (i!=-1)
	{
		KartaSzczegolyForm -> ShowStudent(&students, i);
	}
}
//---------------------------------------------------------------------------

void __fastcall TKartyForm::FormActivate(TObject *Sender)
{
    loadStudents();
}
//---------------------------------------------------------------------------

