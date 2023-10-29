class Solution {
private:
    // int solve(vector<int> &nums1, vector<int> &nums2, int index , bool doSwap){
    //     if( index==nums1.size()){
    //         return 0;
    //     }
    //     int prev1=nums1[index-1];
    //     int prev2=nums2[index-1];
    //     if(doSwap){
    //         swap(prev1,prev2);
    //     }
    //     int ans=INT_MAX;


    //     if(nums1[index]>prev1 && nums2[index]>prev2){
            
    //         ans= solve(nums1,nums2,index+1,false);
    //     }

    //    if(nums1[index]>prev2 && nums2[index]>prev1){
    //        ans=min(ans, 1+solve(nums1,nums2,index+1,true));
    //    }

    //    return ans;
        
    // }

//    int solveMem(vector<int> &nums1, vector<int> &nums2, int index , bool doSwap,vector<vector<int>> &dp){
//         if( index==nums1.size()){
//             return 0;
//         }

//         if(dp[index][doSwap]!=-1){
//             return dp[index][doSwap];
//         }
//         int prev1=nums1[index-1];
//         int prev2=nums2[index-1];
//         if(doSwap){
//             swap(prev1,prev2);
//         }
//         int ans=INT_MAX;


//         if(nums1[index]>prev1 && nums2[index]>prev2){
            
//             ans= solveMem(nums1,nums2,index+1,false,dp);
//         }

//        if(nums1[index]>prev2 && nums2[index]>prev1){
//            ans=min(ans, 1+solveMem(nums1,nums2,index+1,true,dp));
//        }

//        return dp[index][doSwap]=ans;
        
//     }

    int solveTab(vector<int> &nums1, vector<int> &nums2){
        int n=nums1.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));

        int swapp=0;
        int noswap=0;
        int currswap=0;
        int currnoswap=0;
    

        for(int index=n-1;index>=1;index--){
            for(int doSwap=1;doSwap>=0;doSwap--){

                int prev1=nums1[index-1];
                int prev2=nums2[index-1];
                if(doSwap){
                    swap(prev1,prev2);
                }
                int ans=INT_MAX;


                if(nums1[index]>prev1 && nums2[index]>prev2){
                    
                    ans= noswap;
                }

                if(nums1[index]>prev2 && nums2[index]>prev1){
                    
                ans=min(ans, 1+swapp);
                    
                }

                if(doSwap){
                    currswap=ans;
                }
                else{
                    currnoswap=ans;
                }

            }
            swapp=currswap;
            noswap=currnoswap;
        }

        return min(swapp,noswap);

    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
 
        int n= nums1.size()-1;

        // return solve(nums1,nums2, 1,false);
        // vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));
        // return solveMem(nums1,nums2,1,false,dp);

        return solveTab(nums1,nums2);
    }
};