#include <iostream>

void shell_sort(int* arr, int s)
{
    int size = s / 2;
    int i, j, temp;
    while (size >= 1)
    {                   
        for (i = size; i < s; ++i)
        {
            temp = arr[i];
            for (j = i; j - size >= 0 && arr[j - size] > temp; j -= size)
            {
                arr[j] = arr[j - size];
            }
            arr[j] = temp;
        }
        size /= 2;
    }
}


int main()
{
    int arr[] = { 342, 9, 20, 10, 300, 199, 100, 1, 3 };

    int size = sizeof(arr) / sizeof(arr[0]);

    shell_sort(arr, size);

    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }

}
