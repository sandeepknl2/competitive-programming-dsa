cpp
class Solution {
public:
    int value(char r){
        if(r == 'I'){
            return 1;
        }
        if(r == 'V'){
            return 5;
        }
        if(r == 'X'){
            return 10;
        }
        if(r == 'L'){
            return 50;
        }
        if(r == 'C'){
            return 100;
        }
        if(r == 'D'){
            return 500;
        }
        if(r == 'M'){
            return 1000;
        }
        return -1;
    }
    int romanToInt(string s) {
        int n = s.size();

        int result =0;
        for(int i=0; i<n; i++){

            int s1=value(s[i]);

            if(i+1<n){

                int s2 = value(s[i+1]);
                
                if(s1>=s2){
                    result += s1;
                }
                else{
                    result += (s2-s1);
                    i++; //skip next symbol as 2 symbols are used to get value;
                }
            }
            else{
                result += s1;
            }
        }
        return result;
    }
};


optimize

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> roman = {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
            {"C", 100}, {"D", 500}, {"M", 1000},
            {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90},
            {"CD", 400}, {"CM", 900}
        };
        
        int i = 0, n = s.size(), result = 0;
        
        while (i < n) {
            if (i + 1 < n && roman.count(s.substr(i, 2))) {
                result += roman[s.substr(i, 2)];
                i += 2; // skip two characters
            } else {
                result += roman[string(1, s[i])];
                i++;
            }
        }
        
        return result;
    }
};
