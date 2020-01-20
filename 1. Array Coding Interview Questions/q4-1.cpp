/**
 * [Question]
 * - 合計すると与えられた数字と同じになる整数の配列のすべての組み合わせを探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 再帰関数で深さ優先探索を実装
 *     - 分岐は "足した" or "足していない" の2つ
 *     - 一度計算した値を保持する，メモ化再帰で実装
 *     - 部分和が与えたれた値を超えるとそれ以降計算する必要がないので，枝狩りを実装
 */

#include <iostream>
#include <vector>

/* INPUT */
int n = 17;
std::vector<int> v = {2, 4, 6, 9};

// DPの準備
const int IND_MAX = 10000;
const int SUM_MAX = 10000;
int dp[IND_MAX+1][SUM_MAX+1];

bool dfs(int ind, int p_sum)
{
    // ベースケース
    if (ind == v.size())
    {
        if (p_sum == n) return dp[ind][p_sum] = true;
        else return dp[ind][p_sum] = false;
    }

    // 枝狩り
    if (p_sum > n) return dp[ind][p_sum] = false;

    // メモを参照
    if (dp[ind][p_sum] != -1) return dp[ind][p_sum];

    // 足す・足さないで分岐
    if (dfs(ind+1, p_sum)) return dp[ind][p_sum] = true;
    if (dfs(ind+1, p_sum+v[ind])) return dp[ind][p_sum] = true;
    // 両方ダメだったら
    return dp[ind][p_sum] = false;
}

int main()
{
    /* SOLVE */
    // dpを初期化 (未探索は-1で初期化)
    for (int i = 0; i <= IND_MAX; i++)
    {
        for (int j = 0; j <= SUM_MAX; j++)
        {
            dp[i][j] = -1;
        }
    }

    // 部分和が与えられた値になりうるか再帰関数で確認
    bool ans = dfs(0, 0);
    std::cout << ans << std::endl;

    return 0;
}
