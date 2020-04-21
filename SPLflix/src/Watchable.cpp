//
// Created by sivan on 28/02/2020.
//

#include "../include/Watchable.h"

Watchable::Watchable(long id, int length, const std::vector<std::string>& tags): id(id), length(length), tags(tags){}

Watchable::~Watchable(){tags.clear();}

long Watchable::getId() const{ return id;}

int Watchable::getLength() const {return length;}

vector<string> Watchable::getTags() const {return tags;}
