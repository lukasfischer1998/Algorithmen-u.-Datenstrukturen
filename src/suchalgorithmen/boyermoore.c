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

// https://de.wikipedia.org/wiki/Boyer-Moore-Algorithmus
// https://cmps-people.ok.ubc.ca/ylucet/DS/BoyerMoore.html
/*
Bad Character Heuristik: Der Algorithmus vergleicht das Suchmuster von rechts nach links mit dem Text. Wenn ein unpassendes Zeichen im Text gefunden wird,
verschiebt die Heuristik das Muster so weit wie möglich nach rechts, basierend auf dem letzten Vorkommen des unpassenden Zeichens im Muster.

Good Suffix Heuristik: Wenn eine Übereinstimmung zwischen einem Teil des Musters und dem Text gefunden wird,
überprüft der Algorithmus, ob der Rest des Musters auch im Text vorkommt. Wenn ja, wird das Muster verschoben,
um das nächste Vorkommen des übereinstimmenden Suffixes zu finden.*/

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

// Funktion zur Berechnung der Maximalfunktion
int max(int a, int b)
{
    return (a > b) ? a : b;
}

#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

int max(int a, int b)
{
    return (a > b) ? a : b;
}
// Funktion zur Vorbereitung der Bad Character Heuristik
/*Zuerst werden alle Einträge im Array badCharShift mit dem Wert -1 initialisiert.
Dieser Wert dient als Indikator dafür, dass das entsprechende Zeichen nicht im Suchmuster vorhanden ist.
Danach durchläuft die Funktion das Suchmuster (pattern) und speichert für jedes Zeichen
den Index (die Position) im Muster im Array badCharShift. Das heißt, sie speichert den Index des letzten*/
void badCharHeuristic(char *pattern, int patternLength, int badCharShift[ALPHABET_SIZE])
{
    int i;

    for (i = 0; i < ALPHABET_SIZE; i++)
    {
        badCharShift[i] = -1;
    }

    for (i = 0; i < patternLength; i++)
    {
        badCharShift[(int)pattern[i]] = i;
    }
}

void boyerMooreSearch(char *text, char *pattern)
{
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int badCharShift[ALPHABET_SIZE];
    badCharHeuristic(pattern, patternLength, badCharShift);

    int shift = 0;
    int count = 0;

    while (shift <= textLength - patternLength)
    {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0)
        {
            printf("Pattern found at index: %d\n", shift);
            count++;

            if (shift + patternLength < textLength)
            {
                shift += patternLength - badCharShift[text[shift + patternLength]];
            }
            else
            {
                shift += 1;
            }
        }
        else
        {
            shift += max(1, j - badCharShift[text[shift + j]]);
        }
    }

    if (count == 0)
    {
        printf("Pattern not found in the text.\n");
    }
    else
    {
        printf("Total occurrences: %d\n", count);
    }
}

int main()
{
    char text[] = "exampletextfordsfgaklndföexamplegalkdölgaödsfgkaexampjbakkgedsearch";
    char pattern[] = "example";

    printf("Boyer-Moore Search:\n");
    boyerMooreSearch(text, pattern);

    return 0;
}
