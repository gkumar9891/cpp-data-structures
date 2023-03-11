#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
 
void inorderTraversal(int root, vector<int> &left, vector<int> &right, vector<int> &vect) {
    if(root == -1) {
        return;
    }
    inorderTraversal(left[root - 1], left, right, vect);
    vect.push_back(root);  
    inorderTraversal(right[root - 1], left, right, vect);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

    vector<int> left;
    vector<int> right;
    for(int i = 0; i < indexes.size(); i++) {
            left.push_back(indexes[i][0]);
            right.push_back(indexes[i][1]);
    }
    vector<vector<int>> twoDArray;

    for(int i = 0; i < queries.size(); i++) {
        int k = queries[i];   
        int level = 0;
        int count = 0;
        queue<int> q;
        q.push(1);
        
        int point = 0;
        while(!q.empty()) {
            level++;
            count = q.size();
            while(count--) {
                q.pop();
                
                if(level % k == 0) {
                    int temp = left[point];
                    left[point] = right[point];
                    right[point] = temp;
                }
                
                if(left[point] != -1) {
                    q.push(left[point]);
                }
                if(right[point] != -1) {
                    q.push(right[point]);
                }
                
                point++;
            }
        }
        
        
        vector<int> vect;
        inorderTraversal(1, left, right, vect);
        twoDArray.push_back(vect);    
    }
    
    return twoDArray; 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
