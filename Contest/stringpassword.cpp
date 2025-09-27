#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "#2bbbb";
    int n = s.size();

    int Ac = 0, ac = 0, sc = 0, nc = 0;

    // check each character
    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') ac++;
        else if(s[i] >= 'A' && s[i] <= 'Z') Ac++;
        else if(s[i] >= '0' && s[i] <= '9') nc++;
        else sc++;
    }

    // track missing characters
    int missing = 0;
    if(n < 6) {
        missing += 6 - n; // characters to reach length 6
    }
    if(ac == 0) missing++;
    if(Ac == 0) missing++;
    if(nc == 0) missing++;
    if(sc == 0) missing++;

    cout << "Characters needed to make password strong: " << missing << endl;

    // optional: print which types are missing
    if(ac == 0) cout << "Add at least 1 lowercase letter (a-z)" << endl;
    if(Ac == 0) cout << "Add at least 1 uppercase letter (A-Z)" << endl;
    if(nc == 0) cout << "Add at least 1 number (0-9)" << endl;
    if(sc == 0) cout << "Add at least 1 special character (#, @, etc.)" << endl;

    return 0;
}


  string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    int missingTypes = 0;
    bool hasDigit = false, hasLower = false, hasUpper = false, hasSpecial = false;

    for(char c : password) {
        if(numbers.find(c) != string::npos) hasDigit = true;
        else if(lower_case.find(c) != string::npos) hasLower = true;
        else if(upper_case.find(c) != string::npos) hasUpper = true;
        else if(special_characters.find(c) != string::npos) hasSpecial = true;
    }

    if(!hasDigit) missingTypes++;
    if(!hasLower) missingTypes++;
    if(!hasUpper) missingTypes++;
    if(!hasSpecial) missingTypes++;

    // Ensure password length is at least 6
    return max(missingTypes, 6 - n);