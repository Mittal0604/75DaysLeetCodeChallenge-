class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long maxsum= sumSubarrayMaxs(nums);
        long long minsum= sumSubarrayMins(nums);
        return maxsum - minsum;
    }
     long long sumSubarrayMins(vector<int>& nums) {
     vector<int> nse=findNSE(nums);
     vector<int> pse=findPSE(nums);
      long long total1=0;
      for(int i=0;i<nums.size();i++){
        long long left=i-pse[i];
        long long right=nse[i]-i;
        total1=(total1+(right*left*nums[i]));
      }
      return total1;  
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
     long long sumSubarrayMaxs(vector<int>& nums){
        vector<int> nge=findNGE(nums);
        vector<int> pge=findPGE(nums);
        long long total2=0;
        for(int i=0;i<nums.size();i++){
        long long left=i-pge[i];
        long long right=nge[i]-i;
        total2=(total2+(right*left*nums[i]));
      }
      return total2;  
     }
      vector<int> findNGE(vector<int>& nums) {
        int n=nums.size();
       vector<int> next_greater(n); 
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            
            next_greater[i]=st.empty() ? n : st.top();
            
            st.push(i);
        }
        return next_greater;
     }
     vector<int> findPGE(vector<int>& nums) {
        int n=nums.size();
       vector<int> prev_greater(n); 
        stack<int> st;
        for (int i = 0; i <n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            
            prev_greater[i]=st.empty() ? -1 : st.top();
            
            st.push(i);
        }
        return prev_greater;
     }
};