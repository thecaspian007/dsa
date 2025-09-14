class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int multiple = 1, res = 0;
        while (startValue * multiple < target)
            multiple <<= 1, res++;
        int diff = startValue * multiple - target;
        while (diff > 0) {  
            res += diff / multiple;
            diff -= diff / multiple * multiple;
            multiple >>= 1;
        }
        return res;
    }
};