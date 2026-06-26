//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wizyty_dodaj.h"
#include "datastructures.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWizytyNowaForm *WizytyNowaForm;
//---------------------------------------------------------------------------
__fastcall TWizytyNowaForm::TWizytyNowaForm(TComponent* Owner)
	: TForm(Owner)
{
	visitsRef=NULL;
}
//---------------------------------------------------------------------------
void TWizytyNowaForm::SetVisits(Visits* visits)
{
    visitsRef=visits;

}
//---------------------------------------------------------------------------
void __fastcall TWizytyNowaForm::zapiszClick(TObject *Sender)
{
	if(visitsRef==NULL)
	{
		ShowMessage("Brak dostêpu do listy wizyt.");
		return;
	}

	if(imie->Text.Trim().IsEmpty() | nazwisko->Text.Trim().IsEmpty())
	{
		ShowMessage("Imiê i nazwisko nie mog¹ byæ puste.");
		return;
	}

	Word year, month, day;
	DecodeDate(Data->Date, year, month, day);

	Word hour, minute, second, msec;
	DecodeTime(godzina->Time, hour, minute, second, msec);

	Visit v;

	v.setFirstName(AnsiString(imie->Text).c_str());
	v.setLastName(AnsiString(nazwisko->Text).c_str());
	v.setYear(year);
	v.setMonth(month);
	v.setDay(day);
	v.setHour(hour);
	v.setMinutes(minute);

	try
	{
		v.setDuration(StrToInt(dlugosc->Text));
	}
	catch(...)
	{
		ShowMessage("Czas trwania musi byæ liczb¹ ca³kowit¹.");
		return;
	}

	v.setNotes(AnsiString(notatki->Text).c_str());

	visitsRef->addNew(v);

	ShowMessage("Wizyta dodana.");
	Close();
}
//---------------------------------------------------------------------------
