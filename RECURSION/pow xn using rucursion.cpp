class Solution {
public:

double isPowX(double x,long n){
 if(n==0) return 1.0;

        double half = isPowX(x, n / 2);

        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
    
   //  return x * isPowX(x, n - 1);-------->RTE



    double myPow(double x, int n) {
    //    double res=1.0;
    //    long long exp=n;
    //    if(exp<0){
    //     x=1/x;
    //     exp=-exp;
    //    }
    //    while(exp>0){
    //         res*=x;
    //         exp--;
    //    }
     //  return res;
      long long exp=n;
             if(exp<0){
         x=1/x;
         exp=-exp;
        }
return isPowX(x,exp);

    }
};