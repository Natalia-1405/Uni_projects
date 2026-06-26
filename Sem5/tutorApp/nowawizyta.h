//---------------------------------------------------------------------------

#ifndef nowawizytaH
#define nowawizytaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TNowaWizytaForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
private:	// User declarations
public:		// User declarations
	__fastcall TNowaWizytaForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNowaWizytaForm *NowaWizytaForm;
//---------------------------------------------------------------------------
#endif
