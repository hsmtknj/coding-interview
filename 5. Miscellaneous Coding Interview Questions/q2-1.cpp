/**
 * [Question]
 * - Quick Sort のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - left, right インデックスに加えて pivot インデックスを用意
 * - pivot の左は pivot 値より小さく，pivot の右は pivot 値より大きくする
 *      - leftは左端
 *      - rightは右端+1 (配列外)
 * 
 * [計算量]
 * - O(N^2)
 *      - 一般的に高速
 */

#include <iostream>
#include <vector>

void quick_sort(std::vector<int> &v, int left, int right)
{
    // ベースケース
    if (right - left <= 1)
        return;

    // ピボットを求める
    int pivot = left + (right - left) / 2;

    // pivot左をpivot値より小さく，pivot右をpivot値より大きくする
    int pivot_num = v[pivot];
    int i = left;                     // i は後に 右端のpivot を入れる場所になる
    int j = left;                     // 配列を前から走査していく用

    // (1) pivot 値を右端に移動
    std::swap(v[pivot], v[right-1]);

    // (2) jを前から順に進めていく
    //      - pivot値より小さい値に出会ったらiとjを交換する
    //      - iのインデックスを1つ進める
    // 基本的に小さいものを前に集めたい
    // i は常にpivot値より大きいか小さいかの境目となる
    for (; j < right; j++)
    {
        if (v[j] < pivot_num)
        {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    // pivot を適切な位置に移動
    std::swap(v[right-1], v[i]);

    // 再帰関数
    int left1 = left;
    int right1 = i;
    int left2 = i + 1;
    int right2 = right;
    quick_sort(v, left1, right1);
    quick_sort(v, left2, right2);
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 30, 17, 1, 20, 25, 100, 30, 88};

    /* SOLVE */
    int left = 0;
    int right = v.size();
    quick_sort(v, left, right);

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}