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

// https://en.wikipedia.org/wiki/Ternary_search#:~:text=A%20ternary%20search%20algorithm%20is,maximum%20of%20a%20unimodal%20function.
// Idee des Binary Searches aber 3 Teilung des Arrays
// Der Ternary Search teilt das Array in drei Teile und sucht in einem der drei Teile basierend
// auf dem Vergleich des gesuchten Elements mit zwei Zwischenwerten im Array. Auch hier erfolgt eine Teilaufteilung in jeder Iteration.

#include <stdio.h>

// Ternary Search Algorithm
int ternarySearch(int array[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Wenn das Element an einer der beiden Mittelstellen gefunden wurde
        if (array[mid1] == target)
            return mid1;
        if (array[mid2] == target)
            return mid2;

        // Wenn das Element kleiner als das in der ersten Drittel ist, suche im ersten Drittel weiter
        if (target < array[mid1])
            return ternarySearch(array, left, mid1 - 1, target);
        // Wenn das Element größer als das in der zweiten Drittel ist, suche im letzten Drittel weiter
        else if (target > array[mid2])
            return ternarySearch(array, mid2 + 1, right, target);
        // Andernfalls suche im mittleren Drittel weiter
        else
            return ternarySearch(array, mid1 + 1, mid2 - 1, target);
    }

    // Element nicht gefunden
    return -1;
}

// Rekursive Ternary Search Funktion
int recursiveTernarySearch(int array[], int left, int right, int target)
{
    if (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        // Wenn das Element an einer der beiden Mittelstellen gefunden wurde
        if (array[mid1] == target)
            return mid1;
        if (array[mid2] == target)
            return mid2;

        // Wenn das Element kleiner als das in der ersten Drittel ist, suche im ersten Drittel weiter
        if (target < array[mid1])
            return recursiveTernarySearch(array, left, mid1 - 1, target);
        // Wenn das Element größer als das in der zweiten Drittel ist, suche im letzten Drittel weiter
        else if (target > array[mid2])
            return recursiveTernarySearch(array, mid2 + 1, right, target);
        // Andernfalls suche im mittleren Drittel weiter
        else
            return recursiveTernarySearch(array, mid1 + 1, mid2 - 1, target);
    }

    // Element nicht gefunden
    return -1;
}

int main()
{
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    // Ausführung von ternarySearch
    int result1 = ternarySearch(array, 0, arrayLength - 1, target);
    if (result1 != -1)
        printf("Ternary Search: Das Element %d wurde an der Position %d gefunden.\n", target, result1);
    else
        printf("Ternary Search: Das Element %d wurde nicht im Array gefunden.\n", target);

    // Ausführung von recursiveTernarySearch
    int result2 = recursiveTernarySearch(array, 0, arrayLength - 1, target);
    if (result2 != -1)
        printf("Rekursive Ternary Search: Das Element %d wurde an der Position %d gefunden.\n", target, result2);
    else
        printf("Rekursive Ternary Search: Das Element %d wurde nicht im Array gefunden.\n", target);

    return 0;
}
