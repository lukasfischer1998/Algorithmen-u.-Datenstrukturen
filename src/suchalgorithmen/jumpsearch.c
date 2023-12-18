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

// Runterscrollen zur Visualisierung-> https://www.geeksforgeeks.org/pyqt5-jump-search-visualizer/
// https://en.wikipedia.org/wiki/Jump_search
// https://www.studytonight.com/data-structures/jump-search-algorithm

// Sortiertes Array

/*
Die Sprungsuche (Jump Search) ist ein Suchalgorithmus für sortierte Arrays,
der größere Schritte verwendet, um das Array zu durchsuchen und das gesuchte Element zu finden,
indem er Sprünge in Schritten der Quadratwurzel der Arraygröße macht und dann
eine lineare Suche im kleineren Bereich durchführt, um das Element zu lokalisieren.
*/

#include <stdio.h>
#include <math.h>

// Iterative Implementierung
int jumpSearch(int arr[], int size, int target)
{
    int jump = sqrt(size); // Sprunggröße berechnen
    int left = 0, right = 0;

    while (right < size && arr[right] < target)
    {
        left = right;  // Aktualisiere den linken Index
        right += jump; // Gehe zum nächsten Sprung
        if (right >= size)
            right = size - 1;
    }

    for (int i = left; i <= right; i++)
    {
        if (arr[i] == target)
        {
            return i; // Element gefunden, gibt den Index zurück
        }
    }

    return -1; // Element nicht gefunden, gibt -1 zurück
}

// Rekursive Implementierung
int jumpSearchRecursive(int arr[], int target, int left, int right, int size)
{
    int jump = sqrt(size); // Sprunggröße berechnen

    if (left >= size)
        return -1;

    right = fmin(right, size - 1);

    if (arr[right] >= target)
    {
        for (int i = left; i <= right; i++)
        {
            if (arr[i] == target)
            {
                return i; // Element gefunden, gibt den Index zurück
            }
        }
    }

    return jumpSearchRecursive(arr, target, right, right + jump, size);
}

int main()
{
    int arr[] = {1, 4, 7, 9, 12, 15, 18, 21, 25, 30};
    int target = 18;
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test der iterativen Implementierung
    int resultIterative = jumpSearch(arr, size, target);

    if (resultIterative != -1)
    {
        printf("Element %d gefunden an Index %d (iterativ)\n", target, resultIterative);
    }
    else
    {
        printf("Element %d nicht gefunden (iterativ)\n", target);
    }

    // Test der rekursiven Implementierung
    int resultRecursive = jumpSearchRecursive(arr, target, 0, sqrt(size), size);

    if (resultRecursive != -1)
    {
        printf("Element %d gefunden an Index %d (rekursiv)\n", target, resultRecursive);
    }
    else
    {
        printf("Element %d nicht gefunden (rekursiv)\n", target);
    }

    return 0;
}
