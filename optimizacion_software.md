# Optimización de Software Científico

* Programación en dos etapas:
    1. Programar prestando atención a crear código que funcione *correctamente*
	2. Si se desea, *mejorar el rendimiento* del código (en tiempo de
       ejecución o en recursos empleados). Para ello:
        * Detectar los posibles *cuellos de botella*
        * Intentar *optimizarlos*

* *Profilers*: Son programas utilizados para analizar el rendimiento
  del código (y así detectar cuellos de botella)
    * Toman como entrada el programa (código fuente o código binario)
    * Generan estadísticas (tiempo promedio en llamadas a funciones),
      grafos de llamadas entre funciones...
    * Son específicos de los lenguajes

* La *optimización* del software es un asunto muy complejo (ver por
  ejemplo [*Performance Optimización of Numerically Intensive Codes. S. Goedecker and A. Hoisie. SIAM, 2001*].
    * La CPU debe acceder datos de memoria para procesarlos
    * Las memorias de alta velocidad, para el acceso a los datos, son
          caras y por tanto de poca
	* Por ello, se estructuran de la siguiente forma (en orden descendente por su velocidad de acceso y ascendente por su capacidad de almacenamiento).
        * Registros del procesador
        * Memorias caché (distintos niveles de velocidad, L1, L2, L3)
        * Memoria RAM
        * Disco duro
        * Redes (Discos o memorias remotas)
    * Los algoritmos deben optimizar el acceso a la memora caché. Por ejemplo, para un vector de gran tamaño (que no quepa en la caché), deben tratarse los elementos cercanos entre sí y evitar el acceso a elementos lejanos.
    * La cosa es más complicada teniendo en cuenta que cada arquitectura de CPU tiene características diferentes. Algunas, avanzadas, como "Pipelining" pueden mejorar notablemente el rendimiento si son aprovechadas.

* De todas formas, se pueden dar algunas *recomendaciones genéricas*
    * *Elegir el mejor algoritmo*, después de un estudio de los existentes. Por ejemplo, en general, si el número de operaciones es de orden *n^2*, el algoritmo será preferible a otro de orden *n^3*.
    * *Usar bibliotecas eficientes*. En lugar de programar un algoritmo muy complejo, puede ser conveniente estudiar las bibliotecas ya existentes para, siempre que su licencia lo permita, escoger la más adecuada. Por ejemplo, son muy usadas las bibliotecas BLAS para operaciones con (matrices y vectores) números reales. Existen diferentes versiones de estas bibliotecas, adaptadas a las distintas arquitecturas de procesadores.
	* Elegir la *forma más adecuada para disponer los datos en memoria*, programando algoritmos de forma que, dentro de lo osible, sólo se realicen operaciones con datos contiguos. Por ejemplo, dado que en C y C++ (y en Python) las matrices almacenan datos por filas, será más eficiente sumar los elementos de una fila que sumar los de una columna.
	* Utilizar las *posibilidades de optimización automática que ofrecen los compiladores*. Usando niveles de optimización medios, como *-O2*, se puede multiplicar por 2 o por 3 la velocidad de cálculo (sin un gran incremento en el tiempo de compilación). Niveles superiores, como *-O3* no llevan, con frecuencia, a un gran incremento. Las optimizaciones que realizan, automáticamente, los compiladores son de muy diverso tipo. Ver, por ejemplo [Goedecker-Hoisie].
	* Utilizar las posibilidades como pre-procesadores o parametrización tipos de datos (*templates*) para disminuir el esfuerzo de ejecución del código (aumentando, por contra, el tiempo de compilación).
