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

// https://www.toptal.com/developers/sorting-algorithms
// https://de.wikipedia.org/wiki/Shellsort#:~:text=Shellsort%20ist%20eine%20Verbesserung%20des,nur%20das%20kleinste%20%E2%80%9Espringt%E2%80%9C.
// https://studyflix.de/informatik/shellsort-1411

/*
Der Shellsort ist ein Sortieralgorithmus, der auf der Insertion-Sort-Technik basiert,
jedoch mit einer verbesserten Effizienz arbeitet. Er operiert, indem er das Array in Teilmengen
(Subarrays) aufteilt und dann den Insertion-Sort auf diesen Subarrays ausführt.

Das Hauptprinzip des Shellsort besteht darin, dass zu Beginn größere Schrittweiten
verwendet werden, um Elemente zu vergleichen und zu vertauschen. Diese Schrittweiten werden
allmählich reduziert, was dazu führt, dass das Array schrittweise nahezu sortiert wird.
Schließlich wird der Insertion-Sort auf ein fast sortiertes Array angewendet, was zu einer
schnelleren Sortierung führt als beim direkten Anwenden von Insertion-Sort.



Der Algorithmus arbeitet wie folgt:

    Der Shellsort beginnt mit einem größeren Schritt (Gap) und teilt das Array in mehrere Subarrays.

    Er wendet den Insertion-Sort auf jedes dieser Subarrays an.

    Die Gap-Größe wird schrittweise verringert, und der Algorithmus wiederholt die Schritte 1 und 2, bis die Gap-Größe 1 erreicht ist.

    Schließlich wird der Insertion-Sort auf das gesamte Array angewendet, das zu diesem Zeitpunkt bereits teilweise sortiert ist.
*/

#include <stdio.h>

// Shell Sort Algorithm
void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Funktion zur Ausgabe eines Arrays
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Beispiel in der main-Funktion
int main()
{
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("\nSortiertes Array: \n");
    printArray(arr, n);

    return 0;
}