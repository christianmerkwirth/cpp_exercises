#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

using embeddings_map = std::map<std::string, int64_t>;

struct Adder {
    uint32_t offset;
    Adder(uint32_t offset_=0) : offset(offset_) {}
    uint32_t operator()(const uint32_t a) { return a + offset;}
};

int main()
{
    embeddings_map embeddings;
    Adder add_functor(12);

    for (uint32_t i=0; i < 1000 * 1000; i++) {
        embeddings[std::to_string(i)] = add_functor(i);
    }

    for (uint32_t i = 0; const auto& [key, val] : embeddings) {
        std::cout << key << " : " << val << std::endl;
        if (i++ > 10)
            break;
    }
   
   return 0;

}
