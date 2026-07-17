/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray &mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    int binarySearchIncreasing(MountainArray &mountainArr, int low, int high,int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            if (val < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    int binarySearchDecreasing(MountainArray &mountainArr, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target)
                return mid;
            if (val < target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int left = binarySearchIncreasing(mountainArr, 0, peak, target);
        if (left != -1)
            return left;
        return binarySearchDecreasing(mountainArr, peak + 1, mountainArr.length() - 1, target);
    }
};