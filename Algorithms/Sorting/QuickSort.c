#include<stdio.h>

void printArray(int[], int);
void quickSort(int[], int, int);
int partition(int[], int, int);

int main(){
  int nums[] = {15,3,4,5,36,23,11,1,3,4};
  int n = sizeof(nums)/sizeof(int);
  quickSort(nums, 0, n-1);
  printArray(nums, n);
  return 0;
}


void printArray(int nums[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", nums[i]);
  }
}



void quickSort(int nums[], int lb, int ub){
  if (lb < ub){
    int l = partition(nums, lb, ub);
    quickSort(nums, lb, l-1);
    quickSort(nums, l+1, ub);
  }
}


int partition(int nums[], int lb, int ub){

  int pivot = nums[lb];
  int start = lb, end = ub;

  while(start < end){

    while(nums[start] <= pivot ){
      start++;
    }
    while(nums[end] > pivot ){
      end--;
    }

    if(start < end){
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;
    }
  }

  int temp = nums[end];
  nums[end] = nums[lb];
  nums[lb] = temp;

  return end;


}