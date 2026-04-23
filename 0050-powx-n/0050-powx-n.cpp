class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;  // use long long to avoid overflow for INT_MIN
        if (exp == 0) return 1;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        if (exp % 2 == 0) {
            return myPow(x * x, exp / 2);
        } else {
            return x * myPow(x * x, exp / 2);
        }
    }
};
