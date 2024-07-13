#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, pair<int, char>>> robots;  // position, (health, direction)
        
        // Create a vector of pairs {position, {health, direction}}
        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], {healths[i], directions[i]}});
        }
        
        // Sort based on positions
        sort(robots.begin(), robots.end());

        stack<pair<int, pair<int, char>>> st;  // Stack to keep track of robots
        for (int i = 0; i < n; i++) {
            auto& current = robots[i];
            if (current.second.second == 'L') {
                while (!st.empty() && st.top().second.second == 'R') {
                    if (st.top().second.first > current.second.first) {
                        st.top().second.first -= 1;
                        current.second.first = 0;
                        break;
                    } else if (st.top().second.first < current.second.first) {
                        current.second.first -= 1;
                        st.pop();
                    } else {
                        st.pop();
                        current.second.first = 0;
                        break;
                    }
                }
                if (current.second.first > 0) {
                    st.push(current);
                }
            } else {
                st.push(current);
            }
        }

        // Mapping to store the final health of robots by their original positions
        unordered_map<int, int> final_health;
        while (!st.empty()) {
            final_health[st.top().first] = st.top().second.first;
            st.pop();
        }
        
        // Prepare the result in the order the robots were given in the input
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (final_health.find(positions[i]) != final_health.end()) {
                result.push_back(final_health[positions[i]]);
            }
        }

        return result;
    }
};
