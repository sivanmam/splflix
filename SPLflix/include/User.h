
#ifndef USER_H_
#define USER_H_

#include <vector>
#include <string>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;
class Watchable;
class Session;

class User{
public:
    User(const string& name);
    virtual Watchable * getRecommendation(Session& s) = 0;//returns a recommended movie/episode according to the algorithm
    string getName() const;
    vector<Watchable*> getHistory() const;

    bool isInHistory(Watchable* content);
    const void addToHistory(Watchable* watched);
    void setHistory(vector<Watchable*> h);
    void setName(string userName);
protected:
    vector<Watchable*> history;
private:
    string name;
};

//after movie, next recommendation by algorithm
//after episode, next episode. if there is no next episode - by algorithm
//if there is more than one content which fits the recommendation (for example two movies with equal length), the content with smaller index in content vector will be picked
//if no content fits the recommendation, nullptr should be returned

class LengthRecommenderUser : public User {
    //len
    //will recommend the content whose length is closest to the average length of the content in the users watch history, and isn't in history
public:
    LengthRecommenderUser(const string& name);
    virtual Watchable* getRecommendation(Session& s);
private:
};

class RerunRecommenderUser : public User {
    //rer
    //will recommend content in user's watching history, starting from first watchable, in a cyclic order
    //(i+1)mod n
public:
    RerunRecommenderUser(const string& name);
    virtual Watchable* getRecommendation(Session& s);
private:
    int i;
};

class GenreRecommenderUser : public User {
    //gen
    //will recommend on most popular tag in user's watch history, which wasn't already watched by this user
    //if no such content exists it will recommend the second most popular tag, and so on
    //if a set of tags has same popularity, it will recommend by lexicographic order
public:
    GenreRecommenderUser(const string& name);
    virtual Watchable* getRecommendation(Session& s);
private:

};

#endif