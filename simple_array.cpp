#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream> 

using namespace std;

    // Takes only space separated C++ strings.
std::vector<int32_t> parse_input_line(const string& input_line) {
    std::vector<int32_t> result;
    std::stringstream ss(input_line);  
    int32_t value;
    while (ss >> value) { // Extract word from the stream.
        result.push_back(value);
    }
    return result;
} 


int main() {
    vector<vector<int32_t>> all_arrays;
    std::string input_line;
    getline(cin, input_line);
    // cout << input_line << endl;

    auto nq = parse_input_line(input_line);
    int32_t n(nq[0]);
    int32_t q(nq[1]);

    // Read sequences
    for (int32_t i=0; i < n; i++) {
        // std::cout << i << std::endl;
        getline(cin, input_line);
        //cout << input_line << endl;
        all_arrays.push_back(parse_input_line(input_line));
    }
    
    // Read queries
    for (int32_t i=0; i < q; i++) {
        // std::cout << i << std::endl;
        getline(cin, input_line);
        //cout << input_line << endl;
        //for (auto i : v) cout << i << endl;
         auto query_ij = parse_input_line(input_line);
         cout << all_arrays[query_ij[0]][query_ij[1]+1] << endl;
    }
    
    return 0;
}