class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int l = 0,n = fruits.size(),ans = 0;
       vector<int> frq(1e5+1,0);
       int type = 0;
       for(int r = 0; r < n; r++){
        if(frq[fruits[r]] == 0) type++;
        frq[fruits[r]]++;
        while(type > 2) {
            frq[fruits[l]]--;
            if(frq[fruits[l]] == 0) type--;
            l++;
        }
        ans = max(ans,r-l+1);
       }
       return ans;
    }
};