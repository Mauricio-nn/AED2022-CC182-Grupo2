#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;
using namespace System;

vector<string> explode(const string& delimiter, const string& str) {
    vector<string> arr;

    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng == 0)
        return arr;//no change

    int i = 0;
    int k = 0;
    while (i < strleng)
    {
        int j = 0;
        while (i + j < strleng && j < delleng && str[i + j] == delimiter[j])
            j++;
        if (j == delleng)//found delimiter
        {
            arr.push_back(str.substr(k, i - k));
            i += delleng;
            k = i;
        }
        else
        {
            i++;
        }
    }
    arr.push_back(str.substr(k, i - k));
    return arr;
}

int BuscarChar(string cadena, char buscar) {
    int i;
    for (i = cadena.length(); i >= 0; i--) {
        if (cadena[i] == buscar)
            return i;
    }
    return -1; // No se ha encontrado
}
void gotoXY(int c, int f) {
    Console::SetCursorPosition(c, f);
}
void color(ConsoleColor color_fondo, ConsoleColor color_texto) {
    Console::BackgroundColor = color_fondo;
    Console::ForegroundColor = color_texto;
}
void Marco(int pos_ini_col, int pos_ini_fil, int pos_fin_col, int pos_fin_fil, ConsoleColor cf, ConsoleColor ct) {
    char m1 = 196;
    char m2 = 179;
    char m3 = 196;
    char m4 = 179;
    char e4 = 192;
    char e3 = 217;
    char e2 = 191;
    char e1 = 218;
    color(cf, ct);
    for (int f = pos_ini_fil; f <= pos_fin_fil; f++) {
        for (int c = pos_ini_col; c <= pos_fin_col; c++) {
            gotoXY(c, f); cout << " ";
        }
    }
    for (int c = pos_ini_col; c <= pos_fin_col; c++) {
        gotoXY(c, pos_ini_fil); cout << m1;
        gotoXY(c, pos_fin_fil); cout << m3;
    }
    for (int f = pos_ini_fil; f <= pos_fin_fil; f++) {
        gotoXY(pos_ini_col, f); cout << m4;
        gotoXY(pos_fin_col, f); cout << m2;
    }
    gotoXY(pos_ini_col, pos_ini_fil);	cout << e1;
    gotoXY(pos_fin_col, pos_ini_fil);	cout << e2;
    gotoXY(pos_fin_col, pos_fin_fil);	cout << e3;
    gotoXY(pos_ini_col, pos_fin_fil);	cout << e4;
}
void mensaje(string s) {
    cout << s;
}
int CapturarNumPedido() {
    int pos_igual = 0;
    int numPedido = 0;
    string campo = "", valor = "";
    ofstream filewrite;
    //Como fichero de entrada
    ifstream fileread;
    string linea;
    // Enlace del archivo con el visual 
    // ios::in -> Modo de entrada
    fileread.open("Configuracion.txt", ios::in);
    //Se utiliza para verificar si hay algun error al abrir el arcgivo
    if (fileread.fail()) {
        fileread.close();
    }
    else {
        while (getline(fileread, linea)) {
            pos_igual = BuscarChar(linea, '=');
            if (pos_igual != -1) {
                campo = linea.substr(0, pos_igual);
                valor = linea.substr(pos_igual + 1, linea.length() - pos_igual);

                if (campo == "NumPedido") {
                    numPedido = stoi(valor);
                    break;
                }
            }

        }
        fileread.close();
    }
    return numPedido;
}
