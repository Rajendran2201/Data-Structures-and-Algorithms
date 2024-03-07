/*
        CODE FOR INSERTION SORT

Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. 
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.

*/


public class insertionSort {
    public static void main(String[] args) {
        int[] arr = {8,9,7,6,4,5,3,1,2};
        sort(arr);
        System.out.print("The array after sorting: ");
        for (int element : arr) {
            System.out.print(element + " ");
        }
       
    }

    private static void sort(int[] arr) {

        for(int i=1;i<arr.length;i++){ 
            //we assume that the first element of the array is already sorted such that we start out traversal from second element

            int key = arr[i]; // We are taking a duplicate of out current element
            int j= i-1; // j represent the index of the last element of the sorted array
            
            while(j>=0 && arr[j]>key){ 
                // The first condition ensures that the pointer doesn't go to negative values such that array begins with the initial index of zero
                // The second condition checkas whether the current element is smaller than the element in the sorted array,
                        // If yes , then elements in the sorted array are shifted towards rightside once and this process is continued until the condition returns false
                
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;        // Finally our current element is placed in its respective position
        }
    }
}
