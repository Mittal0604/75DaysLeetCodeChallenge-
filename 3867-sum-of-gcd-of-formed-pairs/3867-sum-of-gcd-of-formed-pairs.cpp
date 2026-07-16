class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n);
        p[0] = nums[0];
        for (int i = 1;i<n;i++) {
            p[i] = max(p[i-1],nums[i]);
        }
        for (int i = 0;i<n;i++) {
            p[i] = gcdd(p[i],nums[i]);
        }
        sort(p.begin(),p.end());
        long long ans = 0;
        int l = 0 , r = n-1;
        while (l<r) {
            ans += gcdd(p[l],p[r]);
            l++; r--;
        }
        return ans;
    }
    int gcdd(int a , int b) {
        while (b != 0) {
            int rem = a%b;
            a = b;
            b = rem;
        }
        return a;
    }
};