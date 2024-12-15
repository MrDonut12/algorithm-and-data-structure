#include <bits/stdc++.h>

using namespace std;
#define ll int
#define ii pair <ll, ll>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       
    }
};

bool cmp(ii a, ii b) {
    return (a.first < b.first);
}

vector<int> twoSum(vector<int> nums, int target) {
    vector<ii> v;
    for (int i = 0; i < nums.size(); i++) {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end(), cmp);
    ll i = 0, j = nums.size() - 1;
    while (i < j) {
        ll sum = v[i].first + v[j].first;
        if (sum == target) {
            return {v[i].second, v[j].second};
        }
        else if (sum > target) {
            j--;
        } else if (sum < target) {
            i++;
        }
    }
    return {};
}
int main(){
    ll targ = 9;
    vector<ll> a = {4, 13, 11, 5};
    vector<ll> res = twoSum(a, targ);
    for (int i : res)
        cout << i << " ";
    return 0;

}
