class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=1e5;
        int ans=-1,mid=0;
        while(l<=h){
            mid=(l+h)/2;
            if(valid(quantities,n,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
    bool valid(vector<int>& quantities, int n, int val){
        int count=0;
        for(int x: quantities){
            count+=(x+val-1)/val;
            if(count>n) return false;
        }
        return true;
    }
};