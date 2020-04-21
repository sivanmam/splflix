//
// Created by sivan on 11/03/2020.
//

#include <include/Session.h>

void DuplicateUser::act(Session & sess){
    string input = sess.getInput();
    int space = input.find(' ');
    input.erase(0,space+1);
    int space2 = input.find(' ');
    string userToDup = input.substr(0, space2);
    string newUser = input.substr(space2+1);
    const unordered_map<string,User*> &map = sess.getUserMap();
    if(map.find(userToDup) == map.end())
        error("user doesn't exist");
    else if(map.find(newUser) != map.end())
        error("username is already in use");
    else {
        sess.duplicateUser(userToDup, newUser);
        complete();
    }
    sess.addActionLog(this);
}

string DuplicateUser::toString() const{return "DuplicateUser " + actionToString();}