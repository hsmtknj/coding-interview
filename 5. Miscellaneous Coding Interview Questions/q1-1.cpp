/**
 * [Question]
 * - Bubble Sort のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - 配列の前から順に下記を実施
 *      - i と i+1 を昇順になるように交換する
 * - 一度も交換する必要がなくなるまで繰り返す
 * 
 * [計算量]
 * - O(N^2)
 */

#include <iostream>
#include <vector>
#include <limits.h>

void merge_sort(std::vector<int> &v)
{
    int swapping_cnt = INT_MAX;
    while (swapping_cnt != 0)
    {
        // 交換カウンタを初期化
        swapping_cnt = 0;

        // 前から順に昇順になるように前後を交換する
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                std::swap(v[i], v[i + 1]);
                swapping_cnt++;
            }
        }
    }
}

int main()
{
    /* INPUT */
    std::vector<int> v = {88, 30, 17, 1, 20, 25, 30};

    /* SOLVE */
    merge_sort(v);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}