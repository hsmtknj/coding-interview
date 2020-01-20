/**
 * [Question]
 * - 文字列の中で重複する文字を探すにはどうすればよいですか？
 * 
 * [Solution]
 * - 連想配列を使って既出かどうかを確認
 *      - カウントが2のときだけ表示
 */

#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    /* INPUT */
    std::string s = "hogehogefuga";

    /* SOLVE */
    std::unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
        // はじめて出たとき
        if (map.count(s[i]) == 0)
        {
            map[s[i]] = 1;
        }
        // 2回目のとき
        else if (map.count(s[i]) == 1 && map[s[i]] == 1)
        {
            std::cout << s[i] << std::endl;
            map[s[i]]++;
        }
        else
            map[s[i]]++;        
    }

    return 0;
}