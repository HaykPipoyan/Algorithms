#include <iostream>
#include <vector>
#include <limits>

std::pair<int, int> min_max(std::vector<int>& vec)
{
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();

    for (auto elem : vec)
    {
        if (elem < min)
        {
            min = elem;
        }
        if (elem > max)
        {
            max = elem;
        }
    }
    return { min, max };
}

void counting_sort(std::vector<int>& vec)
{
    if (vec.size() <= 1)
    {
        return;
    }
    auto [min, max] = min_max(vec);
    int range       = max - min + 1;
    std::vector<int> tmp(range, 0);
    std::vector<int> res(vec.size());
    for (int i = 0; i < vec.size(); ++i)
    {
        ++tmp[vec[i] - min];
    }
    for (int i = 1; i < range; ++i)
    {
        tmp[i] += tmp[i - 1];
    }
    for (int i = vec.size() - 1; i >= 0; --i)
    {
        res[tmp[vec[i] - min] - 1] = vec[i];
        --tmp[vec[i] - min];
    }
    for (int i = 0; i < vec.size(); ++i)
    {
        vec[i] = res[i];
    }
}

int main(){
    std::vector<int> vec = {-10, 4, 2, 2, -29, 8, 3, 3, 1};
    std::cout << "Original vector: ";
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    counting_sort(vec);

    std::cout << "Sorted vector: ";
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
