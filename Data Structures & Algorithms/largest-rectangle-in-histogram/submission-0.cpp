class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> s;
        int mx = 0;
        int n = heights.size();
        for(int i=0;i<=n;i++)
        {
            int curr;
            if(i == n)
            {
                curr = 0;
            }
            else
            {
                curr = heights[i];
            }
            while(!s.empty() && curr <= heights[s.back()])
            {
                int height = heights[s.back()];
                s.pop_back();
                int right = i;
                int left;
                if(s.empty())
                {
                    left = -1;
                }
                else
                {
                    left = s.back();
                }
                int width = right - left - 1;
                int area = height * width;
                if(mx < area)
                {
                    mx = area;
                }
            }
            s.push_back(i);
        }
        return mx;
    }
};
