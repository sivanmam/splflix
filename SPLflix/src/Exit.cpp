//
// Created by sivan on 05/03/2020.
//

#include <include/Session.h>

void Exit::act(Session& sess){
    sess.makeTerminate();
    complete();
    sess.addActionLog(this);
}

string Exit::toString() const{return "Exit " + actionToString();}