#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <iterator>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> values(n), results(n, -1);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    //6 2
    //1 5 3 6 2 5

    //ще пазим като ключ числото на съответния индекс и като стойност, която съответства на ключа
    //опашка от индексите на елементите, за които то ще е отговорът
    map<int, queue<int>> entries;

    //започваме обхождането отзад напред
    for (int i = n - 1; i >= 0; --i) {
        
        //добавяме текущия елемент в map-а и запазваме итератор към мястото, където сме го добавили
        auto insertResult = entries.emplace(values[i], queue<int>({i}));

        auto it = insertResult.first;
        
        //ако не сме го добавили, т.е. вече го е имало в map-a, го добавяме в опашката - 
        //той изпълнява условието да е с не повече от k по-голям от вече добавения, защото е със същата стойност
        //и е намерен някъде наляво
        if (!insertResult.second) {
            it->second.push(i);
        }

        //намираме първото число, по-голямо от (текущото + k), през което вече сме минали, т.е.
        //първото число, което не отговаря за условието
        auto upperBound = entries.upper_bound(it->first + k);
        ++it;

        //итерираме до това число и всички числа между нашето число и тази горна граница получават като отговор 
        //това число 
        while(it != upperBound) {
            while (!it->second.empty()) {
                results[it->second.front()] = i;
                it->second.pop();
            }

            entries.erase(it++);
        }
    }

    for (const auto& num : results) {
        printf("%d ", num);
    }

    return 0;
}
