#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void solveJobSequance(int jobs[][2], int totalNumberofJobs,  int timeSlot[]) {

    string jobSequance;
    int profit = 0;

    for(int i = 0; i < totalNumberofJobs; i++) {
        if( timeSlot[ jobs[i][1] - 1 ] == 0) {
            timeSlot[ jobs[i][1] - 1 ] = 1;
            stringstream s;
            s << "job" << i << " ";
            jobSequance.append(s.str());
            profit = profit + jobs[i][0];
        } else {
            for(int j = jobs[i][1] - 1; j >= 0; j--) {
                if(!timeSlot[j]) {
                    timeSlot[j] = 1;
                    stringstream s;
                    s << "job" << i << " ";
                    jobSequance.append(s.str());
                    profit = profit + jobs[i][0];
                    break;
                }      
            }
        }
    }


    cout << jobSequance << endl << profit;
}


int main() {

    //we are asuming maximum to minimum profit order
    
    int jobs[][2] = { {20, 2}, {15, 2}, {10, 1}, {5, 3}, {1, 3} };
    int totalNumberofJobs = 5;
    int timeSlot[3] = {0, 0, 0}; //because maximum wait is 3

    solveJobSequance(jobs, totalNumberofJobs, timeSlot);    

    return 0;
}
