class Solution {

    vector<int> findRight(vector<int> arr, int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
  
    vector<int> findLeft(vector<int> arr, int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0;i<n;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        left = findLeft(heights, n);
        vector<int> right(n);
        right = findRight(heights, n);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            if(right[i] == -1){
                right[i] = n;
            }
            int l = heights[i];
            int b = right[i] - left[i] - 1;
            int s = l*b;
            area = max(area, s);
        }
        return area;
    }
};