class Solution {
  public int[] getConcatenation(int[] nums) {
      int[] ans = new int[2 * nums.length];

      int index = 0;
      int first_time = 1;

      for (int i = 0; index < 2 * nums.length; i++) {
          ans[index] = nums[i];

          if (i == nums.length - 1 && first_time == 1) {
              i = -1; // Reset i to 0 for the next iteration
              first_time = 0;
          }

          index++;
      }
      return ans;
  }
}

