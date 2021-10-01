#include <stdio.h>
#include <stdlib.h>

void heapify(int heap[], int n){
    int i, v, k, j, is_heap = 0;
    for(i=(n/2); i>=1; --i){
        k = i;
        v = heap[k];
        is_heap = 0;
        while(!is_heap && 2*k <= n){
            j = 2 * k;
            if(j < n && heap[j] < heap[j+1])
                j++;
            if(v >= heap[j])
                is_heap = 1;
            else{
                heap[k] = heap[j];
                k = j;
            }
        }
        heap[k] = v;
    }
}

void heap_sort(int heap[], int n){
    int temp, i;
    heapify(heap, n);
    for(i=n; i>=2; --i){
        temp = heap[i];
        heap[i] = heap[1];
        heap[1] = temp;
        heapify(heap, i-1);
    }
}

int main()
{
    int n;
    printf("How many elements do you want to enter: ");
    scanf("%d", &n);

    int a[n+1], i;
    printf("\nEnter the array elements: ");
    for(i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    printf("\nArray before sorting: \n");
    for(i=1; i<=n; ++i)
        printf("%d\t", a[i]);

    heap_sort(a, n);

    printf("\n\nArray after sorting: \n");
    for(i=1; i<=n; ++i)
        printf("%d\t", a[i]);

    printf("\n");

    return 0;
}
