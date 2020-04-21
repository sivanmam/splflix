
#ifndef ACTION_H_
#define ACTION_H_

#include <string>
#include <iostream>
using namespace std;
class Session;

enum ActionStatus{
    PENDING,//actions that weren't performed yet
    COMPLETED,//successfully completed
    ERROR//couldn't be completed
};

//after each action is performed its status shold be updated
class BaseAction{
public:
    BaseAction();
    ActionStatus getStatus() const;
    virtual void act(Session& sess)=0;//recieves refference to the current session as a parameter and performs an action on it
    virtual string toString() const=0;//returns a string represantation of the action and flag status

    string actionToString() const;
    string getErrorMsg() const;
    void setErrorMsg(string msg);
    void setActionStatus(ActionStatus s);
protected:
    void complete();//is called in order to change the status to completed, if the action was completed successfully
    //when an error occurs the program should print "Error - <error_message>"
    void error(const string& msg);//if the action resulted in an error, is called to change the status to error and update the error msg
private:
    string errorMsg;
    ActionStatus status;
};

//creates a new user in the current session
class CreateUser  : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual string toString() const;

};

//changes the current active user
class ChangeActiveUser : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual string toString() const;
};

//removes a given user
class DeleteUser : public BaseAction {
public:
    virtual void act(Session & sess);
    virtual string toString() const;
};

//creates a copy of the given user, wth its watch history and recommendation algorithm, but with a new name
class DuplicateUser : public BaseAction {
public:
    virtual void act(Session & sess);

    virtual string toString() const;
};

//prints all the watchable content available
class PrintContentList : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual string toString() const;
};

//prints the watch history of the current active user
class PrintWatchHistory : public BaseAction {
public:
    virtual void act (Session& sess);
    virtual std::string toString() const;
};

//watches a content
class Watch : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual string toString() const;
};

//prints all the actions that were performeby the user
class PrintActionsLog : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual string toString() const;
};

//exits the main loop
class Exit : public BaseAction {
public:
    virtual void act(Session& sess);
    virtual string toString() const;
};
#endif