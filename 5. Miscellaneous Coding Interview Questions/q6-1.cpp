/**
 * [Question]
 * - Counting Sort のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - ソートしたい配列:v の他に，バケット配列:b と 累積和配列:sum を用意する
 *     - 大きさは適当な大きさMAX(配列の最大が入ればOK)
 * - b   : どの値が何回出てきているかをチェック
 * - sum : bのカウントの累積和を取る
 *     - この累積和がインデックスそのものになる (one-based-indexing)
 * - sorted[--sum[v[i]]] = v[i] で格納
 *     - 前置デクリメントの役割
 *         - one-based-indexing -> zero-based-idexing に変換
 *         - 同じ値でもデクリメントすることで次回登場時に同じインデックスとなることを防ぐ
 * <計算量>
 * - O(n + k)
 * <特徴>
 * - 小さい値までのソートならめちゃめちゃ速い
 * - ソート対象の値に制限がある
 * - Bucket Sort と違い，重複に対応
 * 
 * [Reference]
 * - <https://www.programiz.com/dsa/counting-sort>
 * - <https://qiita.com/drken/items/44c60118ab3703f7727f#8-1-%E8%A8%88%E6%95%B0%E3%82%BD%E3%83%BC%E3%83%88>
 */

#include <iostream>
#include <vector>

// ソートで対象の数字は 100000 を最大とする
const int N_MAX = 100000;

void counting_sort(std::vector<int> &v)
{
    if (v.size() == 0 | v.size() == 1)
        return;

    std::vector<int> b(N_MAX + 1, 0);       // bucket 配列, 登場回数をカウント
    std::vector<int> sum(N_MAX + 1);  // 蓄積和 配列, これがそのまま 配列順 になる

    // 登場回数をカウント
    for (int i = 0; i < v.size(); i++)
        b[v[i]]++;

    // 蓄積和を算出
    sum[0] = b[0];
    for (int i = 1; i <= N_MAX; i++)
        sum[i] = sum[i-1] + b[i];

    // 蓄積和を使ってソート
    std::vector<int> sorted(v.size());
    for (int i = v.size()-1; i >= 0; i--)
        sorted[--sum[v[i]]] = v[i];

    v = sorted;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 100, 2, 17, 1, 30, 1, 88, 57, 25, 20};

    /* SOLVE */
    counting_sort(v);

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}