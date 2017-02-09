import numpy as np

def Poisson(f,g,M, niter=None):
    if(niter==None):
       niter=M**2

    # Calculo h
    h = 1/(M+1)
    h2 = h**2 # para evitar operaciones innecesarias
    # Inicializo u.
    v = [[0 for i in range(M+2)] for i in range(M+2)]
    # Cargamos las condiciones de frontera horizontales.
    for j in range(M+2):
        v[0][j] = g(0,j*h)
        v[M+1][j] = g(1,j*h)
    # Cargamos las condiciones de frontera verticales.
    for i in range(M):
        v[i+1][0] = g((i+1)*h,0)
        v[i+1][M+1] = g((i+1)*h,1)
    # Aproximamos la solución mediante un método iterativo de tipo Jacobi
    for k in range(niter):
        # Rellenamos el resto de la matriz.
        for i in range(1,M+1):
            for j in range(1,M+1):
                v[i][j]=0.25*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1] + h2*f(i*h,j*h))
    return(v)

def PoissonNP(f, g, M, niter=None):

    if(niter==None):
       niter=M**2

    # Calculo h
    h = 1/(M+1)
    h2 = h**2 # para evitar operaciones innecesarias
    # Inicializo v.
    v = np.zeros((M+2,M+2))
    # Cargamos las condiciones de frontera horizontales.
    for j in range(M+2):
        v[0][j]   = g(0,j*h)
        v[M+1][j] = g(1,j*h)
    # Cargamos las condiciones de frontera verticales.
    for i in range(1,M+1):
        v[i][0]   = g(i*h,0)
        v[i][M+1] = g(i*h,1)
    # Aproximamos la solución mediante un método iterativo de tipo Jacobi
    #    ...¿se puede evitar crear un array de valores de f?...
    f_values = np.array( [ [f(i*h,j*h) for i in range(1,M+1)] for j in range(1,M+1)])
    for k in range(niter):
        v[1:-1, 1:-1] = 0.25 * ( v[0:-2, 1:-1] + v[2:, 1:-1]
                                   + v[1:-1, 0:-2] + v[1:-1, 2:] + h2*f_values[:,:] )
    return(v)
