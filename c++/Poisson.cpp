#include<iostream>
#include<stdlib.h>

using namespace std;

float f(float x,float y)
{
    return(x+y);
}

float** Poisson2D(float (*f)(float,float),float (*g)(float,float), int M)
{
  int niter=M*M;
	float h;
	float **v;
	// Calculo h.
	h = 1.0/(M+1);
	// Inicializo u.
	v = (float**)malloc((M+2)*sizeof(float*));
	for(int i=0;i<M+2;i++)
	{
		v[i] = (float*) calloc (M+2,sizeof(float));
	}
    // Cargamos las condiciones de frontera horizontales.
	for(int j=0;j<M+2;j++)
	{
        v[0][j] = g(0,j*h);
        v[M+1][j] = g(1,j*h);
	}
    // Cargamos las condiciones de frontera verticales.
    for(int i=0;i<M;i++)
	{
        v[i+1][0] = g((i+1)*h,0);
        v[i+1][M+1] = g((i+1)*h,1);
	}
    // Rellenamos el resto de la matriz.
	for(int k=0;k<niter;k++)
		for(int i=1;i<M+1;i++)
			for(int j=1;j<M+1;j++)
                v[i][j]=0.25*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-h*h*f(i*h,j*h));
	return(v);
}

void PintarMatriz(float **m,int n)
{
	for(int i=0;i<n+2;i++)
	{
		for(int j=0;j<n+2;j++)
		{
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void LiberarMatriz(float **m, int n)
{
	for(int i=0;i<n+2;i++)
	{
		free(m[i]);
	}
	free(m);
}

int main(void)
{
  int npuntos=100;
	float **m;
	m = Poisson2D(&f,&f,npuntos);
	PintarMatriz(m,npuntos);
	LiberarMatriz(m,npuntos);
}

/*
def Poisson(f,g,M):
    # Cargamos las condiciones de frontera horizontales.
    for j in range(M+2):
        v[0][j] = g(0,j*h)
        v[M+1][j] = g(1,j*h)
    # Cargamos las condiciones de frontera verticales.
    for i in range(M):
        v[i+1][0] = g((i+1)*h,0)
        v[i+1][M+1] = g((i+1)*h,1)
    # Rellenamos el resto de la matriz.
    for k in range(M**2):
        for i in range(1,M+1):
            for j in range(1,M+1):
                v[i][j]=0.25*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-h**2*f(i*h,j*h))
    return(v)
*/
