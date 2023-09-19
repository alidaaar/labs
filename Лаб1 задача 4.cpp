#include <iostream>

// Функция для добавления блока элементов в конец массива
void addBlockToEnd(int*& arr, int& currentSize, const int* block, int blockSize) {
    // Выделяем новую память для массива, учитывая размер блока
    int* newArray = new int[currentSize + blockSize];

    // Копируем существующие элементы из старого массива в новый
    for (int i = 0; i < currentSize; i++) {
        newArray[i] = arr[i];
    }

    // Копируем блок элементов в новый массив
    for (int i = 0; i < blockSize; i++) {
        newArray[currentSize + i] = block[i];
    }

    // Удаляем старый массив
    delete[] arr;

    // Обновляем указатель на новый массив и текущий размер
    arr = newArray;
    currentSize += blockSize;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int* myArray = nullptr;
    int currentSize = 0;

    // Добавляем блок элементов в пустой массив
    int blockToAdd[] = { 10, 20, 30 };
    int blockSize = sizeof(blockToAdd) / sizeof(blockToAdd[0]);

    addBlockToEnd(myArray, currentSize, blockToAdd, blockSize);

    // Выводим содержимое массива после добавления блока
    for (int i = 0; i < currentSize; i++) {
        std::cout << myArray[i] << " ";
    }

    // Не забудьте освободить выделенную память после использования
    delete[] myArray;

    return 0;
}
