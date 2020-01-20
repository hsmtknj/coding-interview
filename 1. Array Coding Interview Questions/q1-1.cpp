/**
 * [Question]
 * - 1から100までの与えられた整数の配列の中から足りない数字を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 順番に先頭から見ていく
 *     - 期待する数字と乖離がないか線形探索で確認
 *     - ソートされていることが前提
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    /* INPUT */
    // 5, 6, 7, 78, 97, 99, 100が抜けた，1~100の配列を準備する
    int N = 100;
    std::vector<int> v;
    for (int i = 1; i <= N; i++)
    {
        if (i == 5 | i == 6 | i == 7 | i == 78 | i == 97 | i == 99 | i == 100) continue;
        else v.push_back(i);
    }

    /* SOLVE */
    // 抜けている数字を探す
    std::vector<int> missing;
    int exp_num = 1;
    int i;
    for (i = 0; i < v.size(); i++)
    {
        // 期待通りの値の場合
        if (v[i] == exp_num)
        {
            exp_num++;
            continue;
        }
        // 期待通りの値でなかった場合
        else
        {
            // 抜けている値を表示
            for (int j = exp_num; j < v[i]; j++)
            {
                missing.push_back(j);
            }
            // 期待する値を更新
            exp_num = v[i] + 1;
        }
    }

    // 上記は配列vの最大までしかチェックしていないので，残りはすべてmissing
    for (int j = exp_num; j <= N; j++)
    {
        missing.push_back(j);
    }

    //  抜けている数字を表示
    for (int j = 0; j < missing.size(); j++)
    {
        std::cout << missing[j] << std::endl;
    }

    return 0;
}
