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

// https://de.wikipedia.org/wiki/Bubblesort
// https://visualgo.net/en/sorting?slide=1-3

#include <stdio.h>

// Iterativer Bubble-Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Letzte i Elemente sind bereits sortiert, daher wird der innere Loop um i verkürzt
        for (int j = 0; j < n - i - 1; j++)
        {
            // Vergleiche aufeinanderfolgende Elemente und tausche, falls sie in falscher Reihenfolge sind
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] und arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Rekursiver Bubble-Sort
void recursiveBubbleSort(int arr[], int n)
{
    // Basisfall: Wenn nur ein Element vorhanden ist, ist das Array bereits sortiert
    if (n == 1)
        return;

    // Ein Durchlauf von Bubble-Sort, um das größte Element an das Ende zu bringen
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // Swap arr[i] und arr[i+1]
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Rekursiver Aufruf für das verbleibende (ungeordnete) Array
    recursiveBubbleSort(arr, n - 1);
}

// Funktion zum Ausgeben eines Arrays
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Hauptfunktion
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    printArray(arr, n);

    // Iterativer Bubble-Sort aufrufen
    bubbleSort(arr, n);
    printf("Sortiertes Array durch iterative Bubble-Sort: \n");
    printArray(arr, n);

    // Array neu initialisieren
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    printf("\nUnsortiertes Array (für rekursiven Bubble-Sort): \n");
    printArray(arr2, n);

    // Rekursiven Bubble-Sort aufrufen
    recursiveBubbleSort(arr2, n);
    printf("Sortiertes Array durch rekursiven Bubble-Sort: \n");
    printArray(arr2, n);

    return 0;
}
