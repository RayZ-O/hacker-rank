#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class BigInt {
    vector<int> num;
    int base = 100000000;
public:
    BigInt(int i) {
        do {
            num.push_back(i % base);
            i /= base;
        } while (i);
    }

    BigInt operator *= (int a) {
        int carry = 0;
        for (int i = 0; i < num.size(); i++) {
            if (!num[i]) {
                continue;
            }
            long n = static_cast<long>(num[i]) * a + carry;
            num[i] = n % base;
            carry = n / base;
        }
        if (carry) {
            num.push_back(carry);
        }
        return *this;
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

int main(){
    int n;
    cin >> n;
    BigInt bi(1);
    for (int i = 2; i <= n; i++) {
        bi *= i;
    }
    cout << bi << endl;
    return 0;
}
