class Solution {
public:
    char findTheDifference(string s, string t) {
      unordered_map<char,int> str;
      for(char i : s){
        str[i]++;
      }
      for(char i : t){
        str[i]--;
        if(str[i] < 0){
            return i;
        }
      }
      return ' ';  
    }
};