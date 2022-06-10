class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        // int l=0,h=arr.size()-1,res=-1;
        // while(l<=h)
        // {
        //     int m=(l+h)/2;
        //     if(arr[m]!=arr[m+1] && arr[m]!=arr[m-1])
        //         return arr[m];
        //     else if(arr[m]==arr[m+1] && arr[m]!=arr[m-1])
        //       h=m-1;
        //     else if(arr[m]!=arr[m+1] && arr[m]==arr[m-1])
        //         l=m+1;
        //     else if(arr[m]==arr[l])
        //     {
        //         res=arr[m];
        //         l=m+1;
        //     }
        // }
        // return res;

        // method -2 using XOR operator
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            res = res ^ arr[i];
        }
        return res;
    }
};