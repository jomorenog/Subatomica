{
  gROOT->Reset();

  // Dibujamos los histogramas como Jesus manda
  //Leemos el archivo como leemos la biblia
  TFile f("W-lAr.root");

  //Creamos el visualizador, como visualizar a Dios en nuestro corazón
  TCanvas* c1 = new TCanvas("c1", " ");
  // Creamos el histograma, me gustaria crear una historia con ella
  TH1D* h1 = (TH1D*)f.Get("21");
  h1->SetLineColor(kRed);
  h1->Draw("Hist");
  h1->SetTitle("Gay el que lo lea");
  c1->SetGrid();
  
}
