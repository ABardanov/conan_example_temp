#include <iostream>
#include <algorithm>

#include "etl/vector.h"

int main()
{
    std::cout << "Using Conan and ETL" << std::endl;

    etl::vector vec {1, 2, 3, 4, 5};

    vec.push_back(6);

    auto it = std::remove_if(vec.begin(), vec.end(), [](int n){return n % 2;});
    vec.erase(it, vec.end());

    for (auto n : vec) {
        std::cout << n << " ";
    }

    return 0;
}