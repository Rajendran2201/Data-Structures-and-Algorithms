/*
        CODE FOR SELECTION SORT 

        * It is a sorting technique which takes a time complexity of O(n^2) as it has to traverse the array with two loops 

        
*/


public class selectionSort {

    static void sort(int[] arr){
       
        for(int i=0;i<arr.length-1;i++){    
            int min = i ;
            for(int j=i+1;j<arr.length;j++){    //This loop is to find the smallest element in the unsorted array
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
            int temp = arr[i];    //Swapping of the minimum value in its respective place
            arr[i] = arr[min];
            arr[min] = temp;
        }
       
    }
    public static void main(String[] args) {
    
        int[] arr = {8,9,7,6,4,5,3,1,2};
        sort(arr);
        System.out.print("The array after sorting: ");
        for (int element : arr) {
            System.out.print(element + " ");
        }
    }
}
