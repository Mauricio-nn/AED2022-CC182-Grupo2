#pragma once
#include "Librerias.h"
#include "Emp_Users.h"


template<class T>
class HashTable {
private:

    CEmp_users<string>** _hashTable;
    size_t _size;
    size_t _capacity;
public:
    int _hashFunction(string key) {
        int res = 0;

        for (char ch : key) {
            res = key.length() * res + ch;
        }
        
        return res % _capacity;
    }

    HashTable(size_t capacity) : _capacity(capacity) {
        _size = 0;
        _hashTable = new CEmp_users<string>*[capacity];
        for (int i = 0; i < capacity; ++i) _hashTable[i] = nullptr;
    }
    void insert(string key, T* value) {
        int base, step = 0;
        if (_size == _capacity) throw "Hash table is full";
        int index = _hashFunction(key);
        base = index;
        while (_hashTable[index] != nullptr) {
            index = (base + step) % _capacity;
            step++;
        }
        if (_hashTable[index] == nullptr) _hashTable[index] = value;
       
    }

    void mostrarHT() {

        for (int i = 0; i < _capacity; i++) {
            if (_hashTable[i] != nullptr) {
                cout << "Posicion: "<< i <<" "<< _hashTable[i]->getEmpUsuario() << ": " << _hashTable[i]->getEmpContrasena() << "\n";
            }
            if (_hashTable[i] == nullptr) {
                cout << "Posicion: " << i << " Espacio libre"<<endl;
                continue;
            }
        }

    }

    void SearchPassword(string emp_name) {

        bool a = false;
        for (unsigned int i = 0; i < _capacity; ++i) {
            if (_hashTable[i] != nullptr && _hashTable[i]->getEmpUsuario()==emp_name) {
                a = true;
                cout << "Se encontro al usuario " << emp_name << " en la base de datos, su contraseña es la siguiente: " << _hashTable[i]->getEmpContrasena() << endl;
                
         
            }
               
        }
        if (a == false) {
            cout << "No existe el empleado con el siguiente usuario: " << emp_name << endl;
        }
    
    }

};