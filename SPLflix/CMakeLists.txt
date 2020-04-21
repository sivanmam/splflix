cmake_minimum_required(VERSION 3.15)
project(untitled3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)
include_directories(src)


add_executable(untitled3
        include/Action.h
        include/Json.hpp
        include/Session.h
        include/User.h
        include/Watchable.h
        src/Action.cpp
        src/Session.cpp
        src/User.cpp
        src/Watchable.cpp
        src/CreateUser.cpp
        src/ChangeActiveUser.cpp
        src/DeleteUser.cpp
        src/DuplicateUser.cpp
        src/PrintContentList.cpp
        src/PrintActionsLog.cpp
        src/PrintWatchHistory.cpp
        src/Exit.cpp
        src/Watch.cpp
        src/Episode.cpp
        src/LengthRecommenderUser.cpp
        src/RerunRecommenderUser.cpp
        src/GenreRecommenderUser.cpp
        src/Movie.cpp
        src/main.cpp)