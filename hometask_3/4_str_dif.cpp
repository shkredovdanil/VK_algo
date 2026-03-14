#include <cstdint>
#include <print>
#include <string>

constexpr int ASCII_SIZE = 128;

void
fill_array(int (&table)[ASCII_SIZE], std::string s)
{
    for (auto x : s) {
        table[static_cast<uint8_t>(x)] += 1;
    }
}

void
empty_array(int (&table)[ASCII_SIZE], std::string s)
{
    for (auto x : s) {
        table[static_cast<uint8_t>(x)] -= 1;
    }
}

char
find_extra(std::string a, std::string b)
{
    int table[ASCII_SIZE] = {};
    fill_array(table, b);
    empty_array(table, a);

    for (int i = 0; i < ASCII_SIZE; i++) {
        if (table[i] != 0) {
            return i;
        }
    }

    return -1;
}

int
main()
{
    {
        std::println("Test 1: 'abc' 'cadb'. Expected: 'd'");
        std::println("{}", char(find_extra("abc", "cadb")));
    }
    {
        std::println("Test 2: 'abdc' 'caddb'. Expected: 'd'");
        std::println("{}", char(find_extra("abdc", "caddb")));
    }
    {
        std::println("Test 3: 'abc' 'abc&'. Expected: '&'");
        std::println("{}", char(find_extra("abc", "abc&")));
    }
}
