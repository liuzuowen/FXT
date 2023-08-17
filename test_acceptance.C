#include "/Users/liuzw/WorkSpace/Tools/useful.h"
#include "/Users/liuzw/WorkSpace/Tools/draw.C"

void test_acceptance(){

    SetMyStyle();
    gStyle->SetLineWidth(1);
    gStyle->SetFrameLineWidth(1);
	gStyle->SetPalette(55);


    const int nEnergy = 4; 
    const int nPart = 3; // 0 = pi+; 1 = K0s; 2 = lambda

    // Read rootfile
    TFile *f[nEnergy][nPart];
    f[0][0] = new TFile("/Users/liuzw/WorkSpace/3GeV/piKp/InputFile/3GeV_pionFlow.root");
    f[1][0] = new TFile("./InputFile/3p2_piKp_acceptance.root");
    f[2][0] = new TFile("./InputFile/3p5_piKp_acceptance.root");
    f[3][0] = new TFile("./InputFile/3p9_piKp_acceptance.root");

    f[0][1] = new TFile("/Users/liuzw/WorkSpace/3GeV/KFparticle/K0s/InputFile/3GeV_K0s.root");
    f[1][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/K0s/InputFile/OtherEnergies/3p2_K0s_newPID_withTOF.root");
    f[2][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/K0s/InputFile/3p5_K0s_newPID_withTOF_newCent.root");
    f[3][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/K0s/InputFile/OtherEnergies/3p9_K0s_newPID_withTOF.root");

    f[0][2] = new TFile("/Users/liuzw/WorkSpace/3GeV/KFparticle/Lambda/InputFile/3GeV_lambda.root");
    f[1][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/Lambda/InputFile/OtherEnergies/3p2_lambda_newPID.root");
    f[2][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/Lambda/InputFile/3p5_lambda_newPID_newCent.root");
    f[3][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/KFparticle/Lambda/InputFile/OtherEnergies/3p9_lambda_newPID.root");

    

    TH2F *hyvsPt[nEnergy][nPart]; 
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            if(j==0){
                if(i==0) hyvsPt[i][j] = (TH2F*)f[i][j]->Get("h_pt_y_pionminus");
                if(i>0) hyvsPt[i][j] = (TH2F*)f[i][j]->Get("h_pt_y_PiM");
            }else{
                hyvsPt[i][j] = (TH2F*)f[i][j]->Get("hyvsPt_afterCut");
            } 

            hyvsPt[i][j]->GetYaxis()->SetRangeUser(-0.1,2.2);
            hyvsPt[i][j]->GetXaxis()->SetRangeUser(-1.25,0.75);
        }
    }


    TCanvas *c1 = new TCanvas("c1","",1100,900);
    c1->cd();
    TPad *p1=new TPad("p1", "", 0.05, 0.05, 0.99, 0.99); p1->Draw(); p1->cd();
    p1->Divide(nEnergy,nPart,0,0); 

    TH1D *hf[nEnergy][nPart];
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            hf[i][j] = new TH1D(Form("hf_%d%d", i, j),"", 1, -1.25,0.3);

            hf[i][j]->GetYaxis()->SetRangeUser(-0.1,2.2);
            hf[i][j]->GetXaxis()->SetLabelOffset(0.02);
            hf[i][j]->GetYaxis()->SetLabelOffset(0.02);
            hf[i][j]->GetXaxis()->SetLabelSize(0.08);
            hf[i][j]->GetYaxis()->SetLabelSize(0.08);

            if(j<2) hf[i][j]->GetYaxis()->SetLabelSize(0.09);
            if(i>0){
                hf[i][j]->GetXaxis()->SetLabelSize(0.09);
                hf[i][j]->GetXaxis()->SetLabelOffset(0.015);
            }
        }
    }

    
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            p1->cd(nEnergy*j+i+1); 
            gPad->SetTicks(1,1);
            gPad->SetLogz();
            
            hf[i][j]->Draw("C");
            hyvsPt[i][j]->Draw("Col Same");

            if(j>1)
            {
                PlotLine(0,0, 0.4,2.0, 1,1,1);
                PlotLine(-1,-1, 0.4,2.0, 1,1,1);
                //PlotLine(-0.5,-0.5, 0.4,2.0, 1,1,2);
                PlotLine(0,-1, 0.4,0.4, 1,1,1);
                PlotLine(0,-1, 2.0,2.0, 1,1,1);
            }
            else
            {
                PlotLine(0,0, 0.2,1.6, 1,1,1);
                PlotLine(-1,-1, 0.2,1.6, 1,1,1);
                //PlotLine(-0.5,-0.5, 0.2,1.6, 1,1,2);
                PlotLine(0,-1, 0.2,0.2, 1,1,1);
                PlotLine(0,-1, 1.6,1.6, 1,1,1);
            } 
        }
    }



    c1->cd();

    DrawText(0.410747,0.0285714, "Particle Rapidity y", 42, 0.04);
    DrawText(0.0373406,0.292571, "Transver Momentum p_{T} (GeV/c)", 42, 0.04, 90);

    p1->cd(1); drawText(0.9, 0.1, "#pi^{ +}", 42, 0.09);
    p1->cd(5); drawText(0.9, 0.1, "K^{0}_{S}", 42, 0.08);
    p1->cd(9); drawText(0.9, 0.25, "#Lambda", 42, 0.09); 
    p1->cd(9);  drawText(0.52, 0.2, "3.0 GeV", 42, 0.08);
    p1->cd(10); drawText(0.52, 0.2, "3.2 GeV", 42, 0.09);
    p1->cd(11); drawText(0.52, 0.2, "3.5 GeV", 42, 0.09);
    p1->cd(12); drawText(0.52, 0.2, "3.9 GeV", 42, 0.09);


    TCanvas *c2 = new TCanvas("c2","",1100,400);
    c2->cd();
    TPad *p2=new TPad("p2", "", 0.05, 0.05, 0.99, 0.99); p2->Draw(); p2->cd();
    p2->Divide(4,1,0,0); 

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<1; j++)
        {
            p2->cd(nEnergy*j+i+1); 
            gPad->SetTicks(1,1);
            gPad->SetLogz();
            
            hf[i][j]->Draw("C");
            hyvsPt[i][j]->Draw("Col Same");

            PlotLine(0,0, 0.4,2.0, 1,1,1);
            PlotLine(-1,-1, 0.4,2.0, 1,1,1);
            //PlotLine(-0.5,-0.5, 0.4,2.0, 1,1,2);
            PlotLine(0,-1, 0.4,0.4, 1,1,1);
            PlotLine(0,-1, 2.0,2.0, 1,1,1);
        }
    }

    c2->cd();

    DrawText(0.410747,0.0285714, "Particle Rapidity y", 42, 0.04);
    DrawText(0.0373406,0.292571, "Transver Momentum p_{T} (GeV/c)", 42, 0.04, 90);

    p2->cd(1);  drawText(0.52, 0.2, "3.0 GeV", 42, 0.08); drawText(0.9, 0.1, "#pi^{ -}", 42, 0.09);
    p2->cd(2); drawText(0.52, 0.2, "3.2 GeV", 42, 0.09);
    p2->cd(3); drawText(0.52, 0.2, "3.5 GeV", 42, 0.09);
    p2->cd(4); drawText(0.52, 0.2, "3.9 GeV", 42, 0.09);
    //c1->Print("./OutputFile/fig1_acceptance.pdf");


}