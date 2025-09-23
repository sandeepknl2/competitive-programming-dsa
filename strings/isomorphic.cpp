class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if(s.length() != t.length()) return false;
        int sToT[256];
        int tToS[256];
        // initialize all mappings to -1
        for(int i = 0; i < 256; i++){
            sToT[i] = -1;
            tToS[i] = -1;
        }
        for(int i = 0; i < s.length(); i++){
            char cs = s[i];
            char ct = t[i];
            // Check mapping s -> t
            if(sToT[cs] == -1){
                sToT[cs] = ct;
            } else if(sToT[cs] != ct){
                return false;
            }
            // Check mapping t -> s
            if(tToS[ct] == -1){
                tToS[ct] = cs;
            } else if(tToS[ct] != cs){
                return false;
            }
        }   return true;
    
    }
};

opyimizwd
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int sPattern[256] = {0};
        int tPattern[256] = {0};
        int count = 1; // assign numbers starting from 1

        for(int i = 0; i < n; i++){
            char cs = s[i];
            char ct = t[i];

            // assign a number if character not seen yet
            if(sPattern[cs] == 0) sPattern[cs] = count;
            if(tPattern[ct] == 0) tPattern[ct] = count;

            // compare assigned numbers
            if(sPattern[cs] != tPattern[ct]) return false;

            count++;
        }

        return true;
    }
};
