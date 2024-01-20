/************************ GNU General Public License 3.0 ************************
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
// https://www.sortvisualizer.com/oddevensort/#:~:text=Odd%20Even%20Sort%20(also%20known,algorithm%20similar%20to%20Bubble%20Sort.
// https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort
// https://www.geeksforgeeks.org/odd-even-sort-brick-sort/

/*
Der Odd-Even-Sort-Algorithmus ist eine Variation des Bubble-Sort-Algorithmus,
der für Parallelisierung optimiert ist. Er vergleicht und tauscht abwechselnd
die Elemente an geraden und ungeraden Indizes, wodurch er parallelisiert werden kann.
*/

#include <stdio.h>

// Funktion zum Tauschen von zwei Elementen
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funktion zum Durchführen des Odd-Even Sort
void oddEvenSort(int arr[], int n)
{
    int sorted = 0; // Variable, um zu überprüfen, ob das Array sortiert ist

    while (!sorted)
    {
        sorted = 1; // Annahme: Das Array ist sortiert, bis zum Gegenteil bewiesen wird

        // Gerade Phase
        for (int i = 0; i <= n - 2; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                sorted = 0; // Das Array ist noch nicht sortiert
            }
        }

        // Ungerade Phase
        for (int i = 1; i <= n - 2; i += 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
                sorted = 0; // Das Array ist noch nicht sortiert
            }
        }
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

    // Odd-Even Sort
    oddEvenSort(arr, n);

    printf("\nSortiertes Array (Odd-Even Sort): \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
