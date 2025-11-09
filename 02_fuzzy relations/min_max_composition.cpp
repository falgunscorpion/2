#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    vector<vector<int>> R = {
        {0,1,0},
        {0,0,1},
        {0,0,0}
    };

    vector<vector<int>> S = {
        {0,1,1},
        {0,0,1},
        {0,0,0}
    };

    vector<vector<int>> RoS(3, vector<int>(3, 0));

    for(int i = 0; i < 3; i++) {
        for(int k = 0; k < 3; k++) {
            vector<int> Min(3);
            for(int j = 0; j < 3; j++) {
                Min[j] = min(R[i][j], S[j][k]);
            }
            RoS[i][k] = max(Min[0], max(Min[1], Min[2]));
        }
    }

    cout << "R o S (Min-Max Composition):" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << RoS[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
