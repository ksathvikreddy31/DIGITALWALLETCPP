#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<int>& uid, vector<int>& amt) {
    int n = uid.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (amt[i] > amt[j]) {
                swap(amt[i], amt[j]);
                swap(uid[i], uid[j]);
            }
        }
    }
}

int main() {
    int n, t;
    cin >> n;
    vector<int> uid(n);
    vector<int> amt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> uid[i] >> amt[i];
    }
    cin >> t;
    int fromuid, touid, ramt;
    for (int i = 0; i < t; i++) {
        cin >> fromuid >> touid >> ramt;
        int fromind = -1, toind = -1;
        for (int j = 0; j < n; ++j) {
            if (uid[j] == fromuid) {
                fromind = j;
            }
            if (uid[j] == touid) {
                toind = j;
            }
            if (fromind != -1 && toind != -1) {
                break;
            }
        }
        if (fromind != -1 && toind != -1 && amt[fromind]>=ramt) {
                amt[fromind] -= ramt;
                amt[toind] += ramt;
                cout << "Success\n";
            } else {
                cout << "Failure\n";
            }
    }

    sort(uid, amt);
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        cout << uid[i] << " " << amt[i] << "\n";
    }

    return 0;
}