#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include <iomanip> // Для форматирования вывода

using namespace std;
using namespace std::chrono;

// Устанавливает цвет текста в консоли
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Функция для вывода текста с раскрашиванием введенных символов
void PrintWithColor(const string& text, int matchedLength) {
    system("CLS"); // Очищает экран консоли
    for (size_t i = 0; i < text.length(); ++i) {
        if (i < matchedLength) {
            SetColor(10); // Салатовый цвет (светло-зеленый)
        }
        else {
            SetColor(15); // Белый цвет
        }
        cout << text[i];
    }
    SetColor(15); // Восстановить белый цвет
    cout << endl;
}

int main() {
    string input;

    // Цикл для запроса текста, пока не будет введено что-либо
    do {
        cout << "Enter text: ";
        getline(cin, input);

        if (input.empty()) {
            cout << "No text entered. Please enter some text." << endl;
        }
    } while (input.empty());

    vector<char> strrr(input.begin(), input.end());
    strrr.push_back('\0');

    int matchedLength = 0;
    auto start = high_resolution_clock::time_point();
    bool started = false;

    // Изначально выводим пустую строку с исходным текстом
    PrintWithColor(input, matchedLength);

    while (matchedLength < input.length()) {
        if (_kbhit()) { // Проверяет, была ли нажата клавиша
            char ch = _getch(); // Считывает символ с клавиатуры
            if (!started) {
                start = high_resolution_clock::now(); // Захватывает время начала ввода первого символа
                started = true;
            }
            if (ch == input[matchedLength]) {
                matchedLength++; // Увеличивает счетчик совпавших символов
            }
            PrintWithColor(input, matchedLength); 
        }
    }

    auto end = high_resolution_clock::now(); // Захватывает время окончания ввода последнего символа
    duration<double> diff = end - start; // Рассчитывает продолжительность ввода в секундах

    cout << "Completed" << endl;
    cout << fixed << setprecision(2) << "Time taken: " << diff.count() << "s." << endl; // Вывод времени с двумя знаками после запятой

    system("pause");
    return 0;
}
