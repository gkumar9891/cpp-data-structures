#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int plantID; // we label plants from 0 to N - 1
    int daysToDie; // the days a plant needs to die, -1 means it will not die
};

int main()
{
    std::vector<int> pesticides;
    pesticides.push_back(3);
    pesticides.push_back(6);
    pesticides.push_back(2);
    int N = 3;
    // std::cin >> N;
    // for (int i = 0; i < N; i++)
    // {
    //     int pesiticide;
    //     std::cin >> pesiticide;
    //     pesticides.push_back(pesiticide);
    // }

    std::stack<Node> s;
    s.push({ 0, -1 });
    int maxDaysToDie = -1; // the max days needed to die among all the plants
    for (int i = 1; i < N; i++)
    {
        // we only care about the plants whose pesticide is smaller (potential killer)
        int daysToDie = 1;
        while (!s.empty() && pesticides[s.top().plantID] >= pesticides[i])
        {
                // need to wait the front plants to die, like "1 5 4", 4 will die only after 5 died
                daysToDie = std::max(daysToDie, s.top().daysToDie + 1);
                s.pop();
        }
        if (s.empty()) // this means no preceding plants have less pesticide than ith plant
        {
            daysToDie = -1;
        }
        maxDaysToDie = std::max(maxDaysToDie, daysToDie);
        s.push({ i, daysToDie });
    }

    std::cout << (maxDaysToDie < 0 ? 0 : maxDaysToDie) << std::endl;
    return 0;
}