#pragma once
#ifndef SCHEDULEVIEWMODEL_H
#define SCHEDULEVIEWMODEL_H

// Fichier : ScheduleViewModel.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QObject>
#include "Scheduler.h"
#include <QMap>
#include "TableModel.h"
#include <QDebug>
#pragma endregion

class ScheduleViewModel : public QObject
{
	Q_OBJECT
		/// <summary>
		/// Bind QML tableview to logic layer.
		/// </summary>
		Q_PROPERTY(QList<TableModel*> schedulesTables READ GetScheduleTables WRITE setSchedulesTables NOTIFY schedulesTablesChanged)
		/// <summary>
		/// Make mSelectedCourseList available to UI layer.
		/// </summary>
		Q_PROPERTY(QList<QList<Group*>> schedules READ GetSchedules)

#pragma region Members
private:
	/// <summary>
	/// Scheduler class use generate schedule from selected courses list.
	/// </summary>
	Scheduler mScheduler;
	/// <summary>
	/// Contain only the selected course from CourseView page.
	/// </summary>
	QList<QList<Group*>> mSelectedCourseList;
	/// <summary>
	/// Contain TableModel use as interface between Schedule model and QML tableview.
	/// </summary>
	QList<TableModel*> mScheduleTables;
#pragma endregion

#pragma region Ctor/Dtor
public:
	explicit ScheduleViewModel(QObject* parent = nullptr);

	virtual ~ScheduleViewModel();
	ScheduleViewModel(ScheduleViewModel const&) = default;
#pragma endregion

#pragma region Operators
public:
	ScheduleViewModel& operator=(ScheduleViewModel const&) = default;
#pragma endregion

#pragma region Functions
public:
	/// <summary>
	/// Generate mScheduleTables QList from mSchedules QList inside mScheduler 
	/// </summary>
	/// <returns></returns>
	Q_INVOKABLE void GenSchedulesTables();

#pragma endregion

#pragma region Slots/Signals

public slots:
	/// <summary>
	/// Generate list of selected courses from list of all courses. 
	/// </summary>
	void GenSchedulesData(int);
signals:
	void schedulesTablesChanged();
#pragma endregion

#pragma region Getters/Setters
public:
	void setSchedulesTables(const QList<TableModel*>& schedulesTables);
	QList<QList<Group*>> GetSchedules() { return mScheduler.GetSchedules(); }
	QList<TableModel*> GetScheduleTables() { return mScheduleTables; }

#pragma endregion



};

#endif // SCHEDULEVIEWMODEL_H



