#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Takes only space separated integer values.
std::vector<int32_t> parse_input_line(const std::string& input_line) {
  std::vector<int32_t> result;
  std::stringstream ss(input_line);
  int32_t value;
  while (ss >> value) {
    result.push_back(value);
  }
  return result;
}

int main() {
  std::vector<std::vector<int32_t>> all_arrays;
  std::string input_line;

  // Read n and q (number of arrays and queries)
  std::getline(std::cin, input_line);
  auto nq = parse_input_line(input_line);
  int32_t n = nq[0];
  int32_t q = nq[1];

  // Read sequences
  for (int32_t i = 0; i < n; ++i) {
    std::getline(std::cin, input_line);
    all_arrays.push_back(parse_input_line(input_line));
  }

  // Read queries
  for (int32_t i = 0; i < q; ++i) {
    std::getline(std::cin, input_line);
    auto query_ij = parse_input_line(input_line);
    std::cout << all_arrays[query_ij[0]][query_ij[1] + 1] << std::endl;
  }

  return 0;
}
