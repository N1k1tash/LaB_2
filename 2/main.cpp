#include <iostream>
#include <string>
#include "modAlphaCipher.h"
using namespace std;
string cipher(string str, const int key);
string decipher(string str, const int key);
int main()
{
    Cipher cpr;
    int number = 7;
    try {
        string original = "MAZZERATI";
        string encrypted = cpr.cipher(original, number);
        string decrypted = cpr.decipher(encrypted, number);
        cout << original << endl;
        cout << encrypted << endl;
        cout << decrypted << endl;
    } catch (const cipher_error & e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
