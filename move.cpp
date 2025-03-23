
#include <functional>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

 
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




template <typename T>
void run() {
    std::vector<T> a = range(static_cast<T>(0), static_cast<T>(10000));
    std::vector<T> b = range(static_cast<T>(0), static_cast<T>(2000));

    std::cout << reduce_sum(a) << " " << reduce_sum(b) << std::endl;

    swap(a, b);

    std::cout << reduce_sum(a) << " " << reduce_sum(b) << std::endl;
}



int main()
{
    run<uint64_t>();
    return 0;
}