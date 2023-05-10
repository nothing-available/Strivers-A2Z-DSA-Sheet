// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        int top = 0,bottom = n-1;

        int left = 0,right = n-1;

        vector<vector<int>> ans(n, vector<int> (n,1));

        int index = 1;

        while(top <= bottom && left <= right){

            //first row

            for(int i = left; i<= right; i++){

                ans[top][i] = index;

                index++;
            }

            top++;

            // last col

            for(int j = top; j <= bottom; j++){

                ans[j][right] = index;

                index++;
            }

            right--;

            // last row

            if(top <= bottom){

                for(int i = right; i >= left; i--){

                    ans[bottom][i] = index;

                    index++;
                }
            }

            bottom--;

            // first col

            if(left <= right){

                for(int j = bottom; j >= top; j--){

                    ans[j][left] = index;

                    index++;
                }
                left++;
            }
        }

        return ans;
    }
};
