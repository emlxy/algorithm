#include "stdafx.h"
#include <vector>

class Solution004 {
public:
    void test()
    {
        vector<int> nums1 = {1,2 };
        vector<int> nums2 = { 3, 4};

        double n = findMedianSortedArrays(nums1, nums2);
        int a = 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len1 > len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left1,right1;
        int left2,right2;
        int low = 0, hi = len1*2;
        int c1, c2;

        while(low <= hi)
        {
            c1 = low+(hi-low)/2;
            c2 = len1+len2-c1;

            left1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
            right1 = c1==2*len1 ? INT_MAX : nums1[c1 / 2];

            left2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
            right2 = c2==2*len2 ? INT_MAX : nums2[c2 / 2];

            if(left1 > right2)
            {
                hi = c1-1;
            }
            else if(left2 > right1)
            {
                low = c1 + 1;
            }
            else
                break;
        }
        return (max(left1, left2) + min<int>(right1, right2) )/2.0;
    }
};


/*  leetcode 通过  */
/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if (len1 > len2)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int left1, right1;
        int left2, right2;
        int low = 0, hi = len1 * 2;
        int c1, c2;

        while (low <= hi)
        {
            c1 = low + (hi - low) / 2;
            c2 = len1 + len2 - c1;

            left1 = c1 == 0 ? INT_MIN : nums1[(c1 - 1) / 2];
            right1 = c1 == 2 * len1 ? INT_MAX : nums1[c1 / 2];

            left2 = c2 == 0 ? INT_MIN : nums2[(c2 - 1) / 2];
            right2 = c2 == 2 * len2 ? INT_MAX : nums2[c2 / 2];

            if (left1 > right2)
            {
                hi = c1 - 1;
            }
            else if (left2 > right1)
            {
                low = c1 + 1;
            }
            else
                break;
        }
        return (max(left1, left2) + min(right1, right2)) / 2.0;
    }
};
*/

