//
// Created by sivan on 03/03/2020.
//

#include <include/Session.h>
#include <include/User.h>
#include <include/Watchable.h>
#include <algorithm>


GenreRecommenderUser::GenreRecommenderUser(const string& name): User(name){}

Watchable* GenreRecommenderUser::getRecommendation(Session& s) {
    map<string, int> tagsNum;
    vector<pair<string, int>> numByTags;
    for (auto h: history)
        for (const auto &tag: h->getTags())
            tagsNum[tag]++;

    for (const auto &t: tagsNum)//creating reversed map
        numByTags.emplace_back(t);

    sort(numByTags.begin(), numByTags.end(),
         [](pair<string, int> const &p1, pair<string, int> const &p2) {
             return p1.second == p2.second ? p1.first.compare(p2.first) : p1.second > p2.second;
         });

    for (const auto &n: numByTags) {
        string mostTagged = n.first;
        const vector<Watchable *> &content = s.getContent();
        for (auto c: content) {
            for(const auto& t: c->getTags())
                if (t == mostTagged && !isInHistory(c))
                return c;
        }
    }
    return nullptr;
}
