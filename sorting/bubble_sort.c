//The bubble sort algorithm is a simple sorting algorithm that works by repeatedly stepping through the list to be sorted, comparing each pair of adjacent items and swapping them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

//Here's a simple example of bubble sort algorithm in C using user input:

#include <stdio.h>

void bubbleSort(int array[], int size) {
  int i, j, temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  int array[100], size, i;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &size);
  printf("Enter the elements of array:\n");
  for (i = 0; i < size; i++) {
    scanf("%d", &array[i]);
  }
  bubbleSort(array, size);
  printf("Sorted array in ascending order:\n");
  for (i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
