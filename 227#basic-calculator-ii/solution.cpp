class Solution {
    enum class opt_type : char {
        remove_bracket,
        calculate,
        push_stack
    };
    class Optmap {
        char pri[128];
    public:
        Optmap() {
            pri['+'] = 1;
            pri['-'] = 1;
            pri['*'] = 2;
            pri['/'] = 2;
            pri['('] = 0;
        }
        opt_type action(char a, char b) {
            if (a == ')') {
                return b == '(' ? opt_type::remove_bracket : opt_type::calculate;
            } else {
                return pri[a] > pri[b] ? opt_type::push_stack : opt_type::calculate;
            }
        }
    };
    template<class Itr>
    int getnum(Itr& s, Itr e) {
        int n = 0;
        while (s != e && *s <= '9' && *s >='0') {
            n = n * 10 + (*(s++) - '0');
        }
        return n;
    }
    int calc(int a, int b, char opt) {
        switch (opt) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        }
    }
    static Optmap optmap;
    vector<char> sopt;
    vector<int> snum;
public:
    int calculate(string s) {
        int t;
        sopt.clear();
        snum.clear();
        sopt.push_back('(');
        s.push_back(')');
        auto p = s.begin(), e = s.end();
        while (p != e) {
            if (*p == ' ') {
                p++;
                continue;
            } else if (*p <= '9' && *p >= '0') {
                snum.push_back(getnum(p, e));
            } else {
                switch (optmap.action(*p, sopt.back())) {
                case opt_type::remove_bracket:
                    sopt.pop_back();
                    p++;
                    break;
                case opt_type::calculate:
                    t = snum.back();
                    snum.pop_back();
                    snum.back() = calc(snum.back(), t, sopt.back());
                    sopt.pop_back();
                    break;
                case opt_type::push_stack:
                    sopt.push_back(*(p++));
                    break;
                }
            }
        }
        return snum.back();
    }
};
Solution::Optmap Solution::optmap{};
