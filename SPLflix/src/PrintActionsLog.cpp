//
// Created by sivan on 05/03/2020.
//

#include <include/Session.h>

void PrintActionsLog::act(Session& sess){
    const vector<BaseAction*> &actions = sess.getActionsLog();
    for(auto a: actions)
        cout << a->toString() << endl;
    complete();
    sess.addActionLog(this);
}

string PrintActionsLog::toString() const{
    return "PrintActionsLog " + actionToString();
}