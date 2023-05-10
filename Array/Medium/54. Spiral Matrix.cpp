class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Get the number of rows and columns in the matrix
        int col = matrix.size();
        int row = matrix[0].size();

        // Initialize variables for the indices of the left, right, top, and bottom edges of the matrix
        int left = 0, right = row - 1;
        int top = 0, bottom = col - 1;

        // Initialize a variable for the direction in which to traverse the matrix
        int direction = 1;

        // Initialize a vector to store the elements of the matrix in spiral order
        vector<int> ans;

        // Loop until the top edge of the matrix is greater than the bottom edge and the left edge of the matrix is less than the right edge
        while(top <= bottom && left <= right){

            if(direction == 1){ // If moving to the right
                // Traverse the row from left to right and add each element to the vector
                for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
                // Update the top edge of the matrix and change direction to move down
                direction = 2;
                top++;
            }

            else if(direction == 2){ // If moving down
                // Traverse the column from top to bottom and add each element to the vector
                for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
                // Update the right edge of the matrix and change direction to move left
                direction = 3;
                right--;
            }

            else if(direction == 3){ // If moving left
                // Traverse the row from right to left and add each element to the vector
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                // Update the bottom edge of the matrix and change direction to move up
                direction = 4;
                bottom--;
            }

            else if(direction == 4){ // If moving up
                // Traverse the column from bottom to top and add each element to the vector
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                // Update the left edge of the matrix and change direction to move right
                direction = 1;
                left++;
            }
        }

        // Return the vector containing the elements of the matrix in spiral order
        return ans;
    }
};
