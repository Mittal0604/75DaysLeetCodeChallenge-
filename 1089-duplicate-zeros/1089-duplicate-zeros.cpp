class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
      int c = 0, n = arr.size() - 1;
      for(int i = 0; i+c < arr.size()-1; i++){
        if(arr[i] == 0) c++;
      }
        arr.resize(arr.size() - c);
      for(int i = 0; i < arr.size(); i++){
        if(i>=n) break;
        if(arr[i] == 0){
            arr.insert(arr.begin() + (i+1),0);
            i++;
        }
      }  
    }
};