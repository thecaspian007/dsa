class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
        {
            return 0;
        }

        int start = 0;
        int end = x;
        while (start <= end)
        {
            long long mid = start + (end-start)/2;

            if(mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return start-1;
    }
};