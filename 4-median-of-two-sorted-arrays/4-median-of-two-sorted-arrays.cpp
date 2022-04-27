class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int i=0; 
        int j=0;
        
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
            
        }
        
        while(i<nums1.size()){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            arr.push_back(nums2[j]);
            j++;
        }
        
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
        
        if(n % 2 != 0){
            double ans = arr[n/2];
            return ans;
        }
        else{
            double ans = double((arr[(n/2)-1] + arr[n/2]))/2;
            return ans;
        }
    }
};