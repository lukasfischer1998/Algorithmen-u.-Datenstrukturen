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

// https://www.chrislaux.com/de/miscsort
// https://de.wikipedia.org/wiki/Quicksort
// https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/visualize/
// https://www.youtube.com/watch?v=WprjBK0p6rw

/*
Der Quicksort-Algorithmus ist ein effizienter, rekursiver Sortieralgorithmus.
Er wählt ein Element als Pivotelement und teilt das Array um das Pivotelement herum
auf, sodass Elemente kleiner als das Pivotelement links davon stehen und größere
Elemente rechts davon. Danach wird der Algorithmus auf die beiden Teillisten
rekursiv angewendet.
*/

#include <stdio.h>

// Funktion zum Tauschen von Elementen
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funktion zum Partitionieren des Arrays und Festlegen des Pivotelements
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Wähle das letzte Element als Pivotelement
    int i = (low - 1);     // Index des kleineren Elements

    for (int j = low; j <= high - 1; j++)
    {
        // Wenn das aktuelle Element kleiner oder gleich dem Pivotelement ist
        if (arr[j] <= pivot)
        {
            i++; // Erhöhe den Index des kleineren Elements
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort-Funktion
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        // Sortiere die Elemente vor und nach der Partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Aufruf des Quicksort-Algorithmus
    quickSort(arr, 0, n - 1);

    printf("\nSortiertes Array nach Quicksort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
