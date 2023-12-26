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

// https://www.studysmarter.de/schule/informatik/algorithmen-und-datenstrukturen/stack/
// https://de.wikipedia.org/wiki/Stapelspeicher
// https://www.happycoders.eu/de/algorithmen/stack-datenstruktur/

/*
Ein Stack ist eine abstrakte Datenstruktur, die nach dem
Last-In-First-Out (LIFO)-Prinzip funktioniert, wobei das
zuletzt hinzugefügte Element als erstes entfernt wird. Es
erlaubt das Hinzufügen (Push) und Entfernen (Pop)
von Elementen nur an einem Ende der Datenstruktur, wodurch
es ähnlich zu einem Stapel von Objekten funktioniert, bei dem nur das oberste Objekt zugänglich ist.
*/

#include <stdio.h>
#define MAX_SIZE 100 // Maximale Größe des Stacks

// Struktur für den Stack
typedef struct
{
    int items[MAX_SIZE];
    int top;
} Stack;

// Funktion zum Initialisieren des Stacks
void initializeStack(Stack *stack)
{
    stack->top = -1;
}

// Funktion zum Überprüfen, ob der Stack leer ist
int isEmpty(Stack *stack)
{
    return (stack->top == -1);
}

// Funktion zum Überprüfen, ob der Stack voll ist
int isFull(Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Funktion zum Hinzufügen eines Elements (Push) zum Stack
void push(Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Der Stack ist voll, kann kein Element hinzufügen!\n");
    }
    else
    {
        stack->items[++stack->top] = value;
        printf("Element %d erfolgreich hinzugefügt.\n", value);
    }
}

// Funktion zum Entfernen eines Elements (Pop) aus dem Stack
int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Der Stack ist leer, kann kein Element entfernen!\n");
        return -1;
    }
    else
    {
        int removedItem = stack->items[stack->top--];
        printf("Element %d erfolgreich entfernt.\n", removedItem);
        return removedItem;
    }
}

// Funktion zum Anzeigen des obersten Elements (Peek) im Stack
int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Der Stack ist leer, kein oberstes Element vorhanden!\n");
        return -1;
    }
    else
    {
        printf("Oberstes Element: %d\n", stack->items[stack->top]);
        return stack->items[stack->top];
    }
}

// Funktion zum Ausgeben aller Elemente im Stack
void printStack(Stack *stack)
{
    printf("Elemente im Stack: ");
    for (int i = 0; i <= stack->top; ++i)
    {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

int main()
{
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    pop(&stack);

    printStack(&stack);

    peek(&stack);

    return 0;
}
