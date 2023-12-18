#include <stdio.h>
int main() {
    int arr[10], no, i, j, c, heap_root, temp;
    // Input the number of elements
    printf("Input number of elements: ");
    scanf("%d", &no);
    // Input array values one by one
    printf("\nInput array values one by one: ");
    for (i = 0; i < no; i++)
        scanf("%d", &arr[i]);
    // Build a max heap using the heapify-up procedure
    for (i = 1; i < no; i++) {
        c = i;
        do {
            heap_root = (c - 1) / 2;
            // Create a max heap array
            if (arr[heap_root] < arr[c]) {
                temp = arr[heap_root];
                arr[heap_root] = arr[c];
                arr[c] = temp;
            }
            c = heap_root;
        } while (c != 0);
    }
    // Display the heap array
    printf("Heap array: ");
    for (i = 0; i < no; i++)
        printf("%d\t", arr[i]);
    // Extract elements from the heap to build the sorted array
    for (j = no - 1; j >= 0; j--) {
        temp = arr[0];
        arr[0] = arr[j];
        arr[j] = temp;
        heap_root = 0;
        // Heapify-down procedure to maintain the max heap property
        do {
            c = 2 * heap_root + 1;
            // Check if the right child is greater than the left child
            if ((arr[c] < arr[c + 1]) && c < j - 1)
                c++;
            // Swap if the root is smaller than the child
            if (arr[heap_root] < arr[c] && c < j) {
                temp = arr[heap_root];
                arr[heap_root] = arr[c];
                arr[c] = temp;
            }
            heap_root = c;
        } while (c < j);
    }
    // Display the sorted array
    printf("\nSorted array: ");
    for (i = 0; i < no; i++)
        printf("\t%d", arr[i]);
    printf("\n");
    return 0;
}
