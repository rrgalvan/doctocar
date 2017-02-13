#!/usr/bin/python3

import Poisson

def f(x,y):
    return x+y

npoints = 100
if __name__=="__main__":
    Poisson.PoissonNP(f,f,npoints)
