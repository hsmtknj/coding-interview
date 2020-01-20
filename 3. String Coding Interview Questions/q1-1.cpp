/** 
 * [Question]
 * - 文字列から重複する文字を表示するにはどうすればよいですか？
 * 
 * [Solution]
 * - 連想配列を用いて既出かどうあkを判定する
 */ 

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    /* INPUT */
    std::string s = "adbcdefgg";

    /* SOLVE */
    std::unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        // まだ出ていないとき
        if (map.count(s[i]) == 0)
        {
            map[s[i]] = 1;
        }
        // 既出のとき
        else
        {
            // 出た回数が1のときだけ表示
            if (map[s[i]] == 1)
                std::cout << s[i] << std::endl;
            map[s[i]]++;
        }
    }

    return 0;
}