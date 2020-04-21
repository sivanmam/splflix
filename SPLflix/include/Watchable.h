
#ifndef WATCHABLE_H_
#define WATCHABLE_H_
#include <string>
#include <vector>
using namespace std;
class Session;

class Watchable{
public:
    Watchable(long id, int length, const vector<std::string>& tags);
    virtual ~Watchable();
    virtual string toString() const = 0;
    virtual Watchable* getNextWatchable(Session&) const = 0;//returns a pointer to the watchable content to be recommended or nullptr if there is no recommendation
    virtual Watchable* clone() const = 0;

    long getId() const;
    int getLength() const;
    vector<string> getTags() const;
private:
    //each watchable content has id, name, length and list of tags
    const long id;
    int length;
    vector<string> tags;
};

class Movie : public Watchable{
public:
    Movie(long id, string  name, int length, const vector<string>& tags);
    virtual string toString() const;
    virtual Watchable* getNextWatchable(Session&) const;

    virtual Watchable* clone() const;
private:
    string name;
};


class Episode: public Watchable{
public:
    Episode(long id, string  seriesName,int length, int season, int episode, const vector<string>& tags);
    virtual string toString() const;
    virtual Watchable* getNextWatchable(Session& s) const;

    void setNextEpisodeId(int i);
    virtual Watchable* clone() const;
//    string getSeriesName() const ;
//    int getSeason() const ;
//    int getEpisode() const ;

private:
    string seriesName;
    int season;
    int episode;
    long nextEpisodeId;
};

#endif