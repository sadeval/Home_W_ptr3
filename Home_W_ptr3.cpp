#include <iostream>
#include <ctime>
using namespace std;

//TASK_1

int main() {
    setlocale(0, "");

    int x = 10;
    int* ptr1 = &x;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;
    int**** ptr4 = &ptr3;
    int***** ptr5 = &ptr4;


    cout << "Адрес переменной x: " << &x << "\n";
    cout << "Адрес указателя ptr1: " << &ptr1 << "\n";
    cout << "Адрес указателя ptr2: " << &ptr2 << "\n";
    cout << "Адрес указателя ptr3: " << &ptr3 << "\n";
    cout << "Адрес указателя ptr4: " << &ptr4 << "\n";
    cout << "Адрес указателя ptr5: " << &ptr5 << "\n\n";


    cout << "Адрес переменной x через ptr5: " << *****ptr5 << "\n";
    cout << "Адрес указателя ptr1 через ptr5: " << ****ptr5 << "\n";
    cout << "Адрес указателя ptr2 через ptr5: " << ***ptr5 << "\n";
    cout << "Адрес указателя ptr3 через ptr5: " << **ptr5 << "\n";
    cout << "Адрес указателя ptr4 через ptr5: " << *ptr5 << "\n";
    cout << "Адрес указателя ptr5: " << ptr5 << "\n";

    return 0;
}


//TASK_2
// Функция для выделения памяти под одномерный динамический массив
void AllocateMemory(int** ar, unsigned int count) {

    if (count > 100000) count = 100000;
    *ar = new int[count];
    cout << "AllocateMemory.\n";
}


void RandomFillArray(int* ar, unsigned int count) {

    if (ar == nullptr) {
        cout << "Null pointer! RandomFillArray Exit...\n";
        return;
    }
    cout << "RandomFillArray START!\n";
    for (int i = 0; i < count; i++) {

        ar[i] = rand() % 100; // числа от 0 до 99
    }
    cout << "RandomFillArray DONE!\n";
}

void PrintArray(int* ar, unsigned int count) {

    if (ar == nullptr) {
        cout << "Array is empty...\n";
        return;
    }
    cout << "Printing array:\n";
    for (int i = 0; i < count; i++) {

        cout << ar[i] << ", ";
    }
    cout << "\nPrintArray DONE!\n";
}


void FreeMemory(int* ar) {

    delete[] ar;
    cout << "Memory freed.\n";
}

// Функция для добавления элемента в конец массива
void AddElementToEnd(int** ar, unsigned int& count, int element) {

    int* temp = *ar;
    int* newArr = new int[count + 1];
    for (int i = 0; i < count; i++) {

        newArr[i] = temp[i];
    }
    newArr[count] = element;
    delete[] temp;
    *ar = newArr;
    count++;
}

// Функция для удаления элемента с конца массива
void RemoveElementFromEnd(int** ar, unsigned int& count) {

    if (count == 0) {
        cout << "Array is empty. Nothing to remove.\n";
        return;
    }
    int* temp = *ar;
    int* newArr = new int[count - 1];
    for (int i = 0; i < count - 1; i++) {

        newArr[i] = temp[i];
    }
    delete[] temp;
    *ar = newArr;
    count--;
}

int main() {

    srand(time(nullptr)); 

    int* ar = nullptr;
    unsigned int count = 0;

    unsigned int size;
    cout << "Please, enter count of elements: ";
    cin >> size;
    
    AllocateMemory(&ar, size);
    RandomFillArray(ar, size);
    count = size;
    PrintArray(ar, count);

    // Добавление элемента в конец массива и его удаление
    AddElementToEnd(&ar, count, 777);
    PrintArray(ar, count);
    RemoveElementFromEnd(&ar, count);
    PrintArray(ar, count);

    FreeMemory(ar);

    return 0;
}

