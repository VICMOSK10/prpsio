// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include <random>

using namespace std;

template <typename T>
void bubblesort(T arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubblesort_for_for_pointer(int* arr, size_t n)
{
    int* w1, * w2, temp;

    for (size_t i = 0; i < n; i++)
    {
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

void bubblesort_for_for_index(int arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void bubblesort_for_while_pointer(int* arr, size_t n) {
    int* w1, * w2, temp;
    for (size_t i = 0; i < n - 1; i++) {
        w1 = arr;
        w2 = w1 + 1;
        size_t j = 0;
        while (j < n - i - 1) {
            if (*w1 > *w2) {
                temp = *w2;
                *w2 = *w1;
                *w1 = temp;

            }
            w1++;
            w2++;
            j++;
        }
    }
}


void bubblesort_for_while_index(int arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
            j++;
        }
    }
}
void bubblesort_for_short_pointer(int* arr, size_t n) {

    int* w1, * w2, temp;

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
void bubblesort_for_short_index(int arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
bool sprawdzanie(int arr[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }

    }
    return true;
}

template <typename Func, typename... Args>
void measure_time(const string& func_name, Func func, Args&&... args) {
    auto start = chrono::high_resolution_clock::now();
    func(forward<Args>(args)...);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << func_name << " execution time: " << duration.count() << " milliseconds" << endl;
}

int main() {
    srand(time(0));
    int arr[80];
    float arr_float[80];

    size_t n = 7;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(1.0, 100.0);

    for (size_t i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        arr_float[i] = dis(gen);
    }

    if (sprawdzanie(arr, n) == 0) {
        cout << "nie" << endl;

    }
    else {
        cout << "tak" << endl;

    }
    std::cout << "Sorting using bubbleSortForShorter:\n";
    measure_time("bubbleSortForShortIndex", bubblesort_for_short_index, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForFor:\n";
    measure_time("bubbleSortForForIndex", bubblesort_for_for_index, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForWhile:\n";
    measure_time("bubbleSortForWhileIndex", bubblesort_for_while_index, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForPointer:\n";
    measure_time("bubbleSortForForPointer", bubblesort_for_for_pointer, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForWhilePointer:\n";
    measure_time("bubbleSortForWhilePointer", bubblesort_for_while_pointer, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using bubbleSortForShortPointer:\n";
    measure_time("bubbleSortForShortPointer", bubblesort_for_short_pointer, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    std::cout << "\n\nSorting using template bubbleSort:\n";
    measure_time("template bubbleSort", bubblesort<int>, arr, n);
    for (size_t i = 0; i < n; i++) cout << arr[i] << " ";

    cout << " \n";
    if (sprawdzanie(arr, n) == 0) {
        cout << "nie" << endl;

    }
    else {
        cout << "tak" << endl;

    }

    std::cout << "\n\nSorting float array using template bubbleSort:\n";
    measure_time("template bubbleSort<float>", bubblesort<float>, arr_float, n);
    for (size_t i = 0; i < n; i++) cout << arr_float[i] << " ";

    return 0;
}
