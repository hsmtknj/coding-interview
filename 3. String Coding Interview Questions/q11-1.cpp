/**
 * [Question]
 * - 2つの文字列が相互に順序が回転しているかどうかを確認するにはどうすればよいですか？
 *      e.g.
 *          "programming" <-> "ingprogramm"
 *      e.g.
 *          "IndiaUSAEngland" <-> "USAEnglandIndia""
 *      e.g.
 *          "123456" <-> "456123"
 * 
 * [Solution]
 * - 2つの文字列の長さが同じか確認
 * - 長さが同じなら文字列の結合を繰り返して全パターン確認
 *      - 1文字目スタートのパターン
 *      - 2文字目スタートのパターン
 *      - ...
 *      - n文字目スタートのパターン
 */

#include <iostream>
#include <vector>

bool is_string_rotation(std::string s1, std::string s2)
{
    bool flag_rotation = false;

    // 長さが異なる場合は回転の関係になり得ない
    if (s1.size() != s2.size())
        flag_rotation = false;
    // 長さが同じ場合は観点の関係にあるか確認する
    else
    {
        // i番目を一文字目としたパターンの回転文字列2を作成する
        int char_cnt;
        int ind;
        std::string rotated_s2;
        for (int i = 0; i < s2.size(); i++)
        {
            // 回転させた文字列2を作成する
            char_cnt = 0;
            ind = i;
            rotated_s2 = "";
            while (char_cnt != s2.size())
            {
                rotated_s2 += s2[ind];
                if (ind == s2.size()-1)
                    ind = 0;
                else
                    ind++;
                char_cnt++;
            }

            // 回転させた文字列2と文字列1を比較する
            if (s1 == rotated_s2)
            {
                flag_rotation = true;
            }
        }
    }

    return flag_rotation;
}

int main()
{
    /* INPUT */
    std::string s1 = "programming";
    std::string s2 = "ingprogramm";

    /* SOLVE */
    bool ans = is_string_rotation(s1, s2);
    if (ans == true)
        std::cout << "ROTATION" << std::endl;
    else
        std::cout << "NOT ROTATION" << std::endl;

    return 0;
}
