//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "archiwum.h"
#include "datastructures.h"
#include "wizyty.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TArchiwumForm *ArchiwumForm;
//---------------------------------------------------------------------------
__fastcall TArchiwumForm::TArchiwumForm(TComponent* Owner)
	: TForm(Owner)
{
    visitsRef=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TArchiwumForm::powrotClick(TObject *Sender)
{
	WizytyForm->Show();
    Close();
}
//---------------------------------------------------------------------------
void TArchiwumForm::loadArchive()
{
	ListBox1->Items->Clear();

	if(visitsRef==NULL)
	{
		return;
	}

	for(int i=0; i<visitsRef->sizeArchive(); i++)
	{
		Visit v = visitsRef->getArchive(i);

		TDateTime data = EncodeDate(v.getYear(), v.getMonth(), v.getDay());
		TDateTime godz = EncodeTime(v.getHour(), v.getMinutes(), 0, 0);

		String date=FormatDateTime("dd.mm.yyyy", data);
		String hour=FormatDateTime("hh:mm", godz);

		String fullName=String(v.getFirstName()) + " " + String(v.getLastName());

		String arch=date + " " + hour + " - " + fullName + " (" + IntToStr(v.getDuration()) + " min)";

		ListBox1->Items->Add(arch);
    }
}


void __fastcall TArchiwumForm::FormShow(TObject *Sender)
{
	loadArchive();
}
//---------------------------------------------------------------------------
void TArchiwumForm::setVisits(Visits* visits)
{
    visitsRef=visits;
}
