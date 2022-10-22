/**
 *
 * @author 6388019 Sorawanan Jeamjantarasakhon
 * @author 6388119 Kittipat Arpanon
 * ITCS443_Parallel and Distributed Systems
 * Parallel Rank Sort
 *
 * Created on : October 20th 2022
 * Modified on : October 22th 2022
 *
 * */
#include <omp.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
#include <stdlib.h>
int main()
{
    int i, j, x;
    int size, numThreads;
    printf("Input array size:");
    scanf("%d", &size);
    printf("Input number of threads:");
    scanf("%d", &numThreads);
    time_t seq_start, seq_end;
    double openmp_start, openmp_end;
    double time_seq, time_par, speedup;
    // int a[size], b[size];
    int *a, *b, *c;
    a = (int *)malloc(size * sizeof(int));
    b = (int *)malloc(size * sizeof(int));
    c = (int *)malloc(size * sizeof(int));
    srand(time(NULL));
    printf("generate random integer...(0-9999)\n");
    for (i = 0; i < size; i++)
    {
        // a[i] = rand() % 10000;
        *(a + i) = rand() % 10000;
    }
    printf("sorting in sequential...\n");
    time(&seq_start);
    for (i = 0; i < size; i++)
    { /* for each number */
        x = 0;
        for (j = 0; j < size; j++) /* count number less than it */
            // if (a[i] > a[j] || (a[i] == a[j] && j < i))
            if (*(a + i) > *(a + j) || (*(a + i) == *(a + j) && j < i))
                x++;
        // b[x] = a[i]; /* copy number into correct place */
        *(b + x) = *(a + i);
    }
    time(&seq_end);
    printf("sorting in parallel...\n");
    openmp_start = omp_get_wtime();
    omp_set_num_threads(numThreads);
#pragma omp parallel for private(j, x)
    for (i = 0; i < size; i++)
    { /* for each number */
        x = 0;
        for (j = 0; j < size; j++) /* count number less than it */
        {                          // if (a[i] > a[j] || (a[i] == a[j] && j < i))
            if (*(a + i) > *(a + j) || (*(a + i) == *(a + j) && j < i))
            {
                x++;
            }
        }
        // c[x] = a[i]; /* copy number into correct place */
        *(c + x) = *(a + i);
    }
    openmp_end = omp_get_wtime();
    for (i = 0; i < size; i++)
    {
        printf("unsorted : %d, Parallel sorted : %d, Sequential sorted : %d  \n", *(a + i), *(c + i), *(b + i));
    }
    time_seq = difftime(seq_end, seq_start);
    time_par = openmp_end - openmp_start;
    speedup = time_seq / time_par;
    printf("Time used in sequential rank sort : %f seconds \n", time_seq);
    printf("Time used in parallel rank sort using openmp : %f seconds \n", time_par);
    printf("speed up for rank sort : %f \n", speedup);
    // for debugging
    //  for (i = 0; i < size; i++)
    //  {
    //      // printf("%d ", a[i]);
    //      printf("%d ", *(a + i));
    //  }
    //  printf("\n");
    //  printf("\n");
    //  for (i = 0; i < size; i++)
    //  {
    //      // printf("%d ", b[i]);
    //      printf("%d ", *(b + i));
    //  }
    //  printf("\n");
    //  printf("\n");
    //  for (i = 0; i < size; i++)
    //  {
    //      // printf("%d ", b[i]);
    //      printf("%d ", *(c + i));
    //  }
    //  printf("\n");
}