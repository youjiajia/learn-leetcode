#include <stdio.h>
#include <vector>
#include <algorithm>

bool cmp(const std::pair<int, int> &a, const std::pair<int, int> &b){
    return a.first < b.first;
}

class Solution {
public:
    int findMinArrowShots(std::vector<pair<int, int>>& points) {
        if(points.size() ==0){return 0;}
        std::sort(points.begin(), points.end(), cmp);
        int shootnum = 1;
        int shootbegin = points[0].first;
        int shootend = points[0].second;
        for(int i=1;i<points.size();i++){
            if(points[i].first>shootend){
                shootnum++;
                shootbegin = points[i].first;
                shootend = points[i].second;
                continue;
            }
            shootbegin = points[i].first;
            if(points[i].second<shootend){
                shootend = points[i].second;
            }
        }
        return shootnum;
    }
};