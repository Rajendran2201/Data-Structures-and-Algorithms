#include<stdio.h>

void printArray(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);


int main(){

  int nums[] = {2,3,4,5,6,23,11,1};
  int n = sizeof(nums)/sizeof(int);
  mergeSort(nums, 0, n-1);
  printArray(nums, n);
  return 0;

}

void printArray(int nums[], int n){
  for(int i=0; i<n; i++){
    printf("%d  ", nums[i]);
  }
}

void mergeSort(int nums[], int lb, int ub){
  if(lb<ub){
    int mid = lb + (ub-lb)/ 2;
    mergeSort(nums, lb, mid);
    mergeSort(nums, mid+1, ub);
    merge(nums, lb, mid, ub);
  }
}


void merge(int nums[], int lb, int mid, int ub){
  int n = 10;
  int arr[n]; 
  int i = lb, j = mid+1, k = lb;

  while( i<=mid && j<=ub){
    if (nums[i] <= nums[j]){
      arr[k++] = nums[i++];
    }else if (nums[j] <= nums[i]){
      arr[k++] = nums[j++];
    }
  }

    while(i<=mid){
      arr[k++] = nums[i++];
    }

     while(j<=ub){
      arr[k++] = nums[j++];
    }
  

  for(int a=lb; a<=ub; a++){
    nums[a] = arr[a];
  }
}