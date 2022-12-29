#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>

using namespace std;

class TiMP
{
private:
	wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
	wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	map <wchar_t,int> alphaNum;
	vector <int> key;
	vector<int> convert(const wstring& ws);
	wstring convert(const vector<int>& v);
	wstring getValidKey(const wstring & ws);
	wstring getValidOpenText(const wstring & ws);
	wstring getValidCipherText(const wstring & ws);
public:
	TiMP()=delete;
	TiMP(const wstring& wskey);
	wstring encrypt(const wstring& open_text);
	wstring decrypt(const wstring& cipher_text);
};
class cipher_error: public invalid_argument
{
public:
	explicit cipher_error (const string& what_arg):
		invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		invalid_argument(what_arg) {}
};
