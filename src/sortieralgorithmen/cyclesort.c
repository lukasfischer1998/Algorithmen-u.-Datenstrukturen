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

// https://www.geeksforgeeks.org/cycle-sort/
// https://en.wikipedia.org/wiki/Cycle_sort
// https://blog.stackademic.com/coding-pattern-cyclic-sort-96511b0f60ac

/*
Der Cycle Sort Algorithmus arbeitet, indem er jedes Element des Arrays durchläuft
und versucht, es an seine korrekte Position zu bringen, indem er Zyklen verwendet,
um das Element zu tauschen und zu platzieren, wodurch das Array schrittweise sortiert
wird und dabei eine minimale Anzahl von Schreibzugriffen auftritt.
Dabei wird jedes Element anhand seines Wertes in den Zyklus eingeordnet,
um es an die richtige Position zu verschieben.


-gute Wahl sein kann, wenn es um die Minimierung der Anzahl von Schreiboperationen geht
- inplace
*/

#include <stdio.h>

// Funktion zum Tauschen von Werten
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Cycle Sort Algorithmus
void cycleSort(int arr[], int n)
{
    for (int cycle_start = 0; cycle_start < n - 1; cycle_start++)
    {
        int item = arr[cycle_start];
        int pos = cycle_start;

        // Finden richtigen Position für das aktuelle Element
        for (int i = cycle_start + 1; i < n; i++)
        {
            if (arr[i] < item)
            {
                pos++;
            }
        }

        // Überspringen, wenn Element bereits an der richtigen Position ist
        if (pos == cycle_start)
        {
            continue;
        }

        // richtige Position verschieben
        while (item == arr[pos])
        {
            pos++;
        }
        if (pos != cycle_start)
        {
            swap(&item, &arr[pos]);
        }

        // Zyklen neu anordnen, verschobenes Element zu platzieren
        while (pos != cycle_start)
        {
            pos = cycle_start;
            for (int i = cycle_start + 1; i < n; i++)
            {
                if (arr[i] < item)
                {
                    pos++;
                }
            }
            while (item == arr[pos])
            {
                pos++;
            }
            if (item != arr[pos])
            {
                swap(&item, &arr[pos]);
            }
        }
    }
}

// Anzeigen eines Arrays
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: ");
    displayArray(arr, n);

    cycleSort(arr, n);

    printf("Sortiertes Array: ");
    displayArray(arr, n);

    return 0;
}
