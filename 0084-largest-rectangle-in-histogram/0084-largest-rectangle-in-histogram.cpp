class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
        int n=heights.size();
        stack<int>st;
        for(int i=0;i<n;i++)
        {
                while(!st.empty() && heights[i]<=heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int curr=(st.empty()?i:i-st.top()-1);
                maxarea=max(maxarea,curr*h);
                }
                st.push(i);
        }
        while(!st.empty()){
            int h=heights[st.top()];
            st.pop();
            int curr=(st.empty()?n:n-1-st.top());
            maxarea=max(maxarea,curr*h);
        }
        
        return maxarea;
    }
};