/*         CODE FOR LINEAR SEARCH IN ARRAY

Problem: Given an array arr[] of n elements, write a function to search a given element x in arr[]. 

ALGORITHM :
Step 1: Start 
Step 2: Declare an array and search element as key.
Step 3: Traverse the array until the number is found.
Step 4: If the key element is found, return the index position of the array element
Step 5: If the key element is not found, return -1
Step 6: Stop.
 

* Linear search is a type of searching technique which is used to find a specific element in an array 
* It requires O(n) time complexity 
* here , we basically use a for loop inorder to iterate through each element in the array and check if it matches with the target provided
* If the element is matched with the target , then the index of the element is returned.
* If no element in the array is matched with the target , then -1 is returned 


    */
import java.util.Scanner;
public class linearSearch{
    static int search(int[] arr, int target){
        int index = -1;
        for (int i=0;i<arr.length;i++){
            if(arr[i]==target){
                index = i;
            }
        }
        return index;
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9};
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the target value to be searched: ");
        int target = sc.nextInt();
        int index = search(arr,target);
        System.out.println("The index position of "+target+" is "+index);
    }
}
