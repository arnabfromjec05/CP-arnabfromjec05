class Solution {
public:

    // returns smallest element index
    int binSearch(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1, mid;
        while(left < right) {
            mid = (left+right)/2;
            if (nums[mid] < nums[n-1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        mid = (left+right)/2;
        return mid;
    }

    // returns the searched element index or -1
    int binSearch(vector<int>& nums, int start, int end, int target) {
        int left = start, right = end, mid;
        while(left <= right) {
            mid = (left + right)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int smallestEleIndex = binSearch(nums);
        int index1 = binSearch(nums, 0, smallestEleIndex - 1, target);
        int index2 = binSearch(nums, smallestEleIndex, n-1, target);
        if (index1 != -1) {
            return index1;
        } else if (index2 != -1) {
            return index2;
        } else {
            return -1;
        }
    }
};
