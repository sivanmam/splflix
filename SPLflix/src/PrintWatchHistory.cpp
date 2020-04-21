//
// Created by sivan on 05/03/2020.
//

#include <include/Session.h>
#include <include/User.h>
#include <include/Watchable.h>



void PrintWatchHistory::act (Session& sess){
    User &user = sess.getActiveUser();
    cout << "Watch history for " + user.getName() << endl;
    int i = 1;
    for(auto h: user.getHistory())
        cout << i++ << ". " <<  h->toString() << endl;
}

string PrintWatchHistory::toString() const{
    return "PrintWatchHistory " + actionToString();
}
