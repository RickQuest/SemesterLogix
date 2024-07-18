#pragma once
#ifndef COURSEVIEWMODEL_H
#define COURSEVIEWMODEL_H

// Fichier : CourseViewModel.H
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QObject>

#pragma endregion

class CourseViewModel : public QObject
{
	Q_OBJECT
		/// <summary>
		/// Two way bind between QML courseGridview and logic layer. Also use to pass the course list to ScheduleView.
		/// </summary>
		Q_PROPERTY(QList<QObject*> Courses READ GetCourseList WRITE SetCourseList NOTIFY courseListChanged)

#pragma region Members
private:
	/// <summary>
	/// List of parsed courses, use as model for courseGridView in CourseView.qml
	/// </summary>
	QList<QObject*> mCourses;


#pragma endregion

#pragma region Ctor/Dtor
public:
	explicit CourseViewModel(QObject* parent = nullptr);

	virtual ~CourseViewModel();
	CourseViewModel(CourseViewModel const&) = default;
#pragma endregion

#pragma region Operators
public:
	CourseViewModel& operator=(CourseViewModel const&) = default;
#pragma endregion

#pragma region Getters/Setters
public:
	QList<QObject*> GetCourseList() { return mCourses; }
	void SetCourseList(QList<QObject*> courseList) {
		if (courseList != mCourses)
		{
			mCourses = courseList;
			emit courseListChanged();
		}
	}
#pragma endregion

#pragma region Functions

#pragma endregion

#pragma region Slots/Signals
signals:
	void courseListChanged();

public slots:
#pragma endregion




};

#endif // CourseViewModel_H

