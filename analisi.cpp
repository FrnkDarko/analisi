#include <TCanvas.h>
#include <TGraph.h>
#include <TF1.h>
#include <TStyle.h>
#include <TMath.h>
#include <cmath>

void analisi()
{
    TGraph *freq = new TGraph("amplitude.txt");
    TF1 *f1 = new TF1("f1", "(2.5*((2 * TMath::Pi() * x)^2) * ([0]^2)) / sqrt((((((2 * TMath::Pi() * x)^2) * ([0]^2)) - ([1]^2))^2) + ((3 * 2 * TMath::Pi() * x * [0] * [1])^2))", 500, 49000);
    f1->SetParameter(0, 0.0470); //L
    f1->SetParameter(1, 820.); //R
    TCanvas *c1 = new TCanvas("c1", "Analisi risposta in frequenza");
    TLegend* legend1 = new TLegend(.1, .7, .3, .9, "Analisi risposta in frequenza");
    legend1->AddEntry(freq, "Punti sperimentali");
    legend1->AddEntry(f1, "Fit");
    gStyle->SetOptFit(1111);
    freq->Fit("f1");
    freq->SetMarkerStyle(1);
    freq->Draw("AP");
    legend1->Draw("S");
    std::cout << "Reduced chi square: " << f1->GetChisquare() / f1->GetNDF() << '\n';
    

    TGraph *fase = new TGraph("phaserad.txt");
    TF1 *f2 = new TF1("f2", "TMath::ATan((3 * 2 * TMath::Pi() * x * [0] * [1]) / ((((2 * TMath::Pi() * x)^2) * ([0]^2)) - ([1]^2)))", 500, 49000);
    f2->SetParameter(0, 0.0470); //L
    f2->SetParameter(1, 820.); //R
    TCanvas *c2 = new TCanvas("c2", "Analisi fase");
    TLegend* legend2 = new TLegend(.1, .7, .3, .9, "Analisi risposta in fase");
    legend2->AddEntry(fase, "Punti sperimentali");
    legend2->AddEntry(f2, "Fit");
    gStyle->SetOptFit(1111);
    fase->Fit("f2");
    fase->SetMarkerStyle(1);
    fase->Draw("AP");
    legend2->Draw("S");
    std::cout << "Reduced chi square: " << f2->GetChisquare() / f2->GetNDF() << '\n';
}

