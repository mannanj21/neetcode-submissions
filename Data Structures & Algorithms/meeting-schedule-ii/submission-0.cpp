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
        map<int,int> mp;

        int n = intervals.size();

        for(int i = 0; i < n; i++){
            if(mp.find(intervals[i].start) == mp.end()){
                mp[intervals[i].start] = 1;
            }else{
                mp[intervals[i].start]++;
            }
            if(mp.find(intervals[i].end) == mp.end()){
                mp[intervals[i].end] = -1;
            }else{
                mp[intervals[i].end]--;
            }
        }

        int count = 0;
        int maxdays = 0;

        map<int,int>::iterator it = mp.begin();

        while(it != mp.end()){
            count += it->second;
            maxdays = max(maxdays,count);
            it++;
        }

        return maxdays;

    }
};
