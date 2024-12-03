#include <iostream>
#include <cassert>
#include "modAlphaCipher.h"  // Подключаем заголовочный файл вашего класса

void testValidKey() {
    try {
        modAlphaCipher cipher("КЛЮЧ");
        std::cout << "Тест на создание объекта с валидным ключом пройден." << std::endl;
    } catch (const cipher_error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        assert(false);
    }
}

void testEmptyKey() {
    try {
        modAlphaCipher cipher("");
        assert(false); // Не должно дойти до этого
    } catch (const cipher_error& e) {
        std::cout << "Тест на создание объекта с пустым ключом пройден." << std::endl;
    }
}

void testInvalidKeyCharacters() {
    try {
        modAlphaCipher cipher("КЛЮЧ123");
        assert(false); // Не должно дойти до этого
    } catch (const cipher_error& e) {
        std::cout << "Тест на создание объекта с недопустимыми символами в ключе пройден." << std::endl;
    }
}

void testEncryptValidText() {
    modAlphaCipher cipher("КЛЮЧ");
    std::string encrypted = cipher.encrypt("ТЕКСТ");
    assert(!encrypted.empty());
    std::cout << "Тест на шифрование валидного текста пройден." << std::endl;
}

void testDecryptValidText() {
    modAlphaCipher cipher("КЛЮЧ");
    std::string encrypted = cipher.encrypt("ТЕКСТ");
    std::string decrypted = cipher.decrypt(encrypted);
    assert(decrypted == "ТЕКСТ");
    std::cout << "Тест на дешифрование валидного зашифрованного текста пройден." << std::endl;
}

void testEncryptInvalidText() {
    modAlphaCipher cipher("КЛЮЧ");
    try {
        cipher.encrypt("ТЕКСТ123");
        assert(false); // Не должно дойти до этого
    } catch (const cipher_error& e) {
        std::cout << "Тест на шифрование текста с недопустимыми символами пройден." << std::endl;
    }
}

void testDecryptInvalidText() {
    modAlphaCipher cipher("КЛЮЧ");
    try {
        cipher.decrypt("INVALIDTEXT123");
        assert(false); // Не должно дойти до этого
    } catch (const cipher_error& e) {
        std::cout << "Тест на дешифрование текста с недопустимыми символами пройден." << std::endl;
    }
}

int main() {
    try {
        testValidKey();
        testEmptyKey();
        testInvalidKeyCharacters();
        testEncryptValidText();
        testDecryptValidText();
        testEncryptInvalidText();
        testDecryptInvalidText();

        std::cout << "Все тесты пройдены!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1; // Возвращаем ненулевой код ошибки
    }

    return 0; // Успешное завершение
}
