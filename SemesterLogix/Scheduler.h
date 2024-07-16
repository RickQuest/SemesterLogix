#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

// Fichier : Scheduler.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -
#pragma region Includes


#include "Course.h"
#pragma endregion

class Scheduler 
{

#pragma region Members
private:
	
	QList<QList<Group*>> mSchedules;


#pragma endregion

#pragma region Ctors/Dtors
public:
	/// <summary>
	/// Constructors V1
	/// </summary>
	Scheduler();
	/// <summary>
	/// Constructor V2
	/// Calls the function GenerateSelectedList().
	/// </summary>
	/// <param name=""></param>
	Scheduler(QList<QObject*>*);
#pragma endregion

#pragma region Operators

#pragma endregion

#pragma region Functions
public:
	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	void GenSchedule(QList<QList<Group*>>, int numberOfCourses);

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	/// <param name=""></param>
	void GeneratePossibleSchedules(QList<QList<Group*>>, QList<Group*>*,int numberOfCourses);

#pragma endregion

#pragma region Getters/Setters
public:
	QList<QList<Group*>> GetSchedules() { return mSchedules; }



#pragma endregion

#pragma region Signals/Slots
signals:


#pragma endregion



};
#endif // SCHEDULER_H

