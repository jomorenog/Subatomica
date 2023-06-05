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
  TH1D* h1 = (TH1D*)fwlar.Get("2");
  TH1D* h2 = (TH1D*)ffesci.Get("2");
  TH1D* h3 = (TH1D*)fpblar.Get("2");

  double x[] = {3.46, 3.46};
  double y[] = {0, 10};
  double ex[]={0.3, 0.3};
  double ey [] ={0, 0}; 
  auto ge = new TGraphErrors(2, x, y, ex, ey);
  ge->SetFillColor(6);
  ge->SetFillStyle(3005);
  ge->Draw("a4");
  
  TLine *l = new TLine(3.46,0,3.46,10);
  auto hb1 = new TH1F("hb", "hb", 1,3.7764, 4.5316);
  auto hb2 = new TH1F("hb", "hb", 1,3.7823, 4.35);
  auto hb3 = new TH1F("hb", "hb", 1,3.1626, 3.7714);
  
  hb2->SetFillColorAlpha(kRed, 0.60);
  hb2->Fill(4.067, 42);
  hb3->SetFillColorAlpha(kGreen, 0.60);
  hb3->Fill(3.4, 28);
  hb1->SetFillColorAlpha(kBlue, 0.60);
  hb1->Fill(4.154, 38);
  
  //Color de la linea 
  h3->SetLineColor(kGreen);
  h3->SetStats(0);
  h3->SetTitle("Absorbente Activo");
  h3->Draw("Hist");
  h3->GetXaxis()->SetTitle("Energia depositada (MeV)");
  h3->GetXaxis()->CenterTitle(true);
  //hb2->Draw("same Hist" );
  c1->Update();
  
  h2->SetLineColor(kRed);
  h2->Draw("same Hist");
  //hb3->Draw("same Hist" );
  h1->SetLineColor(kBlue);
  h1->Draw("same Hist");
  //hb1->Draw("same Hist" );
  //h1->SetTitle("Gay el que lo lea");
  c1->SetGrid();
  
  // Limites del recuadro:Izquierdo, Arriba, Derechas, Abajo
  TLegend* legend = new TLegend(0.65, 0.88, 0.89, 0.70);
  legend->SetHeader("Materiales","C"); // option "C" allows to center the header
  legend->AddEntry(h1,"W-lAr","l");
  legend->AddEntry(h2,"Fe-Sci","l");
  legend->AddEntry(h3,"Pb-lAr","l");
  legend->SetFillColor(0);
  legend->SetTextSize(0.04);
  legend->SetTextFont(40);
  legend->Draw();
}
