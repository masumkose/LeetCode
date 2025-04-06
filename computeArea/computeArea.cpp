#include "../include/include.hpp"

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int overlap_x1 = max(ax1, bx1);
        int overlap_x2 = min(ax2, bx2);
        int overlap_y1 = max(ay1, by1);
        int overlap_y2 = min(ay2, by2);
        int overlap_width = max(0, overlap_x2-overlap_x1);
        int overlap_height = max(0, overlap_y2-overlap_y1);

        int overlap_area = overlap_height * overlap_width;
        int area_a = abs(ay1-ay2) * abs(ax1-ax2);
        int area_b = abs(by1-by2) * abs(bx1-bx2);

        return area_a + area_b - overlap_area;
    }
};


int main() {
    
    Solution ss = Solution();

    cout << ss.computeArea(-3,0,3,4,0,-1,9,2) << endl;
    cout << ss.computeArea(-2,-2,2,2,-2,-2,2,2) << endl;
    return 0;
}
