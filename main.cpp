#include <iostream>
#include "def.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    auto begin = std::chrono::steady_clock::now();
    auto end = begin;
    auto time = end - begin;
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
    auto elapsed_s = std::chrono::duration_cast<std::chrono::seconds>(time);

    ifstream in;
    ofstream out, out_time;

    in.open("in.txt");
    out.open("out.txt");
    out_time.open("time.txt", ios::app);

    int* arr;
    int size = ReadFile(in);
    arr = CreateArr(size, in);

    if (!arr) {
        cout << "Массив пуст.";
        in.close();
        out.close();
        return 0;
    }

    cout << "1. Сортировка выбором.\n2. Сортировка вставками.\n3. Сортировка пузырьком.\n"
        "4. Сортировка слиянием.\n5. Быстрая сортировка.\n6. Сортировка Шелла(d/2).\n7. Сортировка Шелла(Седжвик)"
        "\n8. Сортировка Шелла(Кнут).\n9. Пирамидальная сортировка.\n10. Timsort."
        "\n11. Introsort.\n12. Завершить работу программы.\n";

    int a = 0, count = 0;

    while (a != 12 && count < 3) {
        count = 0;
        cout << "\nВведите номер функции, которую необходимо выполнить: ";

        cin >> a;
        while (!cin || a < 1 || a > 12) {
            count += 1;
            if (count == 3) { cout << "Попытки израсходованы."; return 0; }
            Clear();
            cout << "\nНеверный формат ввода. Введите число от 1 до 12: ";
            cin >> a;
        }

        switch (a) {
        case 1:
            begin = chrono::steady_clock::now();
            SelectionSort(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 2:
            begin = chrono::steady_clock::now();
            InsertionSort(arr, 0, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 3:
            begin = chrono::steady_clock::now();
            BubbleSort(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            out_time << size / 1000 << " ";
            out_time << elapsed_ns.count() << "\n";
            out_time << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            out_time << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 4:
            begin = chrono::steady_clock::now();
            MergeSort(arr, 0, size - 1);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 5:
            begin = chrono::steady_clock::now();
            QuickSort(arr, 0, size - 1);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 6:
            begin = chrono::steady_clock::now();
            ShellSortPow2(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            out_time << size / 1000 << " ";
            out_time << elapsed_ns.count() << "\n";
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 7:
            begin = chrono::steady_clock::now();
            ShellSortInc(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 8:
            begin = chrono::steady_clock::now();
            ShellSortKnuth(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 9:
            begin = chrono::steady_clock::now();
            HeapSort(arr, 0, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 10:
            begin = chrono::steady_clock::now();
            TimSort(arr, size);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            out_time << size / 1000 << " ";
            out_time << elapsed_ns.count() << "\n";
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        case 11:
            begin = chrono::steady_clock::now();
            Introsort(arr, arr, arr + size - 1);
            end = chrono::steady_clock::now();
            time = end - begin;
            elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
            elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
            cout << " Время работы: " << elapsed_ms.count() << " миллисекунд \n";
            cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
            OutArr(arr, size, out);
            break;

        default:
            break;
        }
    }

    //if (arr) delete[] arr;

    in.close();
    out.close();
    out_time.close();
}

