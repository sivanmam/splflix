//
// Created by sivan on 01/03/2020.
//

#include <include/Watchable.h>
#include <include/Session.h>
#include <include/User.h>

#include <utility>



Episode::Episode(long id, string seriesName, int length, int season, int episode, const vector <string> &tags)
    :Watchable(id, length, tags), seriesName(std::move(seriesName)), season(season), episode(episode), nextEpisodeId(id+1) {}

string Episode::toString() const{ return seriesName + " S" + to_string(season) + "E" + to_string(episode);}

Watchable* Episode::getNextWatchable(Session& s) const{
    if(nextEpisodeId != -1)
        return s.getContentAt(nextEpisodeId);
    return s.getActiveUser().getRecommendation(s);
}

void Episode::setNextEpisodeId(int i) {nextEpisodeId = i;}

Watchable *Episode::clone() const {return new Episode(*this);}


