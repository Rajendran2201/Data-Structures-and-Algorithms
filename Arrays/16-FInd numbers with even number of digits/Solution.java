class Solution {
  public int findNumbers(int[] arr) {
      int count=0;
      for(int i=0;i<arr.length;i++){
          if(evendigits(arr[i])){
              count++;
          }
      }
      return count;  
  }
   static boolean evendigits(int num){
      int ans=digits(num);
      if(ans%2==0){
          return true;
      }
      return false;
  }
static  int digits(int num){
      int count=0;
      while(num>0){
          count++;
          num/=10;
      }
      return count;
  }
}
