#include <iostream>
#include <fstream>

#include "src/VarBin.cpp"

using namespace std;

int main(void)
{
  VarBin teste("UnumSumus");

  ofstream arq("saida");


  arq << teste.toString(8) << endl;

  // 01010101 01101110 01110101 01101101 01010011 01110101 01101101 01110101 01110011

  return 0;
}
