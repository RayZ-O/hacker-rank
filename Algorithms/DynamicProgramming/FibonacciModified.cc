#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class BigInt {
    vector<int> num;
    int base = 100000000;
public:
    BigInt(vector<int> &v) {
        num = v;
    }

    BigInt(int i) {
        do {
            num.push_back(i % base);
            i /= base;
        } while (i);
    }

    BigInt operator + (BigInt& b) {
        vector<int> res;
        int i = 0, j = 0, carry = 0;
        while (i < num.size() || j < b.num.size() || carry) {
            int l = i < num.size() ? num[i++] : 0;
            int r = j < b.num.size() ? b.num[j++] : 0;
            long n = static_cast<long>(l) + r + carry;
            res.push_back(n % base);
            carry = n / base;
        }
        return BigInt(res);
    }

    BigInt operator * (BigInt& b) {
        vector<int> res(num.size() + b.num.size(), 0);
        for (int i = 0; i < num.size(); i++) {
            long long carry = 0;
            if (!num[i]) {
                continue;
            }
            for (int j = 0; j < b.num.size(); j++) {
                long long n = res[i+j] + static_cast<long long>(num[i]) * b.num[j] + carry;
                res[i+j] = n % base;
                carry = n / base;
            }
            res[i+b.num.size()] += carry;
        }
        while(res.back() == 0 && res.size() > 1) {
            res.pop_back();
        }
        return BigInt(res);
    }

    friend ostream& operator<< (ostream& out, const BigInt& b) {
        if (!b.num.empty()) {
            out << b.num.back();
            for (int i = b.num.size() - 2; i >= 0; i--) {
                out << setw(8) << setfill('0') << b.num[i];
            }
        } else {
            out << "0";
        }
        return out;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int fst, snd, n;
    cin >> fst >> snd >> n;
    vector<BigInt> nums;
    nums.emplace_back(fst);
    nums.emplace_back(snd);
    for (int i = 2; i < n; i++) {
        nums.push_back(nums[i-1] * nums[i-1] + nums[i - 2]);
    }
    cout << nums.back() << endl;
    return 0;
}
