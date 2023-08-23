#include "/Users/liuzw/WorkSpace/Tools/useful.h"
#include "/Users/liuzw/WorkSpace/Tools/draw.C"

void test_forQM_v1SlopeVSpT()
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

                g_v1Slope_pT_cas[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");

                g_v1Slope_pT_cas_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pip_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_pim_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.0GeV_K0_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");


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


                g_v1Slope_pT_cas[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent1_cas.txt"), "%lg %lg %lg");

                g_v1Slope_pT_cas_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_cas_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent1_cas_rmSpec.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent1_RQMDrmf.txt"), "%lg %lg %lg");

                g_v1Slope_pT_mf_rmSpec[i][0] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pip_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][1] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_pim_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");
                g_v1Slope_pT_mf_rmSpec[i][2] = new TGraphErrors(Form("/Users/liuzw/WorkSpace/3_5GeV/Model/DataFile/3.9GeV_K0_v1Slope_pT_Cent1_RQMDrmf_rmSpec.txt"), "%lg %lg %lg");

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
            if(j==2) g_v1Slope_pT[i][j]->SetMarkerStyle(21);

            g_v1Slope_pT_cas[3][j]->SetFillColorAlpha(4, 0.2);
            g_v1Slope_pT_cas_rmSpec[3][j]->SetFillColorAlpha(9, 0.2);
            //g_v1Slope_pT_cas[3][j]->SetFillStyle(3002);
            //g_v1Slope_pT_cas_rmSpec[3][j]->SetFillStyle(3002);

            g_v1Slope_pT_mf[3][j]->SetFillColorAlpha(2,0.2);
            g_v1Slope_pT_mf_rmSpec[3][j]->SetFillColorAlpha(1,0.2);
            //g_v1Slope_pT_mf[3][j]->SetFillStyle(3002);
            //g_v1Slope_pT_mf_rmSpec[3][j]->SetFillStyle(3002);


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
                g_v1Slope_pT[i][j]->SetMarkerColor(6); 
                g_v1Slope_pT[i][j]->SetLineColor(6);

                g_v1Slope_pT_sys[i][j]->SetFillColorAlpha(6, 0.2); 
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

    TLegend *leg11 = new TLegend(0.197334,0.778979,0.486923,0.895691);
    leg11->SetBorderSize(0);
    leg11->AddEntry(g_v1Slope_pT[3][0],"3.9 GeV", "p");

    TLegend *leg21 = new TLegend(0.420291,0.828252,0.613891,0.966492);
    leg21->SetBorderSize(0);
    leg21->AddEntry(g_v1Slope_pT[0][0],"#pi^{+}", "p");

    TLegend *leg22 = new TLegend(0.420291,0.828252,0.613891,0.966492);
    leg22->SetBorderSize(0);
    leg22->AddEntry(g_v1Slope_pT[0][1],"#pi^{-}", "p");

    TLegend *leg23 = new TLegend(0.0597892,0.843372,0.32847,0.938412);
    leg23->SetBorderSize(0);
    leg23->AddEntry(g_v1Slope_pT[0][2],"K^{0}_{S}", "p");

    TLegend *leg3 = new TLegend(0.508036,0.178524,0.99175,0.372021);
    leg3->SetBorderSize(0);
    leg3->AddEntry(g_v1Slope_pT_cas[3][0],"Cascade","f");
    leg3->AddEntry(g_v1Slope_pT_mf[3][0],"Mean Field","f");
    leg3->AddEntry(g_v1Slope_pT_mf_rmSpec[3][0],"MF w/o Spectator","f");


    // draw on canvas
    TCanvas *c1 = new TCanvas("c1","",1500,800);
    c1->cd();
    TPad *p1=new TPad("p1", "", 0.05, 0.05, 0.99, 0.99); p1->Draw(); p1->cd();
    p1->Divide(2,1,0,0); 

    TH2F *hf1 = new TH2F("hf1","",10, 0.2, 1.25, 10, -0.17, 0.42);
    hf1->GetXaxis()->SetLabelOffset(0.02);
    hf1->GetYaxis()->SetLabelOffset(0.02);

    
    p1->cd(1);
    gPad->SetTicks(1,1);
    hf1->Draw();

    for(Int_t i=0; i < nEnergy; i++)
    {
        g_v1Slope_pT[i][0]->Draw("EP Same");
        g_v1Slope_pT_sys[i][0]->Draw("e5 Same");
    }
    //g_v1Slope_pT_cas[3][0]->Draw("E3 Same");
    //g_v1Slope_pT_mf[3][0]->Draw("E3 Same");
    //g_v1Slope_pT_mf_rmSpec[3][0]->Draw("E3 Same");
    LineY1(0, 1 ,2);


    p1->cd(2);
    gPad->SetTicks(1,1);
    hf1->Draw();

    for(Int_t i=0; i < nEnergy; i++)
    {
        g_v1Slope_pT[i][2]->Draw("EP Same");
        g_v1Slope_pT_sys[i][2]->Draw("e5 Same");
    }
    //g_v1Slope_pT_cas[3][2]->Draw("E3 Same");
    //g_v1Slope_pT_mf[3][2]->Draw("E3 Same");
    //g_v1Slope_pT_mf_rmSpec[3][2]->Draw("E3 Same");
    LineY1(0, 1 ,2);


    c1->cd();
    DrawText(0.324317,0.0426667, "Transver Momentum p_{T} [GeV/c]", 42, 0.06);
    DrawText(0.0446266,0.346667, "Slope dv_{1}/dy|_{y=0}", 42, 0.06, 90);

    p1->cd(1); leg1->Draw("Same");  drawText(0.45, 0.82, "#pi^{+}", 42, 0.08); drawText(0.45, 0.90, "STAR preliminary", 42, 0.05); //leg21->Draw("Same");
    p1->cd(2);   drawText(0.15, 0.82, "K^{0}_{S}", 42, 0.08); //leg22->Draw("Same");

     c1->Print("./OutputFile/forQM_v1SlopeVSpT_1.pdf");


    TCanvas *c2 = new TCanvas("c2","",1500,800);
    c2->cd();
    TPad *p2=new TPad("p2", "", 0.05, 0.05, 0.99, 0.99); p2->Draw(); p2->cd();
    p2->Divide(2,1,0,0); 

    TH2F *hf2 = new TH2F("hf2","",10, 0.2, 1.25, 10, -0.22, 0.32);
    hf2->GetXaxis()->SetLabelOffset(0.02);
    hf2->GetYaxis()->SetLabelOffset(0.02);

    
    p2->cd(1);
    gPad->SetTicks(1,1);
    hf2->Draw();

    for(Int_t i=0; i < nEnergy; i++)
    {
        g_v1Slope_pT[3][0]->Draw("EP Same");
        g_v1Slope_pT_sys[3][0]->Draw("e5 Same");
    }
    g_v1Slope_pT_cas[3][0]->Draw("E3 Same");
    g_v1Slope_pT_mf[3][0]->Draw("E3 Same");
    g_v1Slope_pT_mf_rmSpec[3][0]->Draw("E3 Same");
    LineY1(0, 1 ,2);


    p2->cd(2);
    gPad->SetTicks(1,1);
    hf2->Draw();

    for(Int_t i=0; i < nEnergy; i++)
    {
        g_v1Slope_pT[3][2]->Draw("EP Same");
        g_v1Slope_pT_sys[3][2]->Draw("e5 Same");
    }
    g_v1Slope_pT_cas[3][2]->Draw("E3 Same");
    g_v1Slope_pT_mf[3][2]->Draw("E3 Same");
    g_v1Slope_pT_mf_rmSpec[3][2]->Draw("E3 Same");
    LineY1(0, 1 ,2);


    c2->cd();
    DrawText(0.324317,0.0426667, "Transver Momentum p_{T} [GeV/c]", 42, 0.06);
    DrawText(0.0446266,0.346667, "Slope dv_{1}/dy|_{y=0}", 42, 0.06, 90);

    p2->cd(1); leg11->Draw("Same");  drawText(0.45, 0.82, "#pi^{+}", 42, 0.08); drawText(0.22, 0.90, "STAR preliminary", 42, 0.05); 
    p2->cd(2);  leg3->Draw("Same"); drawText(0.15, 0.82, "K^{0}_{S}", 42, 0.08); drawText(0.53, 0.38, "JAM2", 42, 0.06);

    c2->Print("./OutputFile/forQM_v1SlopeVSpT_2.pdf");

    //
/*
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
    
*/

   


}