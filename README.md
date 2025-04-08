# ProgrammingCourseWork
Big assigment of building one "real" comercial project
The name of the Project is TO DO MANAGER
# Structure
3 classes:

-1) Task - contains the day's achievable goal, stored at day class

0) Goal - big tasks, that have some Types, to have opportunity to play relax and hobbies separetly from work, stored at separeted files. Finished conected with year
1) Day: Has plenty of types, to understand the difficulty of it and larger groups of days, to plan and divide difficulties though the all time you have.
2) Week: Work with a set of 7 days, one of the main structures to plan your future work, relax and others activities in short distance
3) Month: Work with a set of 30 days, planning your schedule for medium distance
4) Year: The Main component of a manager, everything leads to a year, it creates everything and track everything, except some global goals, you can use it to see whole picture and play bigger plans

Day: contains all tasks for this period

Goals have their own lists according to the type of goals. Finished goals will go to the corresponding year.

The week takes the next seven days; it takes them from the months. If the month has not been created yet (a year has not been created yet), once the dynamic week can't find enough days, then you need to create the next year, that then create every months with all days.

Month: contains all days; no other class has access to them without referencing a month.

Year: contains all months, goals for the year, and all statistics.

## Atributes:

-1) Task: Type(work(regular time), relax(doesn't count into regular time), hobbie(doesn't count into regular time), name, description, importance (1-100), difficulty (1-10), deadline (date), time to complete (shouldn't be more than 5 hours), status(Planned, In progress, Completed), time spent (factional time to complete)

0) Goal: Type(life goal(more than a year), work, hobbiie(can take time, and some difficulty, but it will not be included into overall time or difficulty), relax(shouldn't have difficulty and time to complete, doesn't count to day total time) name, description, importance (1-100), difficulty (1-100), deadline (date), time to complete (should be more than 5 hours), plan(set of Tasks), time spended
1) Day: date, Type (relax(at least one per week, not more than 2), easy day, regular day, hard day), set of Tasks for a day, overall difficulty (different litits for every type: relax < 3, easy day >= 3 and < 5, regular day >= 5 and < 10, hard day >= 10 and < 20), overall time (different litits for every type: relax < 30 minuts, easy day >= 0.5 hours and < 1.5, regular day >= 1,5 and < 3, hard day >=3 and < 6(this limit is recommendation)), thoughts after this day (how was it?)
2) Week: Type(dynamic - next 7 days, static - from Monday to Sunday), name(static), array of 7 days, overall time to complete (more than 40 hours is not recommended), overall difficulty(not more than 60), time spent (for static week), conclusion (for static completed week)
3) Month: name, array of days (positions in the year according to other months(first?, second? (It has built-in lap year recognition.) )), overall difficulty, time spent, conclusion
4) Year: name(number), set of days in every month (for month class to know how many days it has), array of Months, overall difficulty, time spent, set of goals completed, conclusion, set of goals for not finished year.


## Functions:

1) Storing and reading data
2) Showing
3) Removing data
4) Filtering
5) Calculating
6) Sorting
