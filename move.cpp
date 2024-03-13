
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>

 
template <typename T>
void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);   
    b = std::move(tmp);
}

template <typename T>
T reduce_sum(const std::vector<T>& v) {
    return std::accumulate(v.begin(), v.end(), 0);
}

template <typename T>
std::vector<T> range(T start, T end) {
    size_t N = (int)floor(end - start) + 1;
    std::vector<T> vec(N);
    std::iota(vec.begin(), vec.end(), start);
    return vec;
}

int main()
{
    std::vector<uint64_t> a = range(0ull, 10000ull);
    std::vector<uint64_t> b = range(0ull, 2000ull);

    std::cout << reduce_sum(a) << " " << reduce_sum(b) << std::endl;

    swap(a, b);

    std::cout << reduce_sum(a) << " " << reduce_sum(b) << std::endl;

    return 0;
}