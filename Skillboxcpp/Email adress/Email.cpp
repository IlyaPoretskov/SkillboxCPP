#include <iostream>
#include <string>
using namespace std;

string first_part(string str) {
    string count = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '@') {
            count += str[i];
        } else {
            break;
        }
    }
    return count;
}

string second_part(string str) {
    bool flag = false;
    string line = "";
    for (int i = 0; i < str.length(); i++) {
        if (flag == true) {
            line += str[i];
        }
        if (str[i] == '@') {
            flag = true;
        }
    }
    return line;
}

int main() {
    string str;
    int dogCount = 0;
    string symbols1 = "!#$%&'*+-/=?^_`{|}~.-", symbols2 = "-.";
    bool SymbolsInFirstPart = true, oneSym = false, dogs = false, twoDots = true, SymbolsInSecondPart = true;
    cout << "Input an email adress: ";
    getline(cin, str);
    string firstPart = first_part(str);
    string secondPart = second_part(str);
    for (int i = 0; i < firstPart.length(); i++) {
        oneSym = false;
         for (int j = 0; j < symbols1.length(); j++) {
            if (firstPart[i] != symbols1[j]) {
                continue;
            } else
            {
                oneSym = true;
                break;
            }
        }
        if (oneSym == true || (firstPart[i] >= '0' && firstPart[i] <= '9') || (firstPart[i] >= 'a' && firstPart[i] <= 'z')
                     || (firstPart[i] >= 'A' && firstPart[i] <= 'Z')) {
            continue;
        } else
        {
            SymbolsInFirstPart = false;
            break;
        }  
    }
    if (firstPart.length() > 64 || firstPart.length() < 1 || firstPart[0] == '.') {SymbolsInFirstPart = false;}
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1] && str[i] == '.') {
            twoDots = false;
        }
        
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '@') {
            ++dogCount;
        }
    }
    if (dogCount == 1) {dogs = true;}
    for (int i = 0; i < secondPart.length(); i++) {
        oneSym = false;
         for (int j = 0; j < symbols2.length(); j++) {
            if (secondPart[i] != symbols2[j]) {
                continue;
            } else
            {
                oneSym = true;
                break;
            }
        }
        if (oneSym == true || (secondPart[i] >= '0' && secondPart[i] <= '9') || (secondPart[i] >= 'a' && secondPart[i] <= 'z')
                     || (secondPart[i] >= 'A' && secondPart[i] <= 'Z')) {
            continue;
        } else
        {
            SymbolsInSecondPart = false;
            break;
        }  
    }
    if (secondPart.length() > 63 || firstPart.length() < 1 || secondPart[secondPart.length()] == '.') {SymbolsInSecondPart = false;}
    if (SymbolsInFirstPart && SymbolsInSecondPart && dogs && twoDots)
    {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    system("pause");
}






