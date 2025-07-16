#include <iostream>
#include <vector>
#include <string>
#include <cctype>

void solve() {
    int n;
    char broken_key_lower;
    std::cin >> n >> broken_key_lower;
    std::string s;
    std::cin >> s; 

    char broken_key_upper = toupper(broken_key_lower);

    std::vector<int> lower_indices;
    std::vector<int> upper_indices;
    
    std::vector<std::pair<char, int>> logged_chars;

    for (char current_char : s) {
        if (current_char == broken_key_lower) {
            if (!lower_indices.empty()) {
                lower_indices.pop_back();
            }
        } else if (current_char == broken_key_upper) {
            if (!upper_indices.empty()) {
                upper_indices.pop_back();
            }
        } else {
        
            logged_chars.push_back({current_char, logged_chars.size()});
            
            if (islower(current_char)) {
                lower_indices.push_back(logged_chars.size() - 1);
            } else {
                upper_indices.push_back(logged_chars.size() - 1);
            }
        }
    }


    std::vector<bool> is_valid(logged_chars.size(), false);

    for (int index : lower_indices) {
        is_valid[index] = true;
    }
    for (int index : upper_indices) {
        is_valid[index] = true;
    }

    for (size_t i = 0; i < logged_chars.size(); ++i) {
        if (is_valid[i]) {
            std::cout << logged_chars[i].first;
        }
    }
    std::cout << std::endl;
}

int main() {
   
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t; 
    while (t--) {
        solve();
    }
    return 0;
}