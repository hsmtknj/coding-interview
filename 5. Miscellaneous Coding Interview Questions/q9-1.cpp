/**
 * [Question]
 * - 2つ矩形が相互に重なっているかどうかを確認するにはどうすればよいですか？
 * 
 * [Solution]
 * - rectangle A と rectangle B は下記の4パターンいずれかを満たせば重ならない
 *      - A が B より左
 *      - A が B より右
 *      - A が B より上
 *      - A が B より下
 * - 上記１つも当てはまらなければ重なっている
 * 
 * [Note]
 * - Collision Detection Algorithm に使える
 */

#include <iostream>

typedef struct rectangle_t
{
    int x1;  // top left, x coordinate
    int y1;  // top left, y coordinate
    int x2;  // bottom right, x coordinate
    int y2;  // bottom right, y coordinate
} rectangle_t;

bool is_overlapping(rectangle_t rec_a, rectangle_t rec_b)
{
    bool flag_overlapping;

    if (rec_a.x2 < rec_b.x1 |  // A is left to B
        rec_a.x1 > rec_b.x2 |  // A is right to B
        rec_a.y2 > rec_b.y1 |  // A is above B
        rec_a.y1 < rec_b.y2)   // A is below B
    {
        flag_overlapping = false;
    }
    else
    {
        flag_overlapping = true;
    }

    return flag_overlapping;
}

int main()
{
    /* INPUT */
    rectangle_t rec_a = {0, 5, 10, 0};
    rectangle_t rec_b = {7, 7, 15, 2};

    /* SOLVE */
    std::cout << is_overlapping(rec_a, rec_b) << std::endl;

    return 0;
}
