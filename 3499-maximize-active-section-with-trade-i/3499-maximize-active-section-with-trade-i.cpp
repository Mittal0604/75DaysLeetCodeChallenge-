class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
      int n=s.size();
      int i=0,one=0,lz=0,cz=0,maxi=0;
      while(i<n && s[i]=='1'){
           one++; i++;
      }
      while(i<n && s[i]=='0') lz++, i++;

      while(i<n){
        while(i<n && s[i]=='1')one++, i++;
        if(i==n) return one+maxi;
        while(i<n && s[i]=='0') cz++,i++;
        maxi=max(maxi,cz+lz);
        lz=cz;
        cz=0;
      }  
      return one+maxi;
    }
};