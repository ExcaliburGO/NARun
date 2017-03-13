//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream>
#include <cstdlib>
#pragma hdrstop

#include "cmdcppb.h"
#include    "Unit2.h"
AnsiString value, value2, value3, value4, value5, value6;        // global variable
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//using namespace std;
void odpal(AnsiString nazwa)
{
system((AnsiString("set __COMPAT_LAYER=RunAsInvoker && start ") + "\"Uruchamianie bez admina:)\" \""+nazwa.c_str() + "\"").c_str());
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
     AnsiString appdata = getenv("APPDATA");
    //ShowMessage(appdata);
    AnsiString text = appdata + "\\NARun\\config.ini" ;
    //ShowMessage(text);
    std::fstream plik;
    plik.open(text.c_str(), std::ios::in);

    if(plik.good())
    {
    char linia[260];
    int nr_linii=1;
    while (plik.getline(linia, 260))
    {
        switch (nr_linii)
        {
            case 1: value=linia; break;
            case 2: value2=linia; break;
            case 3: value3=linia; break;
            case 4: value4=linia; Button1->Caption=linia; break;
            case 5: value5=linia; Button2->Caption=linia; break;
            case 6: value6=linia; Button3->Caption=linia; break;
        }
        nr_linii++;
    }
    plik.close();
    }
    else
    {
    ShowMessage("Nie ustawiono œcie¿ek.");
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    }
 // AnsiString pie = "HELLO";
  //value = pie;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
odpal(value);
if(CheckBox1->Checked)
{
Application->Terminate();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
odpal(value2);
if(CheckBox1->Checked)
{
Application->Terminate();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
odpal(value3);
if(CheckBox1->Checked)
{
Application->Terminate();
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
OpenDialog1->FileName = "";
if(OpenDialog1->Execute())
{
odpal(OpenDialog1->FileName);
if(CheckBox1->Checked)
{
Application->Terminate();
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::zmie1Click(TObject *Sender)
{
Form2->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
     AnsiString appdata = getenv("APPDATA");
    //ShowMessage(appdata);
    AnsiString text = appdata + "\\NARun\\config.ini" ;
    //ShowMessage(text);
    std::fstream plik;
    plik.open(text.c_str(), std::ios::in);

    if(plik.good())
    {
    char linia[260];
    int nr_linii=1;
    while (plik.getline(linia, 260))
    {
        switch (nr_linii)
        {
            case 1: value=linia; break;
            case 2: value2=linia; break;
            case 3: value3=linia; break;
            case 4: value4=linia; break;
            case 5: value5=linia; break;
            case 6: value6=linia; break;
        }
        nr_linii++;
    }
    Button1->Caption=value4;
    Button2->Caption=value5;
    Button3->Caption=value6;
    Button1->Enabled=true;
    Button2->Enabled=true;
    Button3->Enabled=true;
    plik.close();
    }
    else
    {
    //ShowMessage("Nie ustawiono œcie¿ek.");
    Button1->Enabled=false;
    Button2->Enabled=false;
    Button3->Enabled=false;
    Button1->Caption="";
    Button2->Caption="";
    Button3->Caption="";
    }
}
//---------------------------------------------------------------------------

