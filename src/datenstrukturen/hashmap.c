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

// https://www.codeadventurer.de/?p=2091
// https://stackoverflow.com/questions/838404/implementing-a-hashmap-in-c

/*
Eine HashMap ist eine Datenstruktur in der Informatik, die zur
Speicherung von Informationen in Form von
Schlüssel-Wert-Paaren verwendet wird. Sie basiert auf dem Konzept einer
Hashtabelle und bietet eine effiziente Methode, um Elemente zu speichern und darauf zuzugreifen.

In einer HashMap wird jedem Schlüssel ein Wert zugeordnet, ähnlich wie in einem
Wörterbuch, wo jedem Wort eine Definition zugeordnet ist. Diese Datenstruktur
verwendet das Prinzip der Hashfunktion, um den Index oder die Position zu berechnen,
an der ein Schlüssel im Speicher abgelegt wird. Durch die Verwendung dieser Hashfunktionen
kann der Zugriff auf Elemente in konstanter Zeit (O(1)) erfolgen, was bedeutet, dass die
Zugriffszeit unabhängig von der Größe der HashMap bleibt, sofern keine Kollisionen auftreten.

Kollisionen treten auf, wenn zwei unterschiedliche Schlüssel denselben Hash-Wert erzeugen.
In solchen Fällen verwendet die HashMap verschiedene Mechanismen, um damit umzugehen, z. B.
die Verwendung von verketteten Listen oder in neueren Implementierungen die Verwendung von
Baumstrukturen für Kollisionsauflösungen.

Eine wichtige Eigenschaft der HashMap ist, dass sie keine Reihenfolge für die gespeicherten
Elemente garantiert. Das bedeutet, dass die Elemente nicht in der Reihenfolge gespeichert werden,
in der sie hinzugefügt wurden.
HashMaps sind in vielen Programmiersprachen verfügbar und werden häufig
für die Implementierung von Datenbanken, Caches, und allgemein für das Speichern und
Abrufen von Daten verwendet, wo schneller und effizienter Zugriff auf die gespeicherten Elemente erforderlich ist.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Struktur für einen Eintrag in der verketteten Liste der Hash Map
typedef struct Entry
{
    char *key;
    int value;
    struct Entry *next; // Zeiger auf das nächste Element für die Verkettung
} Entry;

// Struktur für die Hash Map
typedef struct
{
    Entry **entries;
} HashMap;

// Funktion, um eine neue Hash Map zu erstellen
HashMap *createHashMap()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->entries = (Entry **)calloc(TABLE_SIZE, sizeof(Entry *));
    return map;
}

// Hashfunktion zur Generierung des Indexes
unsigned int hashFunction(const char *key)
{
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i)
    {
        hash = 31 * hash + key[i];
    }
    return hash % TABLE_SIZE;
}

// Funktion, um einen Wert in die Hash Map einzufügen
void put(HashMap *map, const char *key, int value)
{
    unsigned int index = hashFunction(key);
    Entry *entry = (Entry *)malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = NULL;

    // Überprüfen, ob der Index bereits belegt ist
    if (map->entries[index] != NULL)
    {
        // Kollision: Verketten der Einträge
        Entry *current = map->entries[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = entry;
    }
    else
    {
        map->entries[index] = entry;
    }
}

// Funktion, um den Wert anhand des Schlüssels zu erhalten
int get(HashMap *map, const char *key)
{
    unsigned int index = hashFunction(key);
    Entry *entry = map->entries[index];

    // Durchlaufen der verknüpften Einträge
    while (entry != NULL)
    {
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }
        entry = entry->next;
    }

    // Schlüssel nicht gefunden
    return -1; // oder einen anderen Fehlerwert zurückgeben
}

// Beispielanwendung in der main-Funktion
int main()
{
    HashMap *map = createHashMap();

    put(map, "apple", 5);
    put(map, "banana", 10);
    put(map, "orange", 7);

    printf("Value for 'apple': %d\n", get(map, "apple"));
    printf("Value for 'banana': %d\n", get(map, "banana"));
    printf("Value for 'orange': %d\n", get(map, "orange"));
    printf("Value for 'grape': %d\n", get(map, "grape"));

    return 0;
}
