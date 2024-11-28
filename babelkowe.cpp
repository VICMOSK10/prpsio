#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>

using namespace std;


template <typename T>
void bubblesort_for_for_pointer(T* arr, size_t n) {
    T* w1, * w2, temp;
    for (size_t i = 0; i < n; i++) {
        w1 = arr;
        w2 = w1 + 1;

        for (size_t j = 0; j < n - 1; j++) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
            w1++;
            w2++;
        }
    }
}

template <typename T>
void bubblesort_for_for_index(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubblesort_for_while_pointer(T* arr, size_t n) {
    bool zamiana = true;
    while (zamiana) {
        T* w1, * w2, temp;
        zamiana = false;
        w1 = arr;
        w2 = w1 + 1;
        for (size_t j = 0; j < n - 1; j++) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
                zamiana = true;
            }
            w1++;
            w2++;
        }
    }
}


template <typename T>
void bubblesort_for_short_index(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubblesort_for_while_index(T arr[], size_t n) {
    bool zamiana = true;
    while (zamiana) {
        zamiana = false;
        for (size_t j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                zamiana = true;
            }
        }
    }
}


template <typename T>
void bubblesort_for_short_pointer(T* arr, size_t n) {
    T* w1, * w2, temp;
    for (size_t i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;
            }
        }
    }
}

template <typename T>
bool sprawdzanie(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename Func, typename T>
double measure_time(Func func, T arr[], size_t n) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

template <typename T>
void copy_array(T source[], T dest[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void wszystko(int n, ofstream& file) {
    int* arr_int = new int[n];
    int* arr_int_copy = new int[n];
    float* arr_float = new float[n];
    float* arr_float_copy = new float[n];

    for (int i = 0; i < n; i++) {
        arr_int[i] = rand() % 1000 + 1;
        arr_float[i] = static_cast<float>(arr_int[i]);
    }

    copy_array(arr_int, arr_int_copy, n);
    copy_array(arr_float, arr_float_copy, n);

    file << "| " << setw(1) << "Liczba elementow: " << n << " |\n";
    file << "|------------------------------|--------------------|--------------------|\n";
    file << "| Funkcja                      | Czas (int)         | Czas (float)       |\n";
    file << "|------------------------------|--------------------|--------------------|\n";


    file << "| Bubblesort for for pointer   | "
        << setw(15) << measure_time(bubblesort_for_for_pointer<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_for_pointer<float>, arr_float, n) << " ms" << " | \n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "| Bubblesort for for index     | "
        << setw(15) << measure_time(bubblesort_for_for_index<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_for_index<float>, arr_float, n) << " ms" << " |\n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "| Bubblesort for while pointer | "
        << setw(15) << measure_time(bubblesort_for_while_pointer<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_while_pointer<float>, arr_float, n) << " ms" << " |\n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "| Bubblesort for short index   | "
        << setw(15) << measure_time(bubblesort_for_short_index<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_short_index<float>, arr_float, n) << " ms" << " |\n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "| Bubblesort for while index   | "
        << setw(15) << measure_time(bubblesort_for_while_index<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_while_index<float>, arr_float, n) << " ms" << " |\n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "| Bubblesort for short pointer | "
        << setw(15) << measure_time(bubblesort_for_short_pointer<int>, arr_int, n) << " ms" << " | "
        << setw(15) << measure_time(bubblesort_for_short_pointer<float>, arr_float, n) << " ms" << " |\n";
    copy_array(arr_int_copy, arr_int, n);
    copy_array(arr_float_copy, arr_float, n);

    file << "|------------------------------|--------------------|--------------------|\n\n";

    delete[] arr_int;
    delete[] arr_int_copy;
    delete[] arr_float;
    delete[] arr_float_copy;
}


int main() {
    srand(time(0));

    ofstream file("wynik.txt");

    if (file.is_open()) {
        wszystko(100, file);
        wszystko(1000, file);
        wszystko(10000, file);

        file.close();
        cout << "Wszystko zapisane w pliku wynik.txt\n";
    }
    else {
        cerr << "Nie można otworzyć pliku.\n";
    }

    return 0;
}

