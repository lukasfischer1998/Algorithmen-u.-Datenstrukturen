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
// https://www.hackerearth.com/practice/algorithms/sorting/counting-sort/tutorial/
// https://www.youtube.com/watch?v=7zuGmKfUt7s
// https://de.wikipedia.org/wiki/Countingsort
/*                                                                                                                                                                                                                \
Vorbereitung der Hilfsstrukturen:                                                                                                                                                                                 \
                                                                                                                                                                                                                \ \
Erstelle ein Hilfsarray count mit der Größe des Wertebereichs plus eins, um die Häufigkeit jedes Elements zu zählen.                                                                                          \
Erstelle ein Ausgabe-Array mit der gleichen Größe wie das Eingabearray.                                                                                                                                         \
Zähle die Häufigkeit der Elemente:                                                                                                                                                                              \
                                                                                                                                                                                                                \ \
Iteriere über das Eingabearray und zähle die Anzahl jedes vorkommenden Elements, indem du den entsprechenden Index im count-Array inkrementierst.                                                               \
Berechne die kumulative Summe:                                                                                                                                                                                    \
                                                                                                                                                                                                                \ \
Gehe über das count-Array und addiere die aktuellen Werte mit den vorherigen, um die kumulative Summe der Häufigkeiten zu erhalten. Dies gibt die endgültige Position jedes Elements im sortierten Array an.   \
Platziere die Elemente in das Ausgabe-Array:                                                                                                                                                                      \
                                                                                                                                                                                                                \ \
Durchlaufe das Eingabearray rückwärts:                                                                                                                                                                          \
Finde die Position des aktuellen Elements im sortierten Array anhand der kumulativen Summe aus dem count-Array und platziere das Element in das Ausgabe-Array an dieser Position.                                 \
Dekrementiere dann den Zähler des entsprechenden Elements im count-Array.                                                                                                                                        \
Kopiere das sortierte Ausgabe-Array zurück:                                                                                                                                                                      \
                                                                                                                                                                                                                \ \
Kopiere das sortierte Ausgabe-Array zurück in das ursprüngliche Eingabearray, um es zu sortieren.                                                                                                               \
Fertigstellung:                                                                                                                                                                                                   \
                                                                                                                                                                                                                \ \
Das Eingabearray ist jetzt sortiert, basierend auf der Häufigkeit der Elemente im angegebenen Bereich.                                                                                                           \
*/                                                                                                                                                                                                                \
#include<stdio.h>
#include <stdlib.h>

// Funktion für den Counting-Sort
void countingSort(int arr[], int n, int range)
{
    int *count = (int *)malloc((range + 1) * sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    // Überprüfung der Speicherzuteilung
    if (count == NULL || output == NULL)
    {
        printf("Fehler: Speicher konnte nicht zugewiesen werden.\n");
        exit(EXIT_FAILURE);
    }

    // Initialisiere alle Elemente von count als 0
    for (int i = 0; i <= range; ++i)
    {
        count[i] = 0;
    }

    // Zähle die Häufigkeit jedes Elements im Eingabearray
    for (int i = 0; i < n; ++i)
    {
        ++count[arr[i]];
    }

    // Akkumuliere die Summen der Häufigkeiten
    for (int i = 1; i <= range; ++i)
    {
        count[i] += count[i - 1];
    }

    // Platzierung der Elemente in das Ausgabe-Array in sortierter Reihenfolge
    for (int i = n - 1; i >= 0; --i)
    {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    // Kopiere das sortierte Ausgabe-Array in das ursprüngliche Array
    for (int i = 0; i < n; ++i)
    {
        arr[i] = output[i];
    }

    // Freigabe des Speichers
    free(count);
    free(output);
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Aufruf des Counting-Sort-Algorithmus
    countingSort(arr, n, 8); // Bereich (range) des Arrays hier 0 bis 8

    printf("\nSortiertes Array nach Counting-Sort: \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
