#pragma once
#ifndef TIMEMODEL_H
#define TIMEMODEL_H

// Fichier : TimeModel.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -
#pragma region Includes
#pragma warning(push ,2)
#include <QObject>
#pragma warning(pop)

#pragma endregion



class TimeModel
{
private:
	unsigned int hour = 0;
	unsigned int minutes = 0;
	bool isAM = false;

	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="_hour">The hour</param>
	/// <param name="_minute">The minutes</param>
	/// <param name="_AM">Is the time AM</param>
public:
	TimeModel(unsigned int _hour, unsigned int _minute, bool _AM);
	TimeModel(QString time);

	/// <summary>
	/// Copy Constructor: creates a new Time from an existing one
	/// </summary>
	/// <param name="_time">The Time to copy</param>
	TimeModel(const TimeModel& _time);

	
private:
	/// <summary>
	/// Converts the hour into 24-hour time
	/// </summary>
	/// <returns>The converted 24-hour time</returns>
	unsigned int To24Hour();

	
public:
	/// <summary>
	/// Convert the time into minutes
	/// </summary>
	/// <returns>The time in minutes</returns>
	unsigned int ToMinutes();
	

	/// <summary>
	/// Compares two times.
	/// </summary>
	/// <param name="_other">The other time to compare to</param>
	/// <returns>
	///    -1: this time comes before other
	///     0: the two times are equal
	///     1: this time comes after other
	/// </returns>
	int CompareTime(TimeModel* _other);

	/// <summary>
	/// Creates a string of the selected time.
	/// </summary>
	/// <returns>The string</returns>
	QString ToString();
	
	/// <summary>
	/// Converts a Qstring to a time. This taime is converted to it's minute counterpart.
	/// </summary>
	/// <param name="time"></param>
	/// <returns></returns>
	int TimeStringToMin(QString time);
	
	/// <summary>
	/// Allows us to set the private data member "hour".
	/// </summary>
	/// <param name="mHour">The hour you wish to set for this course.</param>
	void setHour(QString mHour);
	
	/// <summary>
	/// Allows us to set the private data member "minutes".
	/// </summary>
	/// <param name="mMinutes">The minutes you wish to set for current course.</param>
	void setMinutes(QString mMinutes);

	unsigned int GetHour() { return hour; }
	unsigned int GetMinutes() { return minutes; }

};
#endif // TIME_H