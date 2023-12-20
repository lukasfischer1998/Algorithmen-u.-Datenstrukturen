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
// https://de.wikipedia.org/wiki/Selectionsort
// https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/visualize/

/*
Der Selection-Sort-Algorithmus sortiert eine Liste, indem er das kleinste Element findet
und es an die erste Position setzt, dann das zweitkleinste an die zweite Position usw.
*/

#include <stdio.h>

// Selection-Sort-Funktion
void selectionSort(int arr[], int n)
{
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Tausche die gefundenen Elemente
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

/*
SEHR INEFFIZIENT: Overhead durch rekursive Aufrufe, Kein Vorteil gegenüber der Iteration, Verlust der iterativen Logik
void recursiveSelectionSort(int arr[], int n, int index) {
    if (index >= n - 1)
        return;

    int minIndex = index;
    for (int i = index + 1; i < n; i++) {
        if (arr[i] < arr[minIndex])
            minIndex = i;
    }

    int temp = arr[minIndex];
    arr[minIndex] = arr[index];
    arr[index] = temp;

    recursiveSelectionSort(arr, n, index + 1);
}
*/

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Aufruf des Selection-Sort-Algorithmus
    selectionSort(arr, n);

    printf("\nSortiertes Array nach Selection-Sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
