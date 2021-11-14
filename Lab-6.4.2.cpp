#include <iostream>

using namespace std;

void InArr(int Arr[], const int size, int i)
{
    if (i < size)
    {
        Arr[i] = -10 + rand() % 18;
        InArr(Arr, size, i + 1);
        return;
    }
}

void PrArr(const int* const Arr, const int size, int i)
{
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << Arr[i];
        if (i != size - 1)
            cout << ", ";
        else cout << "}" << endl;
        PrArr(Arr, size, i + 1);
        return;
    }
}

int PoSumArr(int* Arr, const int size, int i)
{
    if (i < size)
    {
        if (Arr[i] > 0)
            return Arr[i] + PoSumArr(Arr, size, i + 1);
        else
            return  PoSumArr(Arr, size, i + 1);
    }
    else
        return 0;
}


void SerMax(const int* const arr, const int size, int& max, int& index, int i)
{
    if (i < size)
    {
        if (abs(arr[i]) > abs(max))
        {
            max = arr[i];
            index = i;
        }
        SerMax(arr, size, max, index, i + 1);
    }

}

void SerMin(const int* const arr, const int size, int& min, int& index, int i)
{
    if (i < size)
    {
        if (abs(arr[i]) < abs(min))
        {
            min = arr[i];
            index = i;
        }
       SerMin(arr, size, min, index, i + 1);
    }
}

int ModSum(const int* const arr, const int size, int i)
{
    if (i < size)
    {
        return arr[i] * ModSum(arr, size, i + 1);
    }
    else return 1;
}

void SortArr(int* arr, const int size, int i, int j)
{
    if (arr[i] < arr[i + 1])
    {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;
    }
    if (i < size - j - 1)
        SortArr(arr, size, j, i + 1);

    if (j < size - 1)
        SortArr(arr, size, j + 1, i);
}

int main()
{
    srand(time(0));
    int n;
    cout << "n = "; cin >> n;

    int* a = new int[n];

    InArr(a, n, 0);
    int max = a[0], min = a[0], index = 0, index1 = 0;
    PrArr(a, n, 0);

    SerMin(a, n, min, index, 0);
    SerMax(a, n, max, index1, 0);
    cout << "Min = " << index << endl;
    cout << "Max = " << index1 << endl;
    int P = 1;
    if (index < index1)
        P = ModSum(a, index1, index + 1);
    else
        P = ModSum(a, index, index1 + 1);
    cout << "P = " << P << endl;
    cout << "S = " << PoSumArr(a, n, 0) << endl;

    SortArr(a, n, 0, 0);
    PrArr(a, n, 0);

    delete[]a;
    a = nullptr;

    return 0;
}