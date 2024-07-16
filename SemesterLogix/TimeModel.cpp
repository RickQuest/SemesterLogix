#include "TimeModel.h"
TimeModel::TimeModel(unsigned int _hour, unsigned int _minute, bool _AM)
{
	hour = _hour;
	minutes = _minute;
	isAM = _AM;
}

TimeModel::TimeModel(QString time)
{
	QStringList timeSplit = time.split(":", Qt::SkipEmptyParts);
	//this->hour = hour.toInt();
	//this->hour = TimeStringToMin(hour);
	this->hour = timeSplit[0].toInt();
	//this->minutes = minute.toInt();
	//this->minutes = TimeStringToMin(hour);
	this->minutes = timeSplit[1].toInt(); 
	//REMOVE
	this->isAM = 1;
}

TimeModel::TimeModel(const TimeModel& _time)
{
	this->hour = _time.hour;
	this->minutes = _time.minutes;
	this->isAM = _time.isAM;
}

unsigned int TimeModel::To24Hour()
{
	if (isAM)
	{
		if (hour == 12)
		{
			return 0;
		}

		return hour;
	}
	else
	{
		if (hour == 12)
		{
			return 12;
		}

		return hour + 12;
	}
}

unsigned int TimeModel::ToMinutes()
{
	return To24Hour() * 60 + minutes;
}



int TimeModel::CompareTime(TimeModel* _other)
{
	return static_cast<int>(this->ToMinutes()) - static_cast<int>(_other->ToMinutes());
}

QString TimeModel::ToString()
{
	//create am/pm string
	QString amS;
	if (isAM)
	{
		amS = "am";
	}
	else
	{
		amS = "pm";
	}

	//create hour string
	//std::wstring hourS = std::to_wstring(hour) + L"";
	QString hourS = QString::number(hour);
	if (hour == 0)
	{
		hourS = "0";
	}

	//create minute string
	//std::wstring minutesS = std::to_wstring(minutes) + L"";
	QString minutesS = QString::number(minutes);
	if (minutes == 0)
	{
		minutesS = "0";
	}

	//concatenate and return
	return hourS + ":" + minutesS + amS;
}

int TimeModel::TimeStringToMin(QString time)
{
	
	QStringList timeSplit = time.split(":",Qt::SkipEmptyParts);
	int mHours = timeSplit[0].toInt() * 60;
	int mMinutes = timeSplit[1].toInt();
	return mHours + mMinutes; 
}

void TimeModel::setHour(QString mHour)
{
	hour = mHour.toInt();
}

void TimeModel::setMinutes(QString mMinutes)
{
	minutes = mMinutes.toInt();
}
