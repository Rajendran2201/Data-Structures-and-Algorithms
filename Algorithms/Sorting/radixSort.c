#include<stdio.h>

void countSort(int[], int, int);
void radixSort(int[], int);
void printArray(int[], int);
int getMax(int[], int);
void fillZeros(int[], int);

int main(){

  int arr[] = {3,35,1,34,82,61,45,24};
  int n = sizeof(arr) / sizeof(int);
  radixSort(arr, n);
  printArray(arr, n);
  return 0;
}

void radixSort(int arr[], int n){
  int max = getMax(arr, n);
  for(int pos = 1; max/pos > 0; pos = pos*10){
    countSort(arr, n, pos);
  }
}


void countSort(int arr[], int n, int pos){
  int count[10];
  int b[n];
  fillZeros(count, 10);
  fillZeros(b, n);
  for(int i=0; i<n; i++){
    ++count[(arr[i]/pos) % 10];
  }
  for(int i=1; i<10; i++){
    count[i] = count[i] +  count[i-1];
  }
  for(int i=n-1; i>=0; i--){
    b[--count[(arr[i]/pos) % 10]] = arr[i];
  }
  for(int i=0; i<n; i++){
    arr[i] = b[i];
  }
}



int getMax(int arr[], int n){
  int max = arr[0];
  for(int i=0; i<n; i++){
    if (arr[i] > max){
      max = arr[i];
    }
  }
  return max;
}

void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", arr[i]);
  }
}

void fillZeros(int arr[], int n){
  for(int i=0; i<n; i++){
    arr[i] = 0;
  }
}