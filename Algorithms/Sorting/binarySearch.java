/*        CODE FOR BINARY SEARCH 

Binary Search is defined as a searching algorithm used in a sorted array by repeatedly dividing the search interval in half. 
The idea of binary search is to use the information that the array is sorted and reduce the time complexity to O(log N). 

In this algorithm, 

    * Divide the search space into two halves by finding the middle index “mid”. 
    * Compare the middle element of the search space with the key/target. 
    * If the key is found at middle element, the process is terminated.
    * If the key is not found at middle element, choose which half will be used as the next search space.
        * If the key is smaller than the middle element, then the left side is used for next search.
        * If the key is larger than the middle element, then the right side is used for next search.
    * This process is continued until the key is found or the total search space is exhausted.


* The point to be noted here is The array has to be *SORTED* to implement a binary search.
* The Binary search algorithm takes O(log n) time complexity inorder to search for an element in an array
* It basically uses the "Divide and Conquer" approach

*/


import java.util.Scanner;

public class binarySearch {
    public static void main(String[] args) {
         int[] arr = {1,2,3,4,5,6,7,8,9};
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the target value to be searched: ");
        int target = sc.nextInt();
        int index = search(arr,target);
        System.out.println("The index position of "+target+" in the array is "+index);
    }

    public static int search(int[] arr, int target) {
        int index = -1;
        int mid;
        int start = 0;
        int end = arr.length-1;

        while(start<=end){
             mid = start + (end-start)/2;
             if(arr[mid]>target){
                end = mid-1;
             }else if(arr[mid]<target){
                start = mid+1;
             }else{
                index = mid;
                break;
             }     
        }
        return index;
    }
}
