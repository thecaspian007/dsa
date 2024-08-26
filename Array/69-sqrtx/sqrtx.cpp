class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
        {
            return 0;
        }

        int start = 0;
        int ans = 0;
        int end = x;

        while(start<=end)
        {
            long long int mid = start + (end-start)/2;
            long long sqr = mid*mid;

            if(sqr == x)
            {
                return mid;
            }
            else if(sqr<x)
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
               end = mid-1; 
            }
        }

        return ans;
    }
};