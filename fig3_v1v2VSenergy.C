#include "Utility/useful.h"
#include "Utility/function.h"
#include "Utility/draw.C"

#include "DataFile/v1Slope_cent1040.h"
#include "DataFile/Int_v2_cent1040.h"
#include "DataFile/JAM_v1Slope_cent1040.h"
#include "DataFile/JAM_Int_v2_cent1040.h"


void fig3_v1v2VSenergy()
{
    SetMyStyle();

    double FXT_energy[] = {3, 3.2, 3.5, 3.9};
    double FXT_energy_b[] = {3.0+0.05, 3.2+0.05, 3.5+0.05, 3.9+0.05};
    double FXT_energy_c[] = {3-0.05, 3.2-0.05, 3.5-0.05, 3.9-0.05};
    double FXT_energyErr[] = {0.02, 0.02, 0.02, 0.02};


    const int nPart = 4; // 0 = pi+; 1 = pi-; 2 = K0s; 3 = lambda
    const int nEnergy = 4; // 0 = 3GeV; 1 = 3.2 GeV; 2 = 3.5 GeV; 3 = 3.9 GeV

    TGraphErrors *g_v1Slope[nPart], *g_v1Slope_sys[nPart];
    TGraphErrors *g_Int_v2[nPart], *g_Int_v2_sys[nPart];

    TGraphErrors *g_v1Slope_cas[nPart];
    TGraphErrors *g_v1Slope_mf[nPart];
    TGraphErrors *g_v1Slope_mf_rmSpec[nPart];
    TGraphErrors *g_Int_v2_cas[nPart];
    TGraphErrors *g_Int_v2_mf[nPart];
    TGraphErrors *g_Int_v2_mf_rmSpec[nPart];

    g_v1Slope[0] = new TGraphErrors(nEnergy, FXT_energy, piP_v1Slope, 0, piP_v1Slope_staErr);
    g_v1Slope[1] = new TGraphErrors(nEnergy, FXT_energy, piM_v1Slope, 0, piM_v1Slope_staErr);
    g_v1Slope[2] = new TGraphErrors(nEnergy, FXT_energy_b, K0s_v1Slope, 0, K0s_v1Slope_staErr);
    g_v1Slope[3] = new TGraphErrors(nEnergy, FXT_energy, lam_v1Slope, 0, lam_v1Slope_staErr);
    g_v1Slope_sys[0] = new TGraphErrors(nEnergy, FXT_energy, piP_v1Slope, FXT_energyErr, piP_v1Slope_sysErr);
    g_v1Slope_sys[1] = new TGraphErrors(nEnergy, FXT_energy, piM_v1Slope, FXT_energyErr, piM_v1Slope_sysErr);
    g_v1Slope_sys[2] = new TGraphErrors(nEnergy, FXT_energy_b, K0s_v1Slope, FXT_energyErr, K0s_v1Slope_sysErr);
    g_v1Slope_sys[3] = new TGraphErrors(nEnergy, FXT_energy, lam_v1Slope, FXT_energyErr, lam_v1Slope_sysErr);

    g_Int_v2[0] = new TGraphErrors(nEnergy, FXT_energy, piP_v2, 0, piP_v2_staErr);
    g_Int_v2[1] = new TGraphErrors(nEnergy, FXT_energy, piM_v2, 0, piM_v2_staErr);
    g_Int_v2[2] = new TGraphErrors(nEnergy, FXT_energy_b, K0s_v2, 0, K0s_v2_staErr);
    g_Int_v2[3] = new TGraphErrors(nEnergy, FXT_energy_c, lam_v2, 0, lam_v2_staErr);
    g_Int_v2_sys[0] = new TGraphErrors(nEnergy, FXT_energy, piP_v2, FXT_energyErr, piP_v2_sysErr);
    g_Int_v2_sys[1] = new TGraphErrors(nEnergy, FXT_energy, piM_v2, FXT_energyErr, piM_v2_sysErr);
    g_Int_v2_sys[2] = new TGraphErrors(nEnergy, FXT_energy_b, K0s_v2, FXT_energyErr, K0s_v2_sysErr);
    g_Int_v2_sys[3] = new TGraphErrors(nEnergy, FXT_energy_c, lam_v2, FXT_energyErr, lam_v2_sysErr);

    g_v1Slope_cas[0] = new TGraphErrors(nEnergy, FXT_energy, cas_piP_v1Slope, 0, cas_piP_v1Slope_staErr);
    g_v1Slope_cas[1] = new TGraphErrors(nEnergy, FXT_energy, cas_piM_v1Slope, 0, cas_piM_v1Slope_staErr);
    g_v1Slope_cas[2] = new TGraphErrors(nEnergy, FXT_energy, cas_K0_v1Slope, 0, cas_K0_v1Slope_staErr);
    g_v1Slope_cas[3] = new TGraphErrors(nEnergy, FXT_energy, cas_lam_v1Slope, 0, cas_lam_v1Slope_staErr);
    g_v1Slope_mf[0] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_piP_v1Slope, 0, RQMDrmf_piP_v1Slope_staErr);
    g_v1Slope_mf[1] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_piM_v1Slope, 0, RQMDrmf_piM_v1Slope_staErr);
    g_v1Slope_mf[2] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_K0_v1Slope, 0, RQMDrmf_K0_v1Slope_staErr);
    g_v1Slope_mf[3] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_lam_v1Slope, 0, RQMDrmf_lam_v1Slope_staErr);

    g_v1Slope_mf_rmSpec[0] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_lam_v1Slope, 0, RQMDrmf_rmSpec_lam_v1Slope_staErr);
    g_v1Slope_mf_rmSpec[1] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_lam_v1Slope, 0, RQMDrmf_rmSpec_lam_v1Slope_staErr);
    g_v1Slope_mf_rmSpec[2] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_lam_v1Slope, 0, RQMDrmf_rmSpec_lam_v1Slope_staErr);
    g_v1Slope_mf_rmSpec[3] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_lam_v1Slope, 0, RQMDrmf_rmSpec_lam_v1Slope_staErr);

    g_Int_v2_cas[0] = new TGraphErrors(nEnergy, FXT_energy, cas_piP_v2, 0, cas_piP_v2_staErr);
    g_Int_v2_cas[1] = new TGraphErrors(nEnergy, FXT_energy, cas_piM_v2, 0, cas_piM_v2_staErr);
    g_Int_v2_cas[2] = new TGraphErrors(nEnergy, FXT_energy, cas_K0_v2, 0, cas_K0_v2_staErr);
    g_Int_v2_cas[3] = new TGraphErrors(nEnergy, FXT_energy, cas_lam_v2, 0, cas_lam_v2_staErr);

    g_Int_v2_mf[0] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_piP_v2, 0, RQMDrmf_piP_v2_staErr);
    g_Int_v2_mf[1] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_piM_v2, 0, RQMDrmf_piM_v2_staErr);
    g_Int_v2_mf[2] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_K0_v2, 0, RQMDrmf_K0_v2_staErr);
    g_Int_v2_mf[3] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_lam_v2, 0, RQMDrmf_lam_v2_staErr);

    g_Int_v2_mf_rmSpec[0] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_piP_v2, 0, RQMDrmf_rmSpec_piP_v2_staErr);
    g_Int_v2_mf_rmSpec[1] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_piM_v2, 0, RQMDrmf_rmSpec_piM_v2_staErr);
    g_Int_v2_mf_rmSpec[2] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_K0_v2, 0, RQMDrmf_rmSpec_K0_v2_staErr);
    g_Int_v2_mf_rmSpec[3] = new TGraphErrors(nEnergy, FXT_energy, RQMDrmf_rmSpec_lam_v2, 0, RQMDrmf_rmSpec_lam_v2_staErr);


    for(int i=0; i<nPart; i++)
    {
        g_v1Slope[i]->SetMarkerSize(1.8);
        g_Int_v2[i]->SetMarkerSize(1.8);

        g_v1Slope_cas[i]->SetFillColorAlpha(4, 0.2); 
        g_Int_v2_cas[i]->SetFillColorAlpha(4, 0.2); 
        //g_v1Slope_cas[i]->SetFillStyle(3002); 
        //g_Int_v2_cas[i]->SetFillStyle(3002); 

        g_Int_v2_mf[i]->SetFillColorAlpha(46, 0.2);  
        g_Int_v2_mf_rmSpec[i]->SetFillColorAlpha(1, 0.2);  
        g_v1Slope_mf[i]->SetFillColorAlpha(46, 0.2);
        g_v1Slope_mf_rmSpec[i]->SetFillColorAlpha(1, 0.2);

        //g_Int_v2_mf[i]->SetFillStyle(3002);  
        //g_v1Slope_mf[i]->SetFillStyle(3002);
        //g_Int_v2_mf_rmSpec[i]->SetFillStyle(3002);  
        //g_v1Slope_mf_rmSpec[i]->SetFillStyle(3002);


        if(i==0 || i==1)
        {
            g_v1Slope[i]->SetMarkerColor(2); 
            g_v1Slope[i]->SetLineColor(2);
            g_Int_v2[i]->SetMarkerColor(2); 
            g_Int_v2[i]->SetLineColor(2);

            if(i==0)
            {
                g_v1Slope[i]->SetMarkerStyle(21);
                g_Int_v2[i]->SetMarkerStyle(21);
            }
            if(i==1)
            {
                g_v1Slope[i]->SetMarkerStyle(25);
                g_Int_v2[i]->SetMarkerStyle(25);
            } 

            g_v1Slope_sys[i]->SetFillColorAlpha(2, 0.2); 
            g_Int_v2_sys[i]->SetFillColorAlpha(2, 0.2); 
            g_v1Slope_sys[i]->SetLineWidth(0); 
            g_Int_v2_sys[i]->SetLineWidth(0); 

        }
        if(i==2)
        {
            g_v1Slope[i]->SetMarkerColor(4); 
            g_v1Slope[i]->SetLineColor(4);
            g_v1Slope[i]->SetMarkerStyle(23);
            g_Int_v2[i]->SetMarkerColor(4); 
            g_Int_v2[i]->SetLineColor(4);
            g_Int_v2[i]->SetMarkerStyle(23);

            g_v1Slope_sys[i]->SetFillColorAlpha(4, 0.2); 
            g_Int_v2_sys[i]->SetFillColorAlpha(4, 0.2); 
            g_v1Slope_sys[i]->SetLineWidth(0); 
            g_Int_v2_sys[i]->SetLineWidth(0); 
        }
        if(i==3)
        {
            g_v1Slope[i]->SetMarkerColor(1);
            g_v1Slope[i]->SetLineColor(1);
            g_v1Slope[i]->SetMarkerStyle(20);
            g_Int_v2[i]->SetMarkerColor(1);
            g_Int_v2[i]->SetLineColor(1);
            g_Int_v2[i]->SetMarkerStyle(20);


            g_v1Slope_sys[i]->SetFillColorAlpha(1, 0.2); 
            g_Int_v2_sys[i]->SetFillColorAlpha(1, 0.2); 
            g_v1Slope_sys[i]->SetLineWidth(0); 
            g_Int_v2_sys[i]->SetLineWidth(0); 

        }

    }

    auto leg1 = new TLegend(0.626387,0.758934,0.913173,0.96041,"");
    leg1->SetFillColor(0);
    leg1->SetBorderSize(0);
    leg1->AddEntry(g_v1Slope[0],"#pi^{ +}", "p");
    leg1->AddEntry(g_v1Slope[1],"#pi^{ -}", "p");

    auto leg12 = new TLegend(0.793679,0.760255,0.925122,0.939694,"");
    leg12->SetFillColor(0);
    leg12->SetBorderSize(0);
    leg12->AddEntry(g_v1Slope[3],"#Lambda", "p");
    leg12->AddEntry(g_v1Slope[2],"K^{0}_{S}", "p");

    auto leg2 = new TLegend(0.56186,0.189914,0.946631,0.35250,"");
    leg2->SetFillColor(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(g_v1Slope_cas[3],"Cascade", "f");
    leg2->AddEntry(g_v1Slope_mf[3],"Mean Field", "f");
    leg2->AddEntry(g_v1Slope_mf_rmSpec[3],"MF w/o Spectator", "f");

    TCanvas *c1 = new TCanvas("c1","",500,800);
    c1->cd();
    TPad *p1=new TPad("p1", "", 0.05, 0.05, 0.99, 0.99); p1->Draw(); p1->cd();
    p1->Divide(1,2,0,0); 

    TH2F *hf1 = new TH2F("hf1","",10, 2.9, 4.1, 10, -0.05, 0.35);
    TH2F *hf2 = new TH2F("hf2","",10, 2.9, 4.1, 10, -0.032, 0.045);
    hf1->GetYaxis()->SetLabelSize(0.06);

    p1->cd(1);
    gPad->SetTicks(1,1);
    hf1->Draw();
    for(int i=0; i<nPart; i++)
    {
        g_v1Slope[i]->Draw("EP Same");
        g_v1Slope_sys[i]->Draw("e5 Same");
    }
    g_v1Slope_cas[3]->Draw("E3 Same");
    g_v1Slope_mf[3]->Draw("E3 Same");
    g_v1Slope_mf_rmSpec[3]->Draw("E3 Same");

    leg1->Draw("Same");
    leg12->Draw("Same");
    LineY1(0, 1 ,2);
    drawText(0.200736,0.353158, "#splitline{STAR preliminary}{Au+Au, 10-40%}", 42, 0.055);
    drawText(0.540736,0.32789, "#splitline{#pi/K^{0}_{S}: 0.2/0.4 < p_{T} < 1.6}{#Lambda: 0.4 < p_{T} < 2.0}", 42, 0.055);
    

    p1->cd(2);
    gPad->SetTicks(1,1);
    hf2->Draw();
    for(int i=0; i<nPart; i++)
    {
        g_Int_v2[i]->Draw("EP Same");
        g_Int_v2_sys[i]->Draw("e5 Same");
    }
    g_Int_v2_cas[3]->Draw("E3 Same");
    g_Int_v2_mf[3]->Draw("E3 Same");
    g_Int_v2_mf_rmSpec[3]->Draw("E3 Same");

    LineY1(0, 1 ,2);
    leg2->Draw("Same");
    drawText(0.6, 0.35, "#Lambda JAM2", 42, 0.06); // #Lambda


    c1->cd();
    drawText(0.257028,0.0541935, "Collision Energy #sqrt{s_{NN}} (GeV)", 42, 0.05);
    drawText(0.060241,0.717419, "dv_{1}/dy|_{y=0}", 42, 0.05, 90);
    drawText(0.080241,0.317419, "< v_{2}>", 42, 0.045, 90);


    c1->SaveAs("OutputFile/fig3_v1v2_energyDependence.pdf");


}

