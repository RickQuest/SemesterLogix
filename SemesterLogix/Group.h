#pragma once
#ifndef GROUP_H
#define GROUP_H

// Fichier : Group.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -
#pragma region Includes
#include <QObject>
#include "TimeTable.h"
#include <QList>
#pragma endregion

class Group : public QObject
{
	Q_OBJECT


#pragma region Members
private:
	QList<TimeTable*>* mGrTimeTable;

#pragma endregion

#pragma region Ctors/Dtors
public:

	/// <summary>
	/// Constructor V1 :
	/// Creates a group TimeTable for taht course group.
	/// Example : 
	/// GPA434 has 3 different groups each with it's own set of TimeTables.
	/// </summary>
	Group();
	/// <summary>
	/// Copy constructor V2
	/// </summary>
	/// <param name="obj"></param>
	Group(const Group& obj);

#pragma endregion

#pragma region Operators

#pragma endregion

#pragma region Functions
public:
	/// <summary>
	/// Verifies if timeslot of one course is in conflict with the other course.
	/// This functions calls upon TimeTables own member function which uses the same name.
	/// </summary>
	/// <param name="other"></param>
	/// <returns></returns>QList
	bool HasConflict(Group* other);
#pragma endregion

#pragma region Getters/Setters
public:


	QList<TimeTable*>* GetGrTimeTables() { return mGrTimeTable; }


#pragma endregion

#pragma region Signals/Slots
signals:


#pragma endregion



};
#endif // GROUP_H