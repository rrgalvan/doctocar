#include<stdlib.h>
#include<time.h>
#include <unistd.h>

#ifndef __TORO__
#define __TORO__

/// Esta clase almacena contiene la información necesaria para recrear el juego de la vida en un toro.
class Toro
{
private:
	int dimension_x;	/// \param dimension_x Ancho del retículo.
	int dimension_y;	/// \param dimension_y Alto del retículo.
	Celda **m;			/// \param **m	El conjunto de todos las celdas.
	bool extinto;		/// \param extinto Dice si no queda poblacion.
public:
	/// \brief Constructor por defecto. Inicializa una matriz de 100x100 celdas vivas/muertas de manera aleatoria.
	Toro();
	/// \brief Destructor.
	~Toro();
	/// \brief Esta función pinta el retículo de celdas.
	void Pintar();
	/// \brief Esta función le dice a cada celda cuantos vecinos vivos tiene.
	void BuscarVecinos();
	/// \brief Esta función crea una nueva generación.
	void NuevaGeneracion();
	/// \brief Esta función mira si se ha extinguido la población.
	void Extincion();
	/// \brief Esta función anima el juego de la vida.
	void Animar();
};

Toro::Toro()
{
	extinto = false;
	dimension_x = 25;
	dimension_y = 50;
	m = (Celda**)malloc((dimension_x)*sizeof(Celda*));
	for(int i = 0; i < dimension_x; i++)
	{
		m[i] = (Celda*)malloc((dimension_y)*sizeof(Celda));
		for(int j = 0; j < dimension_y; j++)
		{
			Celda a(rand() % 2,i,j);
			m[i][j] = a;
		}
	}
	BuscarVecinos();
}

Toro::~Toro()
{
	for(int i = 0; i < dimension_x; i++)
		free(m[i]);
	free(m);
}

void Toro::Pintar()
{
	system("clear");
	for(int i = 0; i < dimension_x; i++)
	{
		for(int j = 0; j < dimension_y; j++)
			m[i][j].Pintar();
		cout<<endl;	
	}
}

void Toro::BuscarVecinos()
{
	int Y = dimension_y-1;
	int X = dimension_x-1;
	// Para las celdas que no esta en los bordes.
	for(int i = 1; i < X; i++)
		for(int j = 1; j < Y; j++)
			m[i][j].vecinos_vivos = m[i-1][j-1].esta_viva + m[i-1][ j ].esta_viva + m[i-1][j+1].esta_viva+
									m[ i ][j-1].esta_viva +	                        m[ i ][j+1].esta_viva+
									m[i+1][j-1].esta_viva + m[i+1][ j ].esta_viva + m[i+1][j+1].esta_viva;

	// Para las celdas del borde superior que no están en las esquinas.
	for(int j = 1; j < Y; j++)
		m[0][j].vecinos_vivos = m[ X ][j-1].esta_viva + m[ X ][ j ].esta_viva + m[ X ][j+1].esta_viva+
								m[ 0 ][j-1].esta_viva +                         m[ 0 ][j+1].esta_viva+
								m[ 1 ][j-1].esta_viva + m[ 1 ][ j ].esta_viva + m[ 1 ][j+1].esta_viva;

	// Para las celdas del borde inferior que no están en las esquinas.
	for(int j = 1; j < Y; j++)
		m[dimension_x-1][j].vecinos_vivos = m[X-1][j-1].esta_viva + m[X-1][ j ].esta_viva + m[X-1][j+1].esta_viva+
											m[ X ][j-1].esta_viva                         + m[ X ][j+1].esta_viva+
											m[ 0 ][j-1].esta_viva + m[ 0 ][ j ].esta_viva + m[ 0 ][j+1].esta_viva;

	// Para las celdas del borde izquierdo que no están en las esquinas.
	for(int i = 1; i< X; i++)
		m[i][0].vecinos_vivos = m[i-1][ Y ].esta_viva + m[i-1][0].esta_viva + m[i-1][1].esta_viva +
								m[ i ][ Y ].esta_viva +                       m[ i ][1].esta_viva +
								m[i+1][ Y ].esta_viva + m[i+1][0].esta_viva + m[i+1][1].esta_viva;

	// Para las celdas del borde derecho que no están en las esquinas.
	for(int i = 1; i< X; i++)
		m[i][dimension_y-1].vecinos_vivos = m[i-1][Y-1].esta_viva + m[i-1][ Y ].esta_viva + m[i-1][0].esta_viva +
											m[ i ][Y-1].esta_viva +                         m[ i ][0].esta_viva +
											m[i+1][Y-1].esta_viva + m[i+1][ Y ].esta_viva + m[i+1][0].esta_viva;
	
	// Para la celda [0][0].
	m[0][0].vecinos_vivos = m[ X ][ Y ].esta_viva + m[ X ][ 0 ].esta_viva + m[ X ][ 1 ].esta_viva +
							m[ 0 ][ Y ].esta_viva +                         m[ 0 ][ 1 ].esta_viva +
							m[ 1 ][ Y ].esta_viva + m[ 1 ][ 0 ].esta_viva + m[ 1 ][ 1 ].esta_viva;

	// Para la celda [0][dimension_y-1]
	m[0][Y].vecinos_vivos = m[ X ][Y-1].esta_viva + m[ X ][ Y ].esta_viva + m[ X ][ 0 ].esta_viva +
						  	m[ 0 ][Y-1].esta_viva +							m[ 0 ][ 0 ].esta_viva +
						  	m[ 1 ][Y-1].esta_viva + m[ 1 ][ Y ].esta_viva + m[ 1 ][ 0 ].esta_viva;


	// Para la celda [dimension_x-1][0]
	m[X][0].vecinos_vivos = m[X-1][ Y ].esta_viva + m[X-1][ 0 ].esta_viva + m[X-1][ 1 ].esta_viva +
						  	m[ X ][ Y ].esta_viva +							m[ X ][ 1 ].esta_viva +
						  	m[ 0 ][ Y ].esta_viva + m[ 0 ][ 0 ].esta_viva + m[ 0 ][ 1 ].esta_viva;
	// Para la celda [dimension_x-1][dimension_y-1]
	m[X][Y].vecinos_vivos = m[X-1][Y-1].esta_viva + m[X-1][ Y ].esta_viva + m[X-1][ 0 ].esta_viva +
						  	m[ X ][Y-1].esta_viva +							m[ X ][ 0 ].esta_viva +
						  	m[ 0 ][Y-1].esta_viva + m[ 0 ][ Y ].esta_viva + m[ 0 ][ 0 ].esta_viva;
}

void Toro::NuevaGeneracion()
{
	for(int i = 0; i < dimension_x; i++)
		for(int j = 0; j < dimension_y; j++)
			m[i][j].Reglas();
	BuscarVecinos();
}

void Toro::Extincion()
{
	extinto = true;
	for(int i = 0; i < dimension_x; i++)
		for(int j = 0; j < dimension_y; j++)
			if(m[i][j].esta_viva == true)
				extinto = false;
}

void Toro::Animar()
{
	while(!extinto)
	{
		Pintar();
		NuevaGeneracion();
		usleep(100);
	}
}
#endif









