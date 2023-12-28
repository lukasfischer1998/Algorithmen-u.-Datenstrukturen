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

// https://de.wikipedia.org/wiki/Datenstruktur#Vorrangwarteschlange
// https://studyflix.de/informatik/heap-1440

/*
Es gibt verschiedene Arten von Heaps,
wie z. B. den Min-Heap und den Max-Heap. Ein Min-Heap hat die niedrigste Priorität an der Wurzel,
während ein Max-Heap die höchste Priorität an der Wurzel hat.


Generell ermöglicht die Min-Heap-Datenstruktur eine effiziente Verwaltung von Elementen
mit Prioritäten, indem das kleinste Element schnell abgerufen und entfernt
werden kann, was beispielsweise in Anwendungen wie Sortieralgorithmen,
Graphenalgorithmen (z. B. Dijkstra's Algorithmus) oder Zeitplanungsproblemen
nützlich ist, in denen das Element mit der höchsten oder niedrigsten Priorität wichtig ist.

Ein Min-Heap ist eine spezielle Art von binärem Baum, in dem das Element an der Wurzel des Baumes immer den kleinsten Wert enthält.
Diese Datenstruktur bietet grundlegende Operationen wie Einfügen (insert) und Entfernen des Elements mit der niedrigsten Priorität (extractMin).
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct MinHeap
{
    int *array;
    int size;
    int capacity;
};

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int *)malloc(capacity * sizeof(int));
    return minHeap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != idx)
    {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

void insert(struct MinHeap *minHeap, int value)
{
    if (minHeap->size == minHeap->capacity)
    {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    int idx = minHeap->size;
    minHeap->array[idx] = value;
    minHeap->size++;

    int parent = (idx - 1) / 2;
    while (idx > 0 && minHeap->array[idx] < minHeap->array[parent])
    {
        swap(&minHeap->array[idx], &minHeap->array[parent]);
        idx = parent;
        parent = (idx - 1) / 2;
    }
}

int extractMin(struct MinHeap *minHeap)
{
    if (minHeap->size <= 0)
        return -1; // Signifies empty heap

    if (minHeap->size == 1)
    {
        minHeap->size--;
        return minHeap->array[0];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);

    return root;
}

void printHeap(struct MinHeap *minHeap)
{
    printf("Min-Heap: ");
    for (int i = 0; i < minHeap->size; i++)
    {
        printf("%d ", minHeap->array[i]);
    }
    printf("\n");
}

int main()
{
    struct MinHeap *minHeap = createMinHeap(MAX_HEAP_SIZE);

    insert(minHeap, 5);
    insert(minHeap, 3);
    insert(minHeap, 8);
    insert(minHeap, 1);
    insert(minHeap, 10);

    printHeap(minHeap); // Output: Min-Heap: 1 3 8 5 10

    printf("Extracted Min: %d\n", extractMin(minHeap)); // Output: Extracted Min: 1
    printf("Extracted Min: %d\n", extractMin(minHeap)); // Output: Extracted Min: 3

    printHeap(minHeap); // Output: Min-Heap: 5 10 8

    free(minHeap->array);
    free(minHeap);

    return 0;
}
