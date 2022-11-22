#include <stdio.h>
       #include <stdlib.h>

void QuickSort(int a[], int left, int right)
       {
              int i = left;
              int j = right;
              int temp = a[i];

       if( left < right)
              {
                     while(i < j)
                     {
                            while(a[j] <= temp && i < j)
                            {
                                   j--;
                            }
                            a[i] = a[j];

                     while(a[i] >= temp && i < j)
                            {
                                   i++;
                            }
                            a[j] = a[i];
                     }
                     a[i] = temp;

              QuickSort(a, left, i - 1);
                     QuickSort(a, j + 1, right);
              }
       }

void main()
       {
              int a[8] = {21, 5, 57, 105, 66, 15, 163, 98};
              QuickSort(a, 0, 7);

       int i;
              for (i = 0; i < 8; i++)
                     printf("%d,",a[i]);
              printf("\n");
       }