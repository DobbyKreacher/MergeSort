#include <stdio.h>

void PrintArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void Merge(int a[], int mid, int low, int high)
{
    int i, j, k, b[high + 1];
    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }

    // Copying array b to array a
    for (int x = low; x <= high; x++)
    {
        a[x] = b[x];
    }
}

void MergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);      // sorting left subarray
        MergeSort(a, mid + 1, high); // sorting right subarray
        Merge(a, mid, low, high);    // merging both arrays and then sorting it
    }
}

int main()
{
    int a[] = {9, 14, 4, 8, 7, 5, 6};
    int size = 7;
    int low = 0, high = size - 1;
    PrintArray(a, size);
    MergeSort(a, low, high);
    PrintArray(a, size);
    return 0;
}
