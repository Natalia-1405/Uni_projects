//---------------------------------------------------------------------------

#ifndef wizytyH
#define wizytyH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include "datastructures.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TWizytyForm : public TForm
{
__published:	// IDE-managed Components
	TCalendarView *CalendarView1;
	TBitBtn *menu;
	TBitBtn *finanse;
	TBitBtn *statystyki;
	TBitBtn *karty;
	TBitBtn *dodajnowe;
	TListBox *ListBox1;
	TButton *archiwum;
	TImage *Image1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall menuClick(TObject *Sender);
	void __fastcall finanseClick(TObject *Sender);
	void __fastcall statystykiClick(TObject *Sender);
	void __fastcall kartyClick(TObject *Sender);
	void __fastcall dodajnoweClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall archiwumClick(TObject *Sender);
private:	// User declarations
	Visits visits;
    Incomes incomes;
    void loadVisits();
public:		// User declarations
	__fastcall TWizytyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWizytyForm *WizytyForm;
//---------------------------------------------------------------------------
#endif
