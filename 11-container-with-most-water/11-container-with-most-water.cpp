class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxi = INT_MIN;
        while(l<r){
            int heig = min(height[l],height[r]);
            int width = r-l;
            int area = heig*width;
            maxi = max(maxi,area);
            if(height[l]<height[r]) l++;
            else if(height[l]>height[r]) r--;
            else{
                l++;
                r--;
            }
        }
        return maxi;
    }
};