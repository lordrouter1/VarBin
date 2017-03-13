#include "../include/VarBin.h"

/// CONSTRUTOR QUE RECEBE UMA STRING COMO PARAMETRO:
VarBin::VarBin(string input)
{
  for(unsigned i = 0; i < input.size(); i++)
  {
    if((int) input[i] > 255) return;
  }

  if(VectorBin.size() != 0)
    VectorBin.clear();

  for(unsigned i = 0; i < input.size(); i++)
  {
    VectorBin.push_back(conversor((int)input[i]));
  }
  return;
}

/// CONSTRUTOR QUE RECEBE UM CHAR COMO PARAMETRO:
VarBin::VarBin(char input)
{
  if((int) input > 255) return;

  if(VectorBin.size() != 0)
    VectorBin.clear();

  VectorBin.push_back(conversor((int)input));

  return;
}

/// CONSTRUTOR QUE RECEBE UM INT COMO PARAMETRO:
VarBin::VarBin(int input)
{
  if(input > 255) return;

  if(VectorBin.size() != 0)
    VectorBin.clear();

  VectorBin.push_back(conversor(input));

  return;
}

/// CONSTRUTOR QUE NÃO RECEBE PARAMETRO:
VarBin::VarBin()
{
}

/// OPERADOR DE ENTRADA QUE RECEPE UMA STRING COMO PARAMETRO:
void VarBin::operator << (string input)
{
  for(unsigned i = 0; i < input.size(); i++)
  {
    if((int) input[i] > 255) return;
  }

  if(VectorBin.size() != 0)
    VectorBin.clear();

  for(unsigned i = 0; i < input.size(); i++)
  {
    VectorBin.push_back(conversor((int)input[i]));
  }
  return;
}

/// OPERADOR DE ENTRADA QUE RECEBE UM CHAR COMO PARAMETRO:
void VarBin::operator << (char input)
{
  if((int) input > 255) return;

  if(VectorBin.size() != 0)
    VectorBin.clear();

    VectorBin.push_back(conversor((int)input));

  return;
}

///  OPERADOR DE ENTRADA QUE RECEBE UM INT COMO PARAMETRO:
void VarBin::operator<<(int input)
{
  if(input > 255) return;

  if(VectorBin.size() != 0)
    VectorBin.clear();

  VectorBin.push_back(conversor(input));
}

/// FUNÇÃO QUE CONVERTE UM VALOR INTEIRO EM _VARBIN_BYTE_STRUCT_:
_VARBIN_BYTE_STRUCT_ VarBin::conversor(int var)
{
  _VARBIN_CB_ conv;
  _VARBIN_BYTE_STRUCT_ retorna;

  conv.inteiro = var;

  retorna.bitVector[0] = conv.bite.bit8;
  retorna.bitVector[1] = conv.bite.bit7;
  retorna.bitVector[2] = conv.bite.bit6;
  retorna.bitVector[3] = conv.bite.bit5;
  retorna.bitVector[4] = conv.bite.bit4;
  retorna.bitVector[5] = conv.bite.bit3;
  retorna.bitVector[6] = conv.bite.bit2;
  retorna.bitVector[7] = conv.bite.bit1;

  return retorna;
}

/// FUNÇÃO QUE CONVERTE UMA _VARBIN_BYTE_STRUCT_ EM UM INTEIRO:
int VarBin::conversor(_VARBIN_BYTE_STRUCT_ var)
{
  _VARBIN_CB_ conv;
  int retorna;

  conv.bite.bit8 = var.bitVector[0];
  conv.bite.bit7 = var.bitVector[1];
  conv.bite.bit6 = var.bitVector[2];
  conv.bite.bit5 = var.bitVector[3];
  conv.bite.bit4 = var.bitVector[4];
  conv.bite.bit3 = var.bitVector[5];
  conv.bite.bit2 = var.bitVector[6];
  conv.bite.bit1 = var.bitVector[7];

  retorna = conv.inteiro;

  return retorna;
}

