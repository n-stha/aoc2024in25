#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  FILE *fptr;
  int n = 1001;
  fptr = fopen("1.txt", "r");

  int *leftArr = (int *)malloc(n * sizeof(int));
  int *rightArr = (int *)malloc(n * sizeof(int));

  int index;
  while (fscanf(fptr, "%d %d", &leftArr[index], &rightArr[index]) == 2) {
    index++;
  }

  qsort(leftArr, n, sizeof(int), compare);
  qsort(rightArr, n, sizeof(int), compare);

  long int distance = 0;

  for (int i = 0; i < n; i++) {
    distance += abs(leftArr[i] - rightArr[i]);
  }
  printf("Distance: %ld", distance);

  free(leftArr);
  free(rightArr);
  fclose(fptr);
  return 0;
}