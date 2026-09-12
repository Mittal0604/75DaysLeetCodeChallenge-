class Solution {
public:
    bool isValid(string word) {
      if(word.size() < 3) return false;
      bool Vcheck = false; bool Ccheck = false;
      const string vowels = "aeiouAEIOU";
      for(char ch : word){
        if(!isalnum(ch)) return false;
        if(isalpha(ch)){
            if(vowels.find(ch) != string::npos){
                Vcheck = true;
            }else{
                Ccheck = true;
            }
        }
      }
      return Vcheck && Ccheck;
    }
};