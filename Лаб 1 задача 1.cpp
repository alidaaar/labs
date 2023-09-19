#include <iostream>

// Функция для проверки, существует ли элемент в массиве
bool containsElement(const int* array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return true;
        }
    }
    return false;
}

// Функция для нахождения общих элементов между двумя массивами без повторений
void findCommonElements(const int* arrayA, int sizeA, const int* arrayB, int sizeB, int*& resultArray, int& resultSize) {
    for (int i = 0; i < sizeA; i++) {
        if (containsElement(arrayB, sizeB, arrayA[i]) && !containsElement(resultArray, resultSize, arrayA[i])) {
            resultArray[resultSize] = arrayA[i];
            resultSize++;
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int M, N;

    std::cout << "Введите размер массива A: ";
    std::cin >> M;
    int* arrayA = new int[M];

    std::cout << "Введите элементы массива A: ";
    for (int i = 0; i < M; i++) {
        std::cin >> arrayA[i];
    }

    std::cout << "Введите размер массива B: ";
    std::cin >> N;
    int* arrayB = new int[N];

    std::cout << "Введите элементы массива B: ";
    for (int i = 0; i < N; i++) {
        std::cin >> arrayB[i];
    }

    // Создаем третий массив для общих элементов
    int* commonArray = new int[std::min(M, N)]; // Минимальный размер возможного массива
    int commonSize = 0;

    // Находим общие элементы и добавляем их в commonArray
    findCommonElements(arrayA, M, arrayB, N, commonArray, commonSize);

    // Выводим общие элементы
    std::cout << "Общие элементы двух массивов без повторений: ";
    for (int i = 0; i < commonSize; i++) {
        std::cout << commonArray[i] << " ";
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] arrayA;
    delete[] arrayB;
    delete[] commonArray;

    return 0;
}
