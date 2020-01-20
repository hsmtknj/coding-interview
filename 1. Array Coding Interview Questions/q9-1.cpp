/**
 * [Question]
 * - 配置された配列を反転するにはどうすればよいですか？
 * 
 * [Solution]
 * - 先頭から順にスワップを繰り返す
 *     - e.g. 10の配列の場合
 *         - 0と10をスワップ, 1と9をスワップ, 2と8をスワップ, ...
 *     - 単純な線形探索の半分で実装できる
 */

#include <iostream>
#include <vector>

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 7, 25, 17, 20, 100, 2, 5, 88, 17, 88, 100, 101};

    /* SOLVE */
    int left = 0;
    int right = v.size()-1;
    while (right - left >= 0)
    {
        std::swap(v[left], v[right]);
        left++;
        right--;
    }
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
