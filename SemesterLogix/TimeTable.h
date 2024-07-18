#pragma once
#ifndef TIMETABLE_H
#define TIMETABLE_H

// Fichier : TimeTable.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#pragma warning(push ,2)

#pragma warning(pop)

#include "TimeModel.h"
#include <vector>
#pragma endregion

/// <summary>
/// TimeTable is used as the backbone of most scheduler algorithms. It is in
/// an instance of this very class that we place all the information analyzed 
/// from the pdf in its rightful place.
/// </summary>
class TimeTable
{
public:
	/// <summary>
	/// Used with function CreateDay in order to make conflict 
	/// checking faster after courses are created.
	/// </summary>
	enum class Day
	{
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATHURDAY,
		SUNDAY,
		NONE = -1
	};
private:

	//std::vector<QString> dayStrings;
	TimeModel* mStartTime;
	TimeModel* mEndTime;
	Day mDay;
	QString mClassType;
	QString mLocation;
	QString mCode;

public:

	/// <summary>
	/// Constructor V1
	/// </summary>
	/// <param name="_startTime">Start time of course</param>
	/// <param name="_endTime">End time of course</param>
	/// <param name="_day">Day of course</param>
	TimeTable(TimeModel* _startTime, TimeModel* _endTime, Day _day);
	/// <summary>
	/// Constructor V2
	/// </summary>
	/// <param name="_startTime">Start time of course</param>
	/// <param name="_endTime">End time of course</param>
	/// <param name="_day">Day of course</param>
	/// <param name="_classType">What kind of course it is {C,TP,LABO,ect}</param>
	/// <param name="_location">The location of the course</param>
	/// <param name="_code">The course acronym</param>
	TimeTable(TimeModel* _startTime, TimeModel* _endTime, QString _day, QString _courseType, QString _location, QString _code);
	/// <summary>
	/// Destructor
	/// </summary>
	virtual ~TimeTable()
	{
		delete mStartTime;
		delete mEndTime;
	}

	
	/// <summary>
	/// Check if there is a conflict between two timetable.
	/// First verifies the day then verifies the time delta between both start and and end points.
	/// </summary>
	/// <param name="_other"></param>
	/// <returns></returns>
	bool HasConflict(TimeTable* _other);

	/// <summary>
	/// Used to convert string from text into enum class day.
	/// </summary>
	/// <param name="_day"></param>
	/// <returns></returns>
	static Day CreateDay(const QString& _day);

	/// <summary>
	/// Used to set day from another _day.
	/// </summary>
	/// <param name="_day"></param>
	void SetDay(Day _day);
	bool SetDay(const QString& _day);

	/// <summary>
	/// Used to return info string which contains courseType and location.
	/// </summary>
	/// <returns></returns>
	QString GetInfoString();
	
	/// <summary>
	/// Used to access course start time.
	/// </summary>
	/// <returns></returns>
	TimeModel* GetStartTime();
	/// <summary>
	/// Used to access course end time.
	/// </summary>
	/// <returns></returns>
	TimeModel* GetEndTime();
	/// <summary>
	/// Used to access which day the course is happening.
	/// </summary>
	/// <returns></returns>
	Day GetDay();
	/// <summary>
	/// Used to acces course type. Their is various course types such as :
	/// • C {Cours}
	/// • TP {Travaux pratique}
	/// • Atelier
	/// • ect..
	/// </summary>
	/// <returns></returns>
	QString GetCourseType();
	/// <summary>
	/// Used to access which building the course is happening in.
	/// </summary>
	/// <returns></returns>
	QString GetLocation();
	QString GetCode() { return mCode; }

};
#endif // TIMETABLE_H