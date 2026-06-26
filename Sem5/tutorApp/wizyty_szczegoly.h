//---------------------------------------------------------------------------

#ifndef wizyty_szczegolyH
#define wizyty_szczegolyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "datastructures.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TWizytySzczegolyForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TLabel *Label1;
	TLabel *Label5;
	TLabel *Label2;
	TLabel *Label4;
	TLabel *label9;
	TLabel *Label8;
	TEdit *imie;
	TEdit *nazwisko;
	TDateTimePicker *data;
	TDateTimePicker *godzina;
	TEdit *dlugosc;
	TMemo *notatki;
	TButton *zapisz;
	TButton *edytuj;
	TButton *zakoncz;
	TButton *usun;
	TImage *Image1;
	void __fastcall edytujClick(TObject *Sender);
	void __fastcall zapiszClick(TObject *Sender);
	void __fastcall zakonczClick(TObject *Sender);
	void __fastcall usunClick(TObject *Sender);
private:
	Visits* visitsRef;
    Incomes* incomesRef;
    int visitIndex;
public:		// User declarations
	__fastcall TWizytySzczegolyForm(TComponent* Owner);
    void ShowVisit(Visits* visits, Incomes* incomes, int i);
};
//---------------------------------------------------------------------------
extern PACKAGE TWizytySzczegolyForm *WizytySzczegolyForm;
//---------------------------------------------------------------------------
#endif
