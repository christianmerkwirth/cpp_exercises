COMPILER         := g++
OPTIMIZATION_OPT := -O1
BASE_OPTIONS     := -pedantic-errors -Wall -Wextra -Werror -Wno-long-long -std=c++20
OPTIONS          := $(BASE_OPTIONS) $(OPTIMIZATION_OPT)
LINKER_OPT       := -L/usr/lib -lstdc++ -lm
ASAN_OPT         := -g -fsanitize=address   -fno-omit-frame-pointer
MSAN_OPT         := -g -fsanitize=memory    -fno-omit-frame-pointer
LSAN_OPT         := -g -fsanitize=leak      -fno-omit-frame-pointer
USAN_OPT         := -g -fsanitize=undefined -fno-omit-frame-pointer
BUILD_SRC        := $(sort $(wildcard *.cpp))
BUILD_LIST       := $(BUILD_SRC:%.cpp=%)


all: $(BUILD_LIST)

$(BUILD_LIST) : %: %.cpp
	$(COMPILER) $(OPTIONS) -o $@ $@.cpp $(LINKER_OPT)

strip_bin :
	@for f in $(BUILD_LIST); do if [ -f $$f ]; then strip -s $$f; echo $$f; fi done;

clean:
	rm -f core.* *~ *.o *.bak *stackdump gmon.out *.gcda *.gcno *.gcnor *.gch
