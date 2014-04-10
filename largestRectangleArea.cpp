class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        
        if (height.size() == 0)
            return 0;
    
        int maxArea = 0;
        stack<int> stackHeight;
        stack<int> stackIndex;
    
        for (int i = 0; i < height.size(); i++) 
        {
            //case 1
            if (stackHeight.empty() || height[i] > stackHeight.top()) 
            {
                stackHeight.push(height[i]);
                stackIndex.push(i);
            } 
            else if (height[i] < stackHeight.top()) 
            {
	            // case 3
	            int lastIndex = 0;
	            while (stackHeight.empty() == false && height[i] < stackHeight.top()) 
                {
	        	    lastIndex = stackIndex.top();
                    stackIndex.pop();
                
                
	                int tempArea = stackHeight.top() * (i - lastIndex);
                    stackHeight.pop();
	                if (maxArea < tempArea) 
                    {
	                    maxArea = tempArea;
	                }
	            }
                stackHeight.push(height[i]);
                stackIndex.push(lastIndex);
            }
        }
    
        while(stackHeight.empty() == false) 
        {
            int tempArea = stackHeight.top() * (height.size() - stackIndex.top());
            stackHeight.pop();
            stackIndex.pop();
        
            if (tempArea > maxArea) 
            {
                maxArea = tempArea;
            }
        }
        return maxArea;
    }
        
};