/// RETORNA STRING DOS BYTES (CASO SEJA UM VETOR DE BYTES RETORNA BYTE SEGUIDO DE BYTE SEM ESPAÇO):
string VarBin::toString()
{
  string bufferReturn = "";

  for(unsigned i = 0; i < VectorBin.size(); i++)
  {
    for(int j = 0; j < _VARBIN_BYTE_SIZE_; j++)
    {
      if(VectorBin[i].bitVector[j])
        bufferReturn += "1";
      else
        bufferReturn += "0";
    }
  }
  return bufferReturn;
}

/// RETORNA STRING DO BYTE DESEJADO:
string VarBin::toStringI(int indice)
{
  string bufferReturn = "";

  for(unsigned i = 0; i < _VARBIN_BYTE_SIZE_; i++)
  {
    if(VectorBin[indice].bitVector[i])
      bufferReturn += "1";
    else
      bufferReturn += "0";
  }
  return bufferReturn;
}

/// RETORNA STRING DOS BYTES (CASO SEJA UM VETOR DE BYTE RETORNA BYTES COM ESPAÇAMENTO DEFINIDO POR INTEIRO EM REFERENCIA):
string VarBin::toString(int space)
{
  string bufferReturn = "";
  int spaceCont = 0;

  if(space == 0) return "Espaço Invalido!";
  if(space % 2 == 1) return "Apenas Valores Pares";

  for(unsigned i = 0; i < VectorBin.size(); i++)
  {
    for(int j = 0; j < _VARBIN_BYTE_SIZE_; j++)
    {
      if(spaceCont == space)
      {
        bufferReturn += " ";
        spaceCont = 1;
      }
      else
        spaceCont++;

      if(VectorBin[i].bitVector[j])
        bufferReturn += "1";
      else
        bufferReturn += "0";
    }
  }
  return bufferReturn;
}

/// CONVERTE UM NIBBLE EM UM VALOR HEXADECIMA:
char VarBin::ntoh(bool bitA, bool bitB, bool bitC, bool bitD)
{
  int buffer = 0;

  if(bitA) buffer += 1;
  if(bitB) buffer += 2;
  if(bitC) buffer += 4;
  if(bitD) buffer += 8;

  switch(buffer)
  {
    case 0:
      return '0';
    case 1:
      return '1';
    case 2:
      return '2';
    case 3:
      return '3';
    case 4:
      return '4';
    case 5:
      return '5';
    case 6:
      return '6';
    case 7:
      return '7';
    case 8:
      return '8';
    case 9:
      return '9';
    case 10:
      return 'a';
    case 11:
      return 'b';
    case 12:
      return 'c';
    case 13:
      return 'd';
    case 14:
      return 'e';
    case 15:
      return 'f';
  }
  return '-';
}

/// CONVERTE UM BYTE EM UMA SEQUENCIA HEXADECIMAL:
string VarBin::btoh(_VARBIN_BYTE_STRUCT_ var)
{
  string retorna = "";

  retorna += ntoh(var.bitVector[3], var.bitVector[2], var.bitVector[1], var.bitVector[0]);
  retorna += ntoh(var.bitVector[7], var.bitVector[6], var.bitVector[5], var.bitVector[4]);

  return retorna;
}

/// RETORNA UMA STRING COM O BITE EM HEXADECIMAL:
string VarBin::toHex()
{
  string saida = "";
  _VARBIN_BYTE_STRUCT_ buffer;

  for(int i = 0; i < VectorBin.size(); i++)
  {
    saida += btoh(VectorBin[i]);
  }

  return saida;
}

/// RETORNA UMA STRING COM O BITE EM HEXADECIMAL COM SEPARAÇÃO DE BYTE POR ':':
string VarBin::toHexP()
{
  string saida = "";

  for(unsigned i = 0; i < VectorBin.size(); i++)
  {
    saida += btoh(VectorBin[i]);
    if(i + 1 != VectorBin.size()) saida += ':';
  }
  return saida;
}

/// RETORNA UMA STRING DE APENAS UM BYTE DEFINIDO (INDICE):
string VarBin::toHexI(int indice)
{
  string saida;

  saida = btoh(VectorBin[indice]);

  return saida;
}
