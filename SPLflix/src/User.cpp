//
// Created by sivan on 28/02/2020.
//

#include "../include/User.h"

#include <utility>

User::User(const string& name): name(name), history(){}

string User::getName() const{ return name;}

vector<Watchable*> User::getHistory() const{ return history;}

bool User::isInHistory(Watchable *content) {
    for(auto h: history)
        if(h == content)
            return true;
    return false;
}

const void User::addToHistory(Watchable *watched) {
    history.push_back(watched);
   // lastWatched = watched;
}

void User::setHistory(vector<Watchable *> h) {
    history = move(h);
}

void User::setName(string userName) {name = userName;}





