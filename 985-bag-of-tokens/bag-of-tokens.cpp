class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size() - 1;
        int score = 0;
        int maxScore = 0;
        while (left <= right) {
            if (power >= tokens[left]) {

                power -= tokens[left];
                score++;
                maxScore = max(maxScore, score);
                left++;
            }
            else if (score > 0) {

                power += tokens[right];
                score--;
                right--;
            }
            else {
                break;
            }
        }
        return maxScore;
    }
};