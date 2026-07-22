class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int total = 0;

        for (int i = 0; i < k; i++)
            total += cardPoints[i];

        int maxpoints = total;

        for (int i = 0; i < k; i++) {

            total -= cardPoints[k - 1 - i];   // remove from left
            total += cardPoints[n - 1 - i];   // add from right

            maxpoints = max(maxpoints, total);
        }

        return maxpoints;
    }
};