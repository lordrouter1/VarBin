#ifndef VARBIN_H
#define VARBIN_H

#include "VarBinHeader.h"

class VarBin
{
  public:
    //construtores:
    VarBin(string input); // recebe como entrada valor em string;
    VarBin(char input); // recebe como entrada valor em char;
    VarBin(int input); // recebe como entrada valor em int;
    VarBin(); // não recebe valor de entrada;

    //funções:
    string toString(); // converte todos os bytes do vetor em uma string com todos os bytes unidos
    string toString(int space); // converte todos os bytes em uma string com um espaçamento entre a quantia de bit definito (space)
    string toStringI(int indice); // converte apenas o byte definido (indice)
    string toHex(); // converte todos os bytes do vetor em uma string com todos os bytes unidos
    string toHexP(); // converte todos os bytes do vetor em uma string com os bites separados por ':'
    string toHexI(int indice); // converte apenas o byte definido (indice)

    //operadores:
    void operator << (string input);
    void operator << (char input);
    void operator << (int input);

  private:
    //variavel principal com vetor de bytes:
    vector<_VARBIN_BYTE_STRUCT_> VectorBin;

    // funções para converção de valores:
    _VARBIN_BYTE_STRUCT_ conversor(int var);
    int conversor(_VARBIN_BYTE_STRUCT_ var);
    string btoh(_VARBIN_BYTE_STRUCT_ var);
    char ntoh(bool bitA, bool bitB, bool bitC, bool bitD);
};

#endif // VARBIN_H
