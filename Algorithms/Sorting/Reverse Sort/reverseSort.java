
import java.util.Arrays;
class reverseSort {
    public static void main(String[] args) {
       int arr[] ={1,6,5,4,3,2};
       int step = 0;
       int lastIndex = arr.length -1;
       while(step <= lastIndex){
            int minIndex = findMinimum(arr,step, lastIndex);
            arr = reverse(arr,step, minIndex);
            step++;
       }
      System.out.println(Arrays.toString(arr));
    }
    
    public static int findMinimum(int arr[],int start, int end){
        int minIndex = -1, minimum = arr[start];
        for(int i=start; i<=end; i++){
            if (arr[i]<minimum){
                minimum = arr[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    
    public static int[] reverse(int arr[], int start, int lastIndex){
        while(start <= lastIndex){
            int temp = arr[start];
            arr[start] = arr[lastIndex];
            arr[lastIndex] = temp;
            start++;
            lastIndex--;
        }
        
        return arr;
    }
    
    
    
    
    
}

