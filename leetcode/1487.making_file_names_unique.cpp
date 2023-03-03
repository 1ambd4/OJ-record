#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

#include "leetcode.h"

using namespace std;

vector<string> get_folder_names(vector<string>& names)
{
    unordered_map<string, int> cnt;
    for (auto& name : names) {
        if (!cnt.count(name)) {
            ++cnt[name];
        } else {
            while (cnt.count(name + "(" + to_string(cnt[name]) + ")")) {
                ++cnt[name];
            }
            name += "(" + to_string(cnt[name]) + ")";
            ++cnt[name];
        }
    }
    return names;
}

int main()
{
    vector<string> names1 {"pes", "fifa", "gta", "pes(2019)"};
    vector<string> res1 = get_folder_names(names1);
    print_vector(res1);

    vector<string> names2 {"gta", "gta(1)", "gta", "avalon"};
    vector<string> res2 = get_folder_names(names2);
    print_vector(res2);

    vector<string> names3 {"wano", "wano", "wano", "wano"};
    vector<string> res3 = get_folder_names(names3);
    print_vector(res3);

    vector<string> names4 {"kaido", "kaido(1)", "kaido", "kaido(1)"};
    vector<string> res4 = get_folder_names(names4);
    print_vector(res4);

    return 0;
}

