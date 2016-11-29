/*
 * utils.cpp

 *
 *  Created on: 29 lis 2016
 *      Author: Artur Kucia
 */
#include <cmath>
#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TLegend.h>
#include "TCanvas.h"
#include "TMath.h"
#include "TSystem.h"
#include "TLine.h"
#include "TArrow.h"
#include "TStyle.h"
#include "TGraph.h"

#include <iostream>


// define random number generator
TRandom3 rnd;

double getMixGaussian() {



	// define N1(mu1,sigma1)
	double mu1 = 1.0;
	double sigma1 = sqrt(1/3.0);

	// define N2(mu2,sigma2)
	double mu2 = -1.0;
	double sigma2 = sigma1;

	double f = 0.0;
	double x = 0.0;
	double y = 0.0;

	// draw half of the samples from N(mu1,sigma1)
	if (rnd.Rndm() < 0.5){
		// repeat until a good number is found
		while (true) {
			// x in [-5,5]
			x = -5.0 + rnd.Rndm()*10.0;
			// y in [0,1]
			y = rnd.Rndm();
			// f(x)
			f = ( 1/(sigma1*sqrt(2*3.14)) )*exp( -(mu1-x)*(mu1-x)/(2*sigma1*sigma1) );
			if (y < f)
				return x;
		}
	}
	// draw half of the samples from N(mu1,sigma1)
	else {
		// repeat until a good number is found
		while (true) {
			// x in [-5,5]
			x = -5.0 + rnd.Rndm()*10.0;
			// y in [0,1]
			y = rnd.Rndm();
			// g = f(x)
			f = ( 1/(sigma2*sqrt(2*3.14)) )*exp( -(mu2-x)*(mu2-x)/(2*sigma2*sigma2) );
			if (y < f)
				return x;
		}
	}
}

// TODO this function must returns that sample!
void generateSample(const int sampleSize, const char* filename){

	// define histogram     (name, title, n_bins,xmin,xmax)
	 TH1D* h_tran = new TH1D("h_tran", "", 100, -5.0, 5.0);
	 h_tran->GetXaxis()->SetTitle("x") ;
	 h_tran->GetYaxis()->SetTitle("C") ;
	 h_tran->SetLineColor(2) ;
	 h_tran->SetLineWidth(2) ;

	 // fill the histogram with sampled data
	 for(int i=0; i<sampleSize; ++i ){
		 h_tran->Fill( getMixGaussian() ) ;
	 }

	 // add new canvas
	 TCanvas* cnv = new TCanvas( "cnv", "cnv", 1600, 900 ) ;
	 // draw histogram
	 h_tran->Draw() ;
	 h_tran->Draw("SAME") ;
	 // save to pdf file
	 cnv->Print(filename) ;
}
