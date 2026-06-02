class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        int sum=0,rem;
        while(num>0){
            rem=num%10;
            sum=sum+rem;
            num/=10;
        }
        if (sum>=10){
            int result=addDigits(sum);
            return result;
        }
        return sum;
    }
};