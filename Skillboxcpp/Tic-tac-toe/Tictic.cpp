#include <iostream>
#include <string>
using namespace std;

char get_sym(string first, string second, string third, int x, int y) {
    char n;
    switch(y) {
        case 0: {
            n = first[x];
            break;
        }
        case 1: {
            n = second[x];
            break;
        }
        case 2: {
            n = third[x];
        }
    }
    return n;
}

int find_quantity(char n, string str) {
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == n) {++count;}
    }
    return count;
}

int main() {
    string first, second, third;
    char sym;
    int winOs = 0, winXs = 0, draw = 0;
    bool errors = true;
    cout << "Input a tic-tac-toe game:\n";
    cin >> first >> second >> third;
    string all = first + second + third;
    for (int i = 0; i < 2; i++) {
        sym = (i == 0) ? 'X' : 'O';
            string symstr = {sym, sym, sym}, 
                    line1 = {first[0], second[0], third[0]}, 
                    line2 = {first[1], second[1], third[1]}, 
                    line3 = {first[2], second[2], third[2]},

                    mainDiagonal = {first[0], second[1], third[2]},
                    sideEffectDg = {first[2], second[1], third[0]};

        if (first == symstr) {++(i == 0 ? winXs : winOs);}            /*Проверка горизонталей*/
        if (second == symstr) {++(i == 0 ? winXs : winOs);}
        if (third == symstr) {++(i == 0 ? winXs : winOs);}            /**/

        if (line1 == symstr) {++(i == 0 ? winXs : winOs);}            /*Проверка вертикалей*/
        if (line2 == symstr) {++(i == 0 ? winXs : winOs);}
        if (line3 == symstr) {++(i == 0 ? winXs : winOs);}            /**/

        if (mainDiagonal == symstr) {++(i == 0 ? winXs : winOs);}            /*Проверка диагоналей*/
        if (sideEffectDg == symstr) {++(i == 0 ? winXs : winOs);}            /**/
    }
    for (int i = 0; i < all.length(); i++) {
        if (all[i] != 'X' && all[i] != 'O' && all[i] != '.') {
            errors = false; break;
        }
    }
    draw = (winOs + winXs == 0) ? 1 : 0;
    if (winOs + winXs + draw != 1) {errors = false;}
    if (find_quantity('O', all) != find_quantity('X', all) && find_quantity('O', all) + 1 != find_quantity('X', all)) {errors = false;}
    if (winXs == 1 && find_quantity('O', all) + 1 != find_quantity('X', all)) {
        errors = false;
    }
    if (winOs == 1 && find_quantity('X', all) != find_quantity('O', all)) {
        errors = false;
    }
    if (!errors) {
        cout << "Incorrect\n";
        return 0;
    }
    if (draw == 1) {cout << "Nobody\n";}
    if (winXs == 1) {cout << "Petya won\n";}
    if (winOs == 1) {cout << "Vanya won\n";}
    system("pause");
}
