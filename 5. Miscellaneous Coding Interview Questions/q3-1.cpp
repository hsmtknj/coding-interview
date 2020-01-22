/**
 * [Question]
 * - 挿入ソートのアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - 前から順に走査
 * - 自分より前で昇順になるように適切な位置に挿入
 */

#include <iostream>
#include <vector>

void straight_insertion_sort(std::vector<int> &v)
{
    // 配列が空 or 長さ1ならソートの必要がない
    if (v.size() == 0 | v.size() == 1)
        return;

    // 配列長が2以上のときはソートを実施
    for (int i = 1; i < v.size(); i++)
    {
        // 自分より前で適切な位置に挿入する
        // j が挿入位置になる
        for (int j = i; j > 0; j--)
        {
            // 自分より大きければ後ろにずらす
            if (v[j-1] > v[j])
                std::swap(v[j-1], v[j]);
            else
                break;
        }
    }
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 20, 25, 30, 88, 100, 17, 2, 1};

    /* SOLVE */
    straight_insertion_sort(v);

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
