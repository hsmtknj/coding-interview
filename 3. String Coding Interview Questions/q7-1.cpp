/**
 * [Question]
 * - 与えられた文字列の中の母音と子音の数を数えるにはどうすればよいですか？
 * 
 * [Solution]
 * - 文字列を前から順に走査
 *      - 母音なら母音のカウンタをインクリメント
 *      - 子音なら子音のカウンタをインクリメント
 */

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    /* INPUT */
    std::string s = "hogehogefugafuga1234";

    /* SOLVE */
    int vowel_cnt = 0;
    int consonant_cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // まずはアルファベットかどうかをチェック
        std::string tgt_s = {s[i]};
        if (std::all_of(tgt_s.cbegin(), tgt_s.cend(), isalpha))
        {
            // 母音か子音をチェック
            if (tgt_s == "a" | tgt_s == "i" | tgt_s == "u" | tgt_s == "e" | tgt_s == "o")
                vowel_cnt++;
            else
                consonant_cnt++;
        }
    }

    std::cout << "vowel: " << vowel_cnt << std::endl;
    std::cout << "consonant: " << consonant_cnt << std::endl;

}