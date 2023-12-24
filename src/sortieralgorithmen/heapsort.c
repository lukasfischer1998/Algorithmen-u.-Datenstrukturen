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
// https://de.wikipedia.org/wiki/Heapsort
// https://studyflix.de/informatik/heapsort-1326

/*
Der Heap Sort Algorithmus funktioniert, indem er zuerst einen Max-Heap (spezielle Form
eines binären Baums) aus dem Array
aufbaut und dann wiederholt das größte Element (die Wurzel des Heaps) extrahiert und
in den sortierten Teil des Arrays verschiebt.
Dann wird der Heap neu organisiert, um das nächstgrößte Element zu extrahieren.
Dieser Vorgang wird fortgesetzt, bis das gesamte Array sortiert ist.
*/

#include <stdio.h>

// Funktion zum Vertauschen von zwei Elementen
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funktion zur Erstellung eines Max-Heaps
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Nehme an, dass der größte Wert die Wurzel ist
    int left = 2 * i + 1;  // Index des linken Kindknotens
    int right = 2 * i + 2; // Index des rechten Kindknotens

    // Wenn das linke Kind größer als die Wurzel ist
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Wenn das rechte Kind größer als der momentane größte Wert ist
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Falls der größte Wert nicht die Wurzel ist
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Rekursiv Heapify aufrufen
        heapify(arr, n, largest);
    }
}

// Heap Sort Algorithmus
void heapSort(int arr[], int n)
{
    // Baue einen Max-Heap auf
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extrahiere Elemente aus dem Heap und sortiere sie
    for (int i = n - 1; i > 0; i--)
    {
        // Das größte Element in die Sortierte Sequenz am Ende des Arrays verschieben
        swap(&arr[0], &arr[i]);
        // Erneut Max-Heap aufbauen, aber nur mit den nicht sortierten Elementen
        heapify(arr, i, 0);
    }
}

// Beispiel in der Main-Funktion
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    heapSort(arr, n);

    printf("Sortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
