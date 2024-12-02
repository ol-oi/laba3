#include <iostream>
#include <cctype>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

void check(const string& Text, const string& key, const bool destructCipherText=false) {
    try {
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
#pragma once
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

using namespace std;

class modAlphaCipher {
    private:
        wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        map <wchar_t,int> alphaNum;
        vector <int> key;
        vector<int> convert(const string& s);
        string convert(const vector<int>& v);
        string getValidKey(const string & s);
        string getValidOpenText(const string & s);
        string getValidCipherText(const string & s);
    public:
        modAlphaCipher()=delete;
        modAlphaCipher(const string& skey);
        string encrypt(const string& open_text);
        string decrypt(const string& cipher_text);
};

class cipher_error : public std::invalid_argument {
public:
    explicit cipher_error(const std::string& what_arg) : std::invalid_argument(what_arg) {}
    explicit cipher_error(const char* what_arg) : std::invalid_argument(what_arg) {}
};

        decryptedText = cipher.decrypt(cipherText);

        string decryptedTextNoSpaces;
        for (char c : decryptedText) {
            if (c != ' ') {
                decryptedTextNoSpaces += c;
            }
        }

        cout << "Ключ = " << key << endl;
        cout << "Открытый текст: " << Text << endl;
        cout << "Зашифрованный текст: " << cipherText << endl;
        cout << "Расшифрованный текст: " << decryptedTextNoSpaces << endl;
    } catch (const cipher_error &e) {
        cerr << "Ошибка: " << e.what() << endl;
    } catch (const std::exception &e) {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

int main() {
    check("ЧУМАЗИН", "КЛЮЧ");
    cout << "испытание 1\n" << endl;
    check("ЧУМАЗИН", "Ключ");
    cout << "испытание 2\n" << endl;
    check("ЧУМАЗИН", "");
    cout << "испытание 3\n" << endl;
    check("ЧУМАЗИН", "Клю4");
    cout << "испытание 4\n" << endl;
    check("ЧУМА ЗИН", "КЛЮЧ");
    cout << "испытание 5\n" << endl;
    check("CHUM", "КЛЮЧ");
    cout << "испытание 6\n" << endl;
    check("           ", "КЛЮЧ");
    cout << "испытание 7\n" << endl;
    return 0;
}
