# ProgrammingCourseWork
Big assigment of building one "real" comercial project
The name of the Project is TO DO MANAGER
# Structure
6 classes:

-1) Task - contains the day's achievable goal

0) Goal - big task
1) Day - tasks for one day 
2) Week - work with a set of 7 days, planning your schedule for small distance
3) Month: Work with a set of 30 days, planning your schedule for medium distance
4) Year: The Main component of a manager, everything leads to a year, it creates everything and track everything, except some global goals, you can use it to see whole picture and plan bigger plans



## Atributes:

-1) Task: Type(work(regular time), relax(doesn't count into regular time), hobbie(count into regular time), name, description, importance (1-100), difficulty (1-10), deadline (date), time to complete (shouldn't be more than 5 hours), status(Planned, In progress, Completed), time spent (factional time to complete)

0) Goal: Type(life goal(more than a year), work, hobbiie(can take time, and some difficulty, but it will not be included into overall time or difficulty), relax(shouldn't have difficulty and time to complete, doesn't count to day total time)), name, description, importance (1-100), difficulty (1-100), deadline (date), time to complete (should be more than 5 hours), plan(set of Tasks), time spended, ID(optional)
1) Day: date, Type (relax(at least one per week, not more than 2), easy day, regular day, hard day), set of Tasks for a day, overall difficulty (different litits for every type: relax < 3, easy day >= 3 and < 5, regular day >= 5 and < 10, hard day >= 10 and < 20), time expected (different litits for every type: relax < 30 minuts, easy day >= 0.5 hours and < 1.5, regular day >= 1,5 and < 3, hard day >=3 and < 6(this limit is recommendation)), time spended, thoughts after this day (how was it?)
2) Week: name(what week it is), array of 7 days(links), difficulty(not more than 60), time to complete (more than 40 hours is not recommended), time spent, conclusion
3) Month: name, array of days (positions in the year according to other months(first?, second? (It has built-in lap year recognition.))), difficulty, time to complete, time spent, conclusion
4) Year: name(number), set of every month, set of every week, array of Months, overall difficulty, time spent, set of goals completed, conclusion, set of goals for not finished year.


## Storing structure

Goals --> Life goals --> List of goals (goals that require more than one year); each has a unique ID(0-2999)

Goals --> work --> List of goals (theoretically completable in one year - that related to life goal, if not connected make it as hobbie)

Goals --> hobbie --> List of goals (Side projects that are not connected to life goals, also have a unique ID(start from 3000-6999)

Goals --> relax --> List of goals (It could be watching a series, completing a game, visiting another country, and so on)

List of goals --> goal --> plan (list of tasks related to the goal, list have only links to all tasks that are stored in days

Year --> 12 months --> 365(366) days (each month has a corresponding number of days)

Year --> 53(54) weeks --> links to days in months

Day --> list of tasks

Life achievements --> only finished goals or tasks, chosen only by user

Finished elements will be stored in the same place, but some linking to higher elements like week, month, and year will be added link of finished goal or task

## Functions:

For changing and showing existing data, I will be using encapsulation methods. (get and set).
You can change absolutely anything, but there will be limitations on what value you can change.

Showing methods will show you everything, but you can choose in what order you want to see this data(sorting):

Day (show tasks for a day) - date(by default) type, importance, difficulty, deadline, time to complete; (you can chooce the statuc too, what to show, that is sorthing and it will be implemented in most classes)

Week (show days) - by date(by default), type, difficulty, importance, time expected

Month is the same as week but bigger and has a unique format 

Year (show weeks or months) - by difficulty, time to complete, time spent.


Delete you can only tasks in days or goals, and everything that uses that. Everything else you can refresh (year only delete)


Most data in day, week, month, and year will be calculated (difficulty, importance, time to complete, time spent)

## Additional features:

Timer to track the time the user esed to complete the task, if you can do it online. Otherwise you will need to enter this value by hand.

* Description writing - I want to create a possability to write description with possabilities as in word (Bold, cursive, font size, font style) But I don't know if it is possible
* Add a tutorial on how to properly use this app (explanation of why there are such recommendations on difficulty and time per day, week). Explaining the philosophy of it with proves from science or videos.

** Add productivity features like POMODORA to make work more efficient and healthier

***** Add a new way how to use this app for advanced users. It is similar to using a terminal in a Unix operating system, where there will be only commands with flags.
