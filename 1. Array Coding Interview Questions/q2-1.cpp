/**
 * [Question]
 * - 与えられた整数の配列において重複した数字を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 連想配列を使って既出かどうか調べながら線形探索
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

int main()
{
    /* INPUT */
    std::vector<int> v = {1, 1, 2, 2, 3, 4, 5};
    
    /* SOLVE */
    // 重複する文字列を探す
    std::unordered_map<std::string, int> map;
    std::vector<int> dupl;
    for (int i = 0; i < v.size(); i++)
    {
        std::string tgt = std::to_string(v[i]);

        // まだ出てきていない場合
        if (map.count(tgt) == 0)
        {
            map[tgt] = 1;
        }
        // 既に出てきている場合
        else if (map.count(tgt) > 0)
        {
            map[tgt]++;
            dupl.push_back(v[i]);
        }
    }

    // 重複文字列を表示
    for (int i = 0; i < dupl.size(); i++)
    {
        std::cout << dupl[i] << std::endl;
    }

    return 0;
}
