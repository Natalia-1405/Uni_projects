//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "projekt.h"
#include "finanse.h"
#include "statystyki.h"
#include "karta.h"
#include "wizyty.h"
#include "wizyty_szczegoly.h"
#include "wizyty_dodaj.h"
#include "archiwum.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWizytyForm *WizytyForm;
//---------------------------------------------------------------------------
__fastcall TWizytyForm::TWizytyForm(TComponent* Owner)
	: TForm(Owner)
{
	 
}
//---------------------------------------------------------------------------
void __fastcall TWizytyForm::menuClick(TObject *Sender)
{
	 this->Close();
	 MenuForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TWizytyForm::finanseClick(TObject *Sender)
{
	 this->Close();
	 FinanseForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TWizytyForm::statystykiClick(TObject *Sender)
{
	 this->Close();
	 StatystykiForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TWizytyForm::kartyClick(TObject *Sender)
{
	 this->Close();
	 KartyForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TWizytyForm::FormClose(TObject *Sender, TCloseAction &Action)
{
     visits.saveVisits();
}
//---------------------------------------------------------------------------
void __fastcall TWizytyForm::dodajnoweClick(TObject *Sender)
{
	WizytyNowaForm->SetVisits(&visits);
	WizytyNowaForm->ShowModal();
	loadVisits();
}
//---------------------------------------------------------------------------


void __fastcall TWizytyForm::FormShow(TObject *Sender)
{
	visits.loadVisits();
    loadVisits();
}
//---------------------------------------------------------------------------

void TWizytyForm::loadVisits()
{
	ListBox1->Items->Clear();

	for(int i=0; i<visits.size(); i++)
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
void __fastcall TWizytyForm::ListBox1Click(TObject *Sender)
{
	int i=ListBox1->ItemIndex;
	if(i!=-1)
	{
		WizytySzczegolyForm->ShowVisit(&visits, &incomes, i);
	}
}
//---------------------------------------------------------------------------

void __fastcall TWizytyForm::FormActivate(TObject *Sender)
{
	loadVisits();
    incomes.loadIncome();
}
//---------------------------------------------------------------------------

void __fastcall TWizytyForm::archiwumClick(TObject *Sender)
{
	ArchiwumForm->setVisits(&visits);
    ArchiwumForm->Show();
}
//---------------------------------------------------------------------------

