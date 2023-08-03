#include <iostream>
#include <string>
using namespace std;

string encrypt_caesar(string str, int n) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char) ((((str[i] + n) - 'a') % 26) + 'a');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char) ((((str[i] + n) - 'A') % 26) + 'A');
        }
    }
    return str;
}


string decrypt_caesar(string str, int n) {
    return encrypt_caesar(str, 26 - n);
}

int main() {
    string str;
    int n;
    cout << "Input a string:\n\n";
    getline(cin, str);
    cout << "\nInput a shift value: ";
    cin >> n;
    cout << "\nCode:\n";
    cout << encrypt_caesar(str, n) << "\n\nDecode:\n\n";
    cout << decrypt_caesar(str, n) << "\n";
}