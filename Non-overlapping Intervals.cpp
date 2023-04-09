class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int left=0, right=1;
        int count=0;

        while(right < n) {

            // Case 1 : Non overlapping intervals
            if(intervals[left][1] <= intervals[right][0]) {
                left=right;
                right++;
            }

            // Case 2 : Overlapping (Remove right interval)
            else if(intervals[left][1] <= intervals[right][1]) {
                count++;
                right++;
            }

            // Case 3 : Overlapping (Remove left interval)
            else if(intervals[left][1] > intervals[right][1]) {
                count++;
                left=right;
                right++;
            }
        }

        return count;
    }
};
