/**
 * [Question]
 * - 与えられた文字列を再帰を使って反転するにはどうすればよいですか？ 
 * 
 * [Solution]
 * - 前から順に後半の対応する文字列を swap を繰り返す
 *      e.g. 長さ10なら
 *      - (1, 10) を交換
 *      - (2, 9) を交換
 *      - ...
 */

#include <iostream>
#include <string>

void rec(std::string &s, int left, int right)
{
    std::cout << left << ", " << right << std::endl;
    /* ベースケース*/
    if (right - left <= 0)
        return;
    
    /* 処理 */
    std::swap(s[left], s[right]);

    /* 再帰関数 */
    rec(s, ++left, --right);
}

void reverse_string(std::string &s)
{
    if (s.empty())
        return;
    else
    {
        int left = 0;
        int right = s.size() - 1;
        rec(s, left, right);
    }
    
}

int main()
{
    /* INPUT */
    std::string s = "hogehoge";

    /* SOLVE */
    reverse_string(s);
    std::cout << s << std::endl;
}