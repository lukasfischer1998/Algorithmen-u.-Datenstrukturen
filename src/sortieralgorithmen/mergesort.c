/*********************** GNU General Public License 3.0 ***********************\
|                                                                              |
|  Copyright (C) 2023 Lukas Fischer                                            |
|                                                                              |
|  This program is free software: you can redistribute it and/or modify        |
|  it under the terms of the GNU General Public License as published by        |
|  the Free Software Foundation, either version 3 of the License, or           |
|  (at your option) any later version.                                         |
|                                                                              |
|  This program is distributed in the hope that it will be useful,             |
|  but WITHOUT ANY WARRANTY; without even the implied warranty of              |
|  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               |
|  GNU General Public License for more details.                                |
|                                                                              |
|  You should have received a copy of the GNU General Public License           |
|  along with this program.  If not, see <https://www.gnu.org/licenses/>.      |
|                                                                              |
\******************************************************************************/

// https://de.wikipedia.org/wiki/Mergesort#:~:text=Mergesort%20(von%20englisch%20merge%20%E2%80%9Averschmelzen,wie%20Mergesort%20eine%20Liste%20sortiert.
// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/visualize/
/*
Step 1: Start
Step 2: Declare an array and left, right, mid variable
Step 3: Perform merge function.
        mergesort(array,left,right)
        mergesort (array, left, right)
        if left > right
        return
        mid= (left+right)/2
        mergesort(array, left, mid)
        mergesort(array, mid+1, right)
        merge(array, left, mid, right)
Step 4: Stop

Der Merge-Sort-Algorithmus ist ein effizienter, stabiler Sortieralgorithmus,
der einen rekursiven Ansatz verwendet, um ein Array zu sortieren,
indem er es in kleinere Teile zerlegt, diese sortiert und dann zusammenführt.
*/
#include <stdio.h>
#include <stdlib.h> // Für malloc und free

// Merge-Funktion für den Merge-Sort
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int *L = (int *)malloc(n1 * sizeof(int)); // Dynamische Speicherzuweisung für L[]
    int *R = (int *)malloc(n2 * sizeof(int)); // Dynamische Speicherzuweisung für R[]

    // Kopieren der Daten in temporäre Arrays L[] und R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Zusammenführen der temporären Arrays zurück in arr[left..right]
    i = 0;    // Initialindex des ersten Unterarrays
    j = 0;    // Initialindex des zweiten Unterarrays
    k = left; // Initialindex des zusammengeführten Arrays

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopieren der restlichen Elemente von L[], falls vorhanden
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopieren der restlichen Elemente von R[], falls vorhanden
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Freigabe des dynamisch allokierten Speichers
    free(L);
    free(R);
}

// Merge-Sort-Funktion
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Sortiere erste und zweite Hälften
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Führe die sortierten Hälften zusammen
        merge(arr, left, middle, right);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Aufruf des Merge-Sort-Algorithmus
    mergeSort(arr, 0, n - 1);

    printf("\nSortiertes Array nach Merge-Sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
