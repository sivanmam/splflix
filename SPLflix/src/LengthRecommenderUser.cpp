//
// Created by sivan on 01/03/2020.
//

#include <include/User.h>
#include <include/Session.h>
#include <include/Watchable.h>


LengthRecommenderUser::LengthRecommenderUser(const string& name): User(name){}

Watchable* LengthRecommenderUser::getRecommendation(Session& s){
    const User &user = s.getActiveUser();
    const vector<Watchable *> history = user.getHistory();
    int totalLength = 0;
    for(auto h: history)
        totalLength += h->getLength();
    int avgLength = totalLength/(history.size());
    const vector<Watchable *> &content = s.getContent();
    Watchable *recommended = nullptr;
    int recLength = INT_MAX;
    for(auto c: content)
        if(!isInHistory(c))
            if(abs((c->getLength()-avgLength)) < abs(recLength - avgLength)){
                recLength = c->getLength();
                recommended = c;
            }
    return recommended;
}

