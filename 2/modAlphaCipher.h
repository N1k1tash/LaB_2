#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Cipher
{
public:
    string cipher(string str, const int key);
    string decipher(string str, const int key);
};
class cipher_error : public invalid_argument
{
public:
	explicit cipher_error(const string& what_arg) :
		invalid_argument(what_arg) {}
	explicit cipher_error(const char* what_arg) :
		invalid_argument(what_arg) {}
};
