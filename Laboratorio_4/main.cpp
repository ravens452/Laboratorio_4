//
//  main.cpp
//  Laboratorio_4
//
//  Created by carlos andrade guzman on 5/24/20.
//  Copyright © 2020 carlos andrade guzman. All rights reserved.
//
  
#include <iostream>
#include <cstring>
using namespace std;

class Persona
{
    private:
    std::string nombre;
    std::string apellido;
    int edad;

    public:
    Persona()
    {
        nombre = " "; apellido = " "; edad = 0;
        std::cout<<"Persona contructed by default";
    }
    Persona(char* nombre, char* apellido, int edad)
    {
        this-> nombre = nombre;
        this-> apellido = apellido;
        edad = edad;
        std::cout<<"Persona constructed";
    }
    const std::string getNombre(){return nombre;}
    const std::string getApellido(){return apellido;}
    const int getEdad(){return edad;}

    void setNombre(const std::string nombre)
    {
        this -> nombre = nombre;
    }
    void setApellido(const std::string apellido)
    {
        this -> apellido = apellido;
    }
    void setEdad(const int edad)
    {
        this -> edad = edad;
    }
};
class ArregloDePersonas : public Persona
{
    private:
    int tam;
    Persona* personas;
    public:
    ArregloDePersonas & operator[](int index){return personas[index];}
    ArregloDePersonas(const int tam)
    {
        personas = new Persona[tam];
        this -> tam = tam;
        std::cout<< "Iniciando";
    }
    ArregloDePersonas(const ArregloDePersonas &o)
    {
        personas = new Persona[o.tam];
        tam = o.tam;
        for (int i=0; i<tam; i++)
            personas[i] = o.personas[i];
    }
    ~ArregloDePersonas()
    {
        delete [] personas;
        std::cout<< "adios";
    }

    void redimensionar(int nSize)
{
    Persona* temp = new Persona[nSize];
    int minSize = ((nSize < tam) ? nSize : tam);

    for(int i = 0; i < minSize; ++i)
    {
        temp[i] = personas[i];
    }
    tam = nSize;
    delete[] personas;
    personas = temp;

}
    void push(const Persona &p)
    {
        redimensionar(tam + 1);
        personas[tam - 1]= p;
    }
    void insert(const int posicion, const Persona &p)
    {
        personas[posicion] = p;
    }
    void remove(const int pos)
    {
        for(int i =pos; i<tam; i++)
        {
            personas[i] = personas[i + 1];
        }
        redimensionar(tam-1);
    }
    const int getSize()
    {
        return tam;
    }
    void clear()
    {
        delete [] personas;
        tam = 0;
    }

};

int main()
{
    ArregloDePersonas a(2);
    Persona persona1("persona1", "abc", 300);
    Persona persona2("persona2", "abcd", 300);
    Persona persona3("persona3", "abcde", 300);
    a.insert(0, persona1);
    a.insert(1, persona1);
    a.push(persona3);
    cout << persona3.getNombre();
    cout << persona3.getApellido();
    cout<< a[1].getNombre();

}
