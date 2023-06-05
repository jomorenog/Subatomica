{
  gROOT->Reset();

  // Dibujamos los histogramas como Jesus manda
  //Leemos el archivo como leemos la biblia
  TFile fwlar("W-lAr10000.root");
  TFile ffesci("Fe-Sci10000.root");
  TFile fpblar("Pb-lAr10000.root");
  
  //Creamos el visualizador, como visualizar a Dios en nuestro corazón
  TCanvas* c1 = new TCanvas("c1", " ");
  // Creamos el histograma, como me gustaria crear una historia con ella
  TH1D* h1 = (TH1D*)fwlar.Get("12");
  TH1D* h2 = (TH1D*)ffesci.Get("12");
  TH1D* h3 = (TH1D*)fpblar.Get("12");

  TLine *l = new TLine(3.46,0,3.46,10);
  auto hb1 = new TH1F("hb", "hb", 1,3.7764, 4.5316);
  auto hb2 = new TH1F("hb", "hb", 1,3.7823, 4.35);
  auto hb3 = new TH1F("hb", "hb", 1,3.1626, 3.7714);
  
  //Color de la linea 
  h2->SetLineColor(kRed);
  h2->SetStats(0);
  h2->SetTitle("Absorbente Activo");
  h2->Draw("Hist");
  h2->GetXaxis()->SetTitle("Capa");
  h2->GetXaxis()->CenterTitle(true);
  h2->GetYaxis()->SetTitle("Energia/Evento (MeV)");
  h2->GetYaxis()->CenterTitle(true);
  //hb2->Draw("same Hist" );
  c1->SetLogy(1);
  c1->cd();
  c1->Update();
  
  h3->SetLineColor(kGreen);
  h3->Draw("same Hist");
  //hb3->Draw("same Hist" );
  h1->SetLineColor(kBlue);
  h1->Draw("same Hist");
  //hb1->Draw("same Hist" );
  //h1->SetTitle("Gay el que lo lea");
  c1->SetGrid();
  
  // Limites del recuadro:Izquierdo, Arriba, Derechas, Abajo
  TLegend* legend = new TLegend(0.2, 0.89, 0.35, 0.70);
  legend->SetHeader("Material","C"); // option "C" allows to center the header
  legend->AddEntry(h1,"W-lAr> 4 mm","l");
  legend->AddEntry(h2,"Fe-Sci> 4 mm","l");
  legend->AddEntry(h3,"Pb-lAr> 4 mm","l");
  legend->SetFillColor(0);
  legend->SetTextSize(0.04);
  legend->SetTextFont(40);
  legend->Draw();
}
