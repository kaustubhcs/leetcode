class Solution {
public:
    string convert(string s, int numRows) {
        #define SKY true
        #define GROUND false
        if (numRows == 1) return(s);
        int len = s.size();
        string ans = string(len , ' ');
        // Upper Edge
        int u_offsets = ((numRows-2)*2)+2;
        
        int iterator = 0;
        int ans_idx = 0;
        while(1) {
            ans[ans_idx] = s[iterator];
            ans_idx++;
            iterator += u_offsets;
            if (iterator >= len) {
                break;
            }
        }
        
        // Middle // Iterative
        int total_mid_rows = numRows - 2;
        for (int mid_row = 1; mid_row < (total_mid_rows+1); mid_row++) {
            bool sg_switch = GROUND;
            iterator = mid_row;
            int ground_offset = ((total_mid_rows - mid_row)*2) + 2;
            int sky_offset = ((total_mid_rows - ((total_mid_rows+1) - mid_row))*2) + 2;
            
            
            while(1) {
                ans[ans_idx] = s[iterator];
                ans_idx++;
                if (sg_switch == GROUND) {
                    iterator += ground_offset;
                    sg_switch = SKY;
                } else if (sg_switch == SKY) {
                    iterator += sky_offset;
                    sg_switch = GROUND;
                }
                if (iterator >= len) {
                    break;
                }
            }
        }
        
        // Lower Edge
        iterator = numRows - 1;
        while(1) {
            ans[ans_idx] = s[iterator];
            ans_idx++;
            iterator += u_offsets;
            if (iterator >= len) {
                break;
            }
        }
        
        return (ans);
    }
    
};
