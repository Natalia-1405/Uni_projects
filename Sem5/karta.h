//---------------------------------------------------------------------------

#ifndef kartaH
#define kartaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <vector>
#include <datastructures.h>

using namespace std;
//---------------------------------------------------------------------------
class TKartyForm : public TForm
{
__published:	// IDE-managed Components
	TBitBtn *menu;
	TBitBtn *wizyty;
	TBitBtn *finanse;
	TBitBtn *statystyki;
	TListBox *ListBox1;
	TBitBtn *nowakarta;
	TImage *Image1;
	void __fastcall menuClick(TObject *Sender);
	void __fastcall wizytyClick(TObject *Sender);
	void __fastcall finanseClick(TObject *Sender);
	void __fastcall statystykiClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall nowakartaClick(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:
	Students students;
    void loadStudents();

public:		// User declarations
	__fastcall TKartyForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKartyForm *KartyForm;
//---------------------------------------------------------------------------
#endif
