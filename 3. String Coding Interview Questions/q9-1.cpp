/**
 * [Question]
 * - 文字列のすべての順列を見つけるにはどうすればよいですか？
 *      e.g. aが4個, bが3個のとき その組み合わせ数は
 *      7! / (4! 3!) = 35
 * 
 * [Solution]
 * - next_permutation() を使って順列を洗い出す
 * - 連想配列を使って既出かどうかをチェック
 * - 1回目の登場のときだけ，配列に追加
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main()
{
    /* INPUT */
    std::string s = "aaaabbb";

    /* SOLVE */
    std::vector<char> s_vec;
    std::vector<int> order;
    for (int i = 0; i < s.size(); i++)
    {
        s_vec.push_back(s[i]);
        order.push_back(i);
    }

    std::unordered_map<std::string, int> map;
    std::vector<std::string> ans;
    do
    {
        // その順での文字列を作成
        std::string tgt = "";
        for (int i = 0; i < order.size(); i++)
            tgt += s[order[i]];

        // 既出かどうかを確認する
        if (map.count(tgt) == 0)
        {
            ans.push_back(tgt);
            map[tgt] = 1;
        }
        else
            map[tgt]++;
    }
    while (next_permutation(order.begin(), order.end()));

    // 表示
    std::cout << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << std::endl;
    
}