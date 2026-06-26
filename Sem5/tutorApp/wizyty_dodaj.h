//---------------------------------------------------------------------------

#ifndef wizyty_dodajH
#define wizyty_dodajH
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
class TWizytyNowaForm : public TForm
{
__published:	// IDE-managed Components
	TDateTimePicker *Data;
	TEdit *imie;
	TEdit *nazwisko;
	TDateTimePicker *godzina;
	TEdit *dlugosc;
	TMemo *notatki;
	TButton *zapisz;
	TImage *Image1;
	void __fastcall zapiszClick(TObject *Sender);
private:	// User declarations
   Visits* visitsRef;
public:		// User declarations
	__fastcall TWizytyNowaForm(TComponent* Owner);
    void SetVisits(Visits* visits);
};
//---------------------------------------------------------------------------
extern PACKAGE TWizytyNowaForm *WizytyNowaForm;
//---------------------------------------------------------------------------
#endif
