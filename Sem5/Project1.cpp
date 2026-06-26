//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("projekt.cpp", MenuForm);
USEFORM("statystyki.cpp", StatystykiForm);
USEFORM("wizyty.cpp", WizytyForm);
USEFORM("finanse.cpp", FinanseForm);
USEFORM("karta.cpp", KartyForm);
USEFORM("profil.cpp", ProfilForm);
USEFORM("karta_dodaj.cpp", KartaNowaForm);
USEFORM("karta_szczegoly.cpp", KartaSzczegolyForm);
USEFORM("wizyty_szczegoly.cpp", WizytySzczegolyForm);
USEFORM("wizyty_dodaj.cpp", WizytyNowaForm);
USEFORM("archiwum.cpp", ArchiwumForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TMenuForm), &MenuForm);
		Application->CreateForm(__classid(TWizytyForm), &WizytyForm);
		Application->CreateForm(__classid(TStatystykiForm), &StatystykiForm);
		Application->CreateForm(__classid(TFinanseForm), &FinanseForm);
		Application->CreateForm(__classid(TKartyForm), &KartyForm);
		Application->CreateForm(__classid(TProfilForm), &ProfilForm);
		Application->CreateForm(__classid(TKartaNowaForm), &KartaNowaForm);
		Application->CreateForm(__classid(TKartaSzczegolyForm), &KartaSzczegolyForm);
		Application->CreateForm(__classid(TWizytySzczegolyForm), &WizytySzczegolyForm);
		Application->CreateForm(__classid(TWizytyNowaForm), &WizytyNowaForm);
		Application->CreateForm(__classid(TArchiwumForm), &ArchiwumForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
