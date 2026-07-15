class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ele=0;
        int nse=0,pse=0;
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                ele=st.top();
                st.pop();
                nse=i;
                pse=st.empty() ? -1 : st.top();
                maxArea=max(maxArea,(heights[ele]*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse=n;
            ele=st.top();
            st.pop();
            pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,(heights[ele]*(nse-pse-1)));
        }
        return maxArea;
    }
};