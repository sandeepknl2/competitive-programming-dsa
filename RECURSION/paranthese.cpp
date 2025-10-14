#include <bits/stdc++.h>
using namespace std;

bool isValid(const string &s) {
    int openP = 0, openB = 0;
    for(char c : s){
        if(c=='(') openP++;
        else if(c==')') openP--;
        else if(c=='{') openB++;
        else if(c=='}') openB--;
        if(openP<0 || openB<0) return false;
    }
    return openP==0 && openB==0;
}

int main() {
    int N=1, M=2;
    vector<char> brackets = {'(',')','{','}'};

    for(char a : brackets)
    for(char b : brackets)
    for(char c : brackets)
    for(char d : brackets)
    for(char e : brackets)
    for(char f : brackets) {
        string s = "";
        s += a; s += b; s += c; s += d; s += e; s += f;

        int countP = count(s.begin(), s.end(), '(') + count(s.begin(), s.end(), ')');
        int countB = count(s.begin(), s.end(), '{') + count(s.begin(), s.end(), '}');

        if(countP == 2*N && countB == 2*M && isValid(s))
            cout << s << endl;
    }
    return 0;
}



bavktrack
#include <bits/stdc++.h>
using namespace std;

void backtrack(string &current, int openP, int closeP, int openB, int closeB, int N, int M) {
    // Base case: sequence is complete
    if (current.size() == 2 * N + 2 * M) {
        cout << current << endl;
        return;
    }

    // Add '(' if we have remaining '('
    if (openP < N) {
        current.push_back('(');
        backtrack(current, openP + 1, closeP, openB, closeB, N, M);
        current.pop_back();
    }

    // Add ')' if there are unmatched '('
    if (closeP < openP) {
        current.push_back(')');
        backtrack(current, openP, closeP + 1, openB, closeB, N, M);
        current.pop_back();
    }

    // Add '{' if we have remaining '{'
    if (openB < M) {
        current.push_back('{');
        backtrack(current, openP, closeP, openB + 1, closeB, N, M);
        current.pop_back();
    }

    // Add '}' if there are unmatched '{'
    if (closeB < openB) {
        current.push_back('}');
        backtrack(current, openP, closeP, openB, closeB + 1, N, M);
        current.pop_back();
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    string current = "";
    backtrack(current, 0, 0, 0, 0, N, M);

    return 0;
}
