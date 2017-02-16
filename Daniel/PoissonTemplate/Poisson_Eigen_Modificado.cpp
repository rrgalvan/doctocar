#include"Cabecera.h"


int main(void)
{
  MatrixXf m;

  m = Poisson2D<100>(&f,&f);

  cout << "m =" << endl << m << endl;
}
