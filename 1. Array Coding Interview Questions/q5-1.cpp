/**
 * [Question]
 * - 配列に複数の重複がある場合、配列内の重複した数字を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 連想配列を使って，既出かどうかを確認する
 */

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    /* INPUT */
    std::vector<int> v = {1, 1, 1, 2, 5, 7, 7, 10};

    /* SOLVE */
    std::vector<int> dupl;
    std::unordered_map<std::string, int> map;
    for (int i = 0; i < v.size(); i++)
    {
        // 対象となる数字を文字列で取り出す
        std::string tgt = std::to_string(v[i]);

        // 1度も出てきていないとき
        if (map.count(tgt) == 0)
        {
            map[tgt] = 1;
        }
        // 1度しか出ていないとき，重複文字列に加える
        else if (map.count(tgt) == 1 && map[tgt] == 1)
        {
            dupl.push_back(v[i]);
            map[tgt]++;
        }
        // 2度以上出ているときは，単にインクリメントのみ
        else if (map.count(tgt) == 1 && map[tgt] >=2)
        {
            map[tgt]++;
        }
    }

    // 結果表示
    for (int i = 0; i < dupl.size(); i++)
    {
        std::cout << dupl[i] << std::endl;
    }

    return 0;
}
