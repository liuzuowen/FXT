// analyses function code 
Double_t Gaussion(Double_t *x_val, Double_t *par)
{
  Double_t x, y;
  x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  y = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  return y;
}

double Gaus2(Double_t *x,Double_t *par) // 2 Gaussians with the same peak
{
  Double_t mu = par[1];
  Double_t sigma1 = par[2];
  Double_t sigma2 = par[4];

  Double_t fitsig = (par[0]/(sigma1*sqrt(2*3.14159265358979323846)))*TMath::Exp(-0.5* ((x[0]-mu)/sigma1)* ((x[0]-mu)/sigma1) ) +
                    (par[3]/(sigma2*sqrt(2*3.14159265358979323846)))*TMath::Exp(-0.5* ((x[0]-mu)/sigma2)* ((x[0]-mu)/sigma2) );
  return fitsig;
}

double Poly2Gauss(Double_t *x,Double_t *par)
{
  Double_t mu = par[1];
  Double_t sigma1 = par[2];
  Double_t sigma2 = par[4];

  Double_t Gaus2 = (par[0]/(sigma1*sqrt(2*3.14159265358979323846)))*TMath::Exp(-0.5* ((x[0]-mu)/sigma1)* ((x[0]-mu)/sigma1) ) +
                    (par[3]/(sigma2*sqrt(2*3.14159265358979323846)))*TMath::Exp(-0.5* ((x[0]-mu)/sigma2)* ((x[0]-mu)/sigma2) );

  Double_t Poly = par[5] + par[6]*x[0];
  //Double_t Poly = par[5] + par[6]*x[0] + par[7]*x[0]*x[0] + par[8]*x[0]*x[0]*x[0] + par[9]*x[0]*x[0]*x[0]*x[0] + par[10]*x[0]*x[0]*x[0]*x[0]*x[0];

  Double_t y = Gaus2 + Poly;

  return y;
}

Double_t Poly(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t y = par[0] + par[1]*x;

  return y;
}

Double_t Poly2(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t y = par[0] + par[1]*x + par[2]*x*x;

  return y;
}

Double_t Poly3(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t y = par[0] + par[1]*x + par[2]*x*x + par[3]*x*x*x ;

  return y;
}

Double_t Poly4(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t y = par[0] + par[1]*x + par[2]*x*x + par[3]*x*x*x + par[4]*x*x*x*x;

  return y;
}

Double_t Poly5(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t y = par[0] + par[1]*x + par[2]*x*x + par[3]*x*x*x + par[4]*x*x*x*x + par[5]*x*x*x*x*x;

  return y;
}

Double_t PolyGauss(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  Double_t Gaus = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  Double_t Poly = par[3] + par[4]*x;

  Double_t y = Gaus + Poly;

  return y;
}

Double_t Poly2_Gauss(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  Double_t Gaus = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  Double_t Poly = par[3] + par[4]*x+par[5]*x*x;

  Double_t y = Gaus + Poly;

  return y;
}

Double_t Poly3_Gauss(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  Double_t Gaus = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  Double_t Poly = par[3] + par[4]*x + par[5]*x*x + par[6]*x*x*x;

  Double_t y = Gaus + Poly;

  return y;
}

Double_t Poly4_Gauss(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  Double_t Gaus = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  Double_t Poly = par[3] + par[4]*x + par[5]*x*x + par[6]*x*x*x + par[7]*x*x*x*x;

  Double_t y = Gaus + Poly;

  return y;
}

Double_t Poly5_Gauss(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];

  Double_t mu = par[0];
  Double_t sigma = par[1];
  Double_t norm = par[2];

  Double_t Gaus = norm*TMath::Exp(-1.0*(x-mu)*(x-mu)/(2.0*sigma*sigma))/(sigma*TMath::Sqrt(2*TMath::Pi()));

  Double_t Poly = par[3] + par[4]*x + par[5]*x*x + par[6]*x*x*x + par[7]*x*x*x*x + par[7]*x*x*x*x*x;

  Double_t y = Gaus + Poly;

  return y;
}

Double_t PolyBreitWigner(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t m0 = par[0];
  Double_t Gamma = par[1];
  Double_t Norm = par[2];

  Double_t denom = 2.0*TMath::Pi()*((x-m0)*(x-m0)+Gamma*Gamma/4.0);
  Double_t BW = Norm*Gamma/denom;

  Double_t Poly = par[3] + par[4]*x;

  Double_t y = BW + Poly;

  return y;
}

Double_t BreitWigner(Double_t *x_val, Double_t *par) 
{
  Double_t x = x_val[0];
  Double_t m0 = par[0];
  Double_t Gamma = par[1];
  Double_t Norm = par[2];

  Double_t denom = 2.0*TMath::Pi()*((x-m0)*(x-m0)+Gamma*Gamma/4.0);
  Double_t BW = Norm*Gamma/denom;

  return BW;
}

Double_t Student_t(Double_t *x_val, Double_t*par)
{
    Double_t x, z;
    Double_t z_x;
    Double_t    nu_x;
    Double_t  mean_x;
    Double_t sigma_x;
    Double_t    norm;
    Double_t      pi;
    pi = TMath::Pi();

    x = x_val[0];
    nu_x = par[0];
    mean_x = par[1];
    sigma_x = par[2];
    norm = par[3];

    z_x = (TMath::Gamma((nu_x+1.0)/2.0)/(TMath::Gamma(nu_x/2.0)*TMath::Sqrt(pi*nu_x)*sigma_x))*TMath::Power((1.0+TMath::Power((x-mean_x)/sigma_x,2.0)/nu_x),(-(nu_x+1.0)/2.0));

    z= norm*z_x;
    return z;
}
Double_t Ploy_Student_t(Double_t *x_val, Double_t*par)
{
    Double_t x, z;
    Double_t z_x;
    Double_t    nu_x;
    Double_t  mean_x;
    Double_t sigma_x;
    Double_t    norm;
    Double_t      pi;
    pi = TMath::Pi();

    x = x_val[0];
    nu_x = par[0];
    mean_x = par[1];
    sigma_x = par[2];
    norm = par[3];

    z_x = (TMath::Gamma((nu_x+1.0)/2.0)/(TMath::Gamma(nu_x/2.0)*TMath::Sqrt(pi*nu_x)*sigma_x))*TMath::Power((1.0+TMath::Power((x-mean_x)/sigma_x,2.0)/nu_x),(-(nu_x+1.0)/2.0));

    Double_t Poly = par[4] + par[5]*x;
    z= norm*z_x+Poly;
    return z;
}

Double_t flow_1(Double_t *x_val, Double_t *par)
{
  Double_t x, y;
  Double_t Ampl, v1;
  x = x_val[0];
  Ampl = par[0];
  v1 = par[1];

  y = Ampl*(1.0 + 2.0*v1*TMath::Cos(x));

  return y;
}

Double_t flow_2(Double_t *x_val, Double_t *par)
{
  Double_t x, y;
  Double_t Ampl, v2;
  x = x_val[0];
  Ampl = par[0];
  v2 = par[1];

  y = Ampl*(1.0 + 2.0*v2*TMath::Cos(2.0*x));

  return y;
}

Double_t flow_1_2(Double_t *x_val, Double_t *par)
{
  Double_t x, y;
  Double_t Ampl, v1, v2;
  x = x_val[0];
  Ampl = par[0];
  v1 = par[1];
  v2 = par[2];

  y = Ampl*(1.0 + 2.0*v1*TMath::Cos(x)+2.0*v2*TMath::Cos(2*x));

  return y;
}

Double_t ErrorAdd(double dx, double dy)
{
  return sqrt(dx*dx+dy*dy);
}
Double_t ErrDiv(Double_t x,Double_t y,Double_t dx, Double_t dy)
{
    return (x/y)*ErrorAdd(dx/x,dy/y);
}

// This three function for calculate full resolution by sub resolution
Double_t resEventPlane(double chi) 
{
  // Calculates the event plane resolution as a function of chi
  double con = 0.626657;                   // sqrt(pi/2)/2
  double arg = chi * chi / 4.;

  Double_t res = con * chi * exp(-arg) * (TMath::BesselI0(arg) +
					  TMath::BesselI1(arg)); 

  return res;
}

double Chi(double res)
{
  // Calculates chi from the event plane resolution
  double chi = 2.0;
  double delta = 1.0;
  for (int i = 0; i < 15; i++) {
    chi = (resEventPlane(chi) < res) ? chi + delta : chi - delta;
    delta = delta / 2.;
  }
  return chi;
}

double res_full(double res_sub)
{
    if (res_sub > 0)
    {
      double chi_sub = Chi(res_sub);
      double res_full = resEventPlane( sqrt(2) * chi_sub);
      return res_full; 
    }
    else return -999.0;
    
}

Double_t Resolution_12(Double_t x_val)
{
    Double_t y;
    Double_t chi = x_val;
    Double_t arg = chi*chi/4.0;
    Double_t norm = TMath::Sqrt(TMath::Pi())/(2.0*TMath::Sqrt(2.0));
    Double_t besselOneHalf = TMath::Sqrt(2.0*arg/TMath::Pi()) * TMath::SinH(arg)/arg;
    Double_t besselThreeHalf = TMath::Sqrt(2.0*arg/TMath::Pi()) * (TMath::CosH(arg)/arg - TMath::SinH(arg)/(arg*arg) );

    y = norm * chi * TMath::Exp(-1.0*arg) * (besselOneHalf + besselThreeHalf);

    return y;
}


template <class T>
// return the length of array
int getArrayLen(T& array)
{
return (sizeof(array) / sizeof(array[0]));
}

// For NCQ scaling, PID v2, v2 vs. KE
//               x value: pt, y: v2,      y err: v2 err,  No. Pt bin, scale factor x and y, mass
void TransformXY(double x[], double y[], double err_y[], int n_bin, int sf_x, int sf_y, double m0);
void TransformXY(double x[], double y[], double err_y[], int n_bin, int sf_x, int sf_y, double m0)
{
    //printf("n_bin is %i, scale factor is %i \n", n_bin, n);
    // Transform x, y and err of y
    for (int i = 0; i < n_bin; i++)
    {
       x[i] = (sqrt(x[i]*x[i]+ m0*m0)-m0)/ sf_x;
       y[i] = y[i]/ sf_y;
       err_y[i] = err_y[i]/ sf_y;
       //printf("The parameters after scale: x is %1.3f, y is %1.3f, err_y is %1.3f \n", x[i], y[i], err_y[i]); 
    }
    
}

