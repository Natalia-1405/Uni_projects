//---------------------------------------------------------------------------

#ifndef archiwumH
#define archiwumH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "datastructures.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TArchiwumForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TListBox *ListBox1;
	TButton *powrot;
	TImage *Image1;
	void __fastcall powrotClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
	Visits* visitsRef;
	void loadArchive();
public:		// User declarations
	__fastcall TArchiwumForm(TComponent* Owner);
	void setVisits(Visits* visits);
};
//---------------------------------------------------------------------------
extern PACKAGE TArchiwumForm *ArchiwumForm;
//---------------------------------------------------------------------------
#endif
