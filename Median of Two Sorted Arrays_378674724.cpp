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
        int iterating_val;
        int iterating_val2;
        int vals_passed = 0;
        
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        m += 1;
        n += 1;
        
        bool nswitch = false;  
        bool nswitch2;

        while(1) {
            nswitch2 = nswitch;
            if (nums1[n1] < nums2[n2]) {
                n1++;
                nswitch = true;
            } else {
                n2++;
                nswitch = false;
            }
            vals_passed++;
            if (vals_passed == left_vals) {
                break;
            }
        }
        
        
        if (nswitch) {
            n1--;
            iterating_val = nums1[n1];
        } else {
            n2--;
            iterating_val = nums2[n2];
        }
        
        
        if ((m+n)%2==1) {
            return((double)(iterating_val));
        } else {  
            if (nswitch2) {
                iterating_val2 = nums1[n1-1];
            } else {
                iterating_val2 = nums2[n2-1];
            }
            return((double)    ((iterating_val)+(iterating_val2))/2.0);
            
            
        }
        
    }
};
