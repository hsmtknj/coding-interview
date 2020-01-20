/**
 * [Question]
 * - 与えられた文字列が回文かどうかを確認するにはどうすればよいですか？
 * 
 * [Solution]
 * - 文字列1は先頭から，文字列２は後ろから同一か確認する
 */

#include <iostream>

bool is_palindrome(std::string s)
{
    bool flag_palindrome = true;
    int left = 0;
    int right = s.size() - 1;

    while (right - left > 0)
    {
        if (s[left] != s[right])
        {
            flag_palindrome = false;
            break;
        }
        left++;
        right--;
    }

    return flag_palindrome;
}

int main()
{
    /* INPUT */
    std::string s1 = "civic";
    std::string s2 = "kayak";
    std::string s3 = "hoge";

    /* SOLVE */
    // s1
    if (is_palindrome(s1)) 
        std::cout << "s1: " << "palindrome" << std::endl;
    else
        std::cout << "s1: " << "NOT palindrome" << std::endl;

    // s2
    if (is_palindrome(s2)) 
        std::cout << "s2: " << "palindrome" << std::endl;
    else
        std::cout << "s2: " << "NOT palindrome" << std::endl;

    // s3
    if (is_palindrome(s3)) 
        std::cout << "s3: " << "palindrome" << std::endl;
    else
        std::cout << "s3: " << "NOT palindrome" << std::endl;


    return 0;
}
