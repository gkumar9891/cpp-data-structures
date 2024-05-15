// https://www.geeksforgeeks.org/problems/word-ladder/1
#include <bits/stdc++.h>
#include "../debug.h"
#include "../ctemplate.h"

vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList)
{
    map<string, int> mp, mp2;
    for (auto str : wordList)
    {
        mp[str]++;
    };

    queue<pair<string, pair<vector<string>, map<string, int>>>> q;

    mp2[startWord] = 1;

    q.push({startWord, {{startWord}, mp2}});
    
    
    vector<vector<string>> ans;

    while (!q.empty())
    {
        auto f = q.front();
        string str = f.first;
        vector<string> order = f.second.first;
        map<string, int> mp3 = f.second.second;

        if (str == targetWord)
        {
            if(ans.size() == 0) {
                ans.push_back(order);
            } else if(ans.size() == order.size()) {
                ans.push_back(order);
            }
        }

        q.pop();

        for (int i = 0; i < str.length(); i++)
        {
            string altStr = str;
            for (int j = 0; j < 26; j++)
            {
                altStr[i] = j + 'a';

                if (mp[altStr] && altStr != str && mp3.find(altStr) == mp3.end())
                {
                    mp3[altStr] = 1;
                    order.push_back(altStr);
                    q.push({altStr, {order, mp3}});
                    order.pop_back();
                    mp3[altStr] = 0;
                }
            }
        }
    }

    return ans;
}

int main()
{

    int m;
    string startWord;
    string targetWord;
    read(m);
    vector<string> wordList(m);
    read(wordList);
    read(startWord);
    read(targetWord);

    write(findSequences(startWord, targetWord, wordList));

    return 0;
}