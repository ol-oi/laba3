#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


std::string encrypt(const std::string& text, int columns) {
    std::string cleaned_text;
    for (char c : text) {
        if (c != ' ') {
            cleaned_text += toupper(c);
        }
    }

    int rows = cleaned_text.length() / columns + (cleaned_text.length() % columns != 0 ? 1 : 0);
    std::vector<std::string> table(rows, std::string(columns, ' '));

    // Заполнение таблицы по строкам
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int index = i * columns + j;
            if (index < cleaned_text.length()) {
                table[i][j] = cleaned_text[index];
            }
        }
    }

    // Чтение по столбцам
    std::string encrypted_text;
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i < rows; ++i) {
            if (table[i][j] != ' ') {
                encrypted_text += table[i][j];
            }
        }
    }

    return encrypted_text;
}
