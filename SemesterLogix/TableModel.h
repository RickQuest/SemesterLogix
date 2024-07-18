#pragma once
#ifndef SCHEDULEGRID_H
#define SCHEDULEGRID_H

// Fichier : ScheduleTable.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QObject>
#include <QPoint>
#include <array>
#include <QColor>
#include "Group.h"
#include <QTextStream>
#include <QRect>
#include <qqml.h>
#include <QAbstractTableModel>
#pragma endregion

class TableModel : public QAbstractTableModel
{
	Q_OBJECT
		QML_ELEMENT
		QML_ADDED_IN_MINOR_VERSION(1)
		
	//Q_ENUMS(TableRoles)
	
public:
	enum TableRoles {
		DataRole = Qt::UserRole + 1,
		HeadingRole,
		ColorRole
	};

	explicit TableModel(QObject* parent = nullptr);
	explicit TableModel(QList<Group*>, QObject* parent = nullptr);

	//These four functions need to be overload from the herited QAbstractTableModel class, see documentation for more infos
	int rowCount(const QModelIndex& parent) const override;
	int columnCount(const QModelIndex& parent) const override;
	QVariant data(const QModelIndex& index, int role) const override;
	QHash<int, QByteArray> roleNames() const override;

	/// <summary>
	/// Update the data tables to the next schedule in the mSchedule list
	/// </summary>
	/// <returns></returns>
    /// <note>NOT USE ANYMORE</note>
	Q_INVOKABLE void NextSchedule();
	/// <summary>
	/// Use to convert the schedule list in readable format when we pass it in the constructor 
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	/// <note>NOT USE ANYMORE</note>
	Q_INVOKABLE bool loadSchedules(QList<QList<Group*>>);
	/// <summary>
	/// Convert the QList<Group>TableModel
	///  representing a schedule into a QList<TimeTable> before calling DisplaySchedule 
	/// </summary>
	/// <param name="schedule">QList of groups representing a schedule</param>
	/// <returns></returns>
	Q_INVOKABLE bool loadSchedule(QList<Group*> schedule );
	/// <summary>
	/// Load information of the schedule in the table model
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Q_INVOKABLE void DisplaySchedule(QList<TimeTable*>);



private:
	/// <summary>
	/// List of all schedule in readable format for table
	/// </summary>
	/// <note>NOT USE ANYMORE</note>
	QList<QList<TimeTable*>> mSchedule;
	/// <summary>
	/// Represent the index of the current schedule displayed
	/// </summary>
	/// <note>NOT USE ANYMORE</note>
	int mDisplayedSchedule = 0;

	/// <summary>
	/// Static width of schedule table, 1 column for hours and 7 for each day of week
	/// </summary>
	static constexpr int mWidth = 8;
	/// <summary>
	/// Static height of schedule table, 1 row for days header and 31 for each timeslot (8:00 to 23:00 with half hour)
	/// </summary>
	static constexpr int mHeight = 32;
	/// <summary>
	/// Staitc size of data arrays
	/// </summary>
	static constexpr int mSize = mWidth * mHeight;

	/// <summary>
	/// Map all the displayed information on table
	/// </summary>
	QVector<QVector<QString>> mDataTable;
	/// <summary>
	/// Map the color of each cell (representing course) on table
	/// </summary>
	QVector<QVector<QColor>> mColorTable;

	////////Three utility functions coming from official Qt exemple that are not use yet in this projet///////
	int cellNeighborsCount(const QPoint& cellCoordinates) const;
	static bool areCellCoordinatesValid(const QPoint& coordinates);
	static QPoint cellCoordinatesFromIndex(int cellIndex);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

	/// <summary>
	/// return cell index from coordinates as QPoint
	/// </summary>
	/// <param name="coordinates"></param>
	/// <returns></returns>
	static std::size_t cellIndex(const QPoint& coordinates);
	/// <summary>
	/// Clean the datatables before adding value of next table 
	/// </summary>
	/// <note>NOT USE ANYMORE</note>
	void ClearTable();
	/// <summary>
	/// Init static information of the schedule table AKA days and hours headers
	/// </summary>
	void InitTable();

};
#endif // SCHEDULEGRID_H