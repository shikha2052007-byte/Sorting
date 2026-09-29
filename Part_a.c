#include <stdio.h>

#define MAX 100

typedef struct {
    int weight;
    int id;
} Package;

int mergeComparisons = 0;
int quickComparisons = 0;

void display(Package a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d(P%d) ", a[i].weight, a[i].id);

    printf("\n");
}

void merge(Package a[], int low, int mid, int high)
{
    Package temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        mergeComparisons++;

        if (a[i].weight <= a[j].weight)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(Package a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);

        printf("Merge: ");
        display(&a[low], high - low + 1);
    }
}

int partition(Package a[], int low, int high)
{
    int pivot = a[high].weight;
    int i = low - 1;
    int j;
    Package temp;

    for (j = low; j < high; j++)
    {
        quickComparisons++;

        if (a[j].weight <= pivot)
        {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(Package a[], int low, int high)
{
    int p;

    if (low < high)
    {
        p = partition(a, low, high);

        printf("Partition: ");
        display(&a[low], high - low + 1);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    Package mergeArray[] = {
        {20,1}, {15,2}, {20,3}, {10,4},
        {15,5}, {20,6}, {25,7}, {10,8}
    };

    Package quickArray[] = {
        {20,1}, {15,2}, {20,3}, {10,4},
        {15,5}, {20,6}, {25,7}, {10,8}
    };

    int n = 8;

    printf("ORIGINAL DATA:\n");
    display(mergeArray, n);

    printf("\n--- MERGE SORT ---\n");

    mergeSort(mergeArray, 0, n - 1);

    printf("Sorted result:\n");
    display(mergeArray, n);

    printf("Number of comparisons: %d\n", mergeComparisons);

    printf("\n--- QUICK SORT ---\n");

    quickSort(quickArray, 0, n - 1);

    printf("Sorted result:\n");
    display(quickArray, n);

    printf("Number of comparisons: %d\n", quickComparisons);

    return 0;
}
