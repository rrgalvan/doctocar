#include<iostream>
#include"celda.h"
#include"toro.h"

using namespace std;

int main()
{	
	srand(time(NULL));
	cout << "Hello world!"<<endl;
	Toro t;
	t.Animar();
}



// Para los colores mirar:
// https://en.wikipedia.org/wiki/ANSI_escape_code#graphics
// Por ejemplo:
// cout << "\033[1;31mbold red text\033[0m\n";
// Explicado en:
// http://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal



