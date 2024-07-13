
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses; // Map to count losses for each player
        unordered_set<int> players; // Set to keep track of all players
        
        // Process each match to count losses and register players
        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            losses[loser]++;
            players.insert(winner);
            players.insert(loser);
        }
        
        vector<int> noLosses, oneLoss;
        
        // Determine players with no losses and exactly one loss
        for (int player : players) {
            if (losses.find(player) == losses.end()) {
                noLosses.push_back(player); // Player has no losses
            } else if (losses[player] == 1) {
                oneLoss.push_back(player); // Player has exactly one loss
            }
        }
        
        // Sort results as required
        sort(noLosses.begin(), noLosses.end());
        sort(oneLoss.begin(), oneLoss.end());
        
        return {noLosses, oneLoss};
    }
};
