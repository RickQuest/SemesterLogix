#include "Course.h"

Course::Course()
{
	mName = "";
	mCode = "";
	mSection = "";
	mInstructor = "";
	mPrior = "";
}
Course::Course(const QString& _name, const QString& _code, const QString& _section, const QString& _instructor, const QString& _prior)
{
	mName = _name;
	mCode = _code;
	mSection = _section;
	mInstructor = _instructor;
	mPrior = _prior;
}
Course::Course(const Course& obj)
{
	mCourseTimeTable = obj.mCourseTimeTable;

	mName = obj.mName;
	mCode = obj.mCode;
	mSection = obj.mSection;
	mInstructor = obj.mInstructor;
	mPrior = obj.mPrior;
}


bool Course::IsSameCourse(Course* _other)
{

	return (this->mName == _other->mName && this->mCode == _other->mCode);
}

QString  Course::GetInfoString()
{
	QString s = mCode + ": " + mName + ", " + mSection + ")\n";
	//for (auto timeSlot : *mLabTimeTable)
	//{

	//	s += timeSlot->GetClassType() + ": " + timeSlot->GetDayString() + ", " + timeSlot->GetStartTime()->ToString() + " - " + timeSlot->GetEndTime()->ToString() + ", " + timeSlot->GetLocation() + "\n";
	//}

	return s;
}

bool Course::HasConflict(Course* _other)
{

	//check everyone of this course's timeslots against everyone of other's timeslots

	//In this version we add one lyer of comparaison where we compare all groups of this course vs all groups of other course
	for (auto Groupe1 : mCourseTimeTable)
	{
		if (_other->Code() != this->Code())
		{
			////iterate through groups of the other course
			for (auto Groupe2 : *_other->GetGroupsTimeTables())
			{
				if (Groupe1->HasConflict(Groupe2)) 
				{
					return true;
				}
			}
			
		}
	}

	return false;
}

void Course::SetName(const QString& name)
{
	if (name != mName) {
		mName = name;
		emit nameChanged();
	}
}

void Course::SetCode(const QString& code)
{
	if (code != mCode) {
		mCode = code;
		emit codeChanged();
	}
}

void Course::SetSelected(const bool& selected)
{
	if (selected != mSelected) {
		mSelected = selected;
		emit selectedChanged();
	}
}




