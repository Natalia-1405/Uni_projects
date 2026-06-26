//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "karta_dodaj.h"
#include "datastructures.h"
#include "karta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKartaNowaForm *KartaNowaForm;
//---------------------------------------------------------------------------
__fastcall TKartaNowaForm::TKartaNowaForm(TComponent* Owner)
	: TForm(Owner)
{
	studentsRef=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TKartaNowaForm::ZapiszClick(TObject *Sender)
{
	if(studentsRef==NULL)
	{
		ShowMessage("Brak dostêpu do listy.");
		return;
	}

	if (imie->Text.Trim().IsEmpty() || nazwisko->Text.Trim().IsEmpty())
	{
	   ShowMessage("Imiê i nazwisko nie mog¹ byæ puste.");
	   return;
	}

	if (klasa->Text.Trim().IsEmpty())
	{
		ShowMessage("Klasa nie mo¿e byæ pusta.");
        return;
    }

	Student s;
	s.setFirstName(AnsiString(imie->Text).c_str());
	s.setLastName(AnsiString(nazwisko->Text).c_str());
	s.setClassName(AnsiString(klasa->Text).c_str());
	s.setNotes(AnsiString(notatki->Text).c_str());

	studentsRef->addNew(s);

	ShowMessage("Dodano.");
    Close();

}
//---------------------------------------------------------------------------

void TKartaNowaForm::setStudents(Students* students)
{
    studentsRef=students;

}