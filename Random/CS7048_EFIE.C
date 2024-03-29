/*******************************************************************************************

************************

		TO CALCULATE THE FIELD SCATTERED FROM AN UNDULATING SURFACE WHICH HAS BEEN 

EXCITED
		BY AN INFINITE LINE SOURCE. SEE PAGE 680 -BALANIS.

********************************************************************************************

***************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <complex>
using namespace std;

#define EXP	    2.718281828
#define PI          3.14159265358979323846
#define CONJ -1
#define NO_CONJ 1
#define TRANS 1

#define complex std::complex<double>

#define SWAP(a,b) tempr=(a);(a)=(b);(b)=tempr


typedef int boolean;
#define TRUE 1
#define FALSE 0

complex    H02(double);
complex	   EiRad(double, int);	
complex    Z(int, int);
complex    Z(double);

complex    Zself(int);

double	   abs(complex);
double     Rself (int);
double     R_source_p(int);
double     R_source_obs(int);
double     R_p_q(int,int);
double     R_surf_obs(int,int);
double	   x(int);
double	   y(int);

/*******************************************************************************************

********************************************

		GLOBAL  VARIABLES

********************************************************************************************

***************************************/

const double  Eamp=1.0; 
double Epsilon_0=8.854e-12;
double Epsilon_d=2.47912e-11;
double Mu_0=12.56637061e-7; 
double c=(1.0/sqrt(Mu_0*Epsilon_0));
double GrossStep=10.0;
double f=970e6; 
double Lambda=c/f; 
double DeltaX=Lambda/4.0;
double Omega=2.0*PI*f;


const complex j=complex(0.0,1.0);
const int GrossNoSteps=70;
const double  Beta_0=Omega*(sqrt(Mu_0*Epsilon_0)), 

Eta_0=sqrt(Mu_0/Epsilon_0), TOL=10e-15;
const int NoLinesubs=(int)((GrossStep*GrossNoSteps)/DeltaX);
const double Xsource = 0.0, Ysource=442.0, I=1.0;

double X[385], Y[385];

int efie ()

{

/*******************************************************************************************

********************************************

		LOCAL  VARIABLES

********************************************************************************************

***************************************/
	cout << "start" << endl;
	FILE *fp; 
	ofstream coutput;
	ifstream cinput;
	ofstream coutput2;

	int i, p, q, n, index;

	double *ModJ = new double [NoLinesubs];
	double *ModEt = new double [NoLinesubs]; 

	complex *J = new complex [NoLinesubs];
	complex *Et = new complex [NoLinesubs];
	complex *Sigma = new complex [NoLinesubs];
	complex SUM;

/*******************************************************************************************

****************************

		READ IN TERRAIN PROFILE DATA
		
********************************************************************************************

********************************/

	fp=fopen("X.04","r");
	for (i=0;i<=384;i++)
	{
		fscanf(fp, "%lf %lf",&X[i],&Y[i]);
	}
	fclose(fp);


	cout << "read file finished" << endl;
/***********calculating the solution for the surface current********************/

	//forward scattering

	J[0]=EiRad(R_source_p(0),0)/Zself(0); 

	for(p=0;p<=NoLinesubs-1;p++)
	{
		
		SUM=complex(0.0,0.0);
		for(q=0;q<p;q++)
		{
			SUM+=R_p_q(q,q+1)*Z(p,q)*J[q];
		}
		J[p]=(EiRad(R_source_p(p),p)-SUM)/Zself(p); //Equation (6)
	}

	cout << "forward scattering finished" << endl;
/***************************output the surface current to a file *******************************************************/

	coutput.open("J.dat");

	for (index=0;index<=NoLinesubs-1;index++)
	{
		coutput << x(index) << "  " << abs(J[index]) << endl;
	}

	coutput.close(); 

/***********calculating the total electric field above the surface********************/
	coutput.open("E.dat");

	for (index=0;index<=NoLinesubs-1;index++)
	{

		Et[index]=complex(0.0,0.0);

		for(n=0;n<=index;n++)
		{
			Et[index]=Et[index]+(J[n]*R_p_q(n,n+1)*Z(R_surf_obs(n,index))); //equation (7) & (8)
		}

		Et[index]=EiRad(R_source_obs(index),index)-Et[index]; //E:t = E:total - E:scatt (?) 
		coutput << x(index) << "  "  << 20.0*log10(abs(Et[index])/sqrt(R_source_obs(index))) << endl;
	}

	coutput.close();

	return 0;

} /* Main*/


double x(int a)
{
  return( (double)a*DeltaX);
}

double y(int a)
{
	double Temp, Prop, s;
	int Index; 

	Temp=((double)a*DeltaX)/GrossStep;
	Index=(int)Temp;
	Prop=Temp-(double)Index;


	s=Y[Index]+(Prop*(Y[Index+1]-Y[Index]));

	return(s);
}

double R_source_p(int p)
{
	return(sqrt(((Xsource-x(p))*(Xsource-x(p)))+((Ysource-y(p))*(Ysource-y(p)))));
}

double R_source_obs(int p)
{
	return(sqrt(((Xsource-x(p))*(Xsource-x(p)))+((Ysource-y(p)-2.4)*(Ysource-y(p)-2.4))));
}

double R_p_q(int p, int q)
{
	return(sqrt(((x(q)-x(p))*(x(q)-x(p)))+((y(q)-y(p))*(y(q)-y(p)))));
}

double R_surf_obs(int p, int q)
{
	return(sqrt(((x(q)-x(p))*(x(q)-x(p)))+(((y(q)+2.4)-y(p))*((y(q)+2.4)-y(p)))));
}

double abs(complex c)
{
	return sqrt((c.real()*c.real()) + (c.imag()*c.imag()));
}

complex EiRad(double dist, int p)
{
	complex E;

	E= -((Beta_0*Beta_0)/(4.0*Omega*Epsilon_0))*H02(Beta_0*dist);

	return(E);
}

complex H02(double Arg)
{
	complex H;
	H=complex(j0(Arg),-y0(Arg));

	return(H);
}

complex Z(int p,int q)
{
	complex H;

	H=((Beta_0*Beta_0)/(4.0*Omega*Epsilon_0))*H02(Beta_0*R_p_q(p,q));


	return(H);
}

complex Z(double R)
{
	complex H;

	H=((Beta_0*Beta_0)/(4.0*Omega*Epsilon_0))*H02(Beta_0*R);


	return(H);
}

complex Zself(int i)
{
	double Linesubln;
	complex H;

	Linesubln=R_p_q(i,i+1);

	H=complex(
		((Beta_0*Beta_0)/(4.0*Omega*Epsilon_0))*Linesubln,
		-((Beta_0*Beta_0)/(4.0*Omega*Epsilon_0))*((2.0*Linesubln)/PI)*log((1.781*Beta_0*Linesubln)/(4.0*EXP))
		);

	return(H);
}

double Exp(double d)
{
	return(exp(d));
}

complex cplx_Exp(double d)
{
	complex result;

	result=complex(cos(d),-sin(d));

	return(result);
}

//int main(){
//	efie();
//	return 0;
//}