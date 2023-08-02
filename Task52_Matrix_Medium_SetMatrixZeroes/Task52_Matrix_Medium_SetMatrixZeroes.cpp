#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

// First solution

//class Solution {
//public:
//    static void setZeroes(std::vector<std::vector<int>>& matrix) {
//        std::unordered_map<int, int> tmp_column;
//        for (int i = 0;i < matrix.size();i++) {
//            for (int j = 0;j < matrix[0].size();j++) {
//                if (matrix[i][j] == 0) {
//                    for (int g = 0;g < matrix[0].size();g++) {
//                        if (matrix[i][g] == 0) {
//                            tmp_column[g]++;
//                        }
//                        matrix[i][g] = 0;
//                    }
//                    break;
//                }
//            }
//        }
//        for (auto i : tmp_column) {
//            for (int j = 0;j < matrix.size();j++) {
//                matrix[j][i.first] = 0;
//            }
//        }
//    }
//};

// Second solution
class Solution {
public:
    static void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][j] != 0)
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;

        if (matrix[0][0] == 0)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;

        if (col0 == 0)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1 } };
    Solution::setZeroes(matrix);

    for (auto i : matrix) {
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}
