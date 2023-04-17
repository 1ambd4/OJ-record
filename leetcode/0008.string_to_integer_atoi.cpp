#include <iostream>
#include <cstdlib>
#include <limits>

constexpr int MAX = 214748364;

// 抄了一下musl
int my_atoi(std::string s)
{
    int n = 0, neg = 0, digit = 0;
    const char *p = s.c_str();
    while (isspace(*p)) p++;
    switch(*p) {
        case '-': neg = 1;
        case '+': p++;  // falthrough
    }

    while (isdigit(*p)) {
        digit = *p++ - '0';
        if (neg == 0 && (n > MAX || (n == MAX && digit > 7)))
            return std::numeric_limits<int>::max();
        if (neg == 1 && (-n < -MAX || (-n == -MAX && digit >= 8)))
            return std::numeric_limits<int>::min();
        n = 10 * n + digit;
    }

    return neg ? -n : n;
}


// musl 1.2.3
int atoi(const char *s)
{
	int n=0, neg=0;
	while (isspace(*s)) s++;
	switch (*s) {
	case '-': neg=1;
	case '+': s++;
	}
	/* Compute n as a negative number to avoid overflow on INT_MIN */
	while (isdigit(*s))
		n = 10*n - (*s++ - '0');
	return neg ? n : -n;
}


int main()
{
    std::string s1 {"42"};
    std::cout << my_atoi(s1) << std::endl;
    std::string s2 {"-91283472332"};
    std::cout << my_atoi(s2) << std::endl;
    std::string s3 {"21474836460"};
    std::cout << my_atoi(s3) << std::endl;
    std::string s4 {"-2147483648"};
    std::cout << my_atoi(s4) << std::endl;

    return 0;
}
