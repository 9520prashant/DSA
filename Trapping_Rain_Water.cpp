// Brute-Force Approach to solve this Problem is calculate Highest Building of left side and right side as well,
// and Calculate the Trapping water for every building

// T.C->O(N^2) and S.C->O(1) ** It will give TLE on online Ediotor****


    // Function to find the trapped water between the blocks.

    long long trappingWater(int arr[], int n){
        // code here
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            int Lmax=arr[i];
            
                for(int j=0;j<i;j++)
                    Lmax=max(Lmax,arr[j]);
                    
            int Rmax=arr[i];
            
                for(int j=i;j<n;j++)
                    Rmax=max(Rmax,arr[j]);
                    
            ans+=min(Lmax,Rmax)-arr[i];
        }
        return ans;
}

// Optimal Approach -> Insted for Calculating Highest Building of left side and right side for each building we can store the left and right highest building in two arrays
// for every building

// T.C->O(N) and S.C->O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int Lmax[n];
        Lmax[0]=height[0];
        int Rmax[n];
        Rmax[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            int temp=max(height[i],Lmax[i-1]);
            Lmax[i]=temp;
        }
        for(int i=n-2;i>=0;i--){
            int temp=max(height[i],Rmax[i+1]);
            Rmax[i]=temp;
        }

        for(int i=0;i<n;i++){

            ans+=min(Lmax[i],Rmax[i])-height[i];
        }
        return ans;
    }
};
