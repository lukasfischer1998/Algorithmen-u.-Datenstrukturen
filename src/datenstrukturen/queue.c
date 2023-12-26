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

//https://de.wikipedia.org/wiki/Warteschlange_(Datenstruktur)#:~:text=In%20der%20Informatik%20bezeichnet%20eine,Reihenfolge%2C%20bevor%20diese%20weiterverarbeitet%20werden.
// https://www.studysmarter.de/schule/informatik/algorithmen-und-datenstrukturen/queue/
// https://www.happycoders.eu/de/algorithmen/queue-datenstruktur/
// https://www.cs.usfca.edu/~galles/visualization/QueueArray.html

/*
Eine Queue ist eine Datenstruktur, die nach dem "First-In-First-Out" 
(FIFO)-Prinzip funktioniert, wobei das zuerst hinzugefügte Element 
auch als erstes wieder entfernt wird. Man verwendet eine Queue, um 
Elemente zu speichern und darauf zuzugreifen, 
wobei Elemente hinten eingefügt und vorne entfernt werden, ähnlich wie 
eine Warteschlange, in der das zuerst ankommende Element als erstes bedient wird.
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(Queue *queue)
{
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(Queue *queue)
{
    return (queue->front == -1 || queue->front > queue->rear);
}

void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeued = queue->items[queue->front];
    queue->front++;
    printf("Dequeued: %d\n", dequeued);
    return dequeued;
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printQueue(queue);

    dequeue(queue);
    dequeue(queue);

    printQueue(queue);

    enqueue(queue, 50);
    enqueue(queue, 60);

    printQueue(queue);

    return 0;
}
