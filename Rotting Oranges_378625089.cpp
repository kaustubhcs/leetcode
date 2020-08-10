class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        #define EMPTY 0
        #define FRESH 1
        #define ROT 2
        int x_dim = grid.size();
        int y_dim = grid[0].size();
        int total_cells = x_dim * y_dim;
        int *rotify_x;
        int *rotify_y;
        int new_rots;
        rotify_x = (int *) malloc (total_cells * sizeof(int));
        rotify_y = (int *) malloc (total_cells * sizeof(int));
        cout << x_dim << endl;
        cout << y_dim << endl;
        
        // Reset Rots
        for (int i = 0; i < total_cells; i++) rotify_x[i] = 0;
        for (int i = 0; i < total_cells; i++) rotify_y[i] = 0;
        
        new_rots = 0;
        bool possible_rots = true;
        int minutes_passed = -1;
        while(possible_rots) {
            possible_rots = false;
            minutes_passed++;
            // Get possible rots
            cout << "Rotting: " << minutes_passed << endl;
            for (int i = 0; i < x_dim; i++) {
                for (int j = 0; j < y_dim; j++) {
                    
                    if (grid[i][j] == ROT) {
                        
                        
                        if ((i-1) >= 0) {
                            cout << "C0" << endl;
                            if (grid[i-1][j] == FRESH) {
                                rotify_x[new_rots] = i-1;
                                rotify_y[new_rots] = j;
                                new_rots++;
                                possible_rots = true;
                            }
                        }
                        
                        if ((j-1) >= 0) {
                            cout << "C1" << endl;
                            if (grid[i][j-1] == FRESH) {
                                rotify_x[new_rots] = i;
                                rotify_y[new_rots] = j-1;
                                new_rots++;
                                possible_rots = true;
                            }
                        }
                        
                        
                        if ((i+1) < x_dim) {
                            cout << "C2" << endl;
                            if (grid[i+1][j] == FRESH) {
                                rotify_x[new_rots] = i+1;
                                rotify_y[new_rots] = j;
                                new_rots++;
                                possible_rots = true;
                            }
                        }
                        
                        if ((j+1) < y_dim) {
                            cout << "C3" << endl;
                            if (grid[i][j+1] == FRESH) {
                                rotify_x[new_rots] = i;
                                rotify_y[new_rots] = j+1;
                                new_rots++;
                                possible_rots = true;
                            }
                        }
                    }

    
                }
            }
            
            // Update Rots
            cout << "Updating: " << minutes_passed << endl;
            if (new_rots > 0) {
                for (int i=0; i < new_rots; i++) {
                    grid[rotify_x[i]][rotify_y[i]] = ROT;
                }
            }
            new_rots = 0;
            
        }
        for (int i=0; i < x_dim; i++) {
            for (int j=0; j < y_dim; j++) {
                if (grid[i][j] == FRESH) {
                    return(-1);
                }
            }
        }

        return minutes_passed;
    }
};
