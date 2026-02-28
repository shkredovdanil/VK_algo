#include <print>
#include <string>

bool
palindome_check(std::string s)
{
    char *start = s.data();
    char *end = start + s.size() - 1;
    while (start <= end) {
        if (*start != *end) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int
main()
{
    {
        std::println("Test 1: a = 'abc'. Expect: false");
        std::string a = "abc";
        std::println("{}", palindome_check(a));
    }
    {
        std::println("Test 2: a = 'abba'. Expect: true");
        std::string a = "abba";
        std::println("{}", palindome_check(a));
    }
    {
        std::println("Test 3: a = 'aba'. Expect: true");
        std::string a = "aba";
        std::println("{}", palindome_check(a));
    }
    {
        std::println("Test 4: a = 'a'. Expect: true");
        std::string a = "a";
        std::println("{}", palindome_check(a));
    }
    {
        std::println("Test 5: a = 'abca'. Expect: false");
        std::string a = "abca";
        std::println("{}", palindome_check(a));
    }
}
