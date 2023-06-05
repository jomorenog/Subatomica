{
  gROOT->Reset();

  // Dibujamos los histogramas como Jesus manda
  //Leemos el archivo como leemos la biblia
  TFile fproton("W-lAr-proton.root");
  TFile feme("W-lAr-eme.root");
  TFile fema("W-lAr-ema.root");
  TFile fneutron("W-lAr-neutron.root");
  
  //Creamos el visualizador, como visualizar a Dios en nuestro corazón
  TCanvas* c1 = new TCanvas("c1", " ");
  // Creamos el histograma, como me gustaria crear una historia con ella
  TH1D* h1 = (TH1D*)fproton.Get("11");
  TH1D* h2 = (TH1D*)feme.Get("11");
  TH1D* h3 = (TH1D*)fema.Get("11");
  TH1D* h4 = (TH1D*)fneutron.Get("11");
  //Color de la linea 
  h3->SetLineColor(kBlack);
  h3->SetStats(0);
  //h3->SetTitle("");
  h3->Draw("Hist");
  h3->GetXaxis()->SetTitle("Capa");
  h3->GetXaxis()->CenterTitle(true);
  h3->GetYaxis()->SetTitle("Energia/evento");
  h3->GetYaxis()->CenterTitle(true);
  
  //hb2->Draw("same Hist" );
  c1->SetLogy(1);
  c1->cd();
  c1->Update();
  
  h2->SetLineColor(kRed);
  h2->Draw("same Hist");
  //hb3->Draw("same Hist" );
  h1->SetLineColor(kBlue);
  h1->Draw("same Hist");
  h4->SetLineColor(kGreen);
  h4->Draw("same Hist");
  //hb1->Draw("same Hist" );
  h3->SetTitle("");
  c1->SetGrid();
  
  // Limites del recuadro:Izquierdo, Arriba, Derechas, Abajo
  TLegend* legend = new TLegend(0.65, 0.88, 0.89, 0.70);
  legend->SetHeader("Particulas","C"); // option "C" allows to center the header
  legend->AddEntry(h1,"Proton","l");
  legend->AddEntry(h2,"e-","l");
  legend->AddEntry(h3,"e+","l");
  legend->AddEntry(h4,"neutron","l");
  legend->SetFillColor(0);
  legend->SetTextSize(0.04);
  legend->SetTextFont(40);
  legend->Draw();
}
