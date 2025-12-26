class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;

        for(char c : customers)
            if(c == 'Y') totalY++;

        int penalty = totalY;
        int minPenalty = penalty;
        int bestHour = 0;

        for(int i = 0; i < n; i++) {
            if(customers[i] == 'Y')
                penalty--;
            else
                penalty++;

            if(penalty < minPenalty) {
                minPenalty = penalty;
                bestHour = i + 1;
            }
        }

        return bestHour;
    }
};
