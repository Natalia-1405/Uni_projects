//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "profil.h"
#include "projekt.h"
#include "datastructures.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProfilForm *ProfilForm;
//---------------------------------------------------------------------------
__fastcall TProfilForm::TProfilForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TProfilForm::PowrotClick(TObject *Sender)
{
	this->Close();
    MenuForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TProfilForm::FormShow(TObject *Sender)
{
	UserSettings settings;
	settings.loadSettings();

	Imie->Text=settings.getUserName();
	Stawka->Text=FloatToStr(settings.getHourlyRate());
}
//---------------------------------------------------------------------------

void __fastcall TProfilForm::FormClose(TObject *Sender, TCloseAction &Action)
{
	UserSettings settings;
	settings.setUserName(AnsiString(Imie->Text).c_str());

	try
	{
        settings.setHourlyRate(StrToFloat(Stawka->Text));
	}
	catch (...)
	{
        settings.setHourlyRate(0.0);
    }

	settings.saveSettings();
}
//---------------------------------------------------------------------------

