class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int maxWater = 0;
        while(left<right){
            int length = right - left;
            int width = min(heights[left],heights[right]);
            maxWater = max(maxWater,length*width);
            if(heights[left]<heights[right]) left++;
            else right--;
        }
        return maxWater;
    }
};
