// https://www.geeksforgeeks.org/problems/word-ladder/1
#include <bits/stdc++.h>
#include "../debug.h"
#include "../ctemplate.h"

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    map<string, int> mp;
    for (auto str : wordList)
    {
        mp[str]++;
    };

    queue<pair<string, int>> q;

    q.push({startWord, 1});

    int ans = INT_MAX;

    while (!q.empty())
    {
        auto f = q.front();
        string str = f.first;
        int length = f.second;

        if (str == targetWord)
        {
            ans = min(ans, length);
        }

        q.pop();

        for (int i = 0; i < str.length(); i++)
        {
            string altStr = str;
            for (int j = 0; j < 26; j++)
            {
                altStr[i] = j + 'a';

                if (mp[altStr] && altStr != str)
                {
                    q.push({altStr, length + 1});
                    mp[altStr]--;
                }
            }
        }
    }

    if (ans == INT_MAX)
        return 0;

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

    write(wordLadderLength(startWord, targetWord, wordList));

    return 0;
}