#include <iostream>

int* initArray1()
{
    int size = 20;
    int* randArray = new int[size];

    for (int i = 0; i < size / 2; i++)
        randArray[i] = rand() % 10;
    return randArray;
}

int* initArray2()
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

void mergeArrays(int* array1, int* array2, int size)
{

    int* pArr1 = array1 + size;
    int* pArr2 = array2 + size - 1;

    for (; pArr1 < &array1[size * 2]; pArr1++)
    {
        *pArr1 = *pArr2;
        pArr2--;
    }

}

int main()
{
    srand(time(nullptr));
    int* array1 = initArray1();
    int* array2 = initArray2();
    showArray(array1, 10);
    showArray(array2, 10);
    mergeArrays(array1, array2, 10);
    delete[] array2;
    std::cout << "after merging: \n";
    showArray(array1, 20);
    delete[] array1;

}