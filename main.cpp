#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

using namespace std;
typedef long long ll;
typedef long double ld;

map<char, int> decoding;
char coding[36];

void create_consts() {
    for (int i = 0; i < 36; ++i) {
        if (i < 10) {
            decoding[(char) ('0' + i)] = i;
            coding[i] = (char) ('0' + i);
        } else {
            decoding[(char) ('A' + i - 10)] = i;
            coding[i] = (char) ('A' + i - 10);
        }
    }
}

long long convert_from(const string& s, int syst) {
    long long ans = 0;
    for (char x : s) {
        ans *= syst;
        ans += decoding[x];
    }
    return ans;
}

string convert_to(long long x, int syst) {
    string ans;
    stack<long long> a;
    while (x > 0) {
        a.push(coding[x % syst]);
        x /= syst;
    }
    while (!a.empty()) {
        ans.push_back(a.top());
        a.pop();
    }
    return ans;
}

string multi_convert(const string& s, int base_system, int goal_system) {
    return convert_to(convert_from(s, base_system), goal_system);
}


struct Digit {
private:
    deque<int> self;
    int system;

public:
    Digit(int x, int _system) {
        system = _system;
        while (x > 0) {
            self.push_front(x % 10);
            x /= 10;
        }
    }

    Digit(int x) {
        system = 10;
        while (x > 0) {
            self.push_front(x % 10);
            x /= 10;
        }
    }

    Digit(const string &_s) {
        for (char x: _s) {
            self.push_back(decoding[x]);
        }
    }

    Digit() {
        self = {0};
        system = 10;
    }

    string getString() {
        string ans;
        for (int x : self) {
            ans.push_back(coding[x]);
        }
        return ans;
    }

    long long getDigit() {
        long long ans = 0;
        if (system > 10) {
            printf("%s", "System more than 10! We cannot imagine this for simple digit.");
            exit(1);
        }
        for (int x : self) {
            ans *= system;
            ans += x;
        }
        return ans;
    }

    void rebuilt(int _system) {
        string s = multi_convert(this->getString(), system, _system);
        self.clear();
        for (char x: s) {
            self.push_back(decoding[x]);
        }
    }
};


int main() {
    create_consts();
#ifdef LOCAL
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    return 0;
}
