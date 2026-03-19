class Solution {
public:
    int divide(int dividend, int divisor) {
        int quotient=0;
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
            quotient=dividend/divisor;
            return quotient;
    }
};