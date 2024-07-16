#pragma once
#ifndef COURSE_H
#define COURSE_H

// Fichier : Course.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -
#pragma region Includes
#include "TimeTable.h"
#include "Group.h"
#pragma endregion

class Course : public QObject
{
	Q_OBJECT
		/// <summary>
		/// Make the property mName accessible from the UI
		/// </summary>
		Q_PROPERTY(QString Name READ Name WRITE SetName NOTIFY nameChanged)
		/// <summary>
		/// Make the property mCode accessible from the UI
		/// </summary>
		Q_PROPERTY(QString Code READ Code WRITE SetCode NOTIFY codeChanged)
		/// <summary>
		/// Make the property mSelected accessible from the UI
		/// </summary>
		Q_PROPERTY(bool Selected READ GetSelected WRITE SetSelected NOTIFY selectedChanged)

#pragma region Members
private:
	QList<Group*> mCourseTimeTable;
	QString mName;
	QString mCode;
	QString mSection;
	QString mInstructor;
	QString mPrior;
	bool mSelected = false;
#pragma endregion

#pragma region Ctors/Dtors
public:
	/// <summary>
	/// Constructor V1
	/// </summary>
	Course();
	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="obj"> The course you are copying</param>
	Course(const Course& obj);
	/// <summary>
	/// Constructor V2
	/// </summary>
	/// <param name="_name">Name of course : Ingénierie des systèmes orientés-objet </param>
	/// <param name="_code">Course code : GPA434</param>
	/// <param name="_section">Where course is taking place : Bâtiment A </param>
	/// <param name="_instructor">Who is teaching the course</param>
	/// <param name="_prior">Which are the course prerequisite</param>
	Course(const QString& _name, const QString& _code, const QString& _section, const QString& _instructor, const QString& _prior);
#pragma endregion

#pragma region Operators

#pragma endregion

#pragma region Functions
public:
	/// <summary>
	/// This function verifies if the selected course is the same course.
	/// We cross check both the name and the code for the course agaisnt the other one. 
	/// </summary>
	/// <param name="_other"></param>
	/// <returns></returns>
	bool IsSameCourse(Course* _other);
	/// <summary>
	/// This function returns the info tring associated with the course.
	/// The info string contains the name and location of the course.
	/// </summary>
	/// <returns></returns>
	QString GetInfoString();
	/// <summary>
	/// This function verifies if their is a conflict between this instance of a course and another course passed in through it's parameters.
	/// </summary>
	/// <param name="_other"></param>
	/// <returns></returns>
	bool HasConflict(Course* _other);

#pragma endregion

#pragma region Getters/Setters
public:

	QString Name(){ return mName; }
	QString Code(){ return mCode; }
	QString Section(){ return mSection; }
	QString Instructor(){ return mInstructor; }
	QString Prior(){ return mPrior; }
	bool GetSelected(){ return mSelected; }
	QList<Group*>* GetGroupsTimeTables(){ return &mCourseTimeTable; }
	
	/// <param name="name">Full name of course</param>
	void SetName(const QString& name); 
	
	/// <param name="_name">String you would like to add to current name</param>
	void AddName(const QString& _name){ mName += _name; }
	
	/// <param name="code">Class code. Ex : GPA434</param>
	void SetCode(const QString& code); 
	
	/// <param name="_section">Which building the course is taking place in</param>
	void SetSection(const QString& _section){ mSection = _section; }
	
	/// <param name="_instructor">Name of instructor</param>
	void SetInstructor(const QString& _instructor){ mInstructor = _instructor; }
	
	/// <param name="_prior">Course Prerequisites</param>
	void SetPrior(const QString& _prior){ mPrior = _prior; }
	
	/// <param name="_prior">Prerequisities you would like to add to current.</param>
	void AddPrior(const QString& _prior){ mPrior += _prior; }
	
	/// <param name="selected">Yes=1 : No=0</param>
	void SetSelected(const bool& selected);
#pragma endregion

#pragma region Signals/Slots
signals:
	/// <summary>
	/// This function informs us when the course name as changed. If the current name doesn't match the course mName the name is changed to match it.
	/// When this is completed a signals is emitted to inform the program. It is called at the end of SetName.
	///
	/// </summary>
	void nameChanged();
	/// <summary>
	///This function informs us when the code as changed.If the code doesn't match the current course mCode the code is changed to match it.
	/// When this is completed a signals is emitted to inform the program. It is called at the end of SetCode.
	/// </summary>
	void codeChanged();
	/// <summary>
	/// This function informs us when the mSelected private data member is changed. It is called at the end of SetSelected.
	/// </summary>
	void selectedChanged();

#pragma endregion



};
#endif // COURSE_H