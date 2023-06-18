// approach 1
// Brute force -> find zero update its row and col by some -ve no. for eg(-1) phir jahan jahan -1 udpdate it with zero
// Time Complexity -> O(N^3)

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {

            if (matrix[i][j] == 0)
            {
                int k = row;
                int p = col;
                // row ko 1 kroonga
                while (k--)
                {
                    if (matrix[k][j] != 0)
                    {
                        matrix[k][j] = -1;
                    }
                }
                while (p--)
                {
                    if (matrix[i][p] != 0)
                        matrix[i][p] = -1;
                }
                //    matrix[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Approach 2
// Taking dummy row and col
// Time complexity -> O(N^2)
// Space complexity -> O(N^2)

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> rowArr(n, 0);
    vector<int> colArr(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowArr[i] = 1;
                colArr[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rowArr[i] == 1 || colArr[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// approach 3
// Take first row and col of matrix as dummy row and col
// since [0][0] this position will be overlapped , consider it either for row or col
// if we consider it for row then take a separate variable for column for example bool // col = true and make it false if zero exists in first col
// once we update first col and row accordingly then traverse in reverse direction
// because if we traverse from beg it will affect our first row and col and then it will // affect further values.
// not intuitive
// Time Complexity -> O(N^2)
// space optimised -> constant space

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    bool col = true;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            col = false;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
        if (!col)
        {
            matrix[i][0] = 0;
        }
    }
}