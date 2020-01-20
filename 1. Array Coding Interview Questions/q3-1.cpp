/**
 * [Question]
 * - ソートされていない整数の配列から最大値と最小値を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 先頭から順に最大・最小値を更新しながら線形探索
 */

#include <iostream>
#include <vector>
#include <limits.h>

int main()
{
    /* INPUT */
    std::vector<int> v = {4, 9, 1, 3, 8, 10, 2};
    
    /* SOLVE */
    // 最大と最小を求める
    int max_num = 0;
    int min_num = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        // 最大の更新
        if (v[i] > max_num) max_num = v[i];
        // 最小の更新
        if (v[i] < min_num) min_num = v[i];
    }

    // 最大・最小の更新
    std::cout << max_num << std::endl;
    std::cout << min_num << std::endl;

    return 0;
}