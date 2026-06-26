//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "statystyki.h"
#include "projekt.h"
#include "finanse.h"
#include "karta.h"
#include "wizyty.h"
#include "datastructures.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TStatystykiForm *StatystykiForm;
//---------------------------------------------------------------------------
__fastcall TStatystykiForm::TStatystykiForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TStatystykiForm::menuClick(TObject *Sender)
{
	MenuForm->Show();
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TStatystykiForm::wizytyClick(TObject *Sender)
{
	WizytyForm->Show();
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TStatystykiForm::finanseClick(TObject *Sender)
{
	FinanseForm->Show();
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TStatystykiForm::kartyClick(TObject *Sender)
{
	KartyForm->Show();
    this->Close();
}
//---------------------------------------------------------------------------

void TStatystykiForm::updateStats()
{
    Word year, month, day;
	DecodeDate(Now(), year, month, day);
	int m=0;

	tytul->Caption = IntToStr(year);
	m = visits.getMonthly(year, 1);
	styczen->Caption = "Styczeñ: " + IntToStr(m);
	m = visits.getMonthly(year, 2);
	luty->Caption = "Luty: " + IntToStr(m);
	m = visits.getMonthly(year, 3);
	marzec->Caption = "Marzec: " + IntToStr(m);
	m = visits.getMonthly(year, 4);
	kwiecien->Caption = "Kwiecieñ: " + IntToStr(m);
	m = visits.getMonthly(year, 5);
	maj->Caption = "Maj: " + IntToStr(m);
	m = visits.getMonthly(year, 6);
	czerwiec->Caption = "Czerwiec: " + IntToStr(m);
	m = visits.getMonthly(year, 7);
	lipiec->Caption = "Lipiec: " + IntToStr(m);
	m = visits.getMonthly(year, 8);
	sierpien->Caption = "Sierpieñ: " + IntToStr(m);
	m = visits.getMonthly(year, 9);
	wrzesien->Caption = "Wrzesieñ: " + IntToStr(m);
	m = visits.getMonthly(year, 10);
	pazdz->Caption = "PaŸdziernik: " + IntToStr(m);
	m = visits.getMonthly(year, 11);
	listo->Caption = "Listopad: " + IntToStr(m);
	m = visits.getMonthly(year, 12);
	grudzien->Caption = "Grudzieñ: " + IntToStr(m);
	m = visits.getTotal(year);
	rok->Caption = "Ca³y rok: " + IntToStr(m);
}
void __fastcall TStatystykiForm::FormShow(TObject *Sender)
{
	visits.loadVisits();
    updateStats();
}
//---------------------------------------------------------------------------


