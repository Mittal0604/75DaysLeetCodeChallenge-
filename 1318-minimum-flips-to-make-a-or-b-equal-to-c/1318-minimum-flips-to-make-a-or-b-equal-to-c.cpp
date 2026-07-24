class Solution {
public:
    int minFlips(int a, int b, int c) {
     int count=0;
     int f,s,t;
     for(int i=0;i<32;i++){
        f=a&1;
        s=b&1;
        t=c&1;
        if((f|s)!=t){
            if(t==0 && s==1 && f==1){
                count+=2;
            }
            else{
                count++;
            }
        }
        a/=2; b/=2; c/=2;
     }
     return count;   
    }
};