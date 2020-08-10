class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left_vals = ((m+n)/2)+1;
        
        #define MIN(X,Y) ((X)<(Y)?X:Y)
        #define MAX(X,Y) ((X)>(Y)?X:Y)
        
        
        int n1 = 0;
        int n2 = 0;
        int int_max = INT_MAX;
        
        int iterating_val;
        int iterating_val2;
        int vals_passed = 0;
        
        nums1.push_back(int_max);
        nums2.push_back(int_max);
        m += 1;
        n += 1;

        
        iterating_val = MAX(nums1[n1], nums2[n2]);
        while(1) {
            iterating_val2 = iterating_val;
            if (nums1[n1] < nums2[n2]) {
                iterating_val = nums1[n1];
                n1++;
            } else {
                iterating_val = nums2[n2];
                n2++;
            }
            vals_passed++;
            if (vals_passed == left_vals) {
                break;
            }
        }
        
        if ((m+n)%2==1) {
            return((double)(iterating_val));
        } else {            
            return((double)    ((double)(iterating_val)+(double)(iterating_val2))/2.0);
            
            
        }
        
    }
};
