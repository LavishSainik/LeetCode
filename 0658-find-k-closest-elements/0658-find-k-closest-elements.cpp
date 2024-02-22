class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int left = 0;
    int right = arr.size() - 1;
    vector<int> ans;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            right = mid - 1;
        } else if (arr[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    int l = right;
    int r = right + 1;

    for (int i = 0; i < k; i++) {
        if (l >= 0 && r < arr.size()) {
            int floorDiff = x - arr[l];
            int ceilDiff = arr[r] - x;

            if (floorDiff <= ceilDiff) {
                ans.push_back(arr[l]);
                l--;
            } else {
                ans.push_back(arr[r]);
                r++;
            }
        } else if (l >= 0) {
            ans.push_back(arr[l]);
            l--;
        } else if (r < arr.size()) {
            ans.push_back(arr[r]);
            r++;
        }
    }
sort(ans.begin(),ans.end());
    return ans ;
        }
        
       
    
};