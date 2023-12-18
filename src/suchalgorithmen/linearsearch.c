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

// https://de.wikipedia.org/wiki/Lineare_Suche#:~:text=Lineare%20Suche%20ist%20ein%20Algorithmus,bis%20man%20es%20gefunden%20hat.
// Visualisierung -> https://www.cs.usfca.edu/~galles/visualization/Search.html

#include <stdio.h>

// Iterative Implementierung
int linearSearchIterative(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i; // Index zurück
        }
    }
    return -1; // nicht gefunden -1 zurück
}

// Rekursive Implementierung
int linearSearchRecursive(int arr[], int target, int index, int size)
{
    if (index == size)
    {
        return -1; // Basisfall
    }

    if (arr[index] == target)
    {
        return index; // Index zurück
    }

    return linearSearchRecursive(arr, target, index + 1, size); // Rekursiver Aufruf nächstes Element
}

int main()
{
    int arr[] = {4, 2, 7, 1, 9, 5};
    int target = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    // iterativen Implementierung
    int resultIterative = linearSearchIterative(arr, size, target);

    if (resultIterative != -1)
    {
        printf("Element %d gefunden an Index %d (iterativ)\n", target, resultIterative);
    }
    else
    {
        printf("Element %d nicht gefunden (iterativ)\n", target);
    }

    // rekursiven Implementierung
    int resultRecursive = linearSearchRecursive(arr, target, 0, size);

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
