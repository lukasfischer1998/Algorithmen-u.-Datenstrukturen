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
// https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/
// https://www.opentechguides.com/how-to/article/java/216/count_occurrence_binarySearch.html

/*
Der "Count Occurrences Search" Algorithmus ist eine Erweiterung des binären Suchalgorithmus,
der die Anzahl der Vorkommen eines gesuchten Elements in einem sortierten Array bestimmt.
Er sucht zuerst nach dem ersten Vorkommen des Elements mittels einer modifizierten binären
Suche und dann nach dem letzten Vorkommen desselben Elements.
Die Differenz zwischen den beiden Positionen, zuzüglich eins, gibt die Anzahl der Vorkommen des Elements im Array zurück.
*/

#include <stdio.h>

// Binary Search zur Bestimmung des ersten und letzten Auftretens eines Elements
int binarySearchFirst(int array[], int size, int target)
{
    int left = 0, right = size - 1, first = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
        {
            first = mid;
            right = mid - 1;
        }
        else if (array[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return first;
}

int binarySearchLast(int array[], int size, int target)
{
    int left = 0, right = size - 1, last = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == target)
        {
            last = mid;
            left = mid + 1;
        }
        else if (array[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return last;
}

// Funktion zur Zählung der Vorkommen eines Elements im sortierten Array
int countOccurrences(int array[], int size, int target)
{
    int first = binarySearchFirst(array, size, target);

    if (first == -1)
    {
        // Das Element wurde nicht im Array gefunden
        return 0;
    }

    int last = binarySearchLast(array, size, target);

    return last - first + 1;
}

int main()
{
    int array[] = {2, 4, 6, 6, 6, 8, 10, 10, 10, 12};
    int target = 6;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    int occurrences = countOccurrences(array, arrayLength, target);

    if (occurrences > 0)
        printf("Das Element %d kommt %d Mal im Array vor.\n", target, occurrences);
    else
        printf("Das Element %d kommt nicht im Array vor.\n", target);

    return 0;
}
