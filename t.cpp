#include <iostream>

int* array_additional(int* numbers, int& capacity, int& size);

int main() {
    int capacity = 5;             // Начальная ёмкость массива
    int size_current = 0;         // Текущий размер массива
    int* numbers = nullptr;       // Указатель на массив (инициализируем нулевым указателем)

    // Вызываем функцию для динамического создания массива и ввода чисел
    numbers = array_additional(numbers, capacity, size_current);

    std::cout << "Введённые числа:" << std::endl;

    // Выводим числа из массива
    for (int i = 0; i < size_current; i++) {
        std::cout << numbers[i] << " ";
    }

    // Очистка: освобождение динамически выделенной памяти
    delete[] numbers;

    return 0;
}

int* array_additional(int* numbers, int& capacity, int& size_current, string &stopChar) {
    int input;
    numbers = new int[capacity];

    while (true) {
        std::cin >> input;

        if (input == stopChar) {
            break; // Прекращаем ввод, когда введено -1
        }

        // Проверяем, заполнен ли массив, и изменяем размер при необходимости
        if (size_current == capacity) {
            capacity *= 2; // Удваиваем ёмкость
            int* newNumbers = new int[capacity];

            // Копируем существующие элементы в новый массив
            for (int i = 0; i < size_current; i++) {
                newNumbers[i] = numbers[i];
            }

            // Освобождаем старую память и обновляем указатель
            delete[] numbers;
            numbers = newNumbers;
        }

        // Добавляем введённое число в массив
        numbers[size_current] = input;
        size_current++;
    }
    return numbers;
}
