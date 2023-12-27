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
/*
Ein Baum ist eine Datenstruktur, die ähnlich wie ein echter Baum aussieht
er hat eine Wurzel und Zweige, die von der Wurzel ausgehen und weitere Zweige haben können.
Jeder Zweig endet mit einem Blatt. Diese Struktur wird verwendet, um hierarchische Beziehungen
zwischen Daten darzustellen, ähnlich wie Ordner und Dateien in einem Dateisystem.

Man stelle sich vor, man hat eine Hierarchie von Elementen, die miteinander verbunden
sind, wie z.B. die Struktur einer Organisation mit verschiedenen Abteilungen und
Unterebenen. Der Baum ermöglicht es, diese Strukturen in einem übersichtlichen und
organisierten Format abzubilden.

Bäume werden  für viele Dinge verwendet, z. B. zur Implementierung
von Verzeichnisstrukturen in einem Betriebssystem, zum Erstellen von Entscheidungsbäumen
in der künstlichen Intelligenz, zur Darstellung von Stammbäumen in der Biologie und für
die Strukturierung von Daten in Datenbanken. Sie sind nützlich, wenn hierarchische oder
verschachtelte Beziehungen zwischen Elementen dargestellt werden müssen und ermöglichen
schnelle Such- und Zugriffsmöglichkeiten auf die enthaltenen Daten.*/

#include <stdio.h>
#include <stdlib.h>

// Definition eines Knotens im binären Baum
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Funktion zum Erstellen eines neuen Knotens im Baum
struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (newNode == NULL)
    {
        fprintf(stderr, "Speicher konnte nicht allokiert werden");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Funktion zum Einfügen eines Elements in den binären Baum
struct TreeNode *insertNode(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Funktion zum Durchlaufen des Baumes in-order (links - root - rechts)
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Funktion zum Durchlaufen des Baumes in umgekehrter Reihenfolge (post-order: links - rechts - root)
void postorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Funktion zum Zählen der Knoten im Baum
int countNodes(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // Rekursive Addition der Knoten in linkem und rechtem Teilbaum und Wurzelknoten
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Funktion zum Ausgeben des Baums in einer Baumstruktur (rekursive Hilfsfunktion)
void printTree(struct TreeNode *root, int space)
{
    // Basisfall
    if (root == NULL)
    {
        return;
    }

    // Erhöhe Abstand zwischen Ebenen
    space += 5;

    // Rekursiver rechten Teilbaum
    printTree(root->right, space);

    // Ausgabe des aktuellen Knotens mit Abstand
    printf("\n");
    for (int i = 5; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);

    // Rekursiver Aufruf für den linken Teilbaum
    printTree(root->left, space);
}

// Hilfsfunktion
void printTreeStructure(struct TreeNode *root)
{
    printf("Baumstruktur:\n");
    printTree(root, 0);
}
// Funktion zum Spiegeln
void mirrorTree(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    // Rekursive Spiegelung der Teilbäume
    struct TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main()
{
    struct TreeNode *root = NULL;

    // Beispiel: Einfügen von Elementen in den binären Baum
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Beispiel: Durchlaufen und Ausgeben des Baumes (in-order)
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Beispiel: Durchlaufen und Ausgeben des Baumes in umgekehrter Reihenfolge (post-order)
    printf("Post-order Traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Beispiel: Ausgeben des Baumes in einer Baumstruktur
    printTreeStructure(root);

    // Beispiel: Zählen der Knoten im Baum
    int nodeCount = countNodes(root);
    printf("Anzahl der Knoten im Baum: %d\n", nodeCount);

    // Spiegeln des Baumes
    mirrorTree(root);
    printf("Gespiegelter Baum:\n");
    printTreeStructure(root);

    return 0;
}
