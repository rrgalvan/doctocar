using namespace std;

#ifndef __CELDA__
#define __CELDA__


/// Esta clase almacena la información referente a cada celda.
class Celda
{
friend class Toro;

/// \brief Cada celda "sabe" que forma parte de algo superior, y por tanto
/// almacena sus coordenadas en ese retículo.
private:
	bool esta_viva;		/// \param esta_viva Es true si está viva y false en caso contrario.
	int vecinos_vivos;	/// \param vecinos_vivos Indica el número de vecinos que tiene vivos.
	int pos_x; 			/// \param pos_x Indica la posición X en el retículo.
	int pos_y;			/// \param pos_y Indica la posición Y en el retículo.
public:
	/// \brief Constructor por defecto. Inicializa todos los parámetros a cero.
	Celda();
	/// \brief Constructor al que se le introduce el estado de la celda y sus coordenadas x e y.
	Celda(bool esta_viva,int pos_x,int pos_y);
	/// \brief Pinta la celda de color rojo si está viva y blanca en caso contrario.
	void Pintar();
	/// \brief cualquier celda viva con menos de dos vecinos vivos muere por falta de población.
	void Regla1();
	/// \brief Cualquier celda viva con dos o tres vecinos vivos vive en la siguiente generación.
	void Regla2();
	/// \brief Cualquier celda viva con más de 3 vecinos vivos muere por sobrepoblación.
	void Regla3();
	/// \brief Cualquier celda muerta con exactamente tres vecinos vivos se convierte en una celda viva.
	void Regla4();
	/// \brief Junta todas las reglas.
	void Reglas();
};

inline Celda::Celda()
{
	esta_viva = false;
	vecinos_vivos = 0;
	pos_x = 0;
	pos_y = 0;
}


inline Celda::Celda(bool esta_viva,int pos_x,int pos_y)
{
	this->esta_viva = esta_viva;
	this->pos_x = pos_x;
	this->pos_y = pos_y;
}

inline void Celda::Pintar()
{
	if(esta_viva)
		cout << "\033[0;41m \033[0m";
	else
		cout << "\033[0;47m \033[0m";
}

inline void Celda::Regla1()
{
	if(esta_viva && vecinos_vivos < 2)
		esta_viva = false;
}

inline void Celda::Regla2()
{
	if(esta_viva && vecinos_vivos >= 2 && vecinos_vivos <= 3)
		esta_viva = true;
}

inline void Celda::Regla3()
{
	if(esta_viva && vecinos_vivos > 3)
		esta_viva = false;
}

inline void Celda::Regla4()
{
	if(!esta_viva && vecinos_vivos == 3)
		esta_viva = true;
}

inline void Celda::Reglas()
{
	Regla1();
	Regla2();
	Regla3();
	Regla4();
}
#endif
