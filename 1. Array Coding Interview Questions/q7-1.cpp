/**
 * [Question]
 * - クイックソートのアルゴリズムを使用する場合、整数の配列をソートするにはどうすればよいですか？
 * 
 * [Solution]
 * - クイックソートを実装
 *     - leftは左端，rightは右端外に設定
 *     - 再帰関数で実装
 *     - クイックソートは先行順で処理
 */

#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &v, int left, int pivot, int right)
{
    // ベースケース
    if (right - left <= 1) return;

    /* クイックソートのメイン処理 */
    // pivot 左を pivot 未満に，pivot 右を pivot 以上にソート
    int pivot_num = v[pivot];

    // (1) まずはピボットの値を右端に持っていく
    std::swap(v[pivot], v[right-1]);

    // (2) インデックスを2つ用意
    //  i: 最終的に pivot の値をおさまるところ
    //  j: pivot の値が収まるところを線形探索で探す
    int i = 0;
    int j = 0;
    for (; j < right-1; j++)
    {
        // ピボット値より大きい場合はそのまま
        if (v[j] > pivot_num) continue;
        // ピボット値以下の場合はスワップ・インクリメント
        else
        {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    // (3) 見つけた位置にピボット値を入れる
    std::swap(v[right-1], v[i]);
    
    // デバッグ用表示
    // std::cout << left << ", " << pivot << ", " << right << std::endl;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (i == left) std::cout << "[ ";
    //     if (i == pivot) std::cout << "( ";
    //     std::cout << v[i] << " ";
    //     if (i == pivot) std::cout << ") ";
    //     if (i == right-1) std::cout << "]";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;

    /* 分割してさらにクイックソート */
    int pivot_l = left + (pivot - left) / 2;
    int pivot_r = pivot + (right - pivot) / 2;
    quick_sort(v, left, pivot_l, pivot);
    quick_sort(v, pivot, pivot_r, right);

    return;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 7, 25, 17, 20, 100, 2, 5, 88, 17, 88, 100, 101};

    /* SOLVE */
    int left = 0;
    int right = v.size();
    int pivot = left + (right - left) / 2;
    quick_sort(v, left, pivot, right);
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
