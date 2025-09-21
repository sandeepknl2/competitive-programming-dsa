   double myPow(double x, int n) {
        long long  exp=n;
        int s=n;
        if(n<0){
        exp=-exp;
        }
    double prod=1;
      
        while(exp>0){
            
            prod*=x;
            exp--;
        }
        if(n<0)
        return 1/prod;   
      else
      return prod;
      
    }

TLe

optimized
class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;   // avoid overflow for -INT_MIN
        if (exp < 0) {
            x = 1 / x;       // flip base if negative power
            exp = -exp;      // make exponent positive
        }

        double prod = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {   // if exponent is odd
                prod *= x;
            }
            x *= x;               // square the base
            exp /= 2;             // halve the exponent
        }

        return prod;
    }
    
};