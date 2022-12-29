#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        TiMP cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = tolower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        cerr<<"Error: "<<e.what()<<endl;
    }
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"МАЗЕРАТИ",L"ФОРД");
    check(L"МАЗЕРАТИ",L"");
    check(L"МАЗЕРАТИ",L"7ФОРД7");
    check(L"М А З Е Р А Т И",L"ФОРД");
    check(L"123",L"МАЗЕРАТИ");
}
