//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "wizyty_szczegoly.h"
#include "wizyty.h"
#include "datastructures.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWizytySzczegolyForm *WizytySzczegolyForm;
//---------------------------------------------------------------------------
__fastcall TWizytySzczegolyForm::TWizytySzczegolyForm(TComponent* Owner)
	: TForm(Owner)
{
	visitsRef=NULL;
	visitIndex=-1;
	incomesRef=NULL;
}
//---------------------------------------------------------------------------
void TWizytySzczegolyForm::ShowVisit(Visits* visits, Incomes* incomes, int i)
{
    incomesRef=incomes;
	visitsRef=visits;
	visitIndex=i;

	Visit v=visitsRef->get(i);

	imie->Text=String(v.getFirstName());
	nazwisko->Text=String(v.getLastName());
	dlugosc->Text=IntToStr(v.getDuration());
	notatki->Text=String(v.getNotes());

	TDateTime d = EncodeDate(v.getYear(), v.getMonth(), v.getDay());
	data->Date=d;

	TDateTime t = EncodeTime(v.getHour(), v.getMinutes(), 0, 0);
	godzina->Time=t;

    Show();

}
void __fastcall TWizytySzczegolyForm::edytujClick(TObject *Sender)
{
	imie->ReadOnly=false;
	nazwisko->ReadOnly=false;
	dlugosc->ReadOnly=false;
	notatki->ReadOnly=false;
	data->Enabled=true;
	godzina->Enabled=true;

	zapisz->Visible=true;
	usun->Visible=false;
	edytuj->Visible=false;
    zakoncz->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TWizytySzczegolyForm::zapiszClick(TObject *Sender)
{
	if(visitsRef==NULL || visitIndex==-1)
	{
		ShowMessage("Brak dostêpu do wizyty.");
		return;
	}

	if(imie->Text.Trim().IsEmpty() | nazwisko->Text.Trim().IsEmpty())
	{
		ShowMessage("Imiê i nazwisko nie mog¹ byæ puste.");
		return;
	}

	Word year, month, day;
	DecodeDate(data->Date, year, month, day);

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
		ShowMessage("Czas trwania musi byæ liczb¹.");
		return;
	}

	v.setNotes(AnsiString(notatki->Text).c_str());

	visitsRef->update(visitIndex, v);

	ShowMessage("Zmiany zapisane.");

	imie->ReadOnly=true;
	nazwisko->ReadOnly=true;
	dlugosc->ReadOnly=true;
	notatki->ReadOnly=true;
	data->Enabled=false;
	godzina->Enabled=false;

	zapisz->Visible=false;
	usun->Visible=true;
	edytuj->Visible=true;
	zakoncz->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TWizytySzczegolyForm::zakonczClick(TObject *Sender)
{
	if(MessageDlg("Czy wizyta na pewno zosta³a wykonana? Jeœli tak, zostanie przeniesiona do archiwum.",
	   mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		if(visitsRef==NULL || visitIndex==-1)
		{
			ShowMessage("Brak dostêpu do wizyty");
			return;
		}

		Visit v=visitsRef->get(visitIndex);

		UserSettings settings;
		settings.loadSettings();

		float zarobek = ((float)v.getDuration() / 60) * settings.getHourlyRate();

		Income in;
		in.setAmount(zarobek);
		in.setYear(v.getYear());
		in.setMonth(v.getMonth());

		if(incomesRef!=NULL)
		{
			incomesRef->addNew(in);
			incomesRef->saveIncome();
		}

		visitsRef->moveToArchive(visitIndex);

		ShowMessage("Wizyta zakoñczona.");
		Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TWizytySzczegolyForm::usunClick(TObject *Sender)
{
	if(visitsRef==NULL || visitIndex==-1)
	{
		ShowMessage("Brak dostêpu do wizyty");
	}

	if(MessageDlg("Czy na pewno chcesz usun¹æ wizytê?",
	   mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		visitsRef->remove(visitIndex);
		ShowMessage("Wizyta usuniêta.");
        Close();
	}

}
//---------------------------------------------------------------------------
