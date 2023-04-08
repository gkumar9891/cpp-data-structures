#include<bits/stdc++.h>
using namespace std;
vector<string > grid(10);
vector<string > words;
char charUsed;

//horizontal functions...

bool isHorz(string word ,int i ,int j){

    if(j-1>=0 && grid[i][j-1]!=charUsed) return false;
    if(j+word.size()<=grid[0].size()-1 && grid[i][j+word.size()]!=charUsed) return false;
    for(int k=0;k<word.size();k++){
        if(j+k>=grid[0].size()) return false;
         
        if(grid[i][j+k]=='-' || grid[i][j+k]==word[k]) continue;
        else return false;
    }
  
    return true;
}

vector<bool > fitHorz(string word ,int i ,int j){
    vector<bool > changed((int )word.size() ,false);
    for(int k=0;k<(int )word.size() ;k++){
        if(grid[i][j+k]=='-'){
            grid[i][j+k]=word[k];
            changed[k]=true;
        }
    }
    return changed;
}

void removeHorz(vector<bool > changed ,int i ,int j){
    for(int k=0;k<(int )changed.size() ;k++){
        if(changed[k]==true) grid[i][j+k]='-';
    }
}

//vertical functions...

bool isVert(string word ,int i,int j){
    if(i-1>=0 && grid[i-1][j]!=charUsed) return false;
    if(( i+(int )word.size() )<=(int )grid.size()-1 && grid[i+(int )word.size()][j]!=charUsed) return false;
    for(int k=0;k<(int )word.size();k++){
        if(i+k>=(int )grid.size()) return false;
        if(grid[i+k][j]=='-' || grid[i+k][j]==word[k]) continue;
        else return false;
    }
    return true;
}

vector<bool > fitVert(string word ,int i ,int j){
    vector<bool > changed((int )word.size() ,false);
    for(int k=0;k<(int )word.size();k++){
        if(grid[i+k][j]=='-'){
            grid[i+k][j]=word[k];
            changed[k]=true;
        }
    }
    return changed;
}

void removeVert(vector<bool > changed ,int i ,int j){
    for(int k=0;k<(int )changed.size();k++){
        if(changed[k]==true) grid[i+k][j]='-';
    }
}

//recurse fill function...
void fill(int level){
    if(level==(int )words.size()){
        for(auto w:  grid) cout<<w<<endl;
        return ;
    }
  
    string word=words[level];
    for(int i=0;i<(int )grid.size();i++){
        for(int j=0;j<(int )grid[0].size();j++){
            if(grid[i][j]=='-' || grid[i][j]==word[0]){
                
                if(isHorz(word ,i ,j)){
                    vector<bool > changedH=fitHorz(word ,i,j);
                    fill(level+1);
                    removeHorz(changedH ,i ,j);
                }
                if(isVert(word ,i ,j)){
                    vector<bool > changedV=fitVert(word ,i ,j);
                    fill(level+1);
                    removeVert(changedV ,i ,j);
                }
            }
        }
        
    }
    return ;
}


//main fun...
int main(){
    // for(int i=0;i<(int )grid.size();i++) cin>>grid[i];

    // grid[0] = "++++";
    // grid[1] = "+--+";
    // grid[2] = "++-+";
    // grid[3] = "++++";

    grid[0] = "+-++++++++";
    grid[1] = "+-++-+++++";
    grid[2] = "+-------++";
    grid[3] = "+-++-+++++";
    grid[4] = "+-++-+++++";
    grid[5] = "+-++-+++++";
    grid[6] = "++++-+++++";
    grid[7] = "++++-+++++";
    grid[8] = "++++++++++";
    grid[9] = "----------";

    for(int i=0;i<grid[0].size();i++){
        if(grid[0][i]!='-') {
            charUsed=grid[0][i];
            break;
        }
    }
//    cout<<charUsed<<endl;
    
    string s = "CALIFORNIA;NIGERIA;CANADA;TELAVIV";
    // cin>>s;
    string tmp="";
    for(int i=0;i<(int )s.size();i++){
        if(s[i]==';'){
            words.push_back(tmp);
            tmp="";
        }
        else tmp+=s[i];
    }
    words.push_back(tmp);
//    for(auto wo:words)cout<<wo<<" ";
    
    fill(0);
    
    return 0;
}