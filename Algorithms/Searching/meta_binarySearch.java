public class meta_binary_search {
    private static int meta_binarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

       while (start <= end && target >= arr[start] && target <= arr[end]) {
            
          int mid = start + (((target - arr[start]) * (end - start)) / (arr[end] - arr[start]));

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {7, 13, 34, 43, 54,  76};
        int target = 43;
        int foundIndex = meta_binarySearch(arr, target);
        if (foundIndex != -1) {
            System.out.println("The target is found in the index: " + foundIndex);
        } else {
            System.out.println("The target is not found in the array.");
        }
    }
}
