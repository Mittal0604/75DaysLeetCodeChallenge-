class Solution {
    public int maximumWealth(int[][] accounts) {
      int n = accounts.length;
      int ar[] = new int[n];
      int ans = 0;
      for(int i = 0; i < n; i++){
        int sum = 0, p = -1;
        for(int j = 0; j < accounts[i].length; j++){
            sum = sum + accounts[i][j]; 
        }
        ans = Math.max(ans,sum);
        }
      return ans;  
    }
}