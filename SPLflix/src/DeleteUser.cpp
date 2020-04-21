//
// Created by sivan on 04/03/2020.
//

#include <include/Session.h>

void DeleteUser::act(Session & sess){
    const unordered_map<string,User*> &map = sess.getUserMap();
    string input = sess.getInput();
    int space = input.find(' ');
    string userName = input.substr(space+1);
    if(map.find(userName) == map.end())
        error("user doesn't exist");
    else{
        sess.deleteUser(userName);
        complete();
    }
    sess.addActionLog(this);
}

string DeleteUser::toString() const { return "DeleteUser " + actionToString();}
