/**
 * [Question]
 * - Heap Sort のアルゴリズムを実装するにはどうすればよいですか？
 * 
 * [Solution]
 * - ヒープは二分木で表す
 *       - 親の値は子の値以上
 * - 親 k の子は 2k+1, 2k+2
 * - 子 k の親は (k - 1) / 2
 */

#include <iostream>
#include <vector>

class heap
{
public:
    heap();
    ~heap();

    /* public: 変数 */
public:
    std::vector<int> array;

    /* public: 関数 */
public:
    void push(int key);
    int get_root();
    void pop();
};

heap::heap()
{
}

heap::~heap()
{
}

void heap::push(int key)
{
    this->array.push_back(key);
    int k = this->array.size() - 1;
    while (k != 0)
    {
        int parent_k = (k - 1) / 2;
        if (this->array[k] > this->array[parent_k])
        {
            std::swap(this->array[k], this->array[parent_k]);
            k = parent_k;
        }
        else
            k = 0;
    }
}

int heap::get_root()
{
    return this->array[0];
}

void heap::pop()
{
    if (!this->array.empty())
    {
        // 先頭を最後の要素と交換して，削除する
        std::swap(this->array[0], this->array[this->array.size() - 1]);
        this->array.pop_back();

        // 先頭に持ってきたノードをヒープ条件が成立するまで落としていく
        int k = 0;
        // 子がいなくなるまで繰り返す or ヒープ条件が成立したら break で抜ける
        while (1)
        {
            int left = 2 * k + 1;
            int right = 2 * k + 2;

            // (1) 子がいないとき
            if (left >= this->array.size() &&  right >= this->array.size())
                break;
            // (2) 左の子だけいるとき
            else if (left < this->array.size() && right >= this->array.size())
            {
                // ヒープの条件を満たしている場合
                if (this->array[k] >= this->array[left])
                    break;
                else
                {
                    std::swap(this->array[k], this->array[left]);
                    k = left;
                }
            }
            // (3) 左の子・右の子 両方いるとき
            else if (left < this->array.size() && right < this->array.size())
            {
                // ヒープの条件を満たしている場合
                if (this->array[k] >= this->array[left] && this->array[k] >= this->array[right])
                    break;
                else
                {
                    // 左右の子のうち大きい方と交換
                    if (this->array[left] > this->array[right])
                    {
                        std::swap(this->array[k], this->array[left]);
                        k = left;
                    }
                    else
                    {
                        std::swap(this->array[k], this->array[right]);
                        k = right;
                    }
                }
                
            }
        }
    }
}

void heap_sort(std::vector<int> &v)
{
    // ヒープに格納
    heap tree;
    for (int i = 0; i < v.size(); i++)
        tree.push(v[i]);

    // 先頭を取り出し，削除するを繰り返す (大きい値から順に取り出せる)
    std::vector<int> sorted_v;
    for (int i = 0; i < v.size(); i++)
    {
        sorted_v.push_back(tree.get_root());
        tree.pop();
    }
    v = sorted_v;
}

int main()
{
    /* INPUT */
    std::vector<int> v = {30, 23, 88, 17, 1, 88, 20, 25};

    /* SOLVE */
    heap_sort(v);
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    return 0;
}
