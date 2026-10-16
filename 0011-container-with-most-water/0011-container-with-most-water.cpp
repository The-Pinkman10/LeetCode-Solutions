class Solution {
public:
    int maxArea(vector<int>& height) {
        int k = 0;
        int l = height.size() - 1;
        int maxArea = 0;

        while (k < l) {
            int area = (l - k) * min(height[k], height[l]);
            maxArea = max(area, maxArea);

            if (height[k] < height[l]) {
                k++;
            } else {
                l--;
            }
        }

        return maxArea;
    }
};