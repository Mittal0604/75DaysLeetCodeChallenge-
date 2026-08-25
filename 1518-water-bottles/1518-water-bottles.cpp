class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles; 
        while(numBottles >= numExchange){
            int newB= numBottles / numExchange;
            int left= numBottles % numExchange;
            ans = ans + newB;
            numBottles= newB + left;
        }
       return ans;
    }
};