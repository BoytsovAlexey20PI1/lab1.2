#pragma once
#include <string>
#include <locale>
using namespace std;
class Cipher
{
private:
    int sto,str,len;
public:
    Cipher()=delete;
    Cipher(const int& key);
    wstring encrypt(const wstring& open_text);
    wstring decrypt(const wstring& cipher_text);
    void table(const wstring& open_text);
};
