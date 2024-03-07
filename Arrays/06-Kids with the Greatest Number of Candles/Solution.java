import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
      int max=Integer.MIN_VALUE;
      ArrayList<Boolean> ans =  new ArrayList<Boolean>();
      for(int i=0;i<candies.length;i++){
          if(candies[i]>max){
              max=candies[i];
          }
      }
      for(int i=0;i<candies.length;i++){
          int sum=0;
          sum=candies[i]+extraCandies;
          if(sum>=max){
              ans.add(true);
          }
          else 
         ans.add(false);
      }
      return ans;
  }
}