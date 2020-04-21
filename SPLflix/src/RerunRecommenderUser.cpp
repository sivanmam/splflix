//
// Created by sivan on 03/03/2020.
//

#include <include/User.h>
#include <include/Session.h>

RerunRecommenderUser::RerunRecommenderUser(const string& name): User(name), i(-1){}

Watchable* RerunRecommenderUser::getRecommendation(Session& s){
    vector<Watchable*> history = s.getActiveUser().getHistory();
    int size = history.size();
    Watchable* recommended = nullptr;
    recommended = history.at((i+1)%size);
    i++;
    return recommended;
}
