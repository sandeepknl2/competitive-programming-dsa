class Solution {
public:

 int fibnochi(int  n1){
        if(n1==0) return 0;
        if(n1==1) return 1;
        return  fibnochi(n1-1)+ fibnochi(n1-2);
 }
    int fib(int n) {
        // if(n==0) return 0;
        // if(n==1) return 1;
        // int f0=0,f1=1,f2=0;

        // for(int i=2;i<=n;i++){
        //     f2=f0+f1;
        //     f0=f1;
        //     f1=f2;
        // }
        // return f1;

       return   fibnochi(n);
    }
};