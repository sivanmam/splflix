//
// Created by sivan on 03/03/2020.
//

#include <include/Action.h>
#include <include/Session.h>
#include <include/User.h>

void CreateUser::act(Session& sess){
    string input = sess.getInput();
    int space = input.find(' ');
    input.erase(0,space+1);
    int space2 = input.find(' ');
    string userName = input.substr(0, space2);
    string userAlg = input.substr(space2+1);
    const unordered_map<string,User*> &map = sess.getUserMap();
    if(map.find(userName) != map.end())
        error("username is already in use");
    else if(userAlg!="len" && userAlg!="rer" && userAlg!="gen")
        error("recommendation algorithm is invalid");
    else {
        sess.addUser(userName, userAlg);
        complete();
    }
    sess.addActionLog(this);
}

string CreateUser::toString() const { return "CreateUser " + actionToString();}