#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

std::string
find_palindrome(std::string str)
{
    if (str.empty()) {
        return "";
    }

    int best_start = 0;
    int max_len = 1;

    for (size_t i = 0; i < str.size(); i++) {
        size_t l = i - 1, r = i + 1;
        while (l >= 0 && r < str.size() && str[l] == str[r]) {
            int current_len = r - l + 1;
            if (current_len > max_len) {
                max_len = current_len;
                best_start = l;
            }
            l--;
            r++;
        }

        l = i, r = i + 1;
        while (l >= 0 && r < str.size() && str[l] == str[r]) {
            int current_len = r - l + 1;
            if (current_len > max_len) {
                max_len = current_len;
                best_start = l;
            }
            l--;
            r++;
        }
    }

    return str.substr(best_start, max_len);
}

/*
Сложность O(n^2)
Подход - расширение от центра
*/

int
main()
{
    struct TestCase
    {
        std::string input;
        std::string expected;
    };

    std::vector<TestCase> tests = {{"babad", "bab"},       {"cbbd", "bb"}, {"a", "a"},       {"ac", "a"},
                                   {"racecar", "racecar"}, {"", ""},       {"aaaa", "aaaa"}, {"abbcccbbb", "bbcccbb"}};

    int passed = 0;
    for (const auto &test : tests) {
        std::string result = find_palindrome(test.input);
        if (result == test.expected || (test.input == "babad" && result == "aba")) {
            std::cout << "[ OK ] Input: '" << test.input << "' -> '" << result << "'\n";
            passed++;
        } else {
            std::cout << "[FAIL] Input: '" << test.input << "' | Expected: '" << test.expected << "' | Got: '" << result
                      << "'\n";
        }
    }

    std::cout << "\nPassed: " << passed << "/" << tests.size() << std::endl;

    return 0;
}
