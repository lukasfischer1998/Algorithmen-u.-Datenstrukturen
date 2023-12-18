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

// https://www.geeksforgeeks.org/exponential-search/
// https://www.youtube.com/watch?v=L6AbpxsWJes
/*
Die Exponential Search findet ein mögliches Intervall,
in dem das gesuchte Element enthalten sein könnte, und gibt dieses Intervall für die binäre Suche vor.
Die Binary Search durchsucht effizient das spezifizierte
Intervall, um das gesuchte Element zu finden, und gibt den Index zurück,
an dem das Element gefunden wird, oder -1, falls das Element nicht vorhanden ist.
*/
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid; // Element gefunden, gibt den Index zurück
        }

        if (arr[mid] < target)
        {
            low = mid + 1; // Aktualisiere die linke Grenze
        }
        else
        {
            high = mid - 1; // Aktualisiere die rechte Grenze
        }
    }

    return -1; // Element nicht gefunden, gibt -1 zurück
}

int exponentialSearch(int arr[], int size, int target)
{
    if (arr[0] == target)
    {
        return 0; // Wenn das Element an Index 0 gefunden wird
    }

    int i = 1;
    while (i < size && arr[i] <= target)
    {
        i *= 2; // Verdopple den Index
    }

    // Aufruf der binären Suche für den Bereich von i/2 bis min(i, size - 1)
    return binarySearch(arr, i / 2, (i < size) ? i : size - 1, target);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = exponentialSearch(arr, size, target);

    if (result != -1)
    {
        printf("Element %d gefunden an Index %d\n", target, result);
    }
    else
    {
        printf("Element %d nicht gefunden\n", target);
    }

    return 0;
}
