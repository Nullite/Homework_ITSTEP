#include <iostream>
#include <cstdlib>

int* initFirstArray()
{

    int size = 20;
    int* randArray = new int[size];

    for (int i = 0; i < size / 2; i++)
        randArray[i] = rand() % 10;
    return randArray;
}

int* initSecondArray()
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

    int* pArr1 = array1 + size / 2;
    int* pArr2 = array2;

    for (; pArr1 < &array1[size]; pArr1++)
    {
        *pArr1 = *pArr2;
        pArr2++;
    }
}



int main()
{
    srand(time(nullptr));
    int* firstArr = initFirstArray();
    int* secondArr = initSecondArray();
    showArray(firstArr, 10);
    showArray(secondArr, 10);
    mergeArrays(firstArr, secondArr, 20);
    delete[] secondArr;
    std::cout << "after merging: \n";
    showArray(firstArr, 20);
    delete[] firstArr;
}
