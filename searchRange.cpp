class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector <int> result(2,-1);
        int low=0,high=n-1,mid=n/2;
        while(low<high)
        {
            if(A[mid]==target)
            break;
            else if(A[mid]>target)
            {
                high=mid-1;
                mid=(low+high)/2;
            }
            else if(A[mid]<target)
            {
                low=mid+1;
                mid=(low+high)/2;
            }
        }
        if(A[mid]==target)
        {
            high=mid;
            low=mid;
            while(A[--low]==target && low >-1);//边界处理 要特别担心
            
            while(A[++high]==target && high<n);//边界处理 要特别担心
            result[0]=++low;
            result[1]=--high;
        }
        return result;
    }
};
