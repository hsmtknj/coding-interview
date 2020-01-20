/**
 * [Question]
 * - 与えられた配列から重複を削除するにはどうすればよいですか？
 * 
 * [Solution]
 * - 連想配列を用いて既出かどうかをチェックする
 */

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    /* INPUT */
    std::vector<int> v = {1, 3, 3, 7, 9, 10, 12, 12, 12, 15, 19};

    /* SOLVE */
    std::unordered_map<std::string, bool> map;
    std::vector<int> v_new;
    for (int i = 0; i < v.size(); i++)
    {
        std::string tgt = std::to_string(v[i]);
        if (map.count(tgt) == 0)
        {
            v_new.push_back(v[i]);
            map[tgt] = true;
        }
    }

    // 結果表示
    for (int i = 0; i < v_new.size(); i++)
    {
        std::cout << v_new[i] << std::endl;
    }

    return 0;
}