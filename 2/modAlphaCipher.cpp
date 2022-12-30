#include <iostream>
#include <string>
#include "modAlphaCipher.h"
using namespace std;
string Cipher::cipher(string str, const int key)
{
    if (key == 0)
        throw cipher_error("Empty key");
    if (str == "")
        throw cipher_error("Empty text");
    if (key == 1)
        throw cipher_error("Invalid key");
    int msize = str.length();
    int height;
    if (msize % key > 0) {
        height = (msize / key) + 1;
    } else {
        height = (msize / key) + 0;
    }
    int stroka = str.length()%key;
    int zapoln;
    if (stroka > 0) {
        zapoln = key - stroka;
    } else {
                zapoln = 0;
    }
    char ** massiv = new char*[height];
    for (int i = 0; i < height; i++) {
        massiv[i] = new char[key];
    }
    string exit;
    for (int i = 0; i < zapoln; i++) {
        massiv[height-1][(key-1)-i] = '|';
    }
    int ID = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < key; j++) {
            if (massiv[i][j] == '|') continue;
            massiv[i][j] = str.at(ID);
            ID++;
        }
    }
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < height; j++) {
            if (massiv[j][(key-1)-i] == '|') continue;
            exit += massiv[j][(key-1)-i];
        }
    }
    for (int i = 0; i < height; i++) {
        delete[] massiv[i];
        }
    delete[] massiv;
    return exit;
}
string Cipher::decipher(string str, const int key)
{
    int height;
    if (str.length() % key > 0) {
        height = (str.length() / key) + 1;
    } else {
        height = (str.length() / key) + 0;
    }
    int stroka = str.length()%key;
    int zapoln;
    if (stroka > 0) {
        zapoln = key - stroka;
    } else {
        zapoln = 0;
    }
    char ** massiv = new char*[height];
    for (int i =0; i < height; i++) massiv[i] = new char[key];
    string exit;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < key; j++) {
            massiv[i][j] = '\0';
                    }
    }
    for (int i = 0; i < zapoln; i++) {
        massiv[height-1][(key-1)-i] = '*';
    }
    int ID = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < height; j++) {
            if (massiv[j][(key-1)-i] == '*') continue;
            massiv[j][(key-1)-i] = str.at(ID);
            ID++;
        }
    }
    for (int i = 0; i < str.length(); i++) {
        int y = i/key;
        int x = (i%key);
        char c = massiv[y][x];
        if (c != '\0') {
            exit+=c;
        }
    }
    for (int i = 0; i < height; i++) delete[] massiv[i];
    delete[] massiv;
    return exit;
}
