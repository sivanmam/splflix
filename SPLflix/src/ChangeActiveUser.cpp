//
// Created by sivan on 03/03/2020.
//

#include <include/Action.h>
#include <include/Session.h>

void ChangeActiveUser::act(Session &sess) {
    const unordered_map<string,User*> &map = sess.getUserMap();
    string input = sess.getInput();
    int space = input.find(' ');
    string userName = input.substr(space+1);
    if(map.find(userName) == map.end())
        error("username does not exist");
    else{
        auto it = map.find(userName);
        sess.changeActiveUser(it->second);
        complete();
    }
    sess.addActionLog(this);
}

string ChangeActiveUser::toString() const{return "ChangeUser " + actionToString();}