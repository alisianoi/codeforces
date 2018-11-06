#include<bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using i64 = int64_t;
using ui32 = uint32_t;
using ui64 = uint64_t;

int main() {

    ui64 N, S;
    cin >> N >> S;

    auto ss = vector<ui64>(N, 0);
    auto as = vector<ui32>(N, 0);
    auto bs = vector<ui32>(N, 0);

    auto ais = vector<ui32>();
    auto bis = vector<ui32>();
    auto cis = vector<ui32>();

    ui64 a_slices = 0;
    ui64 b_slices = 0;
    ui64 c_slices = 0;

    for (ui64 i = 0; i != N; ++i) {
        cin >> ss[i] >> as[i] >> bs[i];

        if (as[i] == bs[i]) {
            cis.push_back(i);

            c_slices += ss[i];
        } else if (as[i] > bs[i]) {
            ais.push_back(i);

            a_slices += ss[i];
        } else {
            bis.push_back(i);

            b_slices += ss[i];
        }
    }

    ui64 H = 0;
    ui64 a_pizzas = (a_slices - 1 + S) / S;
    ui64 b_pizzas = (b_slices - 1 + S) / S;

    ui64 t_pizzas = (a_slices + b_slices + c_slices - 1 + S) / S;

    if (a_pizzas + b_pizzas <= t_pizzas) {
        // Everyone eats what they want
        for (ui64 i = 0; i != N; ++i) {
            if (as[i] >= bs[i]) {
                H += as[i] * ss[i];
            } else {
                H += bs[i] * ss[i];
            }
        }
    } else {
        // c_slices < S (strictly)
        // a_pizzas + b_pizzas == t_pizzas + 1

        sort(
            ais.begin(), ais.end()
            , [&as, &bs] (const auto &lhs, const auto &rhs) {
                  if (as[lhs] - bs[lhs] > as[rhs] - bs[rhs]) {
                      return true;
                  }

                  return false;
              }
            );

        sort(
            bis.begin(), bis.end()
            , [&as, &bs] (const auto &lhs, const auto &rhs) {
                  if (bs[lhs] - as[lhs] > bs[rhs] - as[rhs]) {
                      return true;
                  }

                  return false;
              }
            );

        ui64 ai = 0;
        ui64 bi = 0;
        // These slices will definitely be eaten
        auto a_slices = (a_pizzas - 1) * S;
        auto b_slices = (b_pizzas - 1) * S;

        for (; a_slices >= ss[ais[ai]]; ++ai) {
            const auto &person = ais[ai];

            H += ss[person] * as[person];

            a_slices -= ss[person];
        }

        for (; b_slices >= ss[bis[bi]]; ++bi) {
            const auto &person = bis[bi];

            H += ss[person] * bs[person];

            b_slices -= ss[person];
        }

        ui64 person = 0;
        ui64 Ha = 0, Hb = 0;

        person = ais[ai];

        H += a_slices * as[person];
        ss[person] -= a_slices;

        person = bis[bi];

        H += b_slices * bs[person];
        ss[person] -= b_slices;

        for (; ai != ais.size(); ++ai) {
            person = ais[ai];

            Ha += ss[person] * as[person];
            Hb += ss[person] * bs[person];
        }

        for (; bi != bis.size(); ++bi) {
            person = bis[bi];

            Ha += ss[person] * as[person];
            Hb += ss[person] * bs[person];
        }

        H += (Ha > Hb) ? Ha : Hb;

        for (auto &i : cis) {
            H += ss[i] * as[i];
        }
    }

    cout << H << endl;
}
