#include <bits/stdc++.h>
using namespace std;

pair<int, string> superSequence(string &a, string &b, int m, int n, string str) {
    if(m==-1 || n == -1)
        return {0, str};

    if(a[m] == b[n]) {
        pair<int, string> val = superSequence(a, b, m-1, n-1, a[m] + str);
        val.first++;
        return val;
    } else {
        pair<int, string> val2 = superSequence(a, b, m, n-1, str);
        pair<int, string> val1 = superSequence(a, b, m-1, n, str);

        if(val1.first > val2.first) {
            return val1;
        } 
        return val2;
    }
}

int main() {
    string a = "AGGTAB";
    string b = "GXTXAYB";

    pair<int, string> ans = superSequence(a, b, a.length()-1, b.length()-1, "");
    
    string str = "";
    string lcs = ans.second;

    int ptr1 = 0;
    int ptr2 = 0;
    int ptr3 = 0;

    while(ptr1 < a.length() || ptr2 < b.length()) {

       if(a[ptr1] == b[ptr2]){
           str = a[ptr1] + str;
           ptr1++;
           ptr2++;
           ptr3++;
       }

       if(a[ptr1] != lcs[ptr3]) {
            str = a[ptr1] + str;
            ptr1++;
       }

        if(b[ptr2] != lcs[ptr3]) {
             str = b[ptr2] + str;
             ptr2++;
        }
    }

    while(ptr1 < a.length()) {
        str = a[ptr1] + str;
        ptr1++;
    }

    while(ptr2 < b.length()) {
        str = a[ptr2] + str;
        ptr2++;
    }




    cout << str;

    return 0;
}