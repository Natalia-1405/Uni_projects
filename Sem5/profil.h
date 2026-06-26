//---------------------------------------------------------------------------

#ifndef profilH
#define profilH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TProfilForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *Stawka;
	TEdit *Imie;
	TBitBtn *Powrot;
	TImage *Image1;
	void __fastcall PowrotClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TProfilForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TProfilForm *ProfilForm;
//---------------------------------------------------------------------------
#endif
