#include "ScheduleViewModel.h"
#include "SingletonProvider.h"

ScheduleViewModel::ScheduleViewModel(QObject* parent)
	:QObject(parent)
{
}
ScheduleViewModel::~ScheduleViewModel()
{
	for (int i = 0; i < mScheduleTables.count(); i++)
	{
		if (mScheduleTables[i] != nullptr)
			delete mScheduleTables[i];
	}
}


//Q_INVOKABLE void ScheduleViewModel::GenSchedulesTables()
//{
//	//Get the generated schedule list in the Scheduler object and create TableModel interface for each schedule
//	for (QList<Group*> schedule : mScheduler.GetSchedules())
//	{
//		mScheduleTables.push_back( new TableModel(schedule));
//	}
//}

void ScheduleViewModel::GenSchedulesTables()
{
	QList<TableModel*> newScheduleTables;
	for (QList<Group*> schedule : mScheduler.GetSchedules())
	{
		newScheduleTables.push_back(new TableModel(schedule));
	}
	setSchedulesTables(newScheduleTables);
}

void ScheduleViewModel::setSchedulesTables(const QList<TableModel*>& schedulesTables)
{
	if (mScheduleTables != schedulesTables) {
		mScheduleTables = schedulesTables;
		emit schedulesTablesChanged();
	}
}

void ScheduleViewModel::GenSchedulesData(int courseNumber)
{
	qDebug() << "Generating schedules for" << courseNumber << "courses";
	CourseViewModel* courseViewModel = SingletonProvider::instance().getCourseViewModel();
	QList<QObject*> courses = courseViewModel->GetCourseList();
	QList<QList<Group*>> selectedCourseList;

	for (int i = 0; i < courses.count(); i++)
	{
		//qobject_cast<Course*>(courses.at(i));
		//Check if the course as been selected, add to selected course list if true
		if (qobject_cast<Course*>(courses.at(i))->GetSelected())
		{
			//Use qobject_cast to convert from QObject to Course. 
			//The courses came in QObject* type because there were pass to the UI (QObject necessary) in the preceding page (CourseView).
			//This is needed if we want to access easily to Course properties in list iteration of the Schedule generator.
			selectedCourseList.push_back(*qobject_cast<Course*>(courses.at(i))->GetGroupsTimeTables());
		}
	}
	//Pass the selected course list converted in the correct type to the Scheduler to make schedules.
	mScheduler.GenSchedule(selectedCourseList, courseNumber);

}

//void ScheduleViewModel::GenSchedulesData(QList<QObject*> courses, int courseNumber)
//{
//	QList<QList<Group*>> selectedCourseList;
//
//	for (int i = 0; i < courses.count(); i++)
//	{
//		qobject_cast<Course*>(courses.at(i));
//		//Check if the course as been selected, add to selected course list if true
//		if (qobject_cast<Course*>(courses.at(i))->GetSelected())
//		{
//			//Use qobject_cast to convert from QObject to Course. 
//			//The courses came in QObject* type because there were pass to the UI (QObject necessary) in the preceding page (CourseView).
//			//This is needed if we want to access easily to Course properties in list iteration of the Schedule generator.
//			selectedCourseList.push_back(*qobject_cast<Course*>(courses.at(i))->GetGroupsTimeTables());
//		}
//	}
//	//Pass the selected course list converted in the correct type to the Scheduler to make schedules.
//	mScheduler.GenSchedule(selectedCourseList, courseNumber);
//
//}
