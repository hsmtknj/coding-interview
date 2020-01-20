/**
 * [Question]
 * - 2つの文字列が相互にアナグラムであるかどうかを確認するにはどうすればよいですか？
 * 
 * [Solution]
 * - 両文字列をソートして比較する
 */

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    /* INPUT */
    std::string s1 = "canoe";
    std::string s2 = "ocean";

    /* SOLVE */
    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    if (s1 == s2)
        std::cout << "ANAGRAM" << std::endl;
    else
        std::cout << "NOT ANAGRAME" << std::endl;
    
    return 0;
}