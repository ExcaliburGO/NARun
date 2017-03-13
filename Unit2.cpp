//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#pragma hdrstop
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//using namespace std;
extern AnsiString value, value2, value3, value4, value5, value6;
bool ok(AnsiString s2)
{
std::string s1 = s2.c_str();
if (s1.find("&&") != std::string::npos) {
    return false;
    }
    if (s1.find('"') != std::string::npos) {
    return false;
    }
    return true;
}
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
    Edit1->Text=value;
    Edit2->Text=value2;
    Edit4->Text=value3;
    Edit3->Text=value4;
    Edit5->Text=value5;
    Edit6->Text=value6;
    //else ShowMessage("Nie ustawiono œcie¿ek. Aby je ustawic kliknij prawym przyciskiem myszy na okno i wybierz zmieñ œcie¿ki.");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
Edit1->Text="";
Edit2->Text="";
Edit3->Text="";
Edit4->Text="";
Edit5->Text="";
Edit6->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
//OpenDialog1->FileName=Edit1->Text;
if(OpenDialog1->Execute())
Edit1->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
if(OpenDialog1->Execute())
Edit2->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
if(OpenDialog1->Execute())
Edit4->Text=OpenDialog1->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
if(ok(Edit1->Text) && ok(Edit2->Text) && ok(Edit3->Text))
{
std::fstream plik;
AnsiString appdata = getenv("APPDATA");
//ShowMessage(appdata);
AnsiString text = appdata + "\\NARun\\config.ini" ;
//ShowMessage(text);
plik.open(text.c_str(), std::ios::out);
if(plik.good())
{
AnsiString s1 = Edit1->Text;
AnsiString s2 = Edit2->Text;
AnsiString s3 = Edit4->Text;
AnsiString n1 = Edit3->Text;
AnsiString n2 = Edit5->Text;
AnsiString n3 = Edit6->Text;
plik<<s1.c_str()<<std::endl<<s2.c_str()<<std::endl<<s3.c_str()<<std::endl<<n1.c_str()<<std::endl<<n2.c_str()<<std::endl<<n3.c_str();
plik.close();
}
else
{
AnsiString komenda = "cd \""+appdata+"\" && mkdir NARun";
system(komenda.c_str());
Button1Click(this);
}
Close();
}
else ShowMessage("Œcie¿ki zawieraj¹ niedozwolone znaki");
}
//---------------------------------------------------------------------------

