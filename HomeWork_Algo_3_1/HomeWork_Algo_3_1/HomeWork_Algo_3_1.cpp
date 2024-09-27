#include <iostream>
#include <Windows.h>

void merge_sort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    std::cout << size1 << "  Исходный массив: " ;
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    merge_sort(arr1, 0, size1 - 1);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << size2 << "  Исходный массив: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    merge_sort(arr2, 0, size2 - 1);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << size3 << "  Исходный массив: ";
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    merge_sort(arr3, 0, size3 - 1);
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl << std::endl;

    return 0;
}
