//---------------------------------------------------------------------------

#ifndef finanseH
#define finanseH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include "datastructures.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TFinanseForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *menu;
	TBitBtn *wizyty;
	TBitBtn *statystyki;
	TBitBtn *karty;
	TLabel *tytul;
	TLabel *kwartal1;
	TLabel *kwartal2;
	TLabel *kwartal3;
	TLabel *kwartal4;
	TLabel *rok;
	TImage *Image1;
	void __fastcall menuClick(TObject *Sender);
	void __fastcall wizytyClick(TObject *Sender);
	void __fastcall statystykiClick(TObject *Sender);
	void __fastcall kartyClick(TObject *Sender);
	void __fastcall wyjscieClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	Incomes incomes;
    void updateQuarters();
public:		// User declarations
	__fastcall TFinanseForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFinanseForm *FinanseForm;
//---------------------------------------------------------------------------
#endif
