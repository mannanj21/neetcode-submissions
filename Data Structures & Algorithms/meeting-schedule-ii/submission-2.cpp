/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> v1;
        vector<int> v2;
        for(auto& it : intervals){
            v1.push_back(it.start);
            v2.push_back(it.end);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int cnt = 0;
        int st = 0, ed = 0;
        int ans = 0;
        while(st < intervals.size()){
            if(v1[st] < v2[ed]){
                cnt++;
                ans = max(ans, cnt);
                st++;
            }
            else if(v1[st] > v2[ed]){
                cnt--;
                ed++;
            }
            else{
                ed++;
                st++;
            }
        }
        return ans;
    }
};
