#include "test.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size()){
            return {newInterval};
        }
        int n = intervals.size();
        int index = 0;
        vector<vector<int>>ans;
        while(index < n && intervals[index][1] < newInterval[0]){
            ans.push_back(intervals[index]);
            index++;
        }
        while(index<n && intervals[index][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[index][0]);
            newInterval[1] = max(newInterval[1], intervals[index][1]);
            index++;
        }
        ans.push_back(newInterval);
        while(index<n){
            ans.push_back(intervals[index++]);
        }
        return ans;
    }
};