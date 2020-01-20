/**
 * [Question]
 * - 与えられた配列で二分探索を行うにはどうすればよいですか？
 * 
 * [Solution]
 * - まず配列をソート
 *      - 二分探索木を使うなら中間順で昇順になる
 * - left と　right のインデックスを用意
 *      - left 側は探索に含む
 *      - right 側は探索に含まない（or 配列外）
 * - mid を left と right のインデックスから計算
 *      - mid = left + (right - left) / 2; と切り捨てで良い
 * - 大きいか小さいかで left or right を更新
 *      - left の更新時は +1 する（テク）
 */

#include <iostream>
#include <vector>
#include <algorithm>

bool binary_search(std::vector<int> &v, int key)
{
    bool flag_existance = false;

    int left = 0;
    int right = v.size();
    int mid;

    while (right - left > 0)
    {
        mid = left + (right - left) / 2;

        if (v[mid] == key)
        {
            flag_existance = true;
            break;
        }
        else
        {
            if (v[mid] < key)
                left = mid + 1;
            else
                right = mid;            
        }
    }

    return flag_existance;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 88, 17, 1, 25, 20};

    /* SOLVE */
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    for (int i = 0; i < v.size(); i++)
        std::cout << binary_search(v, v[i]) << " ";
    std::cout << std::endl;

    std::cout << binary_search(v, 1000) << std::endl;

    return 0;
}
