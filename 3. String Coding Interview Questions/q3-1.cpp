/**
 * [Question]
 * - 文字列から繰り返されない最初の文字を表示するにはどうすればよいですか？
 * 
 * [Solution]
 * - 前から順に走査し，連想配列を用いて既出かどうかを確認
 *      - 新しい文字は出てきた順に配列 v に登録
 *      - v の順で連想配列をチェック
 *          - 最初に出てきたカウントが1のものが答え
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::string func(std::string s)
{
    std::string ans;
    std::vector<char> v;
    std::unordered_map<char, int> map;

    // 一文字もないとき
    if (s.empty())
        ans = "";
    // 一文字のとき
    else if (s.size() == 1)
    {
        ans = s[0];
    }
    // 二文字以上のとき
    else
    {
        // 前から順に走査
        for (int i = 0; i < s.size(); i++)
        {
            // 出ていなければ登録
            if (map.count(s[i]) == 0)
            {
                map[s[i]] = 1;
                v.push_back(s[i]);
            }
            // 出ていればカウントアップ
            else
                map[s[i]]++;
        }

        // 出てきた文字の中でカウントが1だったものを探す
        for (int i = 0; i < v.size(); i++)
        {
            if (map[v[i]] == 1)
            {
                ans = v[i];
                break;
            }
        }
    }

    return ans;
}

int main()
{
    /* INPUT */
    std::string s1 = "aabbbbcdddd";
    std::string s2 = "a";
    std::string s3 = "abcdeab";
    std::string s4;

    /* SOLVE */
    std::string ans1 = func(s1);
    std::cout << ans1 << std::endl;

    std::string ans2 = func(s2);
    std::cout << ans2 << std::endl;

    std::string ans3 = func(s3);
    std::cout << ans3 << std::endl;

    std::string ans4 = func(s4);
    std::cout << ans4 << std::endl;    

    return 0;
}