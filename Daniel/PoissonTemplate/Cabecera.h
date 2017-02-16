#include<iostream>
#include<Eigen/Dense>

using namespace Eigen;
using namespace std;

float f(float x,float y)
{
  return(x+y);
}

template<class T,int M>
class Clase_Poisson2D
{
private:
	// Definimos los valores constantes.
	float h,h2;
	T M;
	// Definimos las matrices.
	// Definimos las matrices
  	//MatrixXf v = MatrixXf::Constant(M+2,M+2,0);
  	//MatrixXf f_val(M,M);
	void calcularhs(void);
/*public:
	void diffin((T (*f)(T,t),T (*g)(T,T)));*/
};

template<class T, int M>
void Clase_Poisson2D::Calcularhs()
{
	h = 1.0/(M+1);
	h2 = h*h;
}

/*
template<class T>
void Clase_Poisson2D::diffin((T (*f)(T,t),T (*g)(T,T)))
{
	// Condiciones de frontera en esquinas
	 v(0,0)   = g(0,0);
	 v(M+1,0) = g(1,0);
	 v(0,M+1)   = g(0,1);
	 v(M+1,M+1) = g(1,1);

	for(int i=0;i<M;i++)
    {
      // Condiciones de frontera verticales
      v(0,i+1)   = g(0,(i+1)*h);
      v(M+1,i+1) = g(1,(i+1)*h);

      // Condiciones de frontera verticales
      v(i+1,0)   = g((i+1)*h,0);
      v(i+1,M+1) = g((i+1)*h,1);

      // Almacenamos los valores de f
      for(int j=0; j<M; j++)
	f_val(i,j) = f((i+1)*h,(j+1)*h);
    }

  // Rellenamos el resto de la matriz
  for(int k=0;k<M;k++)
    v.block<M,M>(1,1) = 0.25 * (v.block(0,1,M,M) + v.block(2,1,M,M)
			       + v.block(1,0,M,M) + v.block(1,2,M,M) + h2*f_val );

}
*/















/*
template<int M>
MatrixXf Poisson2D (float (*f)(float,float),float (*g)(float,float))
{
  // Definimos los valores constantes
  float h, h2;

  // Definimos las matrices
  MatrixXf v = MatrixXf::Constant(M+2,M+2,0);
  MatrixXf f_val(M,M);

  // Calculamos h y h2
  h  = 1.0/(M+1);
  h2 = h*h;

  // Condiciones de frontera en esquinas
  v(0,0)   = g(0,0);
  v(M+1,0) = g(1,0);
  v(0,M+1)   = g(0,1);
  v(M+1,M+1) = g(1,1);

  for(int i=0;i<M;i++)
    {
      // Condiciones de frontera verticales
      v(0,i+1)   = g(0,(i+1)*h);
      v(M+1,i+1) = g(1,(i+1)*h);

      // Condiciones de frontera verticales
      v(i+1,0)   = g((i+1)*h,0);
      v(i+1,M+1) = g((i+1)*h,1);

      // Almacenamos los valores de f
      for(int j=0; j<M; j++)
	f_val(i,j) = f((i+1)*h,(j+1)*h);
    }

  // Rellenamos el resto de la matriz
  for(int k=0;k<M;k++)
    v.block<M,M>(1,1) = 0.25 * (v.block(0,1,M,M) + v.block(2,1,M,M)
			       + v.block(1,0,M,M) + v.block(1,2,M,M) + h2*f_val );

  return(v);
}*/
