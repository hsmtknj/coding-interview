/**
 * [Question]
 * - 合計すると与えられた数字と同じになる整数の配列のすべての組み合わせを探すにはどうすればよいですか？
 * 
 * [Solution]
 * - ビット全探索で部分和をすべて求める
 *     - e.g. 0101 の 1 のところだけを足せば良い
 *     - 0000, 0001, 0010, ..., 1111 で全パターンを網羅できる
 */

#include <iostream>
#include <vector>
#include <bitset>

int main()
{
    /* INPUT */
    int n = 17;
    std::vector<int> v = {2, 4, 6, 9};

    /* SOLVE */
    // ビット全探索で部分和を求める
    int p_sum;
    for (int bit = 0; bit < (1<<v.size()); bit++)
    {
        // ビットパターンに応じた部分和を求める
        p_sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (bit>>i & 1) p_sum += v[i];
        }
        // 結果を表示    
        if (p_sum == n) std::cout << std::bitset<4>(bit) << ": " << p_sum << " <-" << std::endl;
        else std::cout << std::bitset<4>(bit) << ": " << p_sum << std::endl;
    }

    return 0;
}