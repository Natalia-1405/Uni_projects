//---------------------------------------------------------------------------

#ifndef karta_szczegolyH
#define karta_szczegolyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "datastructures.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TKartaSzczegolyForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label8;
	TEdit *imie;
	TEdit *nazwisko;
	TEdit *klasa;
	TMemo *notatki;
	TButton *zapisz;
	TButton *edytuj;
	TButton *usun;
	TImage *Image1;
	void __fastcall edytujClick(TObject *Sender);
	void __fastcall usunClick(TObject *Sender);
	void __fastcall zapiszClick(TObject *Sender);
private:	// User declarations
	Students* studentsRef;
    int studentIndex;
public:		// User declarations
	__fastcall TKartaSzczegolyForm(TComponent* Owner);
	void ShowStudent(Students* students, int i);
};
//---------------------------------------------------------------------------
extern PACKAGE TKartaSzczegolyForm *KartaSzczegolyForm;
//---------------------------------------------------------------------------
#endif
