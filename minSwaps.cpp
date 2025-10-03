class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
        int n=grid.size(),ans;
        vector<int>cnt;
        for(int i=0;i<n;++i)
        {
            int count=0;
            for(int j=n-1;j>=0;--j)
            {
                if(grid[i][j])
                {
                    break;
                }
                else
                {
                    ++count;
                }
            }
            cnt.push_back(count);
        }
        ans=0;
        for(int i=0;i<n;++i)
        {
            if(cnt[i]>=n-1-i)
            {
                continue;
            }
            else
            {
                int k=-1;
                for(int j=i+1;j<n;++j)
                {
                    if(cnt[j]>=n-1-i)
                    {
                        k=j;
                        break;
                    }
                }
                if(k==-1)
                {
                    return -1;
                }
                // for(int j=i;j<k;++j)
                while(k>i)
                {
                    swap(cnt[k],cnt[k-1]);
                    ++ans;
                    --k;
                }
            }
        }
        // for(int i=0;i<n;++i)
        // {
        //     if(cnt[i]<n-1-i)
        //     {
        //         return -1;
        //     }
        // }
        return ans;
    }
};
