#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
    int M, N;

    std::cout << "Введите размер массива A (M): ";
    std::cin >> M;

    std::cout << "Введите размер массива B (N): ";
    std::cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    // Ввод элементов массива A
    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    // Ввод элементов массива B
    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Создание третьего массива
    int* C = new int[M + N];

    int count = 0;

    // Добавление элементов из массива A, которые не встречаются в B
    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            // Элемент не найден в B, добавляем его в C
            C[count] = A[i];
            count++;
        }
    }

    // Добавление элементов из массива B, которые не встречаются в A
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            // Элемент не найден в A, добавляем его в C
            C[count] = B[i];
            count++;
        }
    }

    // Вывод элементов третьего массива C
    std::cout << "Элементы третьего массива C:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
