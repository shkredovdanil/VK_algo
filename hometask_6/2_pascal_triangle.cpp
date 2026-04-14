#include <vector>

std::vector<std::vector<int>>
generatePascal(int n)
{
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        std::vector<int> row(i + 1, 1);

        for (int j = 1; j < i; j++) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

/*
1
1 1
1 2 1
1 3 3 1

triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
края всегда равны единицам
*/