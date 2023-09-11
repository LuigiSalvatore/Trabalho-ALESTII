#pragma region Includes
#include "funcs.hpp"
#pragma endregion


vector<string> splitCSV(string linhaCSV, char separador)
{
   vector<string> res;
   char c;
   string campo = "";
   for (int i = 0; i < linhaCSV.size(); ++i)
   {
      c = linhaCSV.at(i);
      if (c == separador)
      {
         res.push_back(campo);
         campo = "";
      }
      else
         campo.append(1, c);
   }
   res.push_back(campo);
   return res;
}
bool carregaPaises(string nomeArquivo)
{
   ifstream f(nomeArquivo);
   if (!f.is_open())
      return false;
   string linhaCSV;
   while (getline(f, linhaCSV))
   {
      vector<string> campos = splitCSV(linhaCSV, ';');
      if (campos.size() != 3)
      {
         f.close();
         return false;
      }
    //   paises.push_back(new Pais(campos[0], campos[1], campos[2]));
   }
   f.close();
   return true;
}
