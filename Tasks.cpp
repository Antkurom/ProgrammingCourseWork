#include <iostream>
#include <string>
#include <ctime>

enum Type : unsigned char
{
    Work = 0, Relax, Hobby
};
enum Status : unsigned char
{
    Plan = 0, InProgress, Completed
};

class Task
{
    std::string _name;
    std::string _description;

    short _importance;
    short _difficulty;
    
    time_t _deadline;
    time_t _time_to_complete;
    time_t _time_spend;

    Type _type; 
    Status _status;

    public:

    //-----------Get programs--------------
    std::string get_name(Task self)
    {
        return self._name;
    }
    std::string get_description(Task self)
    {
        return self._description;
    }


    short get_importance(Task self)
    {
        return self._importance;
    }
    short get_difficulty(Task self)
    {
        return self._difficulty;
    }


    time_t get_deadline(Task self)
    {
        return self._deadline;
    }

    time_t get_time_to_complete(Task self)
    {
        return self._time_to_complete;
    }

    time_t get_time_spend(Task self)
    {
        return self._time_spend;
    }


    Type get_type(Task self)
    {
        return self._type;
    }

    Status get_status(Task self)
    {
        return self._status;
    }
    
    // ------------Set programs--------------
    void set_name(Task self, std::string newName)
    {
        self._name = newName;
    }
    
    void set_description(Task self, std::string newDescription)
    {
        self._description = newDescription;
    }

    void set_importance(Task self, int newImportance)
    {
        if(0 < newImportance > 10)
        {
            self._importance = newImportance;
        } 
        else 
        {
            std::cout << "Error. Importance has negative or too high value\n";
        }
    }

    void set_difficulty(Task self, int newDifficulty)
    {
        if(0 < newDifficulty > 10)
        {
            self._difficulty = newDifficulty;
        } 
        else
        {
            std::cout << "Error. Difficulty has negative or too high value, it should be in range from 0 to 10\n";
        }
    }

    void set_deadline(int year, int month, int day, int hour, int day_in_month, int minutes = 0)
    {
        struct tm deadline; // Declaration of a structure form ctime to set a deadline

        if (1900 < year < 3000)
        {
            deadline.tm_year = year - 1900; // Cout start from 1900, so to enter a correct value we have to subscribe
        } 
        else 
        {
            std::cout << "Error, unrealistic year's value\n";
        }
        
        if (0 < month <= 12)
        {
            deadline.tm_mon = month - 1;
        } 
        else
        {
            std::cout << "Error. There is no such month\n";
        }

        if (0 < day <= day_in_month)
        {
            deadline.tm_mday = day;
        } 
        else
        {
            std::cout << "Error. Incorrect day, there is no such day in such month\n";
        }
        
        if (0 <= hour < 24)
        {
            deadline.tm_hour = hour;
        }
        else
        {
            std::cout << "Error. There is no such hour in a day\n";
        }

        if (0 <= minutes < 60)
        {
            deadline.tm_min = minutes;
        }
        else 
        {
            std::cout << "Error. There is no such minute in an hour\n";
        }
        
        deadline.tm_isdst = -1; // Set that use local time

        mktime(&deadline); // Set a deadline

    }

    void set_time_to_complete(int time_expected)
    {

    }
    void set_time_spend();

    void set_type();
    void set_status(Task self, Status newStatus)
    {
        self._status = newStatus;
    }

};

int main()
{

}