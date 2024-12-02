#include <iostream>
#include <vector>
#include <string>


std::string decrypt(const std::string& encrypted_text, int columns) {
    int rows = encrypted_text.length() / columns + (encrypted_text.length() % columns != 0 ? 1 : 0);
    std::vector<std::string> table(rows, std::string(columns, ' '));
    
    // Заполнение таблицы по столбцам
    int index = 0;
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (index < encrypted_text.length()) {
                table[i][j] = encrypted_text[index++];
            }
        }
    }

    // Чтение по строкам
    std::string decrypted_text;
    for (const auto& row : table) {
        decrypted_text += row;
    }

    return decrypted_text;
}
