//
// Created by sivan on 01/03/2020.
//

#include <include/Watchable.h>
#include <include/Session.h>
#include <include/User.h>

#include <utility>



Movie::Movie(long id, string  name, int length, const vector<std::string>& tags): Watchable(id, length, tags), name(std::move(name)) {}

string Movie::toString() const{ return name;}

Watchable *Movie::getNextWatchable(Session &s) const {return s.getActiveUser().getRecommendation(s);}

Watchable *Movie::clone() const{return new Movie(*this);}


