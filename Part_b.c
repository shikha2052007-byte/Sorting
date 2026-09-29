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

void stableMerge(Package a[], int low, int mid, int high)
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

void stableMergeSort(Package a[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        stableMergeSort(a, low, mid);
        stableMergeSort(a, mid + 1, high);

        stableMerge(a, low, mid, high);
    }
}

void stableQuickSort(Package a[], int n)
{
    Package less[MAX];
    Package equal[MAX];
    Package greater[MAX];
    Package result[MAX];

    int lessCount = 0;
    int equalCount = 0;
    int greaterCount = 0;
    int pivot;
    int i, j;

    if (n <= 1)
        return;

    pivot = a[n - 1].weight;

    for (i = 0; i < n - 1; i++)
    {
        quickComparisons++;

        if (a[i].weight < pivot)
            less[lessCount++] = a[i];
        else if (a[i].weight == pivot)
            equal[equalCount++] = a[i];
        else
            greater[greaterCount++] = a[i];
    }

    equal[equalCount++] = a[n - 1];

    stableQuickSort(less, lessCount);
    stableQuickSort(greater, greaterCount);

    i = 0;

    for (j = 0; j < lessCount; j++)
        result[i++] = less[j];

    for (j = 0; j < equalCount; j++)
        result[i++] = equal[j];

    for (j = 0; j < greaterCount; j++)
        result[i++] = greater[j];

    for (j = 0; j < n; j++)
        a[j] = result[j];
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

    printf("\n--- STABLE MERGE SORT ---\n");

    stableMergeSort(mergeArray, 0, n - 1);

    printf("Stable sorted result:\n");
    display(mergeArray, n);

    printf("Number of comparisons: %d\n", mergeComparisons);

    printf("\n--- STABLE QUICK SORT ---\n");

    stableQuickSort(quickArray, n);

    printf("Stable sorted result:\n");
    display(quickArray, n);

    printf("Number of comparisons: %d\n", quickComparisons);

    return 0;
}
