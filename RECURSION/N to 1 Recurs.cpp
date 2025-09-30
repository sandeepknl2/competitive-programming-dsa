class Solution {
  public:
  
  void printN(int N,int I){
      if(I>N)
      return;
      
       printN(N,I+1);
      cout<<I<<" ";
     
  }
    void printNos(int N) {
        // code here
        int i=1;
        printN(N,i);
        
    }
};