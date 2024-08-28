#include<stdio.h>
#include<stdlib.h>
int findElement(int[], int, int);

int main(){

  int arr[] = {1,3,5,7,9,11,13,14,16,18};
  int n = sizeof(arr)/sizeof(int);
  int target = 7;
  int index = findElement(arr, target, n);
  if(index == -1){
    printf("Element Not Found!");
    return -1;
  }
  printf("The %d is found at index-%d", target, index);
  return 0;
}

/*

# Have two arrows pointing to the start and end of the array
# Find the mid element using the formula { mid = (start+end)/2 }
    # Check if the mid element is equal to the target, if so return mid
    # Check if the mid element is greater than the target, then { end = mid - 1 }
    # Check if the mid element is smaller than the target, then { start = mid + 1 }
# Repeat the same process until start <= end
# If no value is returned, return -1 (which implies that the target is not found)

*/


int findElement(int arr[], int target, int n){

    int start = 0, end = n - 1;
    while(start <= end){
      int mid = start + (end-start)/2;
      if(arr[mid] == target){
        return mid;
      }else  if(arr[mid] > target){
        end = mid - 1;
      }else{
        start = mid + 1;
      }
    }
    return -1;
}