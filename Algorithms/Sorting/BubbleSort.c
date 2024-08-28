#include<stdio.h>

void bubbleSort(int[], int);
void printArray(int[], int);

int main(){

  int nums[] = {2,3,4,5,6,23,11,1,3,4};
  int n = sizeof(nums)/sizeof(int);
  printf("%d \n", n);
  bubbleSort(nums, n);
  printArray(nums, n);

  return 0;
}

void bubbleSort(int nums[], int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<n-i-1; j++){
      if (nums[j+1]<nums[j]){
        int temp = nums[j+1];
        nums[j+1] = nums[j];
        nums[j] = temp;
      }
    }
  }
}


void printArray(int nums[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", nums[i]);
  }
}