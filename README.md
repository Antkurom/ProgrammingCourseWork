# ProgrammingCourseWork
Big assigment of building one "real" comercial project
The name of the Project is TO DO MANAGER
# Structure
3 classes:

-1) Task?

0) Goal?
1) Day: This will be the main component of every other class, and it will work with tasks and contain a plan for a day
2) Week: work with the next 7 days containing a plan for a week
3) Month?
4) Year: work with one year


## Atributes:

-1) Task: Type(work(regular time), relax(doesn't count into regular time), hobbie(doesn't count into regular time), name, description, importance (1-100), difficulty (1-10), deadline (date), time to complete (shouldn't be more than 5 hours), status(Planned, In progress, Completed), time spent (factional time to complete)

0) Goal: Type(life goal(more than a year), work, hobbiie(can take time, and some difficulty, but it will not be included into overall time or difficulty), relax(shouldn't have difficulty and time to complete, doesn't count to day total time) name, description, importance (1-100), difficulty (1-100), deadline (date), time to complete (should be more than 5 hours), plan(set of Tasks), time spended
1) Day: date, Type (relax(at least one per week, not more than 2), easy day, regular day, hard day), set of Tasks for a day, overall difficulty (different litits for every type: relax < 3, easy day >= 3 and < 5, regular day >= 5 and < 10, hard day >= 10 and < 20), overall time (different litits for every type: relax < 30 minuts, easy day >= 0.5 hours and < 1.5, regular day >= 1,5 and < 3, hard day >=3 and < 6(this limit is recommendation)), thoughts after this day (how was it?)
2) Week: Type(dynamic - next 7 days, static - from Monday to Sunday), name(static), array of 7 days, overall time to complete (more than 40 hours is not recommended), overall difficulty(not more than 60), time spent (for static week), conclusion (for static completed week)
3) Month: name, array of days (positions in the year according to other months(first?, second? (It has built-in lap year recognition.) )), overall difficulty, time spent, conclusion
4) Year: name(number), set of days in every month (for month class to know how many days it has), array of Months, overall difficulty, time spent, set of goals completed, conclusion, set of goals for not finished year.


## Functions:

a. Storing and reading data to/from files: 
