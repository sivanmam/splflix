//
// Created by sivan on 28/02/2020.
//

#include "../include/Action.h"

BaseAction::BaseAction(): errorMsg(" "), status(PENDING){}

void BaseAction::complete(){status = COMPLETED;}

void BaseAction::error(const string& msg){
    this->errorMsg = msg;
    cout << "Error - " << msg << endl;
    status = ERROR;
}

string BaseAction::getErrorMsg() const{ return errorMsg;}

ActionStatus BaseAction::getStatus() const {return status;}

string BaseAction::actionToString() const{
    string s;
    switch (getStatus()){
        case PENDING:
            s.append("PENDING");
            break;
        case COMPLETED:
            s.append("COMPLETED");
            break;
        case ERROR:
            s.append("ERROR: ");
            s += getErrorMsg();
            break;
        default:
            s.append("wrong status...");
    }
    return s;
}

void BaseAction::setErrorMsg(string msg) {errorMsg = msg;}

void BaseAction::setActionStatus(ActionStatus s) {status = s;}

