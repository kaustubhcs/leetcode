class Solution {
public:
    int hammingDistance(int x, int y) {
                int hamming_dist=0;
        int calc_x = x;
        int calc_y = y;
        int x_bits[32], y_bits[32];
        
        for (int i=0;i<32;i++) {
        x_bits[i] = 0;
        y_bits[i] = 0;
            
        } 
        
        for (int i=0;i<32;i++) {
            x_bits[i] = calc_x%2;
            calc_x = calc_x - (calc_x%2);
            calc_x = calc_x/2;
            if (calc_x ==0)
            {
                i=100; // Overflow for loop.
            }
        }
        
        for (int i=0;i<32;i++) {
            y_bits[i] = calc_y%2;
            calc_y = calc_y - (calc_y%2);
            calc_y = calc_y/2;
            if (calc_y ==0)
            {
                i=100; // Overflow for loop.
            }
        }
        
        for (int i=0;i<32;i++) {
            if (x_bits[i] + y_bits[i] == 1) {
                hamming_dist++;
            }
        }
        
        
        
        return hamming_dist;
        
    }
};
