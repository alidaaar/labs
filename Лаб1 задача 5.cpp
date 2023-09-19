#include <iostream>

void insertBlock(int arr[], int& size, int index, int block[], int blockSize) {
    if (index < 0 || index > size) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    // Увеличиваем размер массива на blockSize
    size += blockSize;

    // Сдвигаем элементы справа от индекса вправо, чтобы создать место для блока
    for (int i = size - 1; i >= index + blockSize; i--) {
        arr[i] = arr[i - blockSize];
    }

    // Вставляем блок элементов в массив
    for (int i = 0; i < blockSize; i++) {
        arr[index + i] = block[i];
    }
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5 };
    int size = 5;

    int block[3] = { 10, 11, 12 };
    int blockSize = 3;
    int insertIndex = 2;

    insertBlock(arr, size, insertIndex, block, blockSize);

    // Выводим массив после вставки блока
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
