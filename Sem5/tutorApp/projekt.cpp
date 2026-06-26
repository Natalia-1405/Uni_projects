//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "wizyty.h"
#include "finanse.h"
#include "statystyki.h"
#include "karta.h"
#include "profil.h"


#include "projekt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMenuForm *MenuForm;
//---------------------------------------------------------------------------
__fastcall TMenuForm::TMenuForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::wizytyClick(TObject *Sender)
{
	 this->Hide();
	 WizytyForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::finanseClick(TObject *Sender)
{
	 this->Hide();
	 FinanseForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::statystykiClick(TObject *Sender)
{
	 this->Hide();
	 StatystykiForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::wyjscieClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------


void __fastcall TMenuForm::kartyClick(TObject *Sender)
{
	this->Hide();
    KartyForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMenuForm::profilClick(TObject *Sender)
{
	this->Hide();
    ProfilForm->Show();
}
//---------------------------------------------------------------------------

void TMenuForm::loadRecent()
{
	if(visits.size()>=0)
	{
		ListBox1->Items->Clear();

		for(int i=0; i<visits.size() && i<5; i++)
		{
			Visit v=visits.get(i);

			TDateTime data = EncodeDate(v.getYear(), v.getMonth(), v.getDay());
			TDateTime godz = EncodeTime(v.getHour(), v.getMinutes(), 0, 0);

			String date=FormatDateTime("dd.mm.yyyy", data);

			String hour=FormatDateTime("hh:mm", godz);

			String full = String(v.getFirstName()) + " " + String(v.getLastName());

			String dl =  IntToStr(v.getDuration());

			String wizyta = date + " " + hour + " - " + full + " (" + dl + " min)";

			ListBox1->Items->Add(wizyta);
		}
	}
}
void __fastcall TMenuForm::FormShow(TObject *Sender)
{
	visits.loadVisits();
	loadRecent();
}
//---------------------------------------------------------------------------

