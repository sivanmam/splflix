//
// Created by sivan on 04/03/2020.
//

#include <include/Session.h>
#include <include/Watchable.h>


void PrintContentList::act (Session& sess){
    const vector<Watchable*> &content = sess.getContent();
    for(const auto c: content){
        string str;
        str += to_string(c->getId()) + ". " + c->toString() + " " + to_string(c->getLength()) + " minutes [";
        for(const string& t: c->getTags())
            str += t + ", " ;
        string out = str.substr(0, str.size()-2);
        out += "]";
        cout << out << endl;
    }
    complete();
    sess.addActionLog(this);
}

string PrintContentList::toString() const { return "PrintContentList " + actionToString();}
