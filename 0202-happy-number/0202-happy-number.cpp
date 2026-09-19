class Solution {
public:
    bool isHappy(int n) {
        int i = 0;
        unordered_set<int> set;
        while(!set.count(n)){
            int sum = 0;
            set.insert(n);
            while(n!=0){
                sum = sum + (n%10)*(n%10);
                n /= 10;
            }
            if(sum == 1) return true;
            n = sum;
        }
        return false;
    }
};