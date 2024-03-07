/*
                CODE FOR BUBBLE SORT 

    Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in the wrong order. 
    This algorithm is not suitable for large data sets as its average and worst-case time complexity is quite high.

    * It has a time complexity of O(n^2) runtime as it has to traverse the array with two loops

*/

public class bubbleSort{
    static void sort(int[] arr){
         for(int i=0;i<arr.length;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[j]<arr[i]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
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
