class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  // use long long to avoid overflow for INT_MIN
        if (exp == 0) return 1;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double result=1;
        while(exp){
            if(exp&1) result=x*result;
            x=x*x;
            exp>>=1;
        }
        return result;
    }
};
