#include <iostream>
#include <string>

using namespace std;

class Persona {
private:	
	string nombre;
	int edad;
public:
	static int numero_personas;
	Persona(string nombre, int edad);
	~Persona() {
		cout << "Destructor" << endl;
	}
	Persona &establecerNombre(string nombre) {
		this->nombre = nombre;
		return *this;
	}
	Persona &establecerEdad(int edad) {
		this->edad = edad;
		return *this;
	}
	void saludar();
};

int Persona::numero_personas = 0;

void Persona::saludar() {
	cout << "Hola soy " << nombre << " y tengo " << edad << " de edad." << endl;
}

Persona::Persona(string nombre, int edad) {
	this->nombre = nombre;
	this->edad = edad;
	numero_personas += 1;
}

int main() {
	string nombre = "";
	int edad = 0;
	Persona* p = new Persona(nombre, edad);

	cout << "Ingrese el nombre: ";
	cin >> nombre;
	cout << "Ingrese la edad: ";
	cin >> edad;

	p->establecerNombre(nombre).establecerEdad(edad);
	p->saludar();
	cout << "Numero de personas: " << Persona::numero_personas << endl;

	delete p;
}