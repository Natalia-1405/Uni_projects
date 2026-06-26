//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "finanse.h"
#include "projekt.h"
#include "statystyki.h"
#include "karta.h"
#include "wizyty.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFinanseForm *FinanseForm;
//---------------------------------------------------------------------------
__fastcall TFinanseForm::TFinanseForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFinanseForm::menuClick(TObject *Sender)
{
	 this->Close();
	 MenuForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFinanseForm::wizytyClick(TObject *Sender)
{
	 this->Close();
	 WizytyForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFinanseForm::statystykiClick(TObject *Sender)
{
	 this->Close();
	 StatystykiForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFinanseForm::kartyClick(TObject *Sender)
{
	 this->Close();
	 KartyForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFinanseForm::wyjscieClick(TObject *Sender)
{
	Close();
}

//---------------------------------------------------------------------------
void TFinanseForm::updateQuarters()
{
	Word year, month, day;
	DecodeDate(Now(), year, month, day);

	tytul->Caption = IntToStr(year);

	float limit=10000;

	float k1 = incomes.getQuarterTotal(year, 1);
	kwartal1->Caption = "1. kwarta³ = " + FloatToStrF(k1, ffFixed, 7, 2) + "z³/10 000z³";
	float k2 = incomes.getQuarterTotal(year, 2);
	kwartal2->Caption = "2. kwarta³ = " + FloatToStrF(k2, ffFixed, 7, 2) + "z³/10 000z³";
	float k3 = incomes.getQuarterTotal(year, 3);
	kwartal3->Caption = "3. kwarta³ = " + FloatToStrF(k3, ffFixed, 7, 2) + "z³/10 000z³";
	float k4 = incomes.getQuarterTotal(year, 4);
	kwartal4->Caption = "4. kwarta³ = " + FloatToStrF(k4, ffFixed, 7, 2) + "z³/10 000z³";
	float r = incomes.getTotal(year);
	rok->Caption = "Ca³y rok: " + FloatToStrF(r, ffFixed, 7, 2) + "z³";
	if(k1>9000)
	{
		kwartal1->Font->Color=clRed;
	}
	else
	{
		kwartal1->Font->Color=clBlack;
	}

	if(k2>9000)
	{
		kwartal2->Font->Color=clRed;
	}
	else
	{
		kwartal2->Font->Color=clBlack;
	}

	if(k3>9000)
	{
		kwartal3->Font->Color=clRed;
	}
	else
	{
		kwartal3->Font->Color=clBlack;
	}

	if(k4>9000)
	{
		kwartal4->Font->Color=clRed;
	}
	else
	{
		kwartal4->Font->Color=clBlack;
	}

}

void __fastcall TFinanseForm::FormShow(TObject *Sender)
{
	incomes.loadIncome();
	updateQuarters();
}
//---------------------------------------------------------------------------


