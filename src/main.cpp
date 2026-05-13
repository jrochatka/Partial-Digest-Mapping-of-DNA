#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

using namespace std;

typedef pair<int, bool> Element; 
vector<int> map;

vector<Element> load_from_file() {
    string namefile;

    cout << "Choose a file, from data directory (full name)" << endl;
    cin >> namefile;

    ifstream file("data/" + namefile);
    
    vector<Element> set;
    int number;

    if (file.is_open()) {
        while (file >> number) {
            set.push_back({ number, false }); 
        }
    }
    else {
        cout << "File not found!" << endl;
        exit(1);
    }
    return set;
}

int numberOfCuts(const vector<Element>& set) {
    for (int k = 1; k < 30; k++) {
        int n = (k + 2) * (k + 1);
        if (n / 2 == set.size()) {
            return k;
        }
    }
    return 0;
}

int findMaxValue(const vector<Element>& set) {
    int maxValue = set[0].first; 
    for (const auto& elem : set) {
        if (elem.first > maxValue) {
            maxValue = elem.first; 
        }
    }

    return maxValue;

}
int find_second_MaxValue(const vector<Element>& set, int maxValue) {
    int maxValue1 = 0;
    for (const auto& elem : set) {
        if (elem.first > maxValue1 && elem.first < maxValue) {
            maxValue1 = elem.first;
        }
    }

    return maxValue1;
}


bool can_be_used(const vector<Element>& set, int x) {
    for (const auto& elem : set) {
        if (x == elem.first && !elem.second) {
            return true;
        }
    }
    return false;
}

void use_element(vector<Element>& set, int x) {
    for (auto& elem : set) {
        if (x == elem.first && !elem.second) {
            elem.second = true;
            return;
        }
    }
}

void un_use_element(vector<Element>& set, int x) {
    for (auto it = set.begin(); it != set.end(); ++it) {
        if (x == it->first && it->second) {
            it->second = false;
            return;
        }
    }
}

void szukaj(int ind, int maxind, int& jest, int n, vector<Element>& set, vector<int>& map , chrono::steady_clock::time_point start) {
    if (ind == maxind) {
        cout << "Solution: ";
        for (int i : map) {
            cout <<"|-"<< i << "-|";
        }
        cout << endl;
        jest = 1;
    }
    else {


        auto now = chrono::steady_clock::now();
        chrono::duration<double> elapsed = now - start;


        for (auto& elem : set) {
            if (can_be_used(set, elem.first)) {
                int tmp = elem.first;
                int cantUse = 0;
                for (int j = map.size() - 1; j > -1; j--) {
                    tmp += map[j]; 
                    if (can_be_used(set, tmp)) continue; 
                    cantUse = 1;
                    break;
                }
                if (cantUse == 1) {
                    continue;
                }
                if (!can_be_used(set, n - tmp)) { 
                    continue;
                }
                map.push_back(elem.first); 
                tmp = 0;
                for (int j = map.size() - 1; j > -1; j--) {
                    tmp += map[j];
                    use_element(set, tmp);
                }
                use_element(set, n - tmp); 

                if (ind == maxind - 1) {
                    map.push_back(n - tmp);
                }
                szukaj(ind + 1, maxind, jest, n, set, map, start);

                if (jest == 1) {
                    break;
                }

                tmp = map.back();
                un_use_element(set, map.back());
                map.pop_back();
                for (int j = map.size() - 1; j > -1; j--) {
                    tmp += map[j];
                    un_use_element(set, tmp);
                }
                un_use_element(set, n - tmp);
            }
        }
    }
}

int main() {

    vector<Element> set = load_from_file();
    int cuts = numberOfCuts(set);
    int last = findMaxValue(set);
    int second_last = find_second_MaxValue(set, findMaxValue(set));
    int first = last - second_last;
    int jest;

    if (cuts == 0) {
        cout << "There is no number of cuts for this instance." << endl;
        exit(2);
    }
    else {
        map.push_back(first);
        if (!can_be_used(set, map[0])) {
            cout << "Error. The first element is not contained in the set." << endl;
            cout << last << "|" << second_last;
            exit(3);
        }
        if (!can_be_used(set, last) || !can_be_used(set, second_last)) {
            cout << "Error" << endl;
            exit(3);
        }
        use_element(set, map[0]);
        use_element(set, last);
        use_element(set, second_last);
       
        auto start = std::chrono::steady_clock::now();
        szukaj(1, cuts, jest, last, set, map, start);
        auto end = std::chrono::steady_clock::now();
        chrono::duration<double> time = end - start;

         cout << "Algorithm runtime " << time.count() << " s." << endl;
      
        if (jest == 0) {
            cout << "The map for the given multiset does not exist." << endl;
            exit(4);
        }
    }
    return 0;
}
