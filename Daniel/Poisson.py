def Poisson(f,g,M):
    # Calculo h
    h = 1/(M+1)
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
    # Rellenamos el resto de la matriz.
    for k in range(M**2):
        for i in range(1,M+1):
            for j in range(1,M+1):
                v[i][j]=0.25*(v[i-1][j]+v[i+1][j]+v[i][j-1]+v[i][j+1]-h**2*f(i*h,j*h))
    return(v)
