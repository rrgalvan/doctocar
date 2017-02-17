Introduction to OpenMP in C++ and Fotran
========================================

OpenMP consists of a set of compiler directives ("\#pragma omp" in C++
and "!omp" commentaries in Fortran 90). Due to this design, if the
compiler does not support OpenMP the program will still be built, but
without any parallelism.

For instance, the following progam creates a table of values, which is
initialized with the values of $\sin(x)$, with $x\in [0,2\pi]$.

      #include <cmath>
      int main()
      {
        const long int size=1024;
        double sinArray[size];

        // Initialize the array (in parallel) with values of sin(x)
        #pragma omp parallel for
        for(long k=0; k<size; k++)
          {
            sinArray[k] = std::sin(2*M_PI/(size-1) * k);
          }
      }

This code divides the for loop into a number of threads (the number of
threads is defined by the sistem, by default, see deatils below), which
are run simultaneously. Each thread Initializes a portion of the array.

Using the GCC C++, the program can be compiled like follows:

``` {.bash}
g++ -fopenmp programa.cpp
```

OpenMP provides advanced possibilities, some of which will not dealed
here. For instance If the compiler supports OPENMP 4.0 and a parallel
floating point library such as AMD ACML or Intel SVML is available, the
previous code can be enhanced using SIMD directives. Another
characteristic supported by OPENMP 4.0 is the offloading of code to
different devices, such as GPU's. This possibilty was improved in OpenMP
4.5.

Basic syntax: `parallel` and `for` constructs
=============================================

Example 1. The `parallel` construct
-----------------------------------

A OpenMP program begins as a simple thread, called initial thread, which
is executed sequentially.

When the initial thread finds a `parallel` construct, it creates a
*team* of multiple *threads* which are run in parallel. When all threads
finish their task, the `parallel` region is completed and the initial
thread resumes execution of the program.

In C++, the `#pragma omp` applies to the surronding statement, which can
be a code block:

      #pragma omp parallel
      {
        // Code inside this region is executed by every thread
        std::cout << "Hello in parallel region" << std::endl;
      }

The number of threads of a parallel region can be set by the
`OMP_NUM_THREADS` environment variable, the `omp_set_num_threads()`
function (whiech is provided in a header file named `omp.h`) or the
`num_threads` clause of the `parallel` directive. `OMP_NUM_THREADS` has
greater recedence than `omp_set_num_threads()`, which has greater
precedence than `num_threads` clause.

An example in Fortran, where the parallel region is enclosed by `!$omp`
commentaries:

``` {.fortran .rundoc-block rundoc-language="fortran" rundoc-flags="-fopenmp"}
    !$omp parallel num_threads(2)
    print*, "Hello in parallel region"
    !$omp end parallel
    print*, "Bye"
```

Loop construct: `for` (C++) and `do` (Fortran)
----------------------------------------------

Inside a `parallel` block, the loop construct specifies that the
different portions of the iterations of a `for` loop (or a `do` lopp, in
Fortran) will be executed in parallel by the different threads in the
current team.

The following example will output each number in $\{0,1,\dots,9\}$ in
parallel (in arbitrary order).

      #pragma omp parallel
      {
      #pragma omp for
      for(int i=0; i<10; i++)
        {
          std::cout << i << ' ';
        }
      }
      std::cout << std::endl;

The `parallel` and `for` constructs can be abreviated as follows:

      #pragma omp parallel for
      {
      for(int i=0; i<10; i++)
        {
          std::cout << i << ' ';
        }

The `for` construct specifies that the iterations of one loop will be
executed in parallel by the threads that already exists (in a `parallel`
region).

      #pragma omp parallel
      {
        #pragma omp for
        for(int n=0; n<10; ++n)
        {
          std::cout << n;
        }
        std::cout << std::endl;
      }

A equivalent shorthand:

      #pragma omp parallel for num_threads(4)
      for(int n=0; n<10; ++n)
      {
        std::cout << n;
      }
      std::cout << std::endl;

Sections
--------

The `sections` construct allows to define code blocks, each of which
will be executed by a thread in the current `parallel` team.
