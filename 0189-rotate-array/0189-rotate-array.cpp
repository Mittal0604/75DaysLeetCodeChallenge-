class Solution {
public:
    void rotate(vector<int>& arr, int k) {
      int n = arr.size();
      if(n == 0) return;
      k = k % n;
      reverse(arr.begin(),arr.end());
      reverse(arr.begin(),arr.begin()+k);
      reverse(arr.begin()+k,arr.end());
    }
};