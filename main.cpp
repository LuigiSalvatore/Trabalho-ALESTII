#pragma region Includes
#include "DLL.hpp"
#include <iostream>
#include <fstream>
#define CASO_DE_TESTE "test01"
#pragma endregion

int main(int argc, char **argv)
{
    fstream casoTeste;
    DLL dll;
    string str;
    string filename(argv[1]);
    casoTeste.open(filename, ios::in);

    if (!casoTeste.is_open())
    {
        cout << "ERROR ";
        return 0;
    }
    getline(casoTeste, str);

    for (int i = 0; i < str.length(); i++)
    {
        dll.add(str[i]);
    }
    // cout << dll.str() << endl;
    dll.doStuff();
    cout << dll.str() << endl;
}