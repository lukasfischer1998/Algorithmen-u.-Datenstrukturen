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

// https://www.geeksforgeeks.org/fibonacci-search/
// https://en.wikipedia.org/wiki/Fibonacci_search_technique
// https://www.youtube.com/watch?v=GAafWFRGP7k
/*
Die Fibonacci-Suche nutzt die Fibonacci-Zahlen, um den Suchbereich in einem
Array zu bestimmen. Sie beginnt mit zwei Fibonacci-Zahlen, um eine Teilsequenz
zu definieren, vergleicht das gesuchte Element mit dem Wert an der Position der
größeren Fibonacci-Zahl und verengt den Suchbereich basierend auf dem Vergleich. Dieser Prozess setzt sich fort,
indem die Fibonacci-Zahlen verschoben werden, um den Bereich schrittweise zu verkleinern,
bis das gesuchte Element gefunden oder der Bereich erschöpft ist.
*/

#include <stdio.h>

// Fibonacci Search Algorithm
int fibonacciSearch(int array[], int size, int target)
{
    int fibM_minus_2 = 0;                   // (m-2)'te Fibonacci-Zahl
    int fibM_minus_1 = 1;                   // (m-1)'te Fibonacci-Zahl
    int fibM = fibM_minus_1 + fibM_minus_2; // m'te Fibonacci-Zahl

    while (fibM < size)
    {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = (offset + fibM_minus_2 < size - 1) ? offset + fibM_minus_2 : size - 1;

        if (array[i] < target)
        {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
            offset = i;
        }
        else if (array[i] > target)
        {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
        else
        {
            return i;
        }
    }

    if (fibM_minus_1 == 1 && array[offset + 1] == target)
    {
        return offset + 1;
    }

    return -1; // Element nicht gefunden
}

int main()
{
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 12;
    int arrayLength = sizeof(array) / sizeof(array[0]);

    int result = fibonacciSearch(array, arrayLength, target);

    if (result != -1)
        printf("Das Element %d wurde an der Position %d gefunden.\n", target, result);
    else
        printf("Das Element %d wurde nicht im Array gefunden.\n", target);

    return 0;
}
