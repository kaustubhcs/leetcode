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
            int ground_offset = ((numRows - 2 - mid_row)*2) + 1 + 1;
            int sky_offset = ((numRows - 2 - ((total_mid_rows+1) - mid_row))*2) + 1 + 1;
            // cout << "Row: " << mid_row << " GO: " << ground_offset << endl;
            // cout << "Row: " << mid_row << " SO: " << sky_offset << endl;
            
            
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
                // if (ans_idx > len) {
                //     cout << "ERROR: Ans idx exceeded\n";
                //     cout << ans << endl;
                //     break;
                // }
            }
        }
        
        // Lower Edge
        iterator = numRows - 1;
        int l_offsets = u_offsets;
        while(1) {
            ans[ans_idx] = s[iterator];
            ans_idx++;
            iterator += l_offsets;
            if (iterator >= len) {
                break;
            }
        }
        
        return (ans);
    }
    
};
