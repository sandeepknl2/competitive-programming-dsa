class Solution {
public:

bool isPowTwo(int s,long i){
        if (i == s) return true;
        if (i > s) return false;
   return  isPowTwo(s,i*2);

}
    bool isPowerOfTwo(int n) {
        // if (n==1) return true;
        // long long i=1;
        // int pow =2;
        // while(i<=n){

        //     if(i*pow==n)
        //     return true;
        //     i*=2;
            
        // }
        
        // return false;
               if (n <= 0) return false;  
        return isPowTwo(n, 1); 
    }
};