class Solution {
public:
    int maxDepth(string s) {
         int n=s.size();
   int cnt=0;
   int ma=0;
   for(int i=0;i<n;i++){
       if(s[i]=='('){
       cnt++;
       ma=max(ma,cnt);
       }
       else if(s[i]==')')
       cnt--;
     
    }
    return ma;
    }
};