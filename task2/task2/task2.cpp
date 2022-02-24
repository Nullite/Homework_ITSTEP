#include <iostream>
#include <cstdlib>

int* initArray()
{

    int size = 10;
    int* randArray = new int[size];

    for (int i = 0; i < size; i++)
        randArray[i] = rand() % 10;
    return randArray;
}

void showArray(int* array, int size)
{
    std::cout << "array: ";
    for (int i = 0; i < size; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";

}

void reverseArr(int* arr, int size)
{
    int* opposite = &arr[size - 1];
    for (int* pArr = arr; pArr < &arr[size / 2]; pArr++)
    {
        int temp = *pArr;
        *pArr = *opposite;
        *opposite = temp;
        opposite--;
    }

}

int main()
{
    srand(time(nullptr));
    int* arr = initArray();
    showArray(arr, 10);
    reverseArr(arr, 10);
    showArray(arr, 10);
    delete[] arr;
}