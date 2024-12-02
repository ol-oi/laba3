#include <iostream>
#include <cctype>
#include <string>
#include "encrypt.cpp"
#include "decrypt.cpp"

bool is_valid_columns(const std::string& input) {
    if (input.empty()) return false; // Пустое поле
    for (char c : input) {
        if (!isdigit(c)) return false; // Не число
    }
    return true; // Ввод валиден
}

void run_tests() {
    std::cout << "Запуск тестов...\n";

    // Пример тестов
    struct Test {
        std::string input;
        int columns;
        std::string expected_encrypted;
        std::string expected_decrypted;
    };

    Test tests[] = {
        {"HELLO", 2, "HLOEL", "HELLO"},
        {"TESTING", 3, "TGEITNS", "TESTING"},
        {"ROUTE", 2, "RUTEO", "ROUTE"},
        {"CIPHER", 3, "CPIHER", "CIPHER"}
    };

    for (const auto& test : tests) {
        std::string encrypted = encrypt(test.input, test.columns);
        std::string decrypted = decrypt(encrypted, test.columns);

        std::cout << "Тест: "" << test.input << "", Количество столбцов: " << test.columns << "\n";
        std::cout << "Ожидаемый зашифрованный текст: " << test.expected_encrypted << "\n";
        std::cout << "Полученный зашифрованный текст: " << encrypted << "\n";

        if (encrypted == test.expected_encrypted) {
            std::cout << "Тест шифрования пройден.\n";
        } else {
            std::cout << "Тест шифрования пройден!\n";
        }

        std::cout << "Ожидаемый расшифрованный текст: " << test.expected_decrypted << "\n";
        std::cout << "Полученный расшифрованный текст: " << decrypted << "\n";

        if (decrypted == test.expected_decrypted) {
            std::cout << "Тест расшифрования пройден.\n";
        } else {
            std::cout << "Тест расшифрования пройден!\n";
        }
        
        std::cout << "-------------------------\n";
    }
}

int main() {
    run_tests(); // Запускаем тесты

    std::string text;
    std::string columns_input;
    int columns;
    int choice;

    std::cout << "Выберите действие:\n1. Шифрование\n2. Расшифрование\n";
    std::cin >> choice;
    std::cin.ignore(); // Игнорируем символ новой строки после выбора

    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    // Проверка на пустой текст
    if (text.empty()) {
        std::cout << "Ошибка: текст не может быть пустым для шифрования/расшифрования.\n";
        return 1; // Завершаем программу с ошибкой
    }

    // Запрос количества столбцов с проверкой
    while (true) {
        std::cout << "Введите количество столбцов: ";
        std::getline(std::cin, columns_input);
        
        if (is_valid_columns(columns_input)) {
            columns = std::stoi(columns_input);
            if (columns > 0) break; // Убедимся, что количество столбцов положительное
            else std::cout << "Количество столбцов должно быть больше 0\n";
        } else {
            std::cout << "Ошибка: введите положительное целое число\n";
        }
    }

    if (choice == 1) {
        std::string encrypted_text = encrypt(text, columns);
        std::cout << "Зашифрованный текст: " << encrypted_text << std::endl;
    } else if (choice == 2) {
        std::string decrypted_text = decrypt(text, columns);
        std::cout << "Расшифрованный текст: " << decrypted_text << std::endl;
    } else {
        std::cout << "Неверный выбор действия\n";
    }

    return 0;
}
