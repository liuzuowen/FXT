#include "Utility/useful.h"
#include "Utility/draw.C"
#include "DataFile/3GeV/3gev_ksl_phi.h"
#include "DataFile/3GeV/3gev_vn_sys.h"

void fig2_v1v2VSy(){

    SetMyStyle();
    gStyle->SetFrameLineWidth(1);
    gStyle->SetLineWidth(1);

    const int nEnergy = 4;
    const int nPart = 4; // 0 = pi+; 1 = pi-; 2 = K0s; 3 = lambda

    // Read rootfile
    TFile *f[nEnergy][5];

    // exp. data
    f[0][0] = new TFile("/Users/liuzw/WorkSpace/3GeV/piKp/InputFile/3GeV_pionFlow.root");
    f[1][0] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/piKp/InputFile/OtherEnergies/pion_3p2GeV.root");
    f[2][0] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/piKp/InputFile/pionFlow_newPID.root");
    f[3][0] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/piKp/InputFile/OtherEnergies/pion_3p9GeV.root");

    // JAM2 cascade
    f[0][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3GeV_cascade.root");
    f[1][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p2_cascade.root");
    f[2][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p5_cascade.root");
    f[3][1] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p9_cascade.root");

    // JAM2 cascade w/o spectator
    f[0][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3GeV_cascade_rmSpectator.root");
    f[1][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p2_cascade_rmSpectator.root");
    f[2][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p5_cascade_rmSpectator.root");
    f[3][2] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p9_cascade_rmSpectator.root");

    // JAM2 RQMD/RMF
    f[0][3] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3GeV_RQMD_RMF.root");
    f[1][3] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p2_RQMD_RMF.root");
    f[2][3] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p5_RQMD_RMF.root");
    f[3][3] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p9_RQMD_RMF.root");

    // JAM2 RQMD/RMF w/o spectator
    f[0][4] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3GeV_RQMD_RMF_rmSpectator.root");
    f[1][4] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p2_RQMD_RMF_rmSpectator.root");
    f[2][4] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p5_RQMD_RMF_rmSpectator.root");
    f[3][4] = new TFile("/Users/liuzw/WorkSpace/3_5GeV/Model/InputFile/JAM/3p9_RQMD_RMF_rmSpectator.root");



    TGraphErrors *g_v1y[nEnergy][nPart];
    TGraphErrors *g_v2y[nEnergy][nPart];
    TGraphErrors *g_v1y_sys[nEnergy][nPart];
    TGraphErrors *g_v2y_sys[nEnergy][nPart];

    TGraphErrors *g_v1y_cas[nEnergy][nPart];
    TGraphErrors *g_v2y_cas[nEnergy][nPart];
    TGraphErrors *g_v1y_mf[nEnergy][nPart];
    TGraphErrors *g_v2y_mf[nEnergy][nPart];
    TGraphErrors *g_v1y_cas_rmSpec[nEnergy][nPart];
    TGraphErrors *g_v2y_cas_rmSpec[nEnergy][nPart];
    TGraphErrors *g_v1y_mf_rmSpec[nEnergy][nPart];
    TGraphErrors *g_v2y_mf_rmSpec[nEnergy][nPart];

    // get v1/v2 from exp.
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            if(j==0)
            {
                g_v1y[0][j] = new TGraphErrors(10, y_pip_3gev,  v1y_pip_val, 0, v1y_pip_err);
                g_v2y[0][j] = new TGraphErrors(10, y_pip_3gev,  v2y_pip_val, 0, v2y_pip_err);
                g_v1y_sys[0][j] = new TGraphErrors(10, y_pip_3gev,  v1y_pip_val, yErr_pip_3gev, v1y_pip_sys);
                g_v2y_sys[0][j] = new TGraphErrors(10, y_pip_3gev,  v2y_pip_val, yErr_pip_3gev, v2y_pip_sys);

                g_v1y[1][j] = new TGraphErrors("DataFile/3p2GeV/pionp_v1_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v2y[1][j] = new TGraphErrors("DataFile/3p2GeV/pionp_v2_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/pionp_v1_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/pionp_v2_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[2][j] = new TGraphErrors("DataFile/3p5GeV/pionp_v1_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v2y[2][j] = new TGraphErrors("DataFile/3p5GeV/pionp_v2_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/pionp_v1_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/pionp_v2_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[3][j] = new TGraphErrors("DataFile/3p9GeV/pionp_v1y_Cent1.txt", "%lg %lg %lg %lg");
                g_v2y[3][j] = new TGraphErrors("DataFile/3p9GeV/pionp_v2y_Cent1.txt", "%lg %lg %lg %lg");
                g_v1y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/pionp_v1y_Cent1_syserr.txt", "%lg %lg %lg %lg");
                g_v2y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/pionp_v2y_Cent1_syserr.txt", "%lg %lg %lg %lg");
            } 
            if(j==1)
            {
                g_v1y[0][j] = new TGraphErrors(10, y_pim_3gev,  v1y_pim_val, 0, v1y_pim_err);
                g_v2y[0][j] = new TGraphErrors(10, y_pim_3gev,  v2y_pim_val, 0, v2y_pim_err);
                g_v1y_sys[0][j] = new TGraphErrors(10, y_pim_3gev,  v1y_pim_val, yErr_pim_3gev, v1y_pim_sys);
                g_v2y_sys[0][j] = new TGraphErrors(10, y_pim_3gev,  v2y_pim_val, yErr_pim_3gev, v2y_pim_sys);

                g_v1y[1][j] = new TGraphErrors("DataFile/3p2GeV/pionm_v1_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v2y[1][j] = new TGraphErrors("DataFile/3p2GeV/pionm_v2_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/pionm_v1_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/pionm_v2_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[2][j] = new TGraphErrors("DataFile/3p5GeV/pionm_v1_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v2y[2][j] = new TGraphErrors("DataFile/3p5GeV/pionm_v2_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/pionm_v1_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/pionm_v2_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[3][j] = new TGraphErrors("DataFile/3p9GeV/pionm_v1y_Cent1.txt", "%lg %lg %lg %lg");
                g_v2y[3][j] = new TGraphErrors("DataFile/3p9GeV/pionm_v2y_Cent1.txt", "%lg %lg %lg %lg");
                g_v1y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/pionm_v1y_Cent1_syserr.txt", "%lg %lg %lg %lg");
                g_v2y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/pionm_v2y_Cent1_syserr.txt", "%lg %lg %lg %lg");
            } 
            if(j==2)
            {
                g_v1y[0][j] = new TGraphErrors(10, yy_ks0,  v1val_ks0, 0, v1err_ks0);
                g_v1y_sys[0][j] = new TGraphErrors(10, yy_ks0,  v1val_ks0, yyErr_ks0, v1sys_ks0);
                g_v2y[0][j] = new TGraphErrors(2, y_ks0,  v2val_ks0, 0, v2err_ks0);
                g_v2y_sys[0][j] = new TGraphErrors(2, y_ks0,  v2val_ks0, yErr_ks0, v2sys_ks0);

                g_v1y[1][j] = new TGraphErrors("DataFile/3p2GeV/K0s_v1_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/K0s_v1_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[1][j] = new TGraphErrors("DataFile/3p2GeV/K0s_v2_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/K0s_v2_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[2][j] = new TGraphErrors("DataFile/3p5GeV/K0s_v1_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/K0s_v1_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[2][j] = new TGraphErrors("DataFile/3p5GeV/K0s_v2_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/K0s_v2_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
                
                g_v1y[3][j] = new TGraphErrors("DataFile/3p9GeV/K0s_v1_rap_cent1040_3.9GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/K0s_v1_rap_cent1040_3.9GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[3][j] = new TGraphErrors("DataFile/3p9GeV/K0s_v2_rap_cent1040_3.9GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/K0s_v2_rap_cent1040_3.9GeV_sysErr.dat", "%lg %lg %lg %lg");
            }

            if(j==3)
            {
                g_v1y[0][j] = new TGraphErrors(10, yy_lam,  v1val_lam, 0, v1err_lam);
                g_v1y_sys[0][j] = new TGraphErrors(10, yy_lam,  v1val_lam, yyErr_lam, v1sys_lam);
                g_v2y[0][j] = new TGraphErrors(4, y_lam,  v2val_lam, 0, v2err_lam);
                g_v2y_sys[0][j] = new TGraphErrors(4, y_lam,  v2val_lam, yErr_lam, v2sys_lam);

                g_v1y[1][j] = new TGraphErrors("DataFile/3p2GeV/lambda_v1_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/lambda_v1_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[1][j] = new TGraphErrors("DataFile/3p2GeV/lambda_v2_rap_cent1040_3.2GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[1][j] = new TGraphErrors("DataFile/3p2GeV/lambda_v2_rap_cent1040_3.2GeV_sysErr.dat", "%lg %lg %lg %lg");

                g_v1y[2][j] = new TGraphErrors("DataFile/3p5GeV/lambda_v1_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/lambda_v1_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[2][j] = new TGraphErrors("DataFile/3p5GeV/lambda_v2_rap_cent1040_3.5GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[2][j] = new TGraphErrors("DataFile/3p5GeV/lambda_v2_rap_cent1040_3.5GeV_sysErr.dat", "%lg %lg %lg %lg");
        
                
                g_v1y[3][j] = new TGraphErrors("DataFile/3p9GeV/lambda_v1_rap_cent1040_3.9GeV.dat", "%lg %lg %lg %lg");
                g_v1y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/lambda_v1_rap_cent1040_3.9GeV_sysErr.dat", "%lg %lg %lg %lg");
                g_v2y[3][j] = new TGraphErrors("DataFile/3p9GeV/lambda_v2_rap_cent1040_3.9GeV.dat", "%lg %lg %lg %lg");
                g_v2y_sys[3][j] = new TGraphErrors("DataFile/3p9GeV/lambda_v2_rap_cent1040_3.9GeV_sysErr.dat", "%lg %lg %lg %lg");

            }
        }
    }


    // get v1/v2 from model
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            if(j==0)
            {
                g_v1y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v1y_pip_cent11");
                g_v2y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v2y_pip_cent11");
                g_v1y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v1y_pip_cent11");
                g_v2y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v2y_pip_cent11");
                g_v1y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v1y_pip_cent11");
                g_v2y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v2y_pip_cent11");
                g_v1y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v1y_pip_cent11");
                g_v2y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v2y_pip_cent11");
            }
            if(j==1)
            {
                g_v1y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v1y_pim_cent11");
                g_v2y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v2y_pim_cent11");
                g_v1y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v1y_pim_cent11");
                g_v2y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v2y_pim_cent11");
                g_v1y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v1y_pim_cent11");
                g_v2y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v2y_pim_cent11");
                g_v1y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v1y_pim_cent11");
                g_v2y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v2y_pim_cent11");
            }
            if(j==2)
            {
                g_v1y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v1y_K0_cent11");
                g_v2y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v2y_K0_cent11");
                g_v1y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v1y_K0_cent11");
                g_v2y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v2y_K0_cent11");
                g_v1y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v1y_K0_cent11");
                g_v2y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v2y_K0_cent11");
                g_v1y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v1y_K0_cent11");
                g_v2y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v2y_K0_cent11");
            }
            if(j==3)
            {
                g_v1y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v1y_lam_cent11");
                g_v2y_cas[i][j] = (TGraphErrors*)f[i][1]->Get("p_v2y_lam_cent11");
                g_v1y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v1y_lam_cent11");
                g_v2y_cas_rmSpec[i][j] = (TGraphErrors*)f[i][2]->Get("p_v2y_lam_cent11");
                g_v1y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v1y_lam_cent11");
                g_v2y_mf[i][j] = (TGraphErrors*)f[i][3]->Get("p_v2y_lam_cent11");
                g_v1y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v1y_lam_cent11");
                g_v2y_mf_rmSpec[i][j] = (TGraphErrors*)f[i][4]->Get("p_v2y_lam_cent11");
            }
        }
    }



    // set style
    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<nPart; j++)
        {
            g_v1y[i][j]->SetMarkerSize(2);
            g_v2y[i][j]->SetMarkerSize(2);
            g_v1y[i][0]->SetMarkerStyle(21);
            g_v2y[i][0]->SetMarkerStyle(21);
            g_v1y[i][1]->SetMarkerStyle(25);
            g_v2y[i][1]->SetMarkerStyle(25);
            g_v1y[i][2]->SetMarkerStyle(23);
            g_v2y[i][2]->SetMarkerStyle(23);
            g_v1y[i][3]->SetMarkerStyle(20);
            g_v2y[i][3]->SetMarkerStyle(20);

            g_v1y[i][0]->SetMarkerColor(2);
            g_v2y[i][0]->SetMarkerColor(2);
            g_v1y[i][1]->SetMarkerColor(2);
            g_v2y[i][1]->SetMarkerColor(2);
            g_v1y[i][0]->SetLineColor(2);
            g_v2y[i][0]->SetLineColor(2);
            g_v1y[i][1]->SetLineColor(2);
            g_v2y[i][1]->SetLineColor(2);

            g_v1y_sys[i][0]->SetFillColorAlpha(2, 0.5);
            g_v2y_sys[i][0]->SetFillColorAlpha(2, 0.5);
            g_v1y_sys[i][1]->SetFillColorAlpha(2, 0.5);
            g_v2y_sys[i][1]->SetFillColorAlpha(2, 0.5);
            g_v1y_sys[i][0]->SetLineWidth(0);
            g_v2y_sys[i][0]->SetLineWidth(0);
            g_v1y_sys[i][1]->SetLineWidth(0);
            g_v2y_sys[i][1]->SetLineWidth(0);
            

            g_v1y[i][2]->SetMarkerColor(4);
            g_v2y[i][2]->SetMarkerColor(4);
            g_v1y[i][3]->SetMarkerColor(1);
            g_v2y[i][3]->SetMarkerColor(1);
            g_v1y[i][2]->SetLineColor(4);
            g_v2y[i][2]->SetLineColor(4);
            g_v1y[i][3]->SetLineColor(1);
            g_v2y[i][3]->SetLineColor(1);

            g_v1y_sys[i][2]->SetFillColorAlpha(4, 0.5);
            g_v2y_sys[i][2]->SetFillColorAlpha(4, 0.5);
            g_v1y_sys[i][3]->SetFillColorAlpha(1, 0.5);
            g_v2y_sys[i][3]->SetFillColorAlpha(1, 0.5);
            g_v1y_sys[i][2]->SetLineWidth(0);
            g_v2y_sys[i][2]->SetLineWidth(0);
            g_v1y_sys[i][3]->SetLineWidth(0);
            g_v2y_sys[i][3]->SetLineWidth(0);


            // model
            g_v1y_cas[i][2]->SetFillColorAlpha(4, 0.3);
            g_v2y_cas[i][2]->SetFillColorAlpha(4, 0.3);
            //g_v1y_cas[i][2]->SetFillStyle(3002);
            //g_v2y_cas[i][2]->SetFillStyle(3002);
            g_v1y_cas_rmSpec[i][2]->SetFillColorAlpha(4, 0.3);
            g_v2y_cas_rmSpec[i][2]->SetFillColorAlpha(4, 0.3);
            //g_v1y_cas_rmSpec[i][2]->SetFillStyle(3002);
            //g_v2y_cas_rmSpec[i][2]->SetFillStyle(3002);

            g_v1y_mf[i][2]->SetFillColorAlpha(46, 0.3);
            g_v2y_mf[i][2]->SetFillColorAlpha(46, 0.3);
            //g_v1y_mf[i][2]->SetFillStyle(3002);
            //g_v2y_mf[i][2]->SetFillStyle(3002);
            g_v1y_mf_rmSpec[i][2]->SetFillColorAlpha(1, 0.3);
            g_v2y_mf_rmSpec[i][2]->SetFillColorAlpha(1, 0.3);
            //g_v1y_mf_rmSpec[i][2]->SetFillStyle(3002);
            //g_v2y_mf_rmSpec[i][2]->SetFillStyle(3002);

            g_v1y_cas[i][3]->SetMarkerColor(0);
            g_v1y_cas[i][3]->SetFillColorAlpha(4, 0.1);
            g_v2y_cas[i][3]->SetMarkerColor(0);
            g_v2y_cas[i][3]->SetFillColorAlpha(4, 0.1);
            //g_v1y_cas[i][3]->SetFillStyle(3002);
            //g_v2y_cas[i][3]->SetFillStyle(3002);
            g_v1y_cas_rmSpec[i][3]->SetFillColorAlpha(4, 0.1);
            g_v2y_cas_rmSpec[i][3]->SetFillColorAlpha(4, 0.1);
            //g_v1y_cas_rmSpec[i][3]->SetFillStyle(3002);
            //g_v2y_cas_rmSpec[i][3]->SetFillStyle(3002);

            g_v1y_mf[i][3]->SetMarkerColor(0);
            g_v1y_mf[i][3]->SetFillColorAlpha(46, 0.1);
            g_v2y_mf[i][3]->SetMarkerColor(0);
            g_v2y_mf[i][3]->SetFillColorAlpha(46, 0.1);
            //g_v1y_mf[i][3]->SetFillStyle(3002);
            //g_v2y_mf[i][3]->SetFillStyle(3002);
            g_v1y_mf_rmSpec[i][3]->SetMarkerColor(0);
            g_v1y_mf_rmSpec[i][3]->SetFillColorAlpha(1, 0.1);
            g_v2y_mf_rmSpec[i][3]->SetMarkerColor(0);
            g_v2y_mf_rmSpec[i][3]->SetFillColorAlpha(1, 0.1);
            //g_v1y_mf_rmSpec[i][3]->SetFillStyle(3002);
            //g_v2y_mf_rmSpec[i][3]->SetFillStyle(3002);
        }
    }


    auto leg1 = new TLegend(0.641054,0.042669,0.956094,0.515209, "");
    leg1->SetFillColor(0);
    leg1->SetBorderSize(0);
    leg1->AddEntry(g_v1y[0][0],"#pi^{ +}", "p");
    leg1->AddEntry(g_v1y[0][1],"#pi^{ -}", "p");
    leg1->AddEntry(g_v1y[0][2],"K^{0}_{S}", "p");
    leg1->AddEntry(g_v1y[0][3],"#Lambda", "p");

    auto leg2 = new TLegend(0.354052,0.0221238,0.924862,0.284075, "");
    leg2->SetFillColor(0);
    leg2->SetBorderSize(0);
    leg2->AddEntry(g_v1y_cas[0][2],"Cascade", "f");
    leg2->AddEntry(g_v1y_mf[0][2],"Mean Field", "f");
    leg2->AddEntry(g_v1y_mf_rmSpec[0][2],"MF w/o Spectator", "f");


    // draw on canvas
    TCanvas *c1 = new TCanvas("c1","",2200,1000);
    c1->cd();
    TPad *p1=new TPad("p1", "", 0.05, 0.05, 0.99, 0.99); p1->Draw(); p1->cd();
    p1->Divide(4,2,0,0); 

    TH2D *hf[4][2];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<2; j++)
        {
            hf[i][j] = new TH2D(Form("hf_%d%d", i, j),"", 100, -1.5,0.5, 100,-0.5,0.5);

            hf[i][j]->GetXaxis()->SetRangeUser(-1.03,0.03);
            if(j==0) hf[i][j]->GetYaxis()->SetRangeUser(-0.45,0.08);
            if(j==1) hf[i][j]->GetYaxis()->SetRangeUser(-0.04,0.065);

            hf[i][j]->GetXaxis()->SetLabelOffset(0.02);
            hf[i][j]->GetYaxis()->SetLabelOffset(0.02);
            hf[i][j]->GetXaxis()->SetLabelSize(0.08);
            hf[i][j]->GetYaxis()->SetLabelSize(0.08);
            if(j==0) hf[i][j]->GetYaxis()->SetLabelSize(0.1);
            
        }
    }


    for(int i=0; i<nEnergy; i++)
    {
        for(int j=0; j<2; j++)
        {
            p1->cd(nEnergy*j+i+1);
            gPad->SetTicks(1,1);
            hf[i][j]->Draw();

            for(int k=0; k<nPart; k++)
            {
                if(j==0)
                {
                    g_v1y[i][k]->Draw("EP Same");
                    g_v1y_sys[i][k]->Draw("e5");
                    
                    g_v1y_cas[i][3]->Draw("E3 Same"); // only K0s
                    //g_v1y_cas_rmSpec[i][2]->Draw("E3 Same");
                    g_v1y_mf[i][3]->Draw("E3 Same"); 
                    g_v1y_mf_rmSpec[i][3]->Draw("E3 Same");
                }
                if(j==1)
                {
                    g_v2y[i][k]->Draw("EP Same");
                    g_v2y_sys[i][k]->Draw("e5");
                    
                    g_v2y_cas[i][3]->Draw("E3 Same");
                    //g_v2y_cas_rmSpec[i][2]->Draw("E3 Same");
                    g_v2y_mf[i][3]->Draw("E3 Same");
                    g_v2y_mf_rmSpec[i][3]->Draw("E3 Same");
                } 
            }

            LineX1(0,1,2,1);
            LineY1(0,1,2,1);
        }

    }

    c1->cd();

    DrawText(0.447177,0.0273684, "Particle Rapidity y", 42, 0.055);
    DrawText(0.0373406,0.734737, "v_{1}", 42, 0.065, 90);
    DrawText(0.0373406,0.307368, "v_{2}", 42, 0.065, 90);

    p1->cd(1); leg1->Draw("Same");
    p1->cd(2); leg2->Draw("Same"); drawText(0.4, 0.3, "#Lambda JAM2", 42, 0.09); //K^{0}_{S}

    p1->cd(3); drawText(0.200736,0.205789, "#splitline{#pi/K^{0}_{S}: 0.2/0.4 < p_{T} < 1.6}{#Lambda: 0.4 < p_{T} < 2.0}", 42, 0.08);

    p1->cd(5); drawText(0.65, 0.85, "3.0 GeV", 42, 0.08);
    p1->cd(6); drawText(0.60, 0.85, "3.2 GeV", 42, 0.08);
    p1->cd(7); drawText(0.60, 0.85, "3.5 GeV", 42, 0.08);
    p1->cd(8); drawText(0.60, 0.85, "3.9 GeV", 42, 0.08);

    c1->SaveAs("./OutputFile/fig2_v1v2VSy.pdf");




}