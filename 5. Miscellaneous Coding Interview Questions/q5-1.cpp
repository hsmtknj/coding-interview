/**
 * [Question]
 * - Bucket Sort (Bin sort) のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - バケット配列を用意する
 * - データを対応するバケットに入れる
 * - バケットから順に取り出す
 * 
 * <計算量>
 * - O(n + A)
 * <特徴>
 * - 小さい値までのソートならめちゃめちゃ速い
 * - 重複に対応していない
 * 
 * [Reference]
 * - <https://www.codereading.com/algo_and_ds/algo/bucket_sort.html>
 * - <https://qiita.com/drken/items/44c60118ab3703f7727f#8-1-%E8%A8%88%E6%95%B0%E3%82%BD%E3%83%BC%E3%83%88>
 */

#include <iostream>
#include <vector>

// ソートで対象の数字は 100000 を最大とする
const int N_MAX = 100000;

void bucket_sort(std::vector<int> &v)
{
    // バケツを用意
    std::vector<bool> bucket(N_MAX+1, false);

    // バケツに入れる
    for (int i = 0; i < v.size(); i++)
        bucket[v[i]] = true;

    // バケツから順に取り出す
    std::vector<int> sorted;
    for (int i = 0; i < bucket.size(); i++)
    {
        if (bucket[i] == true)
            sorted.push_back(i);
    }

    v = sorted;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 100, 1, 25, 20};

    /* SOLVE */
    bucket_sort(v);
    
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}