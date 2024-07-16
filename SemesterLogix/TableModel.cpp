#include "TableModel.h"

TableModel::TableModel(QObject* parent)
	: QAbstractTableModel(parent),
	mDataTable(QVector<QVector<QString>>(mHeight, QVector<QString>(mWidth))),
	mColorTable(QVector<QVector<QColor>>(mHeight, QVector<QColor>(mWidth)))

{
	InitTable();

}
TableModel::TableModel(QList<Group*> schedule, QObject* parent)
	: QAbstractTableModel(parent),
	mDataTable(QVector<QVector<QString>>(mHeight, QVector<QString>(mWidth))),
	mColorTable(QVector<QVector<QColor>>(mHeight, QVector<QColor>(mWidth)))

{
	InitTable();
	loadSchedule(schedule);
}

int TableModel::rowCount(const QModelIndex& parent) const
{
	if (parent.isValid())
		return 0;

	return mHeight;
}

int TableModel::columnCount(const QModelIndex& parent) const
{
	if (parent.isValid())
		return 0;

	return mWidth;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
	switch (role) {
	case ColorRole:
		return mColorTable[index.row()][index.column()]; // .at(index.row()).at(index.column());
	case DataRole:
	{
		return mDataTable[index.row()][index.column()]; // .at(index.row()).at(index.column());
	}
	case HeadingRole:
	{
		if (index.row() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	default:
		break;
	}
	return QVariant();

}

QHash<int, QByteArray> TableModel::roleNames() const
{
	QHash<int, QByteArray> roles; //= QAbstractTableModel::roleNames();
	roles[DataRole] = "tabledata";
	roles[HeadingRole] = "heading";
	roles[ColorRole] = "tablecolor";
	return roles;
	//return { {Qt::DisplayRole, "display"} };
}


Q_INVOKABLE void TableModel::NextSchedule()
{
	if (mDisplayedSchedule < mSchedule.count())
	{
		mDisplayedSchedule++;
		DisplaySchedule(mSchedule.at(mDisplayedSchedule));
	}

}

Q_INVOKABLE bool TableModel::loadSchedules(QList<QList<Group*>> Schedules)
{
	if (Schedules.isEmpty())
		return false;

	for (QList<Group*> schedule : Schedules)
	{
		QList<TimeTable*> tempList;
		for (Group* group : schedule)
		{
			for (TimeTable* timetable : *(group->GetGrTimeTables()))
			{
				tempList.push_back(timetable);
			}
		}
		mSchedule.push_back(tempList);
	}

	DisplaySchedule(mSchedule.at(mDisplayedSchedule));

	return true;
}

Q_INVOKABLE bool TableModel::loadSchedule(QList<Group*> Schedule)
{
	if (Schedule.isEmpty())
		return false;

	QList<TimeTable*> tempList;
	for (Group* group : Schedule)
	{
		for (TimeTable* timetable : *(group->GetGrTimeTables()))
		{
			tempList.push_back(timetable);
		}
	}

	DisplaySchedule(tempList);
	return true;
}

Q_INVOKABLE void TableModel::DisplaySchedule(QList<TimeTable*> schedule)
{
	ClearTable();
	for (TimeTable* timetable : schedule)
	{
		QString code = timetable->GetCode() + " (" + timetable->GetCourseType() + ")";
		int column = (int)timetable->GetDay() + 1;

		int startRow = (timetable->GetStartTime()->GetHour() - 8) * 2;
		if (timetable->GetStartTime()->GetMinutes() != 0)
			startRow++;

		int endRow = (timetable->GetEndTime()->GetHour() - 8) * 2;
		if (timetable->GetEndTime()->GetMinutes() != 0)
			endRow++;

		int numberOfRows = endRow - startRow;

		//Mark the code of the course on the first cell in the column span representing the sesison
		mDataTable[startRow][column] = code;

		//For all the cell representing the session we change there color to simulate a row spanning (not possible with tableview, would be nice)
		for (int i = 0; i < numberOfRows; i++)
		{
			if (timetable->GetCourseType() == "C")
				mColorTable[i + startRow][column] = QColor("indianred");
			else if (timetable->GetCourseType() == "TP")
				mColorTable[i + startRow][column] = QColor("cornflowerblue");
			else if (timetable->GetCourseType() == "Labo")
				mColorTable[i + startRow][column] = QColor("cornflowerblue");

			
		}
	}

	emit dataChanged(index(0, 0), index(mHeight - 1, mWidth - 1), { DataRole });
	emit dataChanged(index(0, 0), index(mHeight - 1, mWidth - 1), { ColorRole });

}


int TableModel::cellNeighborsCount(const QPoint& cellCoordinates) const
{
	int count = 0;

	for (int x = -1; x <= 1; ++x) {
		for (int y = -1; y <= 1; ++y) {
			if (x == 0 && y == 0)
				continue;

			const QPoint neighborPosition{ cellCoordinates.x() + x, cellCoordinates.y() + y };
			if (!areCellCoordinatesValid(neighborPosition))
				continue;

			/*if (mCurrentState[cellIndex(neighborPosition)])
				++count;*/

			if (count > 3)
				return count;
		}
	}

	return count;
}

bool TableModel::areCellCoordinatesValid(const QPoint& coordinates)
{
	return QRect(0, 0, mWidth, mHeight).contains(coordinates);
}

QPoint TableModel::cellCoordinatesFromIndex(int cellIndex)
{
	return { cellIndex % mWidth, cellIndex / mWidth };
}

std::size_t TableModel::cellIndex(const QPoint& coordinates)
{
	return std::size_t(coordinates.y() * mWidth + coordinates.x());
}

void TableModel::ClearTable()
{
	for (int i = 1; i < mHeight; i++)
	{
		for (int j = 1; j < mWidth; j++)
		{
			mDataTable[i][j] = QString("");
			mColorTable[i][j] = QColor("whitesmoke");
		}
	}

}

void TableModel::InitTable()
{
	mColorTable.fill({ QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke"),QColor("whitesmoke") });

	mDataTable[0] = { "","LUNDI","MARDI","MERCREDI","JEUDI","VENDREDI","SAMEDI","DIMANCHE" };
	for (int i = 1; i < mHeight; i++)
	{
		mDataTable[i][0] = QString("%1 : %2").arg(i + 7 - (i / 2)).arg(i % 2 ? "00" : "30");
		//mDataTable[i].replace(0, QString("%1 : %2").arg(i + 7 - (i / 2)).arg(i % 2 ? "00" : "30"));
		//mDataTable.append({ QString("%1 : %2").arg(i + 7-(i/2)).arg(i % 2 ? "00" : "30") });
	}

	emit dataChanged(index(0, 0), index(mHeight - 1, mWidth - 1), { DataRole });
	emit dataChanged(index(0, 0), index(mHeight - 1, mWidth - 1), { ColorRole });


}


