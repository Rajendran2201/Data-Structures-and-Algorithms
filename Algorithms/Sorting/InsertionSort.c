#include<stdio.h>
void printArray(int[], int);
void insertionSort(int[], int);


int main(){


  int nums[] = {2,3,4,5,6,23,11,1,3,4};
  int n = sizeof(nums)/sizeof(int);
  insertionSort(nums, n);
  printArray(nums, n);
  return 0;
}

void insertionSort(int nums[], int n){
  for(int i=1; i<n; i++){
    int temp = nums[i];
    int j = i - 1; 
    while(j >= 0 && nums[j] > temp){
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = temp;
  }
}



void printArray(int nums[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", nums[i]);
  }
}