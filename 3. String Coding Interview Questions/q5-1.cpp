/**
 * [Question]
 * - 文字列に数字しか含まれていないかどうかを確認するにはどうすればよいですか？ 
 * 
 * [Solution]
 * - std::all_of(), isdigit を使う
 */

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    /* INPUT */
    std::string s = "123";

    /* SOLVE */
    if (s.empty())
        std::cout << "NULL" << std::endl;
    else if (std::all_of(s.cbegin(), s.cend(), isdigit))
        std::cout << "digit" << std::endl;
    else
        std::cout << "NOT digit" << std::endl;

    return 0;
}