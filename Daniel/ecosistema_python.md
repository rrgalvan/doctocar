# 1. Empezando con Python para la ciencia

## 1.1. Ecosistema de computación científica de Python.

### 1.1.1 ¿Por qué Python?

#### 1.1.1.1. Los científicos necesitan.

* Obtener los datos,
* Manipular y procesar los datos,
* Visualizar resultados, fáciles de entender pero también gráficas de gran calidad para artículos.

#### 1.1.1.2. Puntos fuertes de Python.

* **Baterías incluidas**. Hay una gran colección de **ladrillos** de métodos numéricos clásicos, representaciones gráficas o herramientas de procesamiento de datos.
* **Fácil de aprender**.
* **Fácil comunicación**. La sintaxis de Python es simple, evitando símbolos extraños o largas especificaciones de rutinas que dificultan el entendimiento del código.
* **Código eficiente**. Los módulos numéricos en Python son computacionalmente eficcientes. Pyhton apuesa por tiempos rápidos de desarrollo y ejecución.
* **Universal**. Aprender Python te evita aprender un nuevo software para cada problema.

#### 1.1.1.3. ¿Cómo se comporta Python comparado con otras soluciones?

Ventajas:

- Muy rico en librerías de computación científica
- Permite escribir un código legible y bien estructurado
- Tiene muchas más librerias más allá de la computación científica.
- Software de código abierto con gran difusión.
- Tiene una gran variedad de poderosos entornos donde trabajar.

Contras:

- No tiene todos los algoritmos que pueden encontrarse en softwares más especializados.
- Frente a lenguajes compilados como C, C++ o Fortran: alejamiento del
  hardware, menor velocidad. Idea: usar Python como "lenguaje
  pegamento"

### 1.1.2. El ecosistema cientifico de Python.

Algunos de los bloques básicos que se pueden combinar para obtener un entorno de computación científica son:

**Python**, un lenguaje de programación moderno y genérico

* El lenguaje: Control de flujo, tipo de datos, colección de datos, etc.
* Módulos de la librería estandar: procesamiento de cadenas, tratamiento de archivos, protocolos simple de redes.
* Una gran cantidad de módulos especializados escritas en Python.
* Herramientas de desarrollo.

**Librerías numéricas fundamentales:**

* **Numpy**: computación numérica con poderosos objetos de tipo **arrays numéricos** y rutinas para manipularlos.
* **Scipy**: rutinas numéricas de alto nivel.
* **Matplotlib**: visualizaciones en 2D.

**Entornos interactivos avanzados:**

* **IPython**, una **consola de Python** avanzada.
* **Jupyter**, **notebooks** en el navegador.

**Paquetes específicos:**

* **Mayavi** para visulacizaciones en 3D.
* **pandas, statsmodels, seaborn** para estadística.
* **sympy** para computación simbólica.
* **scikit-image** para procesamiento de imágenes.
* **scikit-learn** para *machine learning*.

### 1.1.3. Antes de empezar: Instalar un entorno que funcione.

Recomendamos instalar una distribución de computación científica.


### 1.1.4. El flujo de trabajo: entornos interactivos y editores de texto.

Python es un lenguage de propósito general y por lo tanto no hay un único entorno de trabajo ni una sola manera de usarlo.

#### 1.1.4.1 Trabajo interactivo.

Recomendamos el trabajo interactivo con la consola de IPython o el notbook Jupyter. Son útlies para explorar y comprenser los algoritmos.

        En el notebook
        Para ejecutar el código, pulsar "mayúscula enter"

Arranca *ipython*:

         In[1]: print('Hello world')
         Hello world

Obten ayuda usando el operador **?** después de un objeto:

         In[2]: print?

#### 1.1.4.2. Elaboración del trabajo en un editor.

A medida que avanzas, es importante no sólo trabaja de manera interactiva si no también crear y reutilizar los archivos de Python. Para ello un editor de código te llevará lejos. Algunos son:

* Spyder.
* PyCharm.
* Atom.

Como ejercicio, crea un archivo *my_file.py* y añade las siguientes líneas:

        s = 'Hello world'
        print(s)

Ahora puedes ejecutarlo en la consola de IPython o en un notebook:

        In [1]: %run my_file.py
        Hello world

        In [2]: s
        Out[2]: 'Hello world'

        In[3]: %whos
        Variable   Type   Data/Info
        ---------------------------
        s          str    Hello world

#### 1.1.4.3 Trucos y consejos de IPython y Jupyter.

**Histias de comandos**. Pulsa *arriba* o *abajo* pra navegar por los comandos escritos previamente:

        In [1]: x = 10

        In [2]: <ARRIBA>

        In [2]: x = 10

**Completar con el tabulador**. Escribe nombre_objeto.<TAB> para ver los atributos del objeto. También funciona para los archivos y nombres de directorio.

        In [1]: x = 10

        In [2]: x.<TAB>
        x.bit_lenght   x.denominator   x.imag   x.real
        x.conjugate   x.frombytes   x.numerator   x.to_bytes

**Funciones mágicas**.	La consola y los notebooks soportan las llamadas funciones *mágicas* escribiendo antes de un comando el caracter **%**. Si establecemos *automagic* podemos omitir el signo *%*. Algunas funciones mágicas son:

* %cd cambia el directorio actual.
* %cpaste permite pegar código.
* %timeir permite medir el tiempo de ejecución.
* %debug entra en el *debugger* en el punto donde surje el problema.
