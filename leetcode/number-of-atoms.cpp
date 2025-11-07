#include <bits/stdc++.h>
#include "../ctemplate.h"

void multiplyNumInStack(stack<pair<string, string>> &st1, int num) {
    stack<pair<string, string>> st2;
    while(st1.top().first != "(") {
        st2.push(st1.top());
        st1.pop();
    }

    st1.pop();

    while(!st2.empty()) {
        pair<string, string> temp;
        temp = st2.top();
        temp.second = stoi(temp.second) * num;

        st1.push({temp.first, temp.second});

        st2.pop();
    }

}

string countOfAtoms(string formula) {
    stack<pair<string, string>> st1;
    map<string, int> mp;

    string str = "";
    string num = "";

    for(char character : formula) {
        if(character >= 'A' && character <= 'Z') {
            str = "";
            str += character;
            num = "";

            st1.push({str, "1"});
        } else if(character >= '2' && character <= '9' ) {
            if(st1.top().first != ")")
                st1.pop();

            num += character;

            if(st1.size() && st1.top().first != ")")
                st1.push({str, num});          
        } else if(character >= 'a' && character <= 'z') {
            st1.pop();
            str += character;
            st1.push({str, num});
        } else {
            if(character == '(') {
                string temps = "";
                temps += character;
                st1.push({temps, ""});
            }

            if(character == ')') {
                pair<string, string> temp;
                temp = st1.top();
                if(temp.first == ")") {
                    st1.pop();
                    multiplyNumInStack(st1, stoi(num));
                }

                num = "";
                str = "";
                st1.push({")", ""});
            }
        }
    }

    return "";
}

int main() {
    string formula;
    cin >> formula;

    write(countOfAtoms(formula));    

    return 0;
}