object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object BoutonOuverturePort: TButton
    Left = 224
    Top = 32
    Width = 123
    Height = 25
    Caption = 'Ouverture Port'
    TabOrder = 0
    OnClick = BoutonOuverturePortClick
  end
  object BoutonFermeturePort: TButton
    Left = 224
    Top = 72
    Width = 123
    Height = 25
    Caption = 'Fermeture Port'
    TabOrder = 1
    OnClick = BoutonFermeturePortClick
  end
  object BoutonLecturePort: TButton
    Left = 224
    Top = 121
    Width = 123
    Height = 25
    Caption = 'Lecture Port'
    TabOrder = 2
    OnClick = BoutonLecturePortClick
  end
  object BoutonEcriturePort: TButton
    Left = 224
    Top = 168
    Width = 123
    Height = 25
    Caption = 'Ecriture Port'
    TabOrder = 3
    OnClick = BoutonEcriturePortClick
  end
end
