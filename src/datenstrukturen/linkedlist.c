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

// https://www.learn-c.org/en/Linked_lists
// https://de.wikipedia.org/wiki/Liste_(Datenstruktur)

/*
Unterschied Linked List und Array:

ARRAY
- Interne Struktur: Ein Array ist eine lineare Datenstruktur,
  die Elemente desselben Datentyps in sequenziellen Speicherblöcken speichert. Die Elemente sind direkt hintereinander im Speicher platziert.
- Speicherzuordnung: Arrays haben eine statische Größe, die normalerweise beim
  Erstellen des Arrays festgelegt wird. Die Größe bleibt während der Laufzeit konstant.
- Zugriff auf Elemente: Auf Elemente in einem Array kann mit einem Index zugegriffen werden.
  Der Zugriff auf ein Element erfolgt in konstanter Zeit O(1), da auf die Speicheradresse direkt zugegriffen werden kann.
- Einfügen und Löschen: Das Einfügen oder Löschen von Elementen in einem Array erfordert möglicherweise das Verschieben anderer Elemente,
  um Platz zu machen, was je nach Position der Operation und der Größe des Arrays ineffizient sein kann (insbesondere am Anfang oder in der Mitte des Arrays).

LINKED LIST
- Interne Struktur: Eine Linked List besteht aus Knoten, die Elemente und einen Verweis
  (Pointer) auf das nächste Element enthalten. Diese Knoten sind nicht notwendigerweise direkt im Speicher nebeneinander platziert.
- Speicherzuordnung: Linked Lists können dynamisch wachsen und Schrumpfen, da sie Elemente
  durch dynamische Zuweisung hinzufügen oder löschen können. Die Größe ist nicht statisch und kann während der Laufzeit variieren.
- Zugriff auf Elemente: Der Zugriff auf ein Element in einer Linked List erfordert das Durchlaufen der Liste von Anfang bis zum gewünschten Element.
  Daher ist der Zugriff auf ein Element nicht konstant, sondern hat eine Komplexität von O(n), wobei n die Anzahl der Elemente in der Liste ist.
- Einfügen und Löschen: Das Einfügen oder Löschen von Elementen in einer Linked List kann effizienter sein als bei Arrays, da es keine Verschiebung von Elementen erfordert.
  Das Einfügen oder Löschen eines Elements in der Nähe des Anfangs oder Endes der Liste erfolgt in konstanter Zeit O(1), solange man auf die betreffenden
  Knoten direkt zugreifen kann.
*/

#include <stdio.h>
#include <stdlib.h>

// Definition eines Knotens in der Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Funktion zum Erstellen eines neuen Knotens
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Speicher konnte nicht allokiert werden");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Funktion zum Einfügen eines neuen Knotens am Anfang der Linked List
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Funktion zum Drucken der Linked List
void printLinkedList(struct Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Funktion zum Freigeben des Speichers der Linked List
void freeLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    // Erstellen einer leeren Linked List
    struct Node *head = NULL;

    // Beispiel: Einfügen von Elementen in die Linked List
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 15);

    // Beispiel: Drucken der Linked List
    printLinkedList(head);

    // Beispiel: Freigeben des Speichers der Linked List
    freeLinkedList(head);

    return 0;
}
