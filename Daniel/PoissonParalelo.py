from mpi4py import MPI
from numpy import *
import numpy as np

comm = MPI.COMM_WORLD

# Identificador de cada hilo.
nodo = comm.Get_rank()
# Número de hilos.
numProc = comm.Get_size()

def f(x,y):
	return(x+y)

def PoissonParalelo(f,g,M):
	print('m = ', M)
	# Calculo h.
	h = 1/(M+1)
	# Creamos una matriz vacia para meter los datos.
	v = np.zeros((M+2,M+2))	
	# Inicializo v en el nodo 0.
	print('hola')
	if nodo == 0:
		# Cargamos las condiciones de frontera horizontales.
		for j in range(M+2):
			v[0][j] = g(0,j*h)
			v[M+1][j] = g(1,j*h)
		# Cargamos la condiciones de frontera verticales.
		for i in range(M):
			v[i+1][0] = g((i+1)*h,0)
			v[i+1][M+1] = g((i+1)*h,1)
	comm.barrier()
	print('hola')
	# Rellenamos el resto de la matriz con los otros nodos.
	comm.Bcast(v,root=0)
	print('hola')
	comm.barrier()
	# Iteramos el método de Jacobi.
	print('hola')
	for k in range(M**2):
		# Dividimos las tareas entre todos los procesadores asignando a cada uno una fila.
		if(nodo != 0):
			for j in range(1,M+1):	
				v[nodo][j]=0.25*(v[nodo-1][j]+v[nodo+1][j]+v[nodo][j-1]+v[nodo][j+1]-h**2*f(nodo*h,j*h))
				print('hola')
		comm.Send(v[nodo],dest=0)
		print("Aqui llego\n")
		if(nodo == 0):
			for j in range(1,M+1):	
				comm.Recv(v[i],source=j)
		comm.barrier()
		print("k = ", k)
	if(nodo == 0):
		print("la matriz final vale: ",v, "\n")


PoissonParalelo(f,f,3)



