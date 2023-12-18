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

// https://de.wikipedia.org/wiki/Interpolationssuche
// https://gbhat.com/algorithms/interpolation_search.html

/*
Ähnlich wie die binäre Suche, allerdings nutzt sie nicht immer die Mitte des Arrays,
sondern schätzt die Position des gesuchten Elements basierend auf seinem Wert
und der Verteilung der Elemente im Array. In bestimmten Fällen kann die Interpolationssuche effizienter sein als die binäre Suche.
*/

#include <stdio.h>

// Rekursive Implementierung der Interpolationssuche
int interpolationSearchRecursive(int arr[], int target, int low, int high)
{
    if (low <= high && target >= arr[low] && target <= arr[high])
    {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
        {
            return pos; // Element gefunden, gibt den Index zurück
        }

        if (arr[pos] < target)
        {
            return interpolationSearchRecursive(arr, target, pos + 1, high); // Rekursiver Aufruf für rechte Hälfte
        }

        return interpolationSearchRecursive(arr, target, low, pos - 1); // Rekursiver Aufruf für linke Hälfte
    }

    return -1; // Element nicht gefunden, gibt -1 zurück
}

// Iterative Implementierung der Interpolationssuche
int interpolationSearchIterative(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]));

        if (arr[pos] == target)
        {
            return pos; // Element gefunden, gibt den Index zurück
        }

        if (arr[pos] < target)
        {
            low = pos + 1; // Aktualisiere die linke Grenze
        }
        else
        {
            high = pos - 1; // Aktualisiere die rechte Grenze
        }
    }

    return -1; // Element nicht gefunden, gibt -1 zurück
}

// Main-Funktion zum Testen beider Implementierungen
int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test der rekursiven Implementierung
    int resultRecursive = interpolationSearchRecursive(arr, target, 0, size - 1);

    if (resultRecursive != -1)
    {
        printf("Element %d gefunden an Index %d (rekursiv)\n", target, resultRecursive);
    }
    else
    {
        printf("Element %d nicht gefunden (rekursiv)\n", target);
    }

    // Test der iterativen Implementierung
    int resultIterative = interpolationSearchIterative(arr, size, target);

    if (resultIterative != -1)
    {
        printf("Element %d gefunden an Index %d (iterativ)\n", target, resultIterative);
    }
    else
    {
        printf("Element %d nicht gefunden (iterativ)\n", target);
    }

    return 0;
}
