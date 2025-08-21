#include <iostream>

using namespace std;
int main()
{
    system("chcp 65001");
    system("cls");
    int valor1 = 0;
    int valor2 = 0;
    cout << "ingrese el valor 1: ";
    cin >> valor1;
    cout << "ingrese el valor 2: ";
    cin >> valor2;
    if(valor1 > valor2)
    {
        cout << valor1 << " es mayor a " << valor2;
    }
    else{
        if(valor1 == valor2)
        {
            cout << valor1 << " es igual a " << valor2;

        }
        else
        {
            cout << valor1 << " es menor " << valor2;
        }
        
    }
    
    return 0;
}