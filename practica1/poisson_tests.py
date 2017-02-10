#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
from numpy.linalg import norm
import Poisson

def uex(x,y):
    return x*(x-1)*y*(y-1)/2

def laplace_uex(x,y):
    return y*(y-1)+x*(x-1)

def f_uex(x,y):
    return -laplace_uex(x,y)

def test_solexacta():
    M=20
    def uex_to_matrix(uex, M):
        "Stores exact solution uex in an MxM matrix"
        u_matrix = np.zeros((M+2,M+2))
        hx, hy = 1/(M+1), 1/(M+1)
        for i in range(M+2): # Bucle en filas
            for j in range(M+2): # Bucle en columnas
                u_matrix[i,j] = uex(i*hx,j*hy)
                return u_matrix
    u_matrix = uex_to_matrix(uex, M)

    errores_esperados = [2e-16,2e-15,4e-15]
    for M in [10,20,30]:
        print ("M =", M)
        uh_matrix = Poisson.PoissonNP(f_uex, uex, M, M**3)
        u_matrix = uex_to_matrix(uex, M)
        e1 = norm(uh_matrix - u_matrix)
        i = int(M/10-1)
        assert e1 < errores_esperados[i]
        print ("error =", e1)
        print ("error_inf =", np.amax(abs(uh_matrix - u_matrix)) )
