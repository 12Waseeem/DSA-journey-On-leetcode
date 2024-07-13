class Solution {
public:
    int convertTime(string current, string correct) {
        // Convert current time to minutes
        int currMins = 60 * stoi(current.substr(0, 2)) + stoi(current.substr(3, 2));
        // Convert correct time to minutes
        int corrMins = 60 * stoi(correct.substr(0, 2)) + stoi(correct.substr(3, 2));
        // Calculate the difference in minutes
        int diff = corrMins - currMins;
        int operations = 0;
        
        // Perform operations in decreasing order of operation size
        if (diff >= 60) {
            operations += diff / 60;
            diff %= 60;
        }
        if (diff >= 15) {
            operations += diff / 15;
            diff %= 15;
        }
        if (diff >= 5) {
            operations += diff / 5;
            diff %= 5;
        }
        operations += diff; // The remaining difference can be handled with 1-minute operations

        return operations;
    }
};

