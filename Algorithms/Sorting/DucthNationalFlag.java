public class DutchNationalFlag {
    private static void sortColors(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        int mid = 0;

        while (mid <= high) {
            switch (nums[mid]) {
                case 0: 
                    swap(nums, low++, mid++);
                    break;
                case 1: 
                    mid++;
                    break;
                case 2: 
                    swap(nums, mid, high--);
                    break;
            }
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void main(String[] args) {
        int[] nums = {2, 0, 1, 2, 1, 0};
        sortColors(nums);

        System.out.println("Sorted array: ");
        for (int num : nums) {
            System.out.print(num + " ");
        }
    }
}
