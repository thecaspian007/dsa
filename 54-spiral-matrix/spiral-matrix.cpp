class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int r = matrix.size();
       int c = matrix[0].size(); 
       vector<int> ans;

       int startingRow = 0;
       int endRow = r-1;
       int startingCol = 0;
       int endCol = c-1;
       int count = 0;
       int total = r*c;
       
       while(count<total)
       {
            for(int i = startingCol; count<total && i<= endCol; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;

             for(int i = startingRow; count<total && i<= endRow; i++)
            {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--;

            for(int i = endCol; count<total && i>= startingCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--;

            for(int i = endRow; count<total && i>= startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
       }
      

    //    cout<<m<< n<< endl;
       return ans;
    }
};