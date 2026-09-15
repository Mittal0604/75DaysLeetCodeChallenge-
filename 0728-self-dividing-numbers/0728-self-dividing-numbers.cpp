class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
      vector<int> ans;
      while(left <= right){
       int n = left;
       bool flag = true;
       while(n > 0){
        int d = n % 10;
        if(d == 0){
            flag = false;
            break;
        }
        if(left % d != 0){
            flag = false;
            break;
        }
        n /= 10;
       }
        if(flag) ans.push_back(left);
        left++;
      }
      return ans;  
    }
};