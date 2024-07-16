#include "Scheduler.h"

Scheduler::Scheduler()
{
}

Scheduler::Scheduler(QList<QObject*>* courselist)
{
}

void Scheduler::GenSchedule(QList<QList<Group*>> selectedCourse, int numberOfCourses)
{
	mSchedules.clear();
	GeneratePossibleSchedules(selectedCourse, new QList<Group*>(), numberOfCourses);
}


void Scheduler::GeneratePossibleSchedules(QList<QList<Group*>> selectedCourse, QList<Group*>* branchCourses, int numCourses)
{

	//if the size of the branch is equal to the number of courses (base case)
	if (branchCourses->count() == numCourses)
	{
		//add a copy of branch to the possible schedules
		mSchedules.push_back(QList<Group*>(*branchCourses));
		//remove last element and return
		branchCourses->pop_back();
		return;
	}

	bool hasConflict = false;

	for (Group* newCourse : selectedCourse.at(branchCourses->count()))
	{
		//check all courses in the current branch for conflicts
		for (Group* choosenCourse : *branchCourses)
		{
			if (newCourse->HasConflict(choosenCourse))
			{
				hasConflict = true;
				break;
			}
		}
		if (!hasConflict)
		{
			//add the course the current branch and perform a recursive call
			branchCourses->push_back(newCourse);
			GeneratePossibleSchedules(selectedCourse,branchCourses,numCourses);
		}
		hasConflict = false;
	}


	//if branch is not empty remove last element
	if (branchCourses->count() > 0)
	{
		branchCourses->pop_back();
	}

}

