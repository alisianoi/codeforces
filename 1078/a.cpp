#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    u32 n, k; cin >> n >> k;

    u32 a;
    auto as = vector<u32>(101, 0);

    for (u32 i = 0; i != n; ++i) {
        cin >> a;
        ++as[a];
    }

    u64 count = count_if(
        as.begin(), as.end(), [](const auto v) {return v != 0;}
    );
    u64 total = accumulate(as.begin(), as.end(), 0);
    u64 most =  *max_element(as.begin(), as.end());

    u64 sets = (most + k - 1) / k;

    cout << sets * k * count - total << endl;
}
