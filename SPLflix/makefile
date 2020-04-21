# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
LFLAGS  = -L/usr/lib
HEADER = include/Action.h
# All Targets
all: splflix

# Tool invocations
splflix: bin/Main.o bin/Session.o bin/User.o bin/LengthRecommenderUser.o bin/RerunRecommenderUser.o bin/GenreRecommenderUser.o bin/Watchable.o bin/Episode.o bin/Movie.o bin/BaseAction.o bin/ChangeActiveUser.o bin/CreateUser.o bin/DeleteUser.o bin/DuplicateUser.o bin/Exit.o bin/PrintActionsLog.o bin/PrintContentList.o bin/PrintWatchHistory.o bin/Watch.o
	@echo 'Building target: Main'
	@echo 'Invoking: C++ Linker'
	g++ -o bin/splflix bin/Main.o bin/Session.o bin/User.o bin/LengthRecommenderUser.o bin/RerunRecommenderUser.o bin/GenreRecommenderUser.o bin/Watchable.o bin/Episode.o bin/Movie.o bin/BaseAction.o bin/ChangeActiveUser.o bin/CreateUser.o bin/DeleteUser.o bin/DuplicateUser.o bin/Exit.o bin/PrintActionsLog.o bin/PrintContentList.o bin/PrintWatchHistory.o bin/Watch.o
	@echo 'Finished building target: Main'
	@echo ' '

# Depends on the source and header files
bin/Main.o: src/Main.cpp include/Session.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Main.o src/Main.cpp
bin/BaseAction.o: src/BaseAction.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/BaseAction.o src/BaseAction.cpp
bin/ChangeActiveUser.o: src/ChangeActiveUser.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/ChangeActiveUser.o src/ChangeActiveUser.cpp
bin/CreateUser.o: src/CreateUser.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/CreateUser.o src/CreateUser.cpp
bin/DeleteUser.o: src/DeleteUser.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/DeleteUser.o src/DeleteUser.cpp
bin/DuplicateUser.o: src/DuplicateUser.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/DuplicateUser.o src/DuplicateUser.cpp
bin/Exit.o: src/Exit.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Exit.o src/Exit.cpp
bin/PrintActionsLog.o: src/PrintActionsLog.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintActionsLog.o src/PrintActionsLog.cpp
bin/PrintContentList.o: src/PrintContentList.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintContentList.o src/PrintContentList.cpp
bin/PrintWatchHistory.o: src/PrintWatchHistory.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/PrintWatchHistory.o src/PrintWatchHistory.cpp
bin/Watch.o: src/Watch.cpp include/Action.h include/User.h include/Session.h include/Watchable.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Watch.o src/Watch.cpp
bin/Session.o: src/Session.cpp include/Action.h include/User.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Session.o src/Session.cpp
bin/Watchable.o: src/Watchable.cpp include/User.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Watchable.o src/Watchable.cpp
bin/Episode.o: src/Episode.cpp include/User.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Episode.o src/Episode.cpp
bin/Movie.o: src/Movie.cpp include/User.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Movie.o src/Movie.cpp
bin/User.o: src/User.cpp include/Session.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/User.o src/User.cpp
bin/LengthRecommenderUser.o: src/LengthRecommenderUser.cpp include/Session.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LengthRecommenderUser.o src/LengthRecommenderUser.cpp
bin/RerunRecommenderUser.o: src/RerunRecommenderUser.cpp include/Session.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/RerunRecommenderUser.o src/RerunRecommenderUser.cpp
bin/GenreRecommenderUser.o: src/GenreRecommenderUser.cpp include/Session.h
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/GenreRecommenderUser.o src/GenreRecommenderUser.cpp

#Clean the build directory
clean:
	rm -f bin/*