#ifndef USEFUL_H
#define USEFUL_H
#include <TStyle.h>


//-----------------TLine------------------------//
void LineX1(Double_t atX, Int_t iColor = kRed, Int_t iStyle = 1, Double_t iWidth = 1)
{

  gPad->Modified();
  gPad->Update();
  TLine *l1 = new TLine(atX, gPad->GetUymin(), atX, gPad->GetUymax());
  l1->SetLineColor(iColor);
  l1->SetLineStyle(iStyle);
  l1->SetLineWidth(iWidth);
  l1->Draw("Same");

}

void LineY1(Double_t atY, Int_t iColor = kRed, Int_t iStyle = 1, Double_t iWidth = 1)
{

  gPad->Modified();
  gPad->Update();
  TLine *l1 = new TLine( gPad->GetUxmin(), atY, gPad->GetUxmax(), atY);
  l1->SetLineColor(iColor);
  l1->SetLineStyle(iStyle);
  l1->SetLineWidth(iWidth);
  l1->Draw("Same");

}

void PlotLine(Double_t x1_val, Double_t x2_val, Double_t y1_val, Double_t y2_val, Int_t Line_Col, Int_t LineWidth, Int_t LineStyle)
{
  TLine* Zero_line = new TLine();
  Zero_line -> SetX1(x1_val);
  Zero_line -> SetX2(x2_val);
  Zero_line -> SetY1(y1_val);
  Zero_line -> SetY2(y2_val);
  Zero_line -> SetLineWidth(LineWidth);
  Zero_line -> SetLineStyle(LineStyle);
  Zero_line -> SetLineColor(Line_Col);
  Zero_line -> Draw("Same");
  //delete Zero_line;
}


//-------------Set the general style options------------//
void SetMyStyle()
{
  // Format for axes
  gStyle->SetNdivisions(505, "X");
  gStyle->SetNdivisions(505, "Y");
  gStyle->SetTitleOffset(0.8,"X");
  gStyle->SetTitleOffset(0.8,"Y");
  gStyle->SetTitleSize(42,"xyz");
  gStyle->SetLabelSize(0.05,"xyz");
  gStyle->SetFrameLineWidth(2);

  // No err bars in x direction
  gStyle->SetErrorX(0);

  // Margins for pad etc.
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadBorderSize(1);
  
  // Format stats
  gStyle->SetOptStat(0);

  // Format legend
  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFont(22);

  // Format text
  gStyle->SetTextFont(42);
  gStyle->SetTextSize(25);

  // Marker and Line
  gStyle->SetLineWidth(2);
  gStyle->SetMarkerSize(2);


  /*
  // From Wang Siguang
  // No Canvas Border
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasBorderSize(2);
  
  // Frame Color and Border
  gStyle->SetFrameFillColor(10);
  gStyle->SetFrameBorderMode(1);
  
  // White BG
  gStyle->SetCanvasColor(10);

  // Palette
  gStyle->SetPalette(55);
  
  // Format for axes
  gStyle->SetLabelFont(22,"xyz");
  gStyle->SetLabelSize(0.06,"xyz");
  gStyle->SetLabelOffset(0.01,"xyz");
  gStyle->SetNdivisions(510,"xyz");
  
  gStyle->SetTitleFont(22,"xyz");
  gStyle->SetTitleColor(1,"xyz");
  gStyle->SetTitleOffset(0.91);
  
  gStyle->SetTitleYOffset(1.1);
  gStyle->SetTitleXOffset(1.1);
  gStyle->SetTitleYSize(0.05);
  gStyle->SetTitleXSize(0.04);
  //gStyle->SetTitleXCenter();
  //gStyle->SetTitleYCenter();

  // Format legend
  gStyle->SetLegendBorderSize(0);
  gStyle->SetLegendFont(22);
  gStyle->SetFillStyle(0);

  // Format Marker
  gStyle->SetMarkerSize(1.8);

  // Format Stats
  gStyle->SetOptStat(0);
  //gStyle->SetStatColor(0);
  
  // No pad borders
  //gStyle->SetPadBoderMode(0);  // note that not in root6
  //gStyle->SetPadBoderSize(0);
  
  //White BG
  gStyle->SetPadColor(10);
  
  // Margins for labels etc.
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadTopMargin(0.06);
  
  // No err bars in x direction
  gStyle->SetErrorX(0);
  */

  /*
  //------------------------------
  //-----------LHCB Style---------
  //------------------------------
  gStyle->SetOptStat(0);
  gROOT->ForceStyle();
  gStyle->SetPadLeftMargin(0.12);
  gStyle->SetPadRightMargin(0.11);
  gStyle->SetTitleOffset(2.4,"Y");
  gStyle->SetTitleOffset(1.8,"X");
//  TGaxis::SetMaxDigits(3);
  
  // Use times new roman, precision 2
  Int_t lhcbFont        = 133;
  // Line thickness
  Double_t lhcbWidth    = 1.00;
  // Text size
  Double_t lhcbTSize    = 25;
  
  gStyle->SetTextFont(lhcbFont);
  gStyle->SetTextSize(lhcbTSize);
  gStyle->SetLabelFont(lhcbFont,"x");
  gStyle->SetLabelFont(lhcbFont,"y");
  gStyle->SetLabelFont(lhcbFont,"z");
  gStyle->SetLabelSize(lhcbTSize,"x");
  gStyle->SetLabelSize(lhcbTSize,"y");
  gStyle->SetLabelSize(lhcbTSize,"z");
  gStyle->SetTitleFont(lhcbFont,"t");
  gStyle->SetTitleFont(lhcbFont,"x");
  gStyle->SetTitleFont(lhcbFont,"y");
  gStyle->SetTitleFont(lhcbFont,"z");
  gStyle->SetTitleSize(1.2*lhcbTSize,"t");
  gStyle->SetTitleSize(1.2*lhcbTSize,"x");
  gStyle->SetTitleSize(1.2*lhcbTSize,"y");
  gStyle->SetTitleSize(1.2*lhcbTSize,"z");
  // use medium bold lines and thick markers
  gStyle->SetLineWidth(2);
  gStyle->SetFrameLineWidth(2);

  TLatex lt;
  lt.SetNDC();
  lt.SetTextFont(lhcbFont);
  lt.SetTextSize(lhcbTSize);
  //==================================================================
  */
  
  /*
  gStyle->SetLabelColor(1,"X");
  gStyle->SetLabelColor(1,"Y");
  gStyle->SetTitleTextColor(1);
  gStyle->SetNdivisions(6, "X");
  gStyle->SetNdivisions(4, "Y");
  gStyle->SetMarkerStyle(8);
  gStyle->SetMarkerSize(1.7);
  gStyle->SetHistLineColor(2);
  gStyle->SetHistLineWidth(1);
  gStyle->SetFuncWidth(3);
  gStyle->SetPadBorderMode(0);
  gStyle->SetHistLineStyle(0);
  gStyle->SetTitleH(0.058);
  gStyle->SetTitleW(0.98);
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1);
  gStyle->SetOptDate(0);
  gStyle->SetTitleFont(42);
  gStyle->SetLabelFont(42);
  TGaxis::SetMaxDigits(3);
  */

}

/*
//---------------- new TH1F --------------------//
TH1F *newTH1F(char name[]="h1", double binW=0.01, double LowBin=0.0, double HighBin=3.0, bool MevTitle=kTure, int iMode=-1)
{
  int nBin = TMath::Nint((HighBin-LowBin)/binW);
  HighBin = binW * nBin +LowBin;

  TH1F *h =new TH1F(name, "", nBin, LowBin, HighBin);
  if(MevTitle) h->GetYaxis()->SetTitle(Form("Events / (%.0fMeV/c^{2})", h->GetBinWidth(1)*1000) );
  h->SetMinimum(0.0);
  h->GetYaxis()->SetTitleOffset(1.1);
  if(iMode>=0 && iMode<14)
  {
    int iMarker[] = {20,21,24,25,28,29,30,27,3, 5,2, 26,22,23};
    int iColor[] = {2,4,6,9,1,50,40,31,41,35,44,38,47,12};
    h->SetMarkerStyle(iMarker[iMode]);
    h->SetMarkerColor(iColor[iMode]);
    h->SetLineColr(iColor[iMode]);
  }

  return h;
}

//--------- Add text on plot--------------------//
void txtN(double x0, double y0, TH1 *h, char sName[]="N=%.0f", double sizeTxt=0.06)
{
  h->SetStatas(kFalse);
  TLatex *ltx = new TLatex();
  ltx->SetNDC(kTrue);
  ltx->SetTextColor(h->SetLineColor());
  ltx->SetTextColorFont(22);
  ltx->SetTextSize(sizeTxt);
  ltx->DrawLatex(x0,y0,Form(sName,h->GetEntries()));
  gPad->Modified();
  gPad->Update();
}
*/

//-----------------Set Max & Min Yaxies for TProfile------------------------//
//double 
// TProfile -> GetMaximum




#endif
