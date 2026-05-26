class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=0;
        for(int x:piles) maxi=max(x,maxi);
        int left=1, right=maxi, ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(valid(piles,mid,h)){
                ans=mid; right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    bool valid(vector<int>& piles, int speed, int h){
        int hr=0;
        for(int x:piles){
            hr+=x/speed;
            if(x%speed!=0) hr++;
            if(hr>h) return false;
        }
        if(hr<=h) return true;
        return false;
    }
};