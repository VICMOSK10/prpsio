#include <iostream>
#include <ctime>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

template <typename T>
void bubblesort_index(T arr[], size_t n) {
    T temp;
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void bubbleSortVector(std::vector<T>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

template <typename T>
void bubblesort_pointer(T* arr, size_t n) {
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
bool sprawdzanie(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
double measure_time(void (*func)(T[], size_t), T arr[], size_t n) {
    auto start = chrono::high_resolution_clock::now();
    func(arr, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    return duration.count();
}

template <typename T>
double measure_time1(void (*func)(std::vector<T>&), std::vector<T>& vec) {
    auto start = chrono::high_resolution_clock::now();
    func(vec);
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

double calculate_percentage_increase(double base, double current) {
    if (base == 0) return 0;
    return ((current - base) / base) * 100;
}

void wszystko(int n, ofstream& file, double& base_time_index) {
    int* arr_int = new int[n];
    int* arr_int_copy = new int[n];
    float* arr_float = new float[n];
    float* arr_float_copy = new float[n];
    std::vector<int> vec;
    std::vector<float> vec1;

    for (int i = n; i >= 1; --i) {
        vec.push_back(i);
        vec1.push_back(sqrt(i));
    }

    for (int i = 0; i < n; i++) {
        arr_int[i] = n - i;
        arr_float[i] = sqrt(n - i);
    }

    copy_array(arr_int, arr_int_copy, n);
    copy_array(arr_float, arr_float_copy, n);

    file << "| " << setw(1) << "Liczba elementow: " << n << " |\n";
    file << "|------------------------------|-------------------------------|------------------------------|------------------|------------------|\n";
    file << "| Funkcja                      | Czas (int)                    | Czas (float)                 | Sprawdzenie int  | Sprawdzenie float|\n";
    file << "|------------------------------|-------------------------------|------------------------------|------------------|------------------|\n";

    double czas_int_index = measure_time(bubblesort_index<int>, arr_int, n);
    double czas_float_index = measure_time(bubblesort_index<float>, arr_float, n);

        base_time_index = czas_int_index;
		double base_time_index_float = czas_float_index;
    
    double pointer_increase_int = calculate_percentage_increase(base_time_index, measure_time(bubblesort_pointer<int>, arr_int, n));
    double pointer_increase_float = calculate_percentage_increase(base_time_index_float, measure_time(bubblesort_pointer<float>, arr_float, n));

    file << "| Bubblesort pointer           | "
        << setw(15) << measure_time(bubblesort_pointer<int>, arr_int, n) << " ms" << " (" << setw(5) << pointer_increase_int << "%) | "
        << setw(14) << measure_time(bubblesort_pointer<float>, arr_float, n) << " ms" << " (" << setw(5) << pointer_increase_float << "%) | "
        << setw(16) << (sprawdzanie(arr_int, n) ? "Tak" : "Nie") << " | "
        << setw(16) << (sprawdzanie(arr_float, n) ? "Tak" : "Nie") << " |\n";

    double index_increase_int = calculate_percentage_increase(base_time_index, czas_int_index);
    double index_increase_float = calculate_percentage_increase(base_time_index_float, czas_float_index);

    file << "| Bubblesort index             | "
        << setw(17) << czas_int_index << " ms" << " (" << setw(5) << index_increase_int << "%) | "
        << setw(16) << czas_float_index << " ms" << " (" << setw(5) << index_increase_float << "%) | "
        << setw(16) << (sprawdzanie(arr_int, n) ? "Tak" : "Nie") << " | "
        << setw(16) << (sprawdzanie(arr_float, n) ? "Tak" : "Nie") << " |\n";

    double vector_increase_int = calculate_percentage_increase(base_time_index, measure_time1(bubbleSortVector<int>, vec));
    double vector_increase_float = calculate_percentage_increase(base_time_index_float, measure_time1(bubbleSortVector<float>, vec1));

    file << "| Bubblesort vector            | "
        << setw(15) << measure_time1(bubbleSortVector<int>, vec) << " ms" << " (" << setw(5) << vector_increase_int << "%) | "
        << setw(14) << measure_time1(bubbleSortVector<float>, vec1) << " ms" << " (" << setw(5) << vector_increase_float << "%) | "
        << setw(16) << (sprawdzanie(vec.data(), n) ? "Tak" : "Nie") << " | "
        << setw(16) << (sprawdzanie(vec1.data(), n) ? "Tak" : "Nie") << " |\n";

    file << "|------------------------------|-------------------------------|----------------------------|------------------|------------------|\n\n";

    delete[] arr_int;
    delete[] arr_int_copy;
    delete[] arr_float;
    delete[] arr_float_copy;
}

int main() {
    srand(time(0));

    ofstream file("yes.txt");

    if (file.is_open()) {
        double base_time_index = 0; 

        wszystko(1000, file, base_time_index);
        wszystko(2000, file, base_time_index);
        wszystko(3000, file, base_time_index);
        wszystko(4000, file, base_time_index);
        wszystko(5000, file, base_time_index);
        wszystko(6000, file, base_time_index);
        wszystko(7000, file, base_time_index);
        wszystko(8000, file, base_time_index);
        wszystko(9000, file, base_time_index);
        wszystko(10000, file, base_time_index);

        file.close();
        cout << "Wszystko zapisane w pliku yes.txt\n";
    }
    else {
        cerr << "Nie można otworzyć pliku.\n";
    }

    return 0;
}
