/**
 * [Question]
 * - 第3の変数を使わずに2つの数字を交換するにはどうすればよいですか？
 * 
 * [Solution]
 * - 排他的論理和 (exclusive or) を使う
 * 
 */

#include <iostream>

int main()
{
    /* INPUT */
    int a = 10;
    int b = 20;

    /* SOLVE */
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    std::cout << "a:" << a << std::endl;
    std::cout << "b:" << b << std::endl;

    return 0;
}