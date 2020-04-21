//
// Created by sivan on 28/02/2020.
//
#include <fstream>
#include <include/User.h>
#include "../include/Session.h"
#include "../include/Json.hpp"
#include "../include/Watchable.h"

using json = nlohmann::json;

Session::Session(const string &configFilePath): content(), actionsLog(), userMap(), activeUser(nullptr), terminate(false), input(""){
    User *default1 = new LengthRecommenderUser("default");
    userMap.insert({"default", default1});
    activeUser = default1;
    readJson(configFilePath);
}

Session::~Session(){
    deleteOldData();
}

Session::Session(const Session &s): content(), actionsLog(), userMap(), activeUser(nullptr), terminate(false), input("") {
    copy(s);
}

Session &Session::operator=(const Session &other) {
    if(this != &other){
        deleteOldData();
        copy(other);
    }
    return *this;
}

Session::Session(Session &&other): actionsLog(other.actionsLog), content(other.content), userMap(other.userMap), activeUser(other.activeUser) {
    if(this != &other){
        content = move(other.content);
        actionsLog = move(other.actionsLog);
        userMap = move(other.userMap);
        other.activeUser = nullptr;
    }
}

Session &Session::operator=( Session &&other) {
    if(this != &other){
        content = move(other.content);
        actionsLog = move(other.actionsLog);
        userMap = move(other.userMap);
        activeUser = other.activeUser;
        other.activeUser = nullptr;
    }
    return *this;
}

void Session::deleteOldData() {
    for(auto c: content)
        delete c;
    content.clear();
    for(auto a: actionsLog)
        delete a;
    actionsLog.clear();
    activeUser = nullptr;
    for(auto u: userMap)
        delete u.second;
    userMap.clear();
}

void Session::copy(const Session &s) {
    for (auto c: s.getContent())
        content.push_back(c->clone());
    for (auto a: s.getActionsLog()) {
        string actionType = typeid(*a).name();
        if (actionType == "4Exit") {
            BaseAction *action = new Exit();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "10CreateUser") {
            BaseAction *action = new CreateUser();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "16ChangeActiveUser") {
            BaseAction *action = new ChangeActiveUser();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "10DeleteUser") {
            BaseAction *action = new DeleteUser();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "13DuplicateUser") {
            BaseAction *action = new DuplicateUser();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "16PrintContentList") {
            BaseAction *action = new PrintContentList();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "17PrintWatchHistory") {
            BaseAction *action = new PrintWatchHistory();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "5Watch") {
            BaseAction *action = new Watch();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        } else if (actionType == "15PrintActionsLog") {
            BaseAction *action = new PrintActionsLog();
            action->setErrorMsg(a->getErrorMsg());
            action->setActionStatus(a->getStatus());
            actionsLog.push_back(action);
        }
    }

    for (const auto& u: s.getUserMap()){
        vector<Watchable*> oldHistory = u.second->getHistory();
        vector<Watchable*> newHistory;
        for(auto h: oldHistory) {
            long id = h->getId();
            newHistory.push_back(getContentAt(id));
        }
        string newName = u.first;
        string userType = typeid(*u.second).name();
        if(userType == "21LengthRecommenderUser") {
            User *newUser = new LengthRecommenderUser(newName);
            newUser->setHistory(newHistory);
            newUser->setName(newName);
            userMap.insert({newName, newUser});
        }
        else if(userType == "20GenreRecommenderUser"){
            User *newUser = new GenreRecommenderUser(newName);
            newUser->setHistory(newHistory);
            newUser->setName(newName);
            userMap.insert({newName, newUser});
        }
        else if(userType == "20RerunRecommenderUser"){
            User *newUser = new RerunRecommenderUser(newName);
            newUser->setHistory(newHistory);
            newUser->setName(newName);
            userMap.insert({newName, newUser});
        }
    }
 //   userMap = s.getUserMap();
    activeUser = &s.getActiveUser();
    }

void Session::start(){
    cout << "SPLFLIX is now on!" << endl;
    terminate = false;
    while(!terminate){
        getline(cin, input);
        int space = input.find(' ');
        string action = input.substr(0, space);
        if(action == "createuser"){
            BaseAction *createUser = new CreateUser();
            createUser->act(*this);
        }
        else if(action == "changeuser"){
            BaseAction *changeUser = new ChangeActiveUser();
            changeUser->act(*this);
        }
        else if(action == "deleteuser"){
            BaseAction *deleteUser = new DeleteUser();
            deleteUser->act(*this);
        }
        else if(action == "dupuser"){
            BaseAction *duplicateUser = new DuplicateUser();
            duplicateUser->act(*this);
        }
        else if(action == "content"){
            BaseAction *printContent = new PrintContentList();
            printContent->act(*this);
        }
        else if(action == "watchhist"){
            BaseAction *printWatchHist = new PrintWatchHistory();
            printWatchHist->act(*this);
        }
        else if(action == "watch"){
            BaseAction *watch = new Watch();
            watch->act(*this);
        }
        else if(action == "log"){
            BaseAction *printActionsLog = new PrintActionsLog();
            printActionsLog->act(*this);
        }
        else if(action == "exit"){
            BaseAction *exit = new Exit();
            exit->act(*this);
        }
        else
            cout << "wrong input, try again" << endl;
    }
}


void Session::readJson(const string &configFilePath) {
    ifstream i(configFilePath);
    json j;
    i >> j;
    int id = 1;
    for(const auto &movie: j["movies"]) {
        string name(movie["name"].get<string>());
        int length(movie["length"].get<int>());
        vector<string> tags(movie["tags"].get<vector<string>>());
        content.push_back(new Movie(id, name, length, tags));
        id++;
    }

    for(const auto &series: j["tv_series"]){
        string name(series["name"].get<string>());
        int length(series["episode_length"].get<int>());
        vector<string> tags(series["tags"].get<vector<string>>());
        vector<int> seasons(series["seasons"].get<vector<int>>());
        Episode *lastEpisode = nullptr;
        int seasonNum = 1;
        for(int season : seasons){
            for(int episodeNum = 1; episodeNum<= season; episodeNum++) {
                Episode *newEpisode = new Episode(id, name, length, seasonNum, episodeNum, tags);
                content.push_back(newEpisode);
                id++;
                lastEpisode = newEpisode;
            }
            lastEpisode->setNextEpisodeId(-1);
            seasonNum++;
        }
    }
}

User &Session::getActiveUser() const {return *activeUser;}

const unordered_map<string,User*> &Session::getUserMap() const { return userMap;}

string Session::getInput(){ return input;}

void Session::addUser(const string& userName, const string& userAlg){
    if(userAlg == "len") {
        User *newUser = new LengthRecommenderUser(userName);
        userMap.insert({userName, newUser});
    }
    else if(userAlg == "rer") {
        User *newUser = new RerunRecommenderUser(userName);
        userMap.insert({userName, newUser});
    }
    else {
        User *newUser = new GenreRecommenderUser(userName);
        userMap.insert({userName, newUser});
    }
    }

void Session::addActionLog(BaseAction *action) {actionsLog.push_back(action);}

void Session::changeActiveUser(User *user) {activeUser = user;}

void Session::deleteUser(const string& userName) {userMap.erase(userName);}

const vector<Watchable *> &Session::getContent() const {return content;}

const vector<BaseAction *> &Session::getActionsLog() const {return actionsLog;}

void Session::makeTerminate() {terminate = true;}

Watchable* Session::getContentAt(int id) const {return content.at(id - 1);}

void Session::duplicateUser(const string& userName , string dupName) {
    auto it = userMap.find(userName);
    vector<Watchable*> oldHistory = it->second->getHistory();
    vector<Watchable*> newHistory;
    for(auto h: oldHistory) {
        long id = h->getId();
        newHistory.push_back(getContentAt(id));
    }
    User *user = it->second;
    string userType = typeid(*user).name();
    if(userType == "21LengthRecommenderUser") {
        User *newUser = new LengthRecommenderUser(dupName);
        newUser->setHistory(newHistory);
        newUser->setName(dupName);
        userMap.insert({dupName, newUser});
    }
    else if(userType == "20GenreRecommenderUser"){
        User *newUser = new GenreRecommenderUser(dupName);
        newUser->setHistory(newHistory);
        newUser->setName(dupName);
        userMap.insert({dupName, newUser});
    }
    else if(userType == "20RerunRecommenderUser"){
        User *newUser = new RerunRecommenderUser(dupName);
        newUser->setHistory(newHistory);
        newUser->setName(dupName);
        userMap.insert({dupName, newUser});
    }
}










