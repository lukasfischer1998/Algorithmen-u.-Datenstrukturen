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

// https://de.wikipedia.org/wiki/Datenstruktur#Array
// https://www.w3schools.com/c/c_arrays.php

/*
Ein Array ist eine grundlegende Datenstruktur in der Programmierung,
die eine geordnete Sammlung von Elementen desselben Datentyps darstellt.
Es ermöglicht den Zugriff auf einzelne Elemente anhand ihres Index innerhalb
des Arrays. Die Elemente in einem Array sind kontinuierlich im Speicher angeordnet
und können über einen Index effizient abgerufen und manipuliert werden. Arrays
haben eine feste Größe, die bei der Erstellung festgelegt wird und während der
Laufzeit normalerweise nicht verändert werden kann.
Diese Struktur bietet eine einfache Möglichkeit, mehrere ähnliche Datenwerte zu
speichern und darauf zuzugreifen, was die Verarbeitung und Organisation von Daten erleichtert.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition der Array-Datenstruktur
typedef struct
{
    int *arr;
    int size;
} Array;

// Funktion zur Initialisierung eines leeren Arrays
Array *createArray(int size)
{
    Array *newArray = (Array *)malloc(sizeof(Array));
    if (newArray == NULL)
    {
        printf("Speicher konnte nicht zugewiesen werden.\n");
        exit(EXIT_FAILURE);
    }

    newArray->arr = (int *)malloc(size * sizeof(int));
    if (newArray->arr == NULL)
    {
        printf("Speicher konnte nicht zugewiesen werden.\n");
        exit(EXIT_FAILURE);
    }

    newArray->size = size;
    return newArray;
}

// Funktion zum Einfügen eines Elements in das Array an einer bestimmten Position
void insert(Array *array, int index, int value)
{
    if (index < 0 || index >= array->size)
    {
        printf("Ungültiger Index.\n");
        return;
    }

    array->arr[index] = value;
}

// Funktion zum Abrufen eines Elements aus dem Array an einer bestimmten Position
int get(Array *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        printf("Ungültiger Index.\n");
        exit(EXIT_FAILURE);
    }

    return array->arr[index];
}

// Funktion zum Freigeben des Speichers des Arrays
void freeArray(Array *array)
{
    free(array->arr);
    free(array);
}

// Beispiel für die Verwendung der Array-Funktionen
int main()
{
    int arraySize = 10;
    Array *myArray = createArray(arraySize);

    insert(myArray, 0, 5);
    insert(myArray, 1, 10);

    printf("Element an Index 0: %d\n", get(myArray, 0));
    printf("Element an Index 1: %d\n", get(myArray, 1));

    freeArray(myArray);
    return 0;
}
