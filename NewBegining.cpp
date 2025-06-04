#include <iostream>
#include <string>
#include <ctime>
#include <sstream>

static const int MAXYEARNUMBER = 10;
static const int MAXGOALNUMBER = 20;
static const int MAXTASKNUMBER = 10; 

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// https://stackoverflow.com/questions/78690088/display-number-of-days-in-the-current-month
// This function will get the number of days in a month
int days_in_month(int year, int month) {
    // This array contains the number of days in each month
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    // Leap year checking
    if (month == 2 && (isLeapYear(year))) {
        return 29;
    }


    return days[month - 1];
}


class Task{
    private:
        std::string _name;
        int _difficulty;
        int _importance;
        int _time_to_complete;
    public:
        std::string get_name(){
            return _name;
        }
        int get_difficulty(){
            return _difficulty;
        }
        int get_importance(){
            return _importance;
        }
        int get_time_to_complete(){
            return _time_to_complete;
        }


        void set_name(){
            std::string name;
           
            std::cout << "==================================\n";
            std::cout << "What is the name of your task?\n";


            getline(std::cin, name);
            _name = name;


            std::cout << "==================================\n";
        }
        void set_difficulty(){
            int difficulty;
            std::string input = "";
           
            std::cout << "====================================================\n"
            << "Now lets set up an the difficulty of a task\n"
            << "Enter a how difficult is your task (from 1 to 10): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> difficulty){
                    if(1<=difficulty && difficulty<=10){
                        std::cout << "====================================================\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
           
            _difficulty = difficulty;
        }
        void set_importance(){
            int importance;
            std::string input = "";
           
            std::cout << "====================================================\n"
            << "Now lets set up an importance of a task\n"
            << "Enter a how important is your task (from 1 to 10): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> importance){
                    if(1<=importance && importance<=10){
                        std::cout << "====================================================\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
           
            _importance = importance;
        }
        void set_time_to_complete(){
            int hours;
            std::string input = "";
             
            std::cout << "====================================================\n"
            << "Now lets set up a how much time you need to compete it\n"
            << "Enter a how much hours you need (from 1 to 5(if more that mean that your task could be optimized)): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> hours){
                    if(1<=hours && hours<=5){
                        std::cout << "====================================================\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
           
            _time_to_complete = hours;
        }


        void show_task(){
            std::cout << "--------------------------------------------\n";
            std::cout << "Task name: " << _name << std::endl;
            std::cout << "Difficulty: " << _difficulty << std::endl;
            std::cout << "Importance: " << _importance << std::endl;
            std::cout << "Time you expect to spent on it(hours): " << _time_to_complete << std::endl;
            std::cout << "--------------------------------------------\n";
        }
};




class Day{
    private:
        time_t _date;
        Task _array_of_tasks_for_day[MAXTASKNUMBER];
        int _tasks_stored;
        int _total_difficulty = 0;
        int _total_importance = 0;
        int _time_to_complete = 0;
    public:
        time_t get_date(){
            return _date;
        }
        int get_day_of_the_year(){
            struct tm datetime = *localtime(&_date);
            return datetime.tm_yday;
        }
        int get_year(){
            struct tm datetime = *localtime(&_date);
            return datetime.tm_year + 1900 - 2025;
        }
        int get_total_difficulty(){
            return _total_difficulty;
        }
        int get_total_importance(){
            return _total_importance;
        }
        int get_time_to_complete(){
            return _time_to_complete;
        }


        void set_date(){
            int year; int month; int day;
            std::string input = "";
             
            std::cout << "===========================================\n"
            << "Now lets set up a date for a day!\n"
            << "Enter a year of your date(>= 2025 and < 3000): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> year){
                    if(2025<=year && year<3000){
                        std::cout << "----------------------------------------------\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "Enter a month(from 1 to 12): ";
            while (true) {
               
                getline(std::cin, input);
             
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> month){
                    if(1<=month && month<=12){
                        std::cout << "----------------------------------------------\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            int days_in_the_month = days_in_month(year, month);
            std::cout << "Enter a day(from 1 to "<< days_in_the_month <<"): ";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> day){
                    if(1<=day && day<=days_in_the_month){
                        std::cout << "----------------------------------------------\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }      
       
            struct tm datetime;
            time_t timestamp;
             
            datetime.tm_year = year - 1900; // Number of years since 1900
            datetime.tm_mon = month - 1; // Number of months since January
            datetime.tm_mday = day;
            datetime.tm_hour = 0; datetime.tm_min = 0; datetime.tm_sec = 0;
            datetime.tm_isdst = -1;
       
            timestamp = mktime(&datetime);
       
            _date = timestamp;
           
        }
        
        
        void update_statistic(Task task, bool direction){
            if(direction){
                _total_difficulty += task.get_difficulty();
                _total_importance += task.get_importance();
                _time_to_complete += task.get_time_to_complete();
            } else{
                _total_difficulty -= task.get_difficulty();
                _total_importance -= task.get_importance();
                _time_to_complete -= task.get_time_to_complete();
            }
        }

        bool add_task(Task task){
            if(_tasks_stored < MAXTASKNUMBER){
                _array_of_tasks_for_day[_tasks_stored];
                update_statistic(task, 1);
                sort_array_of_tasks_by_name(1);
                _tasks_stored ++;
                return true;
            } else{
                std::cout << "Task limit for one day was reached. Please, delete old tasks or put new task to the different day\n";
                return false;
            }
        }

        void sort_array_of_tasks_by_name(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_name() > _array_of_tasks_for_day[i+1].get_name()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_name() < _array_of_tasks_for_day[i+1].get_name()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_importance(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_importance() > _array_of_tasks_for_day[i+1].get_importance()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_importance() < _array_of_tasks_for_day[i+1].get_importance()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_difficulty(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_difficulty() > _array_of_tasks_for_day[i+1].get_difficulty()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_difficulty() < _array_of_tasks_for_day[i+1].get_difficulty()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_time_to_complete(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_time_to_complete() > _array_of_tasks_for_day[i+1].get_time_to_complete()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_array_of_tasks_for_day[i].get_time_to_complete() < _array_of_tasks_for_day[i+1].get_time_to_complete()){
                            Task temp = _array_of_tasks_for_day[i];
                            _array_of_tasks_for_day[i] = _array_of_tasks_for_day[i+1];
                            _array_of_tasks_for_day[i+1] = temp;
                        }
                    }
                }
            }
        }

        void show_date(){
            char output[50];
            struct tm datetime = *localtime(&_date);
            strftime(output, 50, "%d %B %Y", &datetime);
            std::cout << output;
        }

        void show_day(){
            std::cout << "\n///////////////////////////////////////////\n"
            << "Date: ";
            show_date();
            std::cout << "\nTotal importance: " << _total_importance
            << "\nTotal difficulty: " << _total_difficulty
            << "\nTotal time to complete: " << _time_to_complete
            << "\nAll tasks:\n";
            for(int i = 0; i<_tasks_stored; i++){
                std::cout << "\nTask 1:\n";
                _array_of_tasks_for_day[i].show_task();
            }
        }
};




class Goal{
    private:
        std::string _name;
        int _difficulty;
        int _importance;
        time_t _deadline;
        Task _allTasks[MAXTASKNUMBER];
        int _tasks_stored = 0;
    public:
        std::string get_name(){
            return _name;
        }
        int get_difficulty(){
            return _difficulty;
        }
        int get_importance(){
            return _importance;
        }
        time_t get_deadline(){
            return _deadline;
        }


        void set_name(){
            std::string name;
           
            std::cout << "==================================\n";
            std::cout << "What is the name of your goal?\n";


            getline(std::cin, name);
            _name = name;


            std::cout << "==================================\n";
        }
        void set_difficulty(){
            int difficulty;
            std::string input = "";
           
            std::cout << "====================================================\n"
            << "Now lets set up an the difficulty of a goal\n"
            << "Enter a how difficult is your goal (from 1 to 100): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> difficulty){
                    if(1<=difficulty && difficulty<=100){
                        std::cout << "====================================================\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
           
            _difficulty = difficulty;
        }
        void set_importance(){
            int importance;
            std::string input = "";
           
            std::cout << "====================================================\n"
            << "Now lets set up an importance of a goal\n"
            << "Enter a how important is your goal (from 1 to 100): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> importance){
                    if(1<=importance && importance<=100){
                        std::cout << "====================================================\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
           
            _importance = importance;
           
        }
        void set_deadline(){


            int year; int month; int day; int hour;
            std::string input = "";
             
            std::cout << "===========================================\n"
            << "Now lets create a deadline!\n"
            << "Enter a year of your date(>= 2025 and < 3000): \n";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> year){
                    if(2025<=year && year<3000){
                        std::cout << "----------------------------------------------\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "Enter a month(from 1 to 12): ";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> month){
                    if(1<=month && month<=12){
                        std::cout << "----------------------------------------------\n";
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            int days_in_the_month = days_in_month(year, month);
            std::cout << "Enter a day(from 1 to "<< days_in_the_month <<"): ";
            while (true) {
               
                getline(std::cin, input);
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> day){
                    if(1<=day && day<=days_in_the_month)
                    break;
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "Enter a hour, until, what you need to finish it(from 0 to 23): \n";
            while (true) {
               
                getline(std::cin, input);      
       
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> hour){
                    if(0<=hour && hour<=23)
                    break;
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
       
            struct tm datetime;
            time_t timestamp;
     
            datetime.tm_year = year - 1900; // Number of years since 1900
            datetime.tm_mon = month - 1; // Number of months since January
            datetime.tm_mday = day;
            datetime.tm_hour = hour; datetime.tm_min = 0; datetime.tm_sec = 0;
            datetime.tm_isdst = -1;
       
            timestamp = mktime(&datetime);
       
            _deadline = timestamp;

        }

        void sort_array_of_tasks_by_name(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_name() > _allTasks[i+1].get_name()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_name() < _allTasks[i+1].get_name()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_importance(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_importance() > _allTasks[i+1].get_importance()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_importance() < _allTasks[i+1].get_importance()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_difficulty(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_difficulty() > _allTasks[i+1].get_difficulty()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_difficulty() < _allTasks[i+1].get_difficulty()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            }
        }

        void sort_array_of_tasks_by_time_to_complete(int order){
            if(order==1){
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_time_to_complete() > _allTasks[i+1].get_time_to_complete()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            } else{
                for(int i = 0; i<MAXTASKNUMBER-1; i++){
                    for(int j = i+1; j<MAXTASKNUMBER; j++){
                        if(_allTasks[i].get_time_to_complete() < _allTasks[i+1].get_time_to_complete()){
                            Task temp = _allTasks[i];
                            _allTasks[i] = _allTasks[i+1];
                            _allTasks[i+1] = temp;
                        }
                    }
                }
            }
        }

        bool add_task(Task task){
            if(_tasks_stored < MAXTASKNUMBER){
                _allTasks[_tasks_stored];
                _tasks_stored ++;
                return true;
            } else{
                std::cout << "Task limit for one goal was reached. Please, delete old tasks or put new task to the different goal\n";
                return false;
            }
        }


        void show_goal(){
            char output[50];

            struct tm datetime = *localtime(&_deadline);

            strftime(output, 50, "%a, %d %B %Y    %H:%M", &datetime);

            std::cout << "//////////////////////////////////////////\n"
            << "Name of the goal: " << _name 
            << "\nImportance: " << _importance 
            << "\nDifficulty: " << _difficulty
            << "\nDeadline: " << output
            << "\nAll tasks connected to the goal:";
            for(int i = 0; i<_tasks_stored; i++){
                std::cout << "\nTask "<< i << " - ";
                _allTasks[i].show_task();
            }
            std::cout << "\n//////////////////////////////////////////\n";
        }
     
};

void structureGoalsByNames(Goal* allGoals, int order){
    if(order==1){
        for(int i = 0; i<MAXGOALNUMBER-1; i++){
            for(int j = i+1; j<MAXGOALNUMBER; j++){
                if(allGoals[i].get_name() > allGoals[i+1].get_name()){
                    Goal temp = allGoals[i];
                    allGoals[i] = allGoals[i+1];
                    allGoals[i+1] = temp;
                }
            }
        }
    } else{
        for(int i = 0; i<MAXGOALNUMBER-1; i++){
            for(int j = i+1; j<MAXGOALNUMBER; j++){
                if(allGoals[i].get_name() < allGoals[i+1].get_name()){
                    Goal temp = allGoals[i];
                    allGoals[i] = allGoals[i+1];
                    allGoals[i+1] = temp;
                }
            }
        }
    }
}    


struct YearData{
    int year;
    Day** Days;
    int totaldays;
};

void create_year(int year, YearData allYears[MAXYEARNUMBER]){
    if(year<2025+MAXYEARNUMBER){
        YearData new_year;
        new_year.year = year;
        if(isLeapYear(year)){
            Day* yearDays[366];
            new_year.Days = yearDays;
            new_year.totaldays = 366;
        }
        else{
            Day* yearDays[365];
            new_year.Days = yearDays;
            new_year.totaldays = 365;
        }
        allYears[year-2025] = new_year;
    } else{
        std::cout << "Error of creating a year. Max year is 2034.\n";
    }
}


void create_day(YearData allYears[]){
    Day random_day;
    random_day.set_date();
    allYears[random_day.get_year()].Days[random_day.get_day_of_the_year()] = &random_day; // add day to the year at the day of the year position
}


void create_goal(Goal* allGoals, int& totalGoals){
    if(totalGoals == MAXGOALNUMBER)
        std::cout << "Goal number have reach his limit " << MAXGOALNUMBER
        <<"\nTo create new delete one of the old one.\n";
    else{
        Goal random_goal;
        random_goal.set_name();
        random_goal.set_importance();
        random_goal.set_difficulty();
        random_goal.set_deadline();
        random_goal.show_goal();
        allGoals[totalGoals] = random_goal;
        structureGoalsByNames(allGoals, 1);
        totalGoals ++;
    }
}

void connecting_task_with_a_goal(Goal allGoals[], int totalGoal){
    std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
    << "Now lets connect it with a goal\n"
    << "Chose the goal you want it to connect with:\n";
    for(int i = 0; i<totalGoal; i++){
        std::cout << "Type " << i << " to chose " << allGoals[i].get_name() << std::endl;
    }
    int goal;
    while (true) {
        std::string input = "";
        getline(std::cin, input);

        // This code converts from string to number safely.
        std::stringstream myStream(input);
        if (myStream >> goal){
            if(0<goal && goal<MAXYEARNUMBER){
                break;
            }
        }
        std::cout << "Invalid number, please try again\n";
        std::cout << "Please enter a valid number: \n";
    }
}

void creation_of_a_task(YearData allYears[], Goal allGoal[], int totalGoal,  int answer){
    Task newtask;
    newtask.set_name();
    newtask.set_importance();
    newtask.set_difficulty();
    newtask.set_time_to_complete();
    newtask.show_task();

    connecting_task_with_a_day(allYears, newtask);
    if(answer==2)
        connecting_task_with_a_goal(allGoal, totalGoal);
}

void connecting_task_with_a_day(YearData allYears[], Task newtask){
    bool yes = false;
    while(!yes){
        std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n" 
        << "Now lets connect it with a day\n" 
        << "Chose the year:\n";
        for(int i = 0; i<MAXYEARNUMBER; i++){
            std::cout << "Type " << i << " for " << allYears[i].year << " year;\n";
        }
        int year;
        while (true) {
            std::string input = "";
            getline(std::cin, input);

            // This code converts from string to number safely.
            std::stringstream myStream(input);
            if (myStream >> year){
                if(0<year && year<MAXYEARNUMBER){
                    break;
                }
            }
            std::cout << "Invalid number, please try again\n";
            std::cout << "Please enter a valid number: \n";
        }
        std::cout << "\nYou chose " << allYears[year].year << " year\n"
        << "------------------------------------------------\n"
        << "Now chose the day:\n";
        for(int i = 0; i<allYears->totaldays; i++){
            std::cout << "Type " << i << "to chose ";
            allYears[year].Days[i]->show_date();
        }
        int day;
        while (true) {
            std::string input = "";
            getline(std::cin, input);

            // This code converts from string to number safely.
            std::stringstream myStream(input);
            if (myStream >> day){
                if(0<day && day<MAXYEARNUMBER){
                    break;
                }
            }
            std::cout << "Invalid number, please try again\n";
            std::cout << "Please enter a valid number: \n";
        }
        std::cout << "\nYou chose ";
        allYears[year].Days[day]->show_date();
        if(allYears[year].Days[day]->add_task(newtask)){
                std::cout << "Your task is successfully stored and connected to a day.\n"
                << "+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
        }else{
            std::cout << "Choose what you want to do:\n"
            << "Type 0 to try again;\n"
            << "Type 1 to exit with losing your new task;\n";
            int decision;
            while (true) {
                std::string input = "";
                getline(std::cin, input);

                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> decision){
                    if(-1<decision && decision<2){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            if(decision == 1){
                yes = true;
            }
        }
    }
}


void create_task(YearData allYears[], Goal allGoal[], int totalGoals){
    std::cout << "\n///////////////////////////////////////////////////////////////////////////////////\n";
    std::cout << "To create a task you need to connect it with a day, and potentially with a goal.\n"
    << "Press 0 to exit.\n"
    << "Press 1 to connect only with a day\n"
    << "Press 2 to connect with a goal too\n"
    << "///////////////////////////////////////////////////////////////////////////////////\n"
    << "\nEnter what you want to do: ";
    
    int answer;
    while (true) {
        std::string input = "";
        getline(std::cin, input);

        // This code converts from string to number safely.
        std::stringstream myStream(input);
        if (myStream >> answer){
            if(0<=answer && answer<=2){
                break;
            }
        }
        std::cout << "Invalid number, please try again\n";
        std::cout << "Please enter a valid number: \n";
    }

    if(answer > 0)
        creation_of_a_task(allYears, allGoal, totalGoals, answer);

}


int main(){
    YearData allYears[MAXYEARNUMBER];
    for(int i = 2025; i < 2025+MAXYEARNUMBER; i++){
        create_year(i, allYears);
    }
    Goal allGoals[MAXGOALNUMBER];
    int totalGoal = 0;
    std::cout << "*****************************************************************************\n";
    std::cout << "Hello, welcome to the task manager. Chose the option, what you want to do:\n"
    << "1 - Create a day;\n"
    << "2 - Create a goal;\n"
    << "3 - Create a task;\n"
    << "4 - Show day;\n"
    << "5 - Show goal;\n"
    << "6 - Delete a day;\n"
    << "7 - Delete a goal;\n"
    << "8 - Delete a task;\n"
    << "9 - End program;\n";
    std::cout << "*****************************************************************************\n"
    << "\nPlease enter what you want to do: ";

    int answer;
    while (true) {
        std::string input = "";
        getline(std::cin, input);

        // This code converts from string to number safely.
        std::stringstream myStream(input);
        if (myStream >> answer){
            if(1<=answer && answer<=9){
                break;
            }
        }
        std::cout << "Invalid number, please try again\n";
        std::cout << "Please enter a valid number: \n";
    }

    switch(answer){
        case 1:
            create_day(allYears);
        case 2:
            create_goal(allGoals, totalGoal);
        case 3:
            create_task(allYears, allGoals, totalGoal);
        case 4:
            std::cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++\n" 
            << "Now lets find a day that you what to show\n" 
            << "Chose the year:\n";
            for(int i = 0; i<MAXYEARNUMBER; i++){
                std::cout << "Type " << i << " for " << allYears[i].year << " year;\n";
            }
            int year;
            while (true) {
                std::string input = "";
                getline(std::cin, input);

                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> year){
                    if(0<year && year<MAXYEARNUMBER){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "\nYou chose " << allYears[year].year << " year\n"
            << "------------------------------------------------\n"
            << "Now chose the day:\n";
            for(int i = 0; i<allYears->totaldays; i++){
                std::cout << "Type " << i << "to chose ";
                allYears[year].Days[i]->show_date();
            }
            int day;
            while (true) {
                std::string input = "";
                getline(std::cin, input);

                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> day){
                    if(0<day && day<MAXYEARNUMBER){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "\nYou chose ";
            allYears[year].Days[day]->show_date();
            std::cout << "\n===========================================\n"
            << "Now choose the order that you want to see tasks inside the day:\n"
            << "By name - 1\n"
            << "By importance - 2\n"
            << "By difficulty - 3\n"
            << "By time to complete - 4\n"
            << "Choose out of provided variant: ";
            int order;
            while (true) {
                std::string input = "";
                getline(std::cin, input);
        
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> order){
                    if(1<=order && order<=4){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }

            std::cout << "Now chose in what order:\n" 
            << "Ascending - 1\n"
            << "Descending - 0\n"
            << "Choose order:";
            int another_order;
            while (true) {
                std::string input = "";
                getline(std::cin, input);
        
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> another_order){
                    if(0<=another_order && another_order<=1){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            switch(order){
                case 1:
                    allYears[year].Days[day]->sort_array_of_tasks_by_name(another_order);
                case 2:
                    allYears[year].Days[day]->sort_array_of_tasks_by_importance(another_order);
                case 3:
                    allYears[year].Days[day]->sort_array_of_tasks_by_difficulty(another_order);
                case 4:
                    allYears[year].Days[day]->sort_array_of_tasks_by_time_to_complete(another_order);
            }
            allYears[year].Days[day]->show_day();
            std::cout << "===============================================\n";

        case 5:
            std::cout << "===============================================\n"
            << "Now choose the goal you want to see:";
            for(int i = 0; i>totalGoal; i++){
                std::cout << "\nGoal " << i << " - " << allGoals[i].get_name();
            }
            std::cout << "\nWhat is your choice?\n";
            int goal;
            while (true) {
                std::string input = "";
                getline(std::cin, input);

                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> goal){
                    if(0<goal && goal<MAXYEARNUMBER){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            std::cout << "\n----------------------------------------------------\n"
            << "Now choose the order that you want to see tasks inside the goal:\n"
            << "By name - 1\n"
            << "By importance - 2\n"
            << "By difficulty - 3\n"
            << "By time to complete - 4\n"
            << "Choose out of provided variant: ";
            int order;
            while (true) {
                std::string input = "";
                getline(std::cin, input);
        
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> order){
                    if(1<=order && order<=4){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }

            std::cout << "Now chose in what order:\n" 
            << "Ascending - 1\n"
            << "Descending - 0\n"
            << "Choose order:";
            int another_order;
            while (true) {
                std::string input = "";
                getline(std::cin, input);
        
                // This code converts from string to number safely.
                std::stringstream myStream(input);
                if (myStream >> another_order){
                    if(0<=another_order && another_order<=1){
                        break;
                    }
                }
                std::cout << "Invalid number, please try again\n";
                std::cout << "Please enter a valid number: \n";
            }
            switch(order){
                case 1:
                    allGoals[goal].sort_array_of_tasks_by_name(another_order);
                case 2:
                    allGoals[goal].sort_array_of_tasks_by_importance(another_order);
                case 3:
                    allGoals[goal].sort_array_of_tasks_by_difficulty(another_order);
                case 4:
                    allGoals[goal].sort_array_of_tasks_by_time_to_complete(another_order);
            }
            allGoals[goal].show_goal();
            std::cout << "===============================================\n";


        
        // case 6:
        
        // case 7:
        
        // case 8:
        
        // case 9:

    }

}





