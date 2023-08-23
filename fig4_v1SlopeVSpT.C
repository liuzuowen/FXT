#include "Utility/useful.h"
#include "Utility/draw.C"

void fig4_v1SlopeVSpT()
{
    SetMyStyle();
    gStyle->SetLineWidth(1);
    gStyle->SetFrameLineWidth(1);

    const int nEnergy = 4;
    const int nPart = 3; // 0 = pi+; 1 = pi-; 2 = K0s


    TGraphErrors *g_v1Slope_pT[nEnergy][nPart];
    TGraphErrors *g_v1Slope_pT_sys[nEnergy][nPart];

    TGraphErrors *g_v1Slope_pT_cas[nEnergy][nPart];
    TGraphErrors *g_v1Slope_pT_cas_rmSpec[nEnergy][nPart];
    TGraphErrors *g_v1Slope_pT_mf[nEnergy][nPart];
    TGraphErrors *g_v1Slope_pT_mf_rmSpec[nEnergy][nPart];
    
    // read data
    for(Int_t i=0; i < nEnergy; i++)
    {
        for(Int_t j=0; j < nPart; j++)
        {
            if(i==0)
            {
                g_v1Slope_pT[i][0] = new TGraphErrors(Form("DataFile/3GeV/pionp_v1Slope_pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][1] = new TGraphErrors(Form("DataFile/3GeV/pionm_v1Slope_pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][2] = new TGraphErrors(Form("DataFile/3GeV/K0s_Slope_9pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT_sys[i][0] = new TGraphErrors(Form("DataFile/3GeV/pionp_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][1] = new TGraphErrors(Form("DataFile/3GeV/pionm_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][2] = new TGraphErrors(Form("DataFile/3GeV/K0s_Slope_9pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");

                g_v1Slope_pT_cas[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");

                g_v1Slope_pT_cas_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");


            }
            if(i==1)
            {
                g_v1Slope_pT[i][0] = new TGraphErrors(Form("DataFile/3p2GeV/pionp_v1Slope_pT_Cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][1] = new TGraphErrors(Form("DataFile/3p2GeV/pionm_v1Slope_pT_Cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][2] = new TGraphErrors(Form("DataFile/3p2GeV/K0s_Slope_9pT_cent1.txt"), "%lg %lg %lg");

                g_v1Slope_pT_sys[i][0] = new TGraphErrors(Form("DataFile/3p2GeV/pionp_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][1] = new TGraphErrors(Form("DataFile/3p2GeV/pionm_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][2] = new TGraphErrors(Form("DataFile/3p2GeV/K0s_Slope_9pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");

            }
            if(i==2)
            {
                g_v1Slope_pT[i][0] = new TGraphErrors(Form("DataFile/3p5GeV/pionp_v1Slope_pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][1] = new TGraphErrors(Form("DataFile/3p5GeV/pionm_v1Slope_pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][2] = new TGraphErrors(Form("DataFile/3p5GeV/K0s_Slope_9pT_cent1.txt"), "%lg %lg %lg");

                g_v1Slope_pT_sys[i][0] = new TGraphErrors(Form("DataFile/3p5GeV/pionp_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][1] = new TGraphErrors(Form("DataFile/3p5GeV/pionm_v1Slope_pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][2] = new TGraphErrors(Form("DataFile/3p5GeV/K0s_Slope_9pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");

            }
            if(i==3)
            {
                g_v1Slope_pT[i][0] = new TGraphErrors(Form("DataFile/3p9GeV/pionp_v1Slope_pT_Cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][1] = new TGraphErrors(Form("DataFile/3p9GeV/pionm_v1Slope_pT_Cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT[i][2] = new TGraphErrors(Form("DataFile/3p9GeV/K0s_Slope_9pT_cent1.txt"), "%lg %lg %lg");
                g_v1Slope_pT_sys[i][0] = new TGraphErrors(Form("DataFile/3p9GeV/pionp_v1Slope_pT_Cent1_syserr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][1] = new TGraphErrors(Form("DataFile/3p9GeV/pionm_v1Slope_pT_Cent1_syserr.txt"), "%lg %lg %lg %lg");
                g_v1Slope_pT_sys[i][2] = new TGraphErrors(Form("DataFile/3p9GeV/ks0_Slope_9pT_cent1_sysErr.txt"), "%lg %lg %lg %lg");


                g_v1Slope_pT_cas[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent0_cas.txt"), "%lg %lg %lg");

                g_v1Slope_pT_cas_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent0_cas_rmSpec.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent0_RQMDrmf.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent0_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");

            }
        }
    }


    for(Int_t i=0; i < nEnergy; i++)
    {
        for(Int_t j=0; j < nPart; j++)
        {
            g_v1Slope_pT[i][j]->SetMarkerSize(2);


            if(j==0) g_v1Slope_pT[i][j]->SetMarkerStyle(21);
            if(j==1) g_v1Slope_pT[i][j]->SetMarkerStyle(25);
            if(j==2) g_v1Slope_pT[i][j]->SetMarkerStyle(23);

            g_v1Slope_pT_cas[3][j]->SetFillColorAlpha(4, 0.4);
            g_v1Slope_pT_cas_rmSpec[3][j]->SetFillColorAlpha(9, 0.4);
            g_v1Slope_pT_cas[3][j]->SetFillStyle(3002);
            g_v1Slope_pT_cas_rmSpec[3][j]->SetFillStyle(3002);

            g_v1Slope_pT_mf[3][j]->SetFillColorAlpha(46,0.4);
            g_v1Slope_pT_mf_rmSpec[3][j]->SetFillColorAlpha(1,0.4);
            g_v1Slope_pT_mf[3][j]->SetFillStyle(3002);
            g_v1Slope_pT_mf_rmSpec[3][j]->SetFillStyle(3002);


            if(i==0) 
            {
                g_v1Slope_pT[i][j]->SetMarkerColor(1); 
                g_v1Slope_pT[i][j]->SetLineColor(1);

                g_v1Slope_pT_sys[i][j]->SetFillColorAlpha(1, 0.2); 
                g_v1Slope_pT_sys[i][j]->SetLineWidth(0);
            }
            if(i==1) 
            {
                g_v1Slope_pT[i][j]->SetMarkerColor(2); 
                g_v1Slope_pT[i][j]->SetLineColor(2);

                g_v1Slope_pT_sys[i][j]->SetFillColorAlpha(2, 0.2); 
                g_v1Slope_pT_sys[i][j]->SetLineWidth(0);
            }
            if(i==2) 
            {
                g_v1Slope_pT[i][j]->SetMarkerColor(4); 
                g_v1Slope_pT[i][j]->SetLineColor(4);

                g_v1Slope_pT_sys[i][j]->SetFillColorAlpha(4, 0.2); 
                g_v1Slope_pT_sys[i][j]->SetLineWidth(0);
            }
            if(i==3) 
            {
                g_v1Slope_pT[i][j]->SetMarkerColor(46); 
                g_v1Slope_pT[i][j]->SetLineColor(46);

                g_v1Slope_pT_sys[i][j]->SetFillColorAlpha(46, 0.2); 
                g_v1Slope_pT_sys[i][j]->SetLineWidth(0);
            }
        }
    }

    TLegend *leg1 = new TLegend(0.187108,0.654588,0.476841,0.981485);
    leg1->SetBorderSize(0);
    leg1->AddEntry(g_v1Slope_pT[0][0],"3.0 GeV", "p");
    leg1->AddEntry(g_v1Slope_pT[1][0],"3.2 GeV", "p");
    leg1->AddEntry(g_v1Slope_pT[2][0],"3.5 GeV", "p");
    leg1->AddEntry(g_v1Slope_pT[3][0],"3.9 GeV", "p");

    TLegend *leg21 = new TLegend(0.420291,0.828252,0.613891,0.966492);
    leg21->SetBorderSize(0);
    leg21->AddEntry(g_v1Slope_pT[0][0],"#pi^{+}", "p");

    TLegend *leg22 = new TLegend(0.420291,0.828252,0.613891,0.966492);
    leg22->SetBorderSize(0);
    leg22->AddEntry(g_v1Slope_pT[0][1],"#pi^{-}", "p");

    TLegend *leg23 = new TLegend(0.0597892,0.843372,0.32847,0.938412);
    leg23->SetBorderSize(0);
    leg23->AddEntry(g_v1Slope_pT[0][2],"K^{0}_{S}", "p");

    TLegend *leg3 = new TLegend(0.0237173,0.720622,0.507533,0.914119);
    leg3->SetBorderSize(0);
    leg3->AddEntry(g_v1Slope_pT_cas[3][0],"Cascade","f");
    leg3->AddEntry(g_v1Slope_pT_mf[3][0],"Mean Field","f");
    leg3->AddEntry(g_v1Slope_pT_mf_rmSpec[3][0],"MF w/o Spectator","f");



    // draw on canvas
    TCanvas *c1 = new TCanvas("c1","",2200,800);
    c1->cd();
    TPad *p1=new TPad("p1", "", 0.05, 0.05, 0.99, 0.99); p1->Draw(); p1->cd();
    p1->Divide(3,1,0,0); 

    TH2F *hf1 = new TH2F("hf1","",10, 0.2, 1.25, 10, -0.22, 0.42);
    hf1->GetXaxis()->SetLabelOffset(0.02);
    hf1->GetYaxis()->SetLabelOffset(0.02);

    for(Int_t j=0; j < nPart; j++)
    {
        p1->cd(j+1);
        gPad->SetTicks(1,1);
        hf1->Draw();

        for(Int_t i=0; i < nEnergy; i++)
        {
            g_v1Slope_pT[i][j]->Draw("EP Same");
            g_v1Slope_pT_sys[i][j]->Draw("e5 Same");
        }

        g_v1Slope_pT_cas[3][j]->Draw("E3 Same");
        //g_v1Slope_pT_cas_rmSpec[3][j]->Draw("E3 Same");
        g_v1Slope_pT_mf[3][j]->Draw("E3 Same");
        g_v1Slope_pT_mf_rmSpec[3][j]->Draw("E3 Same");

        LineY1(0, 1 ,2);

    }

    c1->cd();
    DrawText(0.324317,0.0426667, "Transver Momentum p_{T} [GeV/c]", 42, 0.07);
    DrawText(0.0446266,0.346667, "Slope dv_{1}/dy|_{y=0}", 42, 0.06, 90);
    p1->cd(1); leg1->Draw("Same");  drawText(0.45, 0.82, "#pi^{+}", 42, 0.08); drawText(0.45, 0.90, "STAR preliminary", 42, 0.05); //leg21->Draw("Same");
    p1->cd(2); leg3->Draw("Same");  drawText(0.45, 0.82, "#pi^{-}", 42, 0.09); drawText(0.05, 0.92, "3.9 GeV, JAM", 42, 0.06);//leg22->Draw("Same");
    p1->cd(3);                      drawText(0.15, 0.82, "K^{0}_{S}", 42, 0.08); //leg23->Draw("Same");
    


    c1->Print("./OutputFile/fig4_v1SlopeVSpT.pdf");
    
}