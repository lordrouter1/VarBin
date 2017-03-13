#ifndef VARBINHEADER_H_INCLUDED
#define VARBINHEADER_H_INCLUDED

// DEFINIÇÕES BASICAS PARA O USUARIO:
#define _VARBIN_VAR_BIT_ bool
#define _VARBIN_BYTE_SIZE_ 8

// CABEÇALHOS:
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

// NOMES DE ESPAÇOS:
using namespace std;

/// STRUCT QUE DEFINE UM BYTE COMO 8 BIT (BOOL):
struct _VARBIN_BYTE_STRUCT_
{
  _VARBIN_VAR_BIT_ bitVector[8];
};

/// UNION QUE CONVERTE UM INT EM UMA STRUCT DE 8 BOOL E VICE VERSA:
union _VARBIN_CB_
{
  struct _VARBIN_CB_STRUCT_BITE_
  {
    _VARBIN_VAR_BIT_ bit1 : 1;
    _VARBIN_VAR_BIT_ bit2 : 1;
    _VARBIN_VAR_BIT_ bit3 : 1;
    _VARBIN_VAR_BIT_ bit4 : 1;
    _VARBIN_VAR_BIT_ bit5 : 1;
    _VARBIN_VAR_BIT_ bit6 : 1;
    _VARBIN_VAR_BIT_ bit7 : 1;
    _VARBIN_VAR_BIT_ bit8 : 1;
  }bite;
  int inteiro;
};

#endif // VARBINHEADER_H_INCLUDED
