/**
 * [Question]
 * - ライブラリメソッドを何も使わずに，与えられた文の中で単語を反転させるにはどうすればよいですか？
 *    e.g.
 *    "C++ is Great" -> "Great is C++"
 * 
 * [Solution]
 * - 前から順に単語を見つける
 *      - スペースに出会ったらそこまでを単語として配列に格納
 * - 単語を格納した配列を後ろから文にしていく
 */

#include <iostream>
#include <vector>

int main()
{
    /* INPUT */
    std::string sentence = "C++ is Great";
    std::string word;

    /* SOLVE */
    // まずは word を検出
    std::vector<std::string> t;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            t.push_back(word);
            word = "";
        }
        else if (i == sentence.size()-1)
        {
            word += sentence[i];
            t.push_back(word);
        }
        else
        {
            word += sentence[i];
        }
    }

    // 検出した word を逆順で文を作る
    std::string reversed_sentence;
    for (int i = t.size()-1; i >= 0; i--)
    {
        reversed_sentence += t[i];
        reversed_sentence += " ";
    }

    // 表示
    std::cout << reversed_sentence << std::endl;
}