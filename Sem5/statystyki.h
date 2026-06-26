//---------------------------------------------------------------------------

#ifndef statystykiH
#define statystykiH
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
class TStatystykiForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *menu;
	TBitBtn *wizyty;
	TBitBtn *finanse;
	TBitBtn *karty;
	TLabel *luty;
	TLabel *marzec;
	TLabel *kwiecien;
	TLabel *maj;
	TLabel *czerwiec;
	TLabel *lipiec;
	TLabel *sierpien;
	TLabel *styczen;
	TLabel *wrzesien;
	TLabel *pazdz;
	TLabel *listo;
	TLabel *grudzien;
	TLabel *rok;
	TLabel *tytul;
	TImage *Image1;
	void __fastcall menuClick(TObject *Sender);
	void __fastcall wizytyClick(TObject *Sender);
	void __fastcall finanseClick(TObject *Sender);
	void __fastcall kartyClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	Visits visits;
    void updateStats();
public:		// User declarations
	__fastcall TStatystykiForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TStatystykiForm *StatystykiForm;
//---------------------------------------------------------------------------
#endif
