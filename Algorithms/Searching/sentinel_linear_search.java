public class sentinal_linear_search {
  public static void main(String[] args) {
    int arr[] = {3,8,3,6,3,2,1};
    int target = 8;
    int result_index = findtarget(arr,target);
    System.out.println("The element is found at "+result_index);
  }

  private static int findtarget(int[] arr, int target) {
        int n = arr.length;
        int last = arr[n-1];

        arr[n-1] = target;

        int i=0;
        while(arr[i] != target){
          i++;
        }

        arr[n-1] = last;

        if(i<n && arr[i] == target){
          return i;
        }
    return -1;
  }
}
