#include <iostream>

void removeBlock(int arr[], int& size, int startIndex, int blockSize) {
    if (startIndex < 0 || startIndex >= size || blockSize <= 0) {
        std::cout << "Некоректные параметры удаления блока." << std::endl;
        return;
    }

    if (startIndex + blockSize > size) {
        blockSize = size - startIndex;
    }

    for (int i = startIndex + blockSize; i < size; i++) {
        arr[i - blockSize] = arr[i];
    }

    size -= blockSize;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер массива должен быть положительным." << std::endl;
        return 1;
    }

    int* arr = new int[size];

    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    int startIndex, blockSize;
    std::cout << "Введите индекс начала блока: ";
    std::cin >> startIndex;

    std::cout << "Введите размер блока для удаления: ";
    std::cin >> blockSize;

    removeBlock(arr, size, startIndex, blockSize);

    std::cout << "Массив после удаления блока:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
