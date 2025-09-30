RECURSION

class Solution {
public:

void  reverse1(vector<char>& s1,int st,int e){
    if(st<e){
    swap(s1[st],s1[e]);
    
     reverse1(s1,st+1,e-1);
    }



}

    void reverseString(vector<char>& s) {
       int i=0,j=s.size()-1;
     
     reverse1(s,i,j);

       
    }
};

in while loop also we can do