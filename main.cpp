#include <iostream>
#include <cctype>
#include "Cipher.h"
#include <locale>
using namespace std;

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int key;
    wstring text;
    unsigned op;
    wcout<<L"Cipher ready. Input key: ";
    wcin>>key;
    wcout<<L"Key loaded\n";
    Cipher cipher(key);
    do {
        wcout<<L"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        wcin>>op;
    
        if (op > 2) {
            wcout<<L"Illegal operation\n";
        } else if (op >0) {
            wcout<<L"Cipher ready. Input text: ";
            wcin>>text;
            if (op==1) {
                wcout<<L"Encrypted text: "<<cipher.encrypt(text)<<endl;
            } else {
                wcout<<L"Decrypted text: "<<cipher.decrypt(text)<<endl;
            }
        } else {
            wcout<<L"Operation aborted: invalid text\n";
        }
    } while (op!=0);
    return 0;
}
