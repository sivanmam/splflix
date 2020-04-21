#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <unordered_map>
#include <string>
#include "Action.h"
using namespace std;
class User;
class Watchable;

class Session{
public:
    Session(const string &configFilePath);
    ~Session();

    Session(const Session &s);
    Session(Session &&other);
    Session &operator=(const Session &other);
    Session &operator=(Session &&other);
    //once the program starts it opens the splflix by printing "SPLFLIX is now on!"
    //initializing a default watching user with name "default" and algorithm "Length recommender"
    //the program enters a loop , it waits for the user to enter an action.
    //the loop ends when the user enters "exit"
    //the session can be stated again after the exit command should only exit the main loop and not change the data structures
    void start();

    User &getActiveUser() const;
    const unordered_map<string,User*> &getUserMap () const;
    string getInput();
    const vector<Watchable*> &getContent() const;
    Watchable* getContentAt(int id) const;
    const vector<BaseAction*> &getActionsLog() const;
    void makeTerminate();
    void addUser(const string& userName, const string& userAlg);
    void addActionLog(BaseAction* action);
    void changeActiveUser(User *user);
    void deleteUser(const string& userName);
    void copy(const Session &s);
    void deleteOldData();
    void duplicateUser(const string& userName, string dupName);

private:
    vector<Watchable*> content;//avalable watching content
    vector<BaseAction*> actionsLog;//history of all actions
    unordered_map<string,User*> userMap;//list of users
    User* activeUser;//currently active user

    void readJson(const string &configFilePath);
    bool terminate;
    string input;
};
#endif