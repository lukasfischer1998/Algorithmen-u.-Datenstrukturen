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

// https://de.wikipedia.org/wiki/Bin%C3%A4re_Suche
/*Funktionsweise: Der Algorithmus beginnt damit, das gesuchte Element mit dem Element in der Mitte der Liste zu vergleichen.
Wenn das gesuchte Element kleiner ist als das mittlere Element,
wird die Suche im linken Teil der Liste fortgesetzt. Ist es größer, wird im rechten Teil weitergesucht.

Halbierung des Suchbereichs: Der Schlüssel zur Effizienz des Algorithmus liegt darin, dass der Suchbereich in jedem Schritt
halbiert wird. Dadurch wird die Liste in jedem Durchlauf der Schleife, je nach Vergleich des gesuchten Elements mit dem Mittelwert, in zwei Hälften aufgeteilt.
Die Suche findet dann im relevanten Teil weiter statt.*/

#include <stdio.h>

// Binary Search Algorithm
int binarySearch(int array[], int left, int right, int target)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // Wenn das Element in der Mitte gefunden wurde
        if (array[mid] == target)
            return mid;

        // Wenn das Element größer als das in der Mitte ist, suche im rechten Teil weiter
        if (array[mid] < target)
            left = mid + 1;
        // Andernfalls suche im linken Teil weiter
        else
            right = mid - 1;
    }

    // Element nicht gefunden
    return -1;
}

// Rekursive Binary Search Funktion
int recursiveBinarySearch(int array[], int left, int right, int target)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;

        // Wenn das Element in der Mitte gefunden wurde
        if (array[mid] == target)
            return mid;

        // Wenn das Element kleiner als das in der Mitte ist, suche im linken Teil weiter
        if (array[mid] > target)
            return recursiveBinarySearch(array, left, mid - 1, target);

        // Andernfalls suche im rechten Teil weiter
        return recursiveBinarySearch(array, mid + 1, right, target);
    }

    // Element nicht gefunden
    return -1;
}

int main()
{
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    // Aufruf der iterativen Binary Search Funktion
    int iterativeResult = binarySearch(array, 0, arrayLength - 1, target);
    if (iterativeResult != -1)
        printf("Iterative Suche: Das Element %d wurde an der Position %d gefunden.\n", target, iterativeResult);
    else
        printf("Iterative Suche: Das Element %d wurde nicht im Array gefunden.\n", target);

    // Aufruf der rekursiven Binary Search Funktion
    int recursiveResult = recursiveBinarySearch(array, 0, arrayLength - 1, target);
    if (recursiveResult != -1)
        printf("Rekursive Suche: Das Element %d wurde an der Position %d gefunden.\n", target, recursiveResult);
    else
        printf("Rekursive Suche: Das Element %d wurde nicht im Array gefunden.\n", target);

    return 0;
}