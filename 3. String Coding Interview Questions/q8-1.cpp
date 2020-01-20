/**
 * [Question]
 * - 文字列の中の特定の文字の出現回数を数えるにはどうすればよいですか？
 * 
 * [Solution]
 * - 特定の文字列の数を数えるカウンタを用意して数える
 */

#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
    /* INPUT */
    std::string s = "hogehoge";

    /* SOLVE */
    int cnt = 0;
    std::string tgt = "h";

    for (int i = 0; i < s.size(); i++)
    {
        if (std::string{s[i]} == tgt)
            cnt++;
    }
    std::cout << cnt << std::endl;

    return 0;
}