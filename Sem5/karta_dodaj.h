//---------------------------------------------------------------------------

#ifndef karta_dodajH
#define karta_dodajH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCalendars.hpp>
#include "datastructures.h"
#include "karta.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TKartaNowaForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *imie;
	TLabel *Label6;
	TLabel *Label7;
	TEdit *nazwisko;
	TLabel *Label8;
	TEdit *klasa;
	TButton *Zapisz;
	TMemo *notatki;
	TImage *Image1;
	void __fastcall ZapiszClick(TObject *Sender);
private:
	Students* studentsRef;
public:
	__fastcall TKartaNowaForm(TComponent* Owner);
    void setStudents(Students* students);
};
//---------------------------------------------------------------------------
extern PACKAGE TKartaNowaForm *KartaNowaForm;
//---------------------------------------------------------------------------
#endif
