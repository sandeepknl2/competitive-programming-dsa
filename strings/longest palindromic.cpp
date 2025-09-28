// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindromic(string s,int a,int b){
    int i=a,j=b;
    while(i<j){
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}

int main() {
   string s="babdd";
   int n=s.size();
   string res="";
   int maxLen = 0, start = 0, end = 0;
   
   for(int i=0;i<n;i++){
      for(int j = i; j < n; j++){
       
       if(isPalindromic(s,i,j) ){
           int currentLen = j - i + 1;
           if(currentLen > maxLen){
               maxLen = currentLen;
               start = i;
               end = j;
           }
       }
      }
   }
   
   // Manual substring creation without substr
   for(int i = start; i <= end; i++){
       res += s[i];
   }
   
   cout << res;
   return 0;
}

 int n = s.size();
        if (n <= 1) return s;
        
        int start = 0, maxLen = 1;
        
        for (int i = 0; i < n; i++) {
            // Check odd length palindromes (center at i)
            int len1 = expandAroundCenter(s, i, i);
            // Check even length palindromes (center between i and i+1)
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
    
private:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }