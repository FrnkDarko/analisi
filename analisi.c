#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TStyle.h>
#include <TMath.h>
#include <cmath>

void analisi()
{
    TGraph *freq = new TGraph("frequenza_sweep.txt");
    TF1 *f1 = new TF1("f1", "((x^2) * ([0]^2)) / sqrt(((((x^2) * ([0]^2)) - ([1]^2))^2) + ((3 * x * [0] * [1])^2))", 500, 49000);
    f1->SetParameter(0, 0.02157); //L
    f1->SetParameter(1, 1795.5); //R
    TCanvas *c1 = new TCanvas("c1", "Analisi ampiezza");
    gStyle->SetOptFit(0111);
    freq->Fit("f1");
    freq->SetMarkerStyle(1);
    freq->Draw("AP");
    

    TGraph *fase = new TGraph("fase_sweep.txt");
    TF1 *f2 = new TF1("f2", "TMath::ATan((3 * x * [0] * [1]) / (((x^2) * ([0]^2)) - ([1]^2)))", 500, 49000);
    f2->SetParameter(0, 0.02157);
    f2->SetParameter(1, 1795.5); 
    TCanvas *c2 = new TCanvas("c2", "Analisi fase");
    gStyle->SetOptFit(0111);
    fase->Fit("f2");
    fase->SetMarkerStyle(1);
    fase->Draw("AP");
}

