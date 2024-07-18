#pragma once
#ifndef ISCHOOL_H
#define ISCHOOL_H

// Fichier : ISchool.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QDebug>
#include "IParser.h"
#include "Scheduler.h"
#pragma endregion

class ISchool
{
#pragma region Members
public :
	/// <summary>
	/// The base class pdf parser.
	/// </summary>
	IParser* mIParser;
protected:
	/// <summary>
	/// A list of courses captured from the schools pdf.
	/// </summary>
	QList<QObject*>* mCourses;
private:

#pragma endregion

#pragma region Ctor/Dtor
protected:
	ISchool(IParser* parser);
public:
	ISchool();
	virtual ~ISchool();
	ISchool(ISchool const&) = default;
#pragma endregion

#pragma region Operators
public:
	ISchool& operator=(ISchool const&) = default;
#pragma endregion

#pragma region Getters/Setters
public:
	QList<QObject*>* GetCourseList() { return mCourses; }
#pragma endregion

#pragma region Functions
public:
	
#pragma endregion

#pragma region Slots
private slots:


public slots:

#pragma endregion
};

#endif // ISCHOOL_H
