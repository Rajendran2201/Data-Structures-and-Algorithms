#include<stdio.h>

void shellSort(int[], int);
void printArray(int[], int);

int main(){

 int arr[] = {3,35,1,34,82,61,45,24};
  int n = sizeof(arr) / sizeof(int);
  shellSort(arr, n);
  printArray(arr, n);
  return 0;

}


void printArray(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", arr[i]);
  }
}

void shellSort(int arr[], int n){
  for(int gap = n/2; gap > 0; gap = gap/2){
    for(int j = gap; j <=n; j++){
      for(int i = j-gap; i >= 0; i = i - gap){
        if (arr[i+gap] > arr[i]){
          break;
        }else{
          int temp = arr[i];
          arr[i] = arr[i+gap];
          arr[i+gap] = temp;
        }
      }
    }
  }
}