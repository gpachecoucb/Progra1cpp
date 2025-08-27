#include <iostream>
using namespace std;
int main()
{
    char letra;
    cout << "Ingrese una letra" << endl;
    cin >> letra;
    if(letra >= 'A' && letra <= 'z'){
        if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            cout << "Es una vocal" << endl;
        
        }
        else if(letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U'){
            cout << "Es una vocal" << endl;
        
        }
        else {
            cout << "Es una consonante" <<endl;
        }
        
    }
    else{
        cout << "Es un caracter especial";
    }
    return 0;
}