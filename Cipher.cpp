#include "Cipher.h"
using namespace std;

Cipher::Cipher(const int& key)
{
    sto=key;
}
void Cipher::table(const wstring& open_text)
{
    len=open_text.size();
    if(len>sto){
        str=len/sto;
    }else{
     str=1;   
    }
    if (len%sto>0) 
        str+=1;
}
wstring Cipher::encrypt(const wstring& open_text)
{
    table(open_text);
    wstring tcipher[str][sto];
    int nums=0;
    for (int i=0; i<str; i++) {
        for (int j=sto-1; j>=0; j--) {
            if (nums<len) {
                tcipher[i][j]=open_text[nums];
            } else {
                tcipher[i][j]=L"_";
            }
            nums++;
        }
    }
    wstring en_result;
    for (int j=sto-1; j>=0; j--) {
        for (int i=0; i<str; i++) {
            en_result+=tcipher[i][j];
        }
    }
    return en_result;
}
wstring Cipher::decrypt(const wstring& cipher_text)
{
    table(cipher_text);
    wstring tcipher[str][sto];
    int nums=0;
    for (int j=0; j<sto; j++) {
        for (int i=0; i<str; i++) {
            tcipher[i][j]=cipher_text[nums];
            nums++;
        }
    }
    wstring de_result;
    for (int i=0; i<str; i++) {
        for (int j=0; j<sto; j++) {
            if (tcipher[i][j]!=L"_")
            de_result+=tcipher[i][j];
        }
    }
    return de_result;
}
