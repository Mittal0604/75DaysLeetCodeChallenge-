class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
     vector<int> nse=findNSE(arr);
     vector<int> pse=findPSE(arr);
      long long total=0;
      int mod=1e9+7;
      for(int i=0;i<arr.size();i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;
        total=(total+(right*left*arr[i])%mod)%mod;
      }
      return total;  
    }
     vector<int> findNSE(vector<int>& nums) {
        int n=nums.size();
       vector<int> next_smaller(n); 
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            
            next_smaller[i]=st.empty() ? n : st.top();
            
            st.push(i);
        }
        return next_smaller;
     }
     vector<int> findPSE(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev_smaller(n); 
        stack<int> st;
        for (int i = 0; i <n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            
            prev_smaller[i]=st.empty() ? -1 :st.top();
            
            st.push(i);
        }
        return prev_smaller;
     }
};
