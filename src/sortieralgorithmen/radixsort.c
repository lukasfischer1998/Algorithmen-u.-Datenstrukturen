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

// https://www.hackerearth.com/practice/algorithms/sorting/radix-sort/visualize/
// https://de.wikipedia.org/wiki/Radixsort
// https://studyflix.de/informatik/radix-sort-1408
// https://www.programiz.com/dsa/radix-sort
/*
Der Radix Sort Algorithmus ist ein Sortieralgorithmus, der Zahlen sortiert, indem er sie nach ihren
einzelnen Ziffern oder Stellen gruppiert und sortiert. Der Algorithmus beginnt mit der Sortierung der
Zahlen nach der niedrigsten bedeutenden Stelle und arbeitet sich zur höchsten bedeutenden Stelle vor.
Dazu verwendet er einen stabilen Sortieralgorithmus wie den Counting Sort,
um die Zahlen an jeder Stelle zu sortieren. Durch die wiederholte Anwendung des Sortierens nach den
einzelnen Stellen werden die Zahlen schließlich vollständig sortiert.
*/

#include <stdio.h>
#include <stdlib.h>

// Hilfsfunktion, um das Maximum in einem Array zu finden
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Funktion zur Durchführung des Counting Sorts für eine bestimmte Stelle (Exponent)
void countSort(int arr[], int n, int exp)
{
    int *output = (int *)malloc(sizeof(int) * n); // Dynamische Speicherreservierung für das Ausgabearray
    int count[10] = {0};                          // Zählerarray für die Ziffern 0 bis 9

    // Zähle das Vorkommen jeder Ziffer an der gegebenen Stelle
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Ändere das Zählerarray, sodass es jetzt die genaue Position der Ziffern enthält
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Erstelle das Ausgabearray durch Platzieren der Elemente in der richtigen Reihenfolge entsprechend der Zähler
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Kopiere das Ausgabearray zurück ins ursprüngliche Array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
    free(output); // Freigabe des dynamisch reservierten Speichers
}

// Radix Sort Algorithmus
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    // Durchlaufe jede Stelle (Einer, Zehner, Hunderter, usw.)
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

// Beispiel in der Main-Funktion
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("Sortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
