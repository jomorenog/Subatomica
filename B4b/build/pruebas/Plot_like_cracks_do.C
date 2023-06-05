{
  gROOT->Reset();

  // Dibujamos los histogramas como Jesus manda
  //Leemos el archivo como leemos la biblia
  TFile fwlar("e.root");
  TFile ffesci("e.root");
  TFile fpblar("e.root");
  
  //Creamos el visualizador, como visualizar a Dios en nuestro corazón
  TCanvas* c1 = new TCanvas("c1", " ");
  // Creamos el histograma, como me gustaria crear una historia con ella
  TH1D* h1 = (TH1D*)fwlar.Get("1");
  TH1D* h2 = (TH1D*)ffesci.Get("1");
  TH1D* h3 = (TH1D*)fpblar.Get("1");

  
  //Color de la linea 
  h2->SetLineColor(kBlue);
  h2->Draw("Hist");
  c1->Update();

  h3->SetLineColor(kGreen);
  h3->Draw("same Hist");
  
  h1->SetLineColor(kRed);
  h1->Draw("same Hist");
  //h1->SetTitle("Gay el que lo lea");
  c1->SetGrid();

  // Limites del recuadro:Izquierdo, Arriba, Derechas, Abajo
  TLegend* legend = new TLegend(0.13, 0.88, 0.45, 0.70);
  legend->SetHeader("Materiales","C"); // option "C" allows to center the header
  legend->AddEntry(h1,"W-lAr","l");
  legend->AddEntry(h2,"Fe-Sci","l");
  legend->AddEntry(h3,"Pb-lAr","l");
  legend->SetFillColor(0);
  legend->SetTextSize(0.04);
  legend->SetTextFont(40);
  legend->Draw();
}
