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

// https://studyflix.de/informatik/bucketsort-1438
// https://de.wikipedia.org/wiki/Bucketsort#:~:text=Bucketsort%20(von%20englisch%20bucket%20%E2%80%9EEimer,Elemente%20auf%20die%20Buckets%20(Partitionierung)
// https://www.hackerearth.com/practice/algorithms/sorting/bucket-sort/tutorial/

/*
Der Bucket Sort Algorithmus funktioniert, indem er Elemente in "Buckets" (Eimer)
verteilt und dann jeden Bucket separat sortiert. Die Idee ist, dass Elemente, die
in denselben Bucket fallen, wahrscheinlich nahe beieinander liegen und daher effizienter
sortiert werden können. In dieser Implementierung werden für die Verteilung der Elemente Arrays von Pointern auf Integer-Arrays verwendet, die als Buckets dienen.
Nach der Verteilung werden die einzelnen Buckets mit einer einfachen Sortiermethode
(hier wird Insertion Sort verwendet) sortiert und dann in das ursprüngliche Array zurückgeführt.
*/
#include <stdio.h>
#include <stdlib.h>

void insertSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n)
{
    const int num_buckets = 10;
    float **buckets = (float **)malloc(sizeof(float *) * num_buckets);

    for (int i = 0; i < num_buckets; i++)
    {
        buckets[i] = (float *)malloc(sizeof(float) * n);
    }

    float max_val = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        int bucket_idx = (int)(arr[i] * num_buckets / (max_val + 1));
        int j = 0;

        while (buckets[bucket_idx][j] != 0)
        {
            j++;
        }
        buckets[bucket_idx][j] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++)
    {
        if (buckets[i][0] != 0)
        {
            insertSort(buckets[i], n);
            for (int j = 0; j < n; j++)
            {
                if (buckets[i][j] != 0)
                {
                    arr[index++] = buckets[i][j];
                }
            }
        }
        free(buckets[i]);
    }
    free(buckets);
}

int main()
{
    float arr[] = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n);

    printf("Sortiertes Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
