object Form1: TForm1
  Left = 208
  Top = 149
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'NARun'
  ClientHeight = 313
  ClientWidth = 136
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 9
    Top = 0
    Width = 113
    Height = 73
    TabOrder = 0
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 33
    Top = 296
    Width = 57
    Height = 17
    Caption = 'Zamknij'
    Checked = True
    State = cbChecked
    TabOrder = 1
  end
  object Button2: TButton
    Left = 9
    Top = 72
    Width = 113
    Height = 73
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 9
    Top = 144
    Width = 113
    Height = 73
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 9
    Top = 216
    Width = 113
    Height = 73
    Caption = 'W'#322'asny'
    TabOrder = 4
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Pliki program'#243'w(.exe)|*.exe|Wszystko|*.*'
    Options = [ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 80
    Top = 232
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object zmiecieki1: TMenuItem
      Caption = 'zmie'#324' '#347'cie'#380'ki'
      OnClick = zmie1Click
    end
  end
  object Timer1: TTimer
    Interval = 100
    OnTimer = Timer1Timer
    Left = 72
    Top = 16
  end
end
