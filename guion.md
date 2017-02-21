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
        * También interesante: Hans Petter Langtangen: [A Primer on Scientific Programming with Python](<http://www.dsf.unica.it/~fiore/psc.pdf>) (Springer, 2016), Secciones 1.3 y siguientes.

## Sesión 3

* *Fecha*: 7/2/2017

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
* *[Sesión no presencial]* Práctica 1. Resolución mediante diferencias finitas de la ecuación de Poisson. Puede consultarse el siguiente documento [Introducción a los métodos de solución numérica de E.D.P.](http://www.ugr.es/~lorente/APUNTESCN/capitulo5.pdf)

## Sesión 4

* *Fecha*: 10/2/2017

### Temario:

* *[Puesta en común]* Práctica 1. Resolución mediante diferencias finitas de la ecuación de Poisson
    * Mejora del rendimiento del código Python usando "*slicing*" para arrays
	* Introducción de tests para verificar el correcto funcionamiento del código
* Proyectos Make, ver por ejemplo la página correspondiente en [Software Carpentry](https://swcarpentry.github.io/make-novice/02-makefiles/)
* *[Sesión no presencial]* [Introducción a C++. Biblioteca matricial "Eigen"](https://rrgalvan.github.io/cpp-intro/)

## Sesión 5

* *Fecha*: 13/2/2017
* *[Puesta en común]* [Introducción a C++. Biblioteca matricial "Eigen"](https://rrgalvan.github.io/cpp-intro/)
* *Acceso desde Python a Bibliotecas C++*
    Distintas posibilidades:
    1. Acceder a la API (*Application Programmers Interface*) del
       intérprete Python (en concreto, de CPython): funciones y
       variables contenidas en `Python.h`. [Ver manual de Python](https://docs.python.org/2/extending/extending.html)
        * Inconveniente: Solución de bajo nivel, propensa a errores
	2. Usar [Swig](http://www.swig.org/)
    	* Herramienta para generar acceder a C/C++ desde distintos lenguajes interpretados, entre ellos *Python*
		* Idea:
    		1. Crear un fichero de *interface*, que contendrá los ficheros de cabecera para el código C/C++
			2. Ejecutar Swig para construir un "envoltorio" sobre el código C/C++. Éste será accesible desde Python
			3. Compilar el código y el "envoltorio" C/C++
			4. Generar una biblioteca dinámica (`.so` , `.dylib`, `.dll`, etc), conteniendo un módulo al que se puede acceder desde Python
	3. Usar [Boost.Python](http://www.boost.org/doc/libs/1_63_0/libs/python/doc/html/index.html)
	    * Biblioteca específica para acceder a Python desde C/C++.
        * Idea:
    		1. Crear un fichero de *interface*, que contendrá los ficheros de cabecera para el código C/C++
			2. Crear un envoltorio desde C/C++, usando las macros proporcionadas por la biblioteca Boost.Python
			3. Generar una biblioteca dinámica, conteniendo un módulo al que se puede acceder desde Python. Para esto puede usarse el paquete Python [distutils](https://docs.python.org/2/library/distutils.html), diseñado específicamente para construir módulos de extensión para Python.
		Más detalles, por ejemplo, en [1](http://www.boost.org/doc/libs/1_63_0/libs/python/doc/html/tutorial/index.html#tutorial.quickstart), [2](https://en.wikibooks.org/wiki/Python_Programming/Extending_with_C%2B%2B)
	4. Usar [Cython](http://cython.org/), una extensión (un superconjunto) del lenguaje Python que permite definir variables y llamar funciones C.
* Práctica 2. El problema de Poisson en C++

## Sesión 6.

### Profundizando en el lenguaje C++

* *Programación orientada a objetos*. Ver, por ejemplo [1](http://umh1467.edu.umh.es/wp-content/uploads/sites/25/2016/02/Programacio%CC%81n-Orientada-a-Objetos.pdf)

* *Buenas prácticas* para orientación a objetos en C++:
    * Utilizar un fichero de cabecera `.h` o `.hpp` para cada clase o,
      excepcionalmente, para un conjunto de clases estrechamente
      ligadas. El fichero debería reflejar el nombre de la clase.
    * Frecuentemente, se utilizan letras mayúsculas para clases (como
      `BaseClass`) y letras minúsculas para funciones (como
      `funcionMiembro`), variables. Los ficheros de cabecera suelen
      tener el mismo nombre que la clase pero con letras minúsculas.
    * No utilizar rutas completas para incluir ficheros de cabecera
      (para evitar problemas de *portabilidad*). Es mejor usar
      directivas de compilación del tipo
      `-I/ruta_a_ficheros_de_cabecera`
    * Usar lertas mayúsculas (MAYUSCULAS) para variables el preprocesador o para enumeraciones.
    * Para evitar inclusión múltiple, usar el procesador: `#ifndef __CLASS_NAME__ ` (...)
    * Usar la palabra clave `const` para indicar que una variable o el
      parámetro de una función no va a cambiar su valor
	* Elegir un estilo y ser consistente con él en todo el
      proyecto. Por ejemplo, a mi me gusta dejar espacios en blanco a
      ambos lados de los operadores (`+`, `-`, `<`,...). Existen
      numerosos estilos corporativos, por
      ejemplo [Ellemtel](http://www.doc.ic.ac.uk/lab/cplus/c++.rules),
      con los que se integran editores como Emacs.

* *Doxygen* es un generador de documentación a partir comentarios formateados. La idea es:
    1. Utilizar bloques especiales en los comentarios sobre funciones, clases, etc. Véase la sección [Documenting the code](http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html) en su página web. Estos bloques [admiten código *markdown*](http://www.stack.nl/~dimitri/doxygen/manual/markdown.html)
    2. Ejecutar la orden
	```
	doxygen -g <config-file>
	```
	para crear un fichero de configuración, antes de generar la documentación. Si se omite el nombre del fichero, se creará automáticamente un fichero de documentación llamado `Doxyfile`, que se puede usar como plantilla y usarla como configuración por defecto. Ver más detalles en [Getting Started](http://www.stack.nl/~dimitri/doxygen/manual/starting.html)
   3. Una vez existe un fichero de configuración, basta ejecutar
   ```
   doxygen <config-file>
   ```
   para generar la documentación, típicamente en HTML, aunque también en PDF y en otros formatos, según las instrucciones que hayan sido indicadas en del fichero de configuración.

* [OpenMP](https://htmlpreview.github.io/?https://github.com/rrgalvan/doctocar/blob/master/intro-openmp.html)

## Temas relacionados y material compolementario

### Particle tracing
* [Particle Tracing](https://ai2-s2-pdfs.s3.amazonaws.com/0a62/57254285aa7d792a1056a19c31f5f79d0576.pdf)
* [Parallel Implementation of Particle Tracing FEM](http://www.cimec.org.ar/ojs/index.php/mc/article/viewFile/3967/3884)

### Conway's Game of Life
* [Conway's Game of Life (Wikipedia)](https://en.wikipedia.org/wiki/Conway's_Game_of_Life)
* [Golly (Potente versión, con licencia libre)](http://golly.sourceforge.net/)
* [Implementación en (decenas de) lenguajes](http://rosettacode.org/wiki/Conway%27s_Game_of_Life)
