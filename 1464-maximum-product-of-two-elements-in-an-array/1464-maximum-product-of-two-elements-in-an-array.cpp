class Solution {
public:
    int maxProduct(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int p=(arr[arr.size()-1]-1)*(arr[arr.size()-2]-1);
        int q=arr[0]-1 * arr[arr.size()-1]-1;
        return max(p,q);
    }
};