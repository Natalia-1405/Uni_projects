//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "karta_szczegoly.h"
#include "datastructures.h"
#include "karta.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKartaSzczegolyForm *KartaSzczegolyForm;
//---------------------------------------------------------------------------
__fastcall TKartaSzczegolyForm::TKartaSzczegolyForm(TComponent* Owner)
	: TForm(Owner)
{
	studentsRef = NULL;
	studentIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TKartaSzczegolyForm::edytujClick(TObject *Sender)
{
	imie->ReadOnly = false;
	nazwisko->ReadOnly = false;
	klasa->ReadOnly = false;
	notatki->ReadOnly = false;

	zapisz->Visible = true;
	usun->Visible = false;
	edytuj->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TKartaSzczegolyForm::usunClick(TObject *Sender)
{
	if(studentsRef == NULL || studentIndex==-1)
	{
		ShowMessage("Brak dostêpu do ucznia.");
		return;
	}

	if(MessageDlg("Czy napewno chcesz usun¹æ ucznia?",
	   mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		studentsRef->remove(studentIndex);
		ShowMessage("Uczeñ usuniêty.");
		KartyForm->Show();
        this->Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TKartaSzczegolyForm::zapiszClick(TObject *Sender)
{
	if(studentsRef == NULL || studentIndex==-1)
	{
		ShowMessage("Brak dostêpu do ucznia.");
		return;
	}

	Student s;
	s.setFirstName(AnsiString(imie->Text).c_str());
	s.setLastName(AnsiString(nazwisko->Text).c_str());
	s.setClassName(AnsiString(klasa->Text).c_str());
	s.setNotes(AnsiString(notatki->Text).c_str());

	studentsRef->update(studentIndex, s);

	ShowMessage("Zapisano.");
	imie->ReadOnly = true;
	nazwisko->ReadOnly = true;
	klasa->ReadOnly = true;
	notatki->ReadOnly = true;

	zapisz->Visible = false;
	usun->Visible = true;
	edytuj->Visible = true;

}
//---------------------------------------------------------------------------

void TKartaSzczegolyForm::ShowStudent(Students* students, int i)
{
	studentsRef=students;
	studentIndex = i;

	Student s = students->get(i);
	imie->Text=String(s.getFirstName());
	nazwisko->Text=String(s.getLastName());
	klasa->Text=String(s.getClassName());
	notatki->Text=String(s.getNotes());

    Show();
}