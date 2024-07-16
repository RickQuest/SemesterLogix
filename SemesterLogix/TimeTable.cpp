#include "TimeTable.h"

TimeTable::TimeTable(TimeModel* _startTime, TimeModel* _endTime, Day _day)
{
	mStartTime = _startTime;
	mEndTime = _endTime;
	mDay = _day;
	
	
}
TimeTable::TimeTable(TimeModel* _startTime, TimeModel* _endTime, QString _day, QString _courseType, QString _location, QString _code)
{
	
	mStartTime = _startTime;
	mEndTime = _endTime;
	mDay = CreateDay(_day);
	mClassType = _courseType;
	mLocation = _location;
	mCode = _code;
}
bool TimeTable::HasConflict(TimeTable* _other)
{
	//check if same day
	if (this->mDay != _other->mDay)
	{
		return false;
	}

	/*
	* Check time conflicts
	* Case 1: If other starts after this starts but before this ends or
	* Case 2: If other ends after this starts but before this ends or
	* Case 3: If other starts before this starts and ends after this ends
	*/
	return (_other->mStartTime->CompareTime(this->mStartTime) >= 0 && _other->mStartTime->CompareTime(this->mEndTime) < 0 || _other->mEndTime->CompareTime(this->mStartTime) > 0 && _other->mEndTime->CompareTime(this->mEndTime) <= 0 || _other->mStartTime->CompareTime(this->mStartTime) <= 0 && _other->mEndTime->CompareTime(this->mEndTime) >= 0);
}

TimeTable::Day TimeTable::CreateDay(const QString& _day)
{
	QString temp = _day.toLower();

	if (temp == "lun")
		return Day::MONDAY;
	else if (temp == "mar")
		return Day::TUESDAY;
	else if (temp == "mer")
		return Day::WEDNESDAY;
	else if (temp == "jeu")
		return Day::THURSDAY;
	else if (temp == "ven")
		return Day::FRIDAY;
	else if (temp == "sam")
		return Day::SATHURDAY;
	else if (temp == "dim")
		return Day::SUNDAY;
	else
		return Day::NONE;
	
}

void TimeTable::SetDay(Day _day)
{
	mDay = _day;
}

bool TimeTable::SetDay(const QString& _day)
{
	Day newDay = CreateDay(_day);
	if (newDay == Day::NONE)
	{
		return false;
	}

	mDay = newDay;
	return true;
}

QString TimeTable::GetInfoString()
{
	return (mClassType  + mLocation);
}

TimeModel* TimeTable::GetStartTime()
{
	return new TimeModel(*mStartTime);
}

TimeModel* TimeTable::GetEndTime()
{
	return new TimeModel(*mEndTime);
}

TimeTable::Day TimeTable::GetDay()
{
	return mDay;
}


QString TimeTable::GetCourseType()
{
	return mClassType;
}

QString TimeTable::GetLocation()
{
	return mLocation;
}