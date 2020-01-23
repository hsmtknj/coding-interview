/**
 * [Question]
 * - Merge Sort のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - 分割統治法を利用
 *      - ソート済みの左右の配列を準備
 *      - 左右の配列から小さい順にポップして，なくなるまで繰り返す
 * - 再帰関数で実装
 * 
 * [計算量]
 * - O(N log(N))
 */

#include <iostream>
#include <vector>

void merge_sort(std::vector<int> &v, int left, int right)
{
    // ベースケース
    if (right - left <= 1)
        return;

    // マージソートのソート処理は後行順
    int mid = left + (right - left) / 2;
    merge_sort(v, left, mid);
    merge_sort(v, mid, right);

    /* 左右の配列をソート */
    // バッファ配列に真ん中が大きく，外側が小さくなるように格納
    std::vector<int> buf;
    for (int i = left; i < mid; i++)
        buf.push_back(v[i]);
    for (int i = right-1; i >= mid; i--)
        buf.push_back(v[i]);

    // 左右のインデックスを用意し、小さい方から格納し直す（ソートする）
    int buf_left = 0;
    int buf_right = buf.size() - 1;

    for (int i = left; i < right; i++)
    {
        if (buf[buf_left] < buf[buf_right])
        {
            v[i] = buf[buf_left];
            buf_left++;
        }
        else
        {
            v[i] = buf[buf_right];
            buf_right--;
        }
    }
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 20, 17, 1, 30, 88, 100, 7, 25, 78, 7};

    /* SOLVE */
    int left = 0;
    int right = v.size();
    merge_sort(v, left, right);
    
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
