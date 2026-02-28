#include <print>
#include <string>

bool
a_is_parent_to_b(std::string a, std::string b)
{
    char *pa = &a[0];
    char *pb = &b[0];

    while (*pa && *pb) {
        if (*pb == *pa) {
            pa++;
        }

        pb++;
    }
    if (*pa) {
        return false;
    }

    return true;
}

int
main()
{
    {
        std::println("Test 1: a = 'abc', b = 'abc'. Expect: true");
        std::string a = "abc";
        std::string b = "abc";
        std::println("{}", a_is_parent_to_b(a, b));
    }
    {
        std::println("Test 2: a = 'abc', b = 'dabdc'. Expect: true");
        std::string a = "abc";
        std::string b = "dadbc";
        std::println("{}", a_is_parent_to_b(a, b));
    }
    {
        std::println("Test 3: a = 'abc', b = 'ab'. Expect: false");
        std::string a = "abc";
        std::string b = "ab";
        std::println("{}", a_is_parent_to_b(a, b));
    }
    {
        std::println("Test 4: a = '', b = 'abc'. Expect: true");
        std::string a = "";
        std::string b = "abc";
        std::println("{}", a_is_parent_to_b(a, b));
    }
    {
        std::println("Test 5: a = '', b = ''. Expect: true");
        std::string a = "";
        std::string b = "";
        std::println("{}", a_is_parent_to_b(a, b));
    }
    {
        std::println("Test 6: a = 'afdaf', b = ''. Expect: false");
        std::string a = "afdaf";
        std::string b = "";
        std::println("{}", a_is_parent_to_b(a, b));
    }
}
