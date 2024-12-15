#include <bits/stdc++.h>
using namespace std;
	bool cmp (pair <int ,int> a, pair <int ,int> b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first < b.first;
	}
class Solution {
public:
	

    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        vector <pair <int , int > > v;
        for (int i = 0 ; i < nums.size(); i++) {
        	v[i].first = nums[i];
        	v[i].second = i;
		}
        sort(v.begin(), v.end(), cmp);
        while (true) {
        	if (v[i].first + v[j].first > target) {
        		j--;
			} else if (v[i].first + v[j].first < target){
				i++;
			} else {
				return {v[i].second, v[j].second};
			}
			
		}
		return {};
    }
}; 
