#include<stdio.h>

void printArray(int[], int);
void selectionSort(int[], int);

int main(){
  int nums[] = {2,3,4,5,6,23,11,1,3,4};
  int n = sizeof(nums)/sizeof(int);
  selectionSort(nums, n);
  printArray(nums, n);
  return 0;
}


void printArray(int nums[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", nums[i]);
  }
}

void selectionSort(int nums[], int n){
  for(int i=0; i<n; i++){
    for(int j = i+1; j<n; j++){
      if (nums[j]<nums[i]){
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }


}