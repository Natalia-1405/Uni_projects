//---------------------------------------------------------------------------

#ifndef projektH
#define projektH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "datastructures.h"
//---------------------------------------------------------------------------
class TMenuForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *profil;
	TBitBtn *wyjscie;
	TBitBtn *wizyty;
	TBitBtn *finanse;
	TBitBtn *statystyki;
	TBitBtn *karty;
	TImage *Image1;
	TListBox *ListBox1;
	void __fastcall wizytyClick(TObject *Sender);
	void __fastcall finanseClick(TObject *Sender);
	void __fastcall statystykiClick(TObject *Sender);
	void __fastcall wyjscieClick(TObject *Sender);
	void __fastcall kartyClick(TObject *Sender);
	void __fastcall profilClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	Visits visits;
    void loadRecent();
public:		// User declarations
	__fastcall TMenuForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMenuForm *MenuForm;
//---------------------------------------------------------------------------
#endif
