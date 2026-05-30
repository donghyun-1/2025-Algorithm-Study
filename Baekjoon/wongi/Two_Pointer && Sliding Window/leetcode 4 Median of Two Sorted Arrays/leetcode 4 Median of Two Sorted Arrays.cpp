class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double answer;

        int num1S = nums1.size();
        int num2S = nums2.size();
        bool even = false;
        vector<double> arr;
        int midnum = (num1S + num2S) / 2;
        if ((num1S + num2S) % 2 == 0)
        {
            even = true;
        }
        int idxF = 0;
        int idxS = 0;
        int cur = 0;
        while (cur != midnum + 1)//중간값 찾을때 stop
        {
            // nums1 다 쓴 경우
            if (idxF >= num1S)
            {
                arr.push_back(nums2[idxS]);
                idxS++;
            }
            // nums2 다 쓴 경우
            else if (idxS >= num2S)
            {
                arr.push_back(nums1[idxF]);
                idxF++;
            }
            else if (nums1[idxF] < nums2[idxS])
            {
                arr.push_back(nums1[idxF]);
                idxF++;
            }
            else
            {
                arr.push_back(nums2[idxS]);
                idxS++;
            }
            cur++;
        }
        if (even)
        {
            answer = (arr[midnum - 1] + arr[midnum]) / 2;
        }
        else
        {
            answer = arr[midnum];
        }
        return answer;

    }
};