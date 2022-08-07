/*
 * Jesse@FDU-VTS-MIA
 * created @date: 2022-08-07
 * brief: 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>> st;
        vector<int> time(n, 0);
        for (auto &log : logs) {
            char type[10];
            int idx, timestamp;
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's') {
                if (!st.empty()) {
                    time[st.top()[0]] += timestamp - st.top()[1];
                    st.top()[1] = timestamp;
                }
                vector<int> tmp{idx, timestamp};
                st.emplace(tmp);
            } else {
                auto curr = st.top();
                st.pop();
                time[curr[0]] += timestamp - curr[1] + 1;
                if (!st.empty()) {
                    st.top()[1] = timestamp + 1;
                }

            }

        }
        return time;
    }
};


int main() {

}