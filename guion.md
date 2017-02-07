# Curso de Doctorado "*Computación de Alto Rendimiento para Matemáticos y Científicos*"

**Curso 2016/2017**

## Sesión 1

* *Fecha*: 31/1/2017

### Temario:

* Recepción, panorámica del curso,
* Entornos Unix en supercomputación. La shell Unix
* *[Sesión no presencial]* Sistemas de control de versiones: Git. Repositorios remotos: Github y Bitbucket
   * [Introducción a Git (UCACCAR)](https://bitbucket.org/proyecto-ucaccar/ucaccar/src/7d1fda8beb3dcaf8400d01d96e87a903750a7b27/notes-es/git.rst?fileviewer=file-view-default)
   * [Software Carpentry: Version Control with Git](http://swcarpentry.github.io/git-novice)
   * [Git - SVN Crash Course](http://git.or.cz/course/svn.html). Brief introduction you to Git usage based on your current Subversion knowledge.


## Sesión 2

* *Fecha*: 3/2/2017

### Temario:

* *[Puesta en común]* Sistemas de control de versiones: Git. Repositorios remotos: Github y Bitbucket
* Creación de programas científicos de forma eficiente.
    * [Artículo "Best Practices for Scientific Computing"](http://journals.plos.org/plosbiology/article/file?id=10.1371/journal.pbio.1001745&type=printable). *G. Wilson et al*, PLOS Biology, 2014.
    * [Optimización de Software Científico](optimizacion_software.md)
    * Representación de números en los ordenadores.
	    * Ver por ejemplo [A. Quarteroni, F. Salieri: "Cálculo Científico con Matlab y Octave". Springer, 2006] o apuntes de Métodos Numéricos I (Grado en Matemáticas de la Universidad de Cádiz).
    * *[Sesión no presencial]* Programación interactiva en lenguaje Python para las Matemáticas, las Ciencias y la Ingeniería
	    * Recomendado: [Getting started with Python for science](http://www.scipy-lectures.org/intro/intro.html)
        * También interesante: Hans Petter Langtangen: [A Primer on Scientific Programming with Python](<https://hplgit.github.io/primer.html/doc/pub/half/book.pdf>) (Springer, 2016), Secciones 1.3 y siguientes.

## Sesión 3

* *Fecha*: 6/2/2017

### Temario:

* *[Puesta en común]* Programación interactiva en lenguaje Python para las Matemáticas, las Ciencias y la Ingeniería
    * [El ecosistema Python](Daniel/ecosistema_python.md)
    * Introducción al lenguaje Python
        * [Sección de scipy-lectures](http://www.scipy-lectures.org/intro/language/python_language.html#python-language-chapter) (secciones: *Basic types*, *Control flow*, *Defining functions*)
		* [Sección de UCA-CCAR](https://bitbucket.org/proyecto-ucaccar/ucaccar/src/7d1fda8beb3dcaf8400d01d96e87a903750a7b27/notes-es/python.rst?fileviewer=file-view-default) (más breve)
	* [Cálculo con *arrays*: Numpy]* Programas interpretados (*scripts*) en Python
    	* [Secciónde scipy-lectures](http://www.scipy-lectures.org/intro/numpy/index.html) (secciones: *The Numpy array object*, *Numerical operations on arrays*)
        * [Sección de UCA-CCAR](https://bitbucket.org/proyecto-ucaccar/ucaccar/src/7d1fda8beb3dcaf8400d01d96e87a903750a7b27/notes-es/numerical*python.rst?fileviewer=file-view-default) (más breve)
    * Reusing code: scripts and modules
	    * [Sección de scipy-lectures](http://www.scipy-lectures.org/intro/language/reusing*code.html)
        * [Sección de UCA-CCAR](https://bitbucket.org/proyecto-ucaccar/ucaccar/src/7d1fda8beb3dcaf8400d01d96e87a903750a7b27/notes-es/python_scripts_modules.rst?fileviewer=file-view-default)
* Gráficas e interpretación de resultados
    * [Gráficas "matemáticas" en Python](http://nbviewer.jupyter.org/github/rrgalvan/python-mnii/blob/master/extra/graficas-matematicas.ipynb)
    * [Matplotlib Examples](http://matplotlib.org/examples/index.html) (muchos ejemplos de gráficas)
* Testeo de errores y verificación del código
    * [Testing Your Code in Python](http://docs.python-guide.org/en/latest/writing/tests/)
    * Avanzado: uso de [Travis](https://en.wikipedia.org/wiki/Travis_CI) para tests automáticos de código en Github. [Introducción para principiantes](https://docs.travis-ci.com/user/for-beginners)
* *[Sesión no presencial]* Práctica 1. Resolución mediante diferencias finitas de la ecuación de Poisson
