//
// Created by sivan on 05/03/2020.
//

#include <include/Session.h>
#include <include/Watchable.h>
#include <include/User.h>
#include <sstream>

void Watch::act(Session& sess){
    string input = sess.getInput();
    int space = input.find(" ");
    string strId = input.substr(space+1);
    stringstream str(strId);
    int id = 0;
    str >> id;
    bool flag = false;
    User &user = sess.getActiveUser();
    Watchable *watchable = sess.getContentAt(id);
    cout << "Watcing " + watchable->toString() << endl;
    user.addToHistory(sess.getContentAt(id));
    do {
        watchable = watchable->getNextWatchable(sess);
        cout << "we recommend watching " << watchable->toString()
             << " continue watching[y/n]" << endl;
        string ans = "";
        getline(cin, ans);
        if (ans == "y") {
            user.addToHistory(watchable);
            cout << "Watching " + watchable->toString() << endl;
        }
        else
            flag = true;
    }while (!flag);
    complete();
    sess.addActionLog(this);
}

string Watch::toString() const{return "Watch " + actionToString();}