#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string get_adress_part(string ip, int n) {

    string to = "";
    int dots = 0;
    for (int i = 0; i < ip.length(); i++) {
        if (ip[i] == '.') {
            ++dots;
        } else if (dots == n)
        {
            to += ip[i];
        }
    }
    return to;
}

int main() {
    string str, sym;
    int intsym;
    cout << "Input an IP adress: ";
    getline(cin, str);
    bool unnecessaryZero = true, limit = true, dotInTheEnd = true, twoDots = true, outsiderSymbols = true;
    for (int i = 0; i < 4; i++)     //этот цикл проверяет наличие посторонних элементов
    {
        sym = get_adress_part(str, i);
        for (int i = 0; i < sym.length(); i++)
        {
            if (isdigit(sym[i]) == 0) {
                outsiderSymbols = false;
                break;
            }
        }
        if (outsiderSymbols == false) {break;}
    }

    for (int i = 1; i < str.length(); i++) {    //этот цикл проверяет наличие двух точек подряд
        if (str[i] == str[i - 1] && str[i] == '.') {
            twoDots = false;
        }
        
    }

    if (outsiderSymbols == true && twoDots == true)    //проверка на то, что есть посторонние элементы, чтобы избежать ошибки с std::stoi при конвертировании в число
    {
    
        for (int i = 0; i < 4; i++) {           //этот цикл проверяет наличие ненужных нулей и чисел больше 255
            sym = get_adress_part(str, i);
            intsym = stoi(sym);

            if (sym != to_string(intsym)) {
                unnecessaryZero = false;
                break;
            }
            if (intsym > 255) {
                limit = false;
                break;
            }
        }

    }

    if (str[str.length() - 1] == '.') {
        dotInTheEnd = false;
    }

    if (unnecessaryZero && limit && dotInTheEnd && twoDots && outsiderSymbols) {
        cout << "Valid";
    } else
    {
        cout << "Invalid";
    }
    
}