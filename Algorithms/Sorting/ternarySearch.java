public class ternary_search {
    private static int ternarySearch(int[] arr, int target) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            
            int mid1 = start + (end - start) / 3;
            int mid2 = end - (end - start) / 3;

            // returns the index of the target element 
            if (arr[mid1] == target) {
                return mid1;
            } else if (arr[mid2] == target) {
                return mid2;
            }

            
            if (target < arr[mid1]) {
                end = mid1 - 1;
            } else if (target > arr[mid2]) {
                start = mid2 + 1;
            } else {
                start = mid1 + 1;
                end = mid2 - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
        int target = 23;
        int foundIndex = ternarySearch(arr, target);
        if (foundIndex != -1) {
            System.out.println("The target is found in the index: " + foundIndex);
        } else {
            System.out.println("The target is not found in the array.");
        }
    }
}
