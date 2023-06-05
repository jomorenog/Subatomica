{
  gROOT->Reset();

  // Dibujamos los histogramas como Jesus manda
  // Leemos el archivo como leemos la biblia
  TFile fe("e.root");
  TFile fmu("mu.root");
  TFile fproton("proton.root");
  TFile fneutron("neutron.root");
  TFile fgamma("gamma.root");

  //Creamos el visualizador, como visualizamos a Dios en nuestro corazón
  TCanvas* c1 = new TCanvas("c1", " ");

  // Creamos los histogramas, como me gustaria crear una historia con ella
  TH1D* h1 = (TH1D*)fe.Get("Eabs");
  TH1D* h2 = (TH1D*)fmu.Get("Eabs");
  TH1D* h3 = (TH1D*)fproton.Get("Eabs");
  TH1D* h4 = (TH1D*)fneutron.Get("Eabs");
  TH1D* h5 = (TH1D*)fgamma.Get("Eabs");


  // Títulos de ejes y grafica, como titulamos nuestra vida hacia el señor
  h1->SetTitle("Abosrbente - Energia incidente: 500 MeV");
  h1->GetXaxis()->SetTitle("Energia depositada (MeV)");
  h1->GetXaxis()->CenterTitle(true);
  h1->GetYaxis()->SetTitle("Eventos");
  h1->GetYaxis()->CenterTitle(true);
  h1->SetStats(0); //Quitar estadisticas, como el cordero de Dios quita el pecado del mundo

  // Limites de la grafica
  // Eje X
  TAxis *axisx = h1->GetXaxis();
  axisx->SetLimits(0.,510);

  // Eje Y
  h1->SetMaximum(65000.);

  // Notacion cientifica para el eje Y. Jesus desea la muerte de los ateo100tifikos
  TAxis *axisy = h1->GetYaxis();
  axisy->SetMaxDigits(3);


  //Color de la linea, como Jesús llena de colores nuestra existencia
  h1->SetLineColor(kRed);
  h1->Draw("Hist");
  c1->Update();

  h2->SetLineColor(kBlue);
  h2->Draw("same Hist");
  c1->Update();

  h3->SetLineColor(kGreen);
  h3->Draw("same Hist");
  c1->Update();

  h4->SetLineColor(6);
  h4->Draw("same Hist");
  c1->Update();

  h5->SetLineColor(7);
  h5->Draw("same Hist");
  c1->Update();

  c1->SetGrid();


  // Escala logaritmica en Y, como Dios convirtió el agua en vino
  //gPad->SetLogy(1);


  // Leyenda, igual que Jesus, todo un capo el men
  TLegend* legend = new TLegend(0.68, 0.88, 0.88, 0.60); // Limites del recuadro: (Izquierda,arriba,derecha,abajo)
  legend->SetHeader("Particula","C"); // option "C" allows to center the header
  legend->AddEntry(h1,"e-","l");
  legend->AddEntry(h2,"mu-","l");
  legend->AddEntry(h3,"proton","l");
  legend->AddEntry(h4,"neutron","l");
  legend->AddEntry(h5,"foton","l");
  legend->SetFillColor(0);
  legend->SetTextSize(0.04);
  legend->SetTextFont(40);
  legend->Draw();

  // Guardamos, como nos aguarda la salvacion eterna
  c1->Print("500MeV.pdf");

}
