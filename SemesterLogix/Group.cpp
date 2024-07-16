#include "Group.h"

Group::Group()
	:mGrTimeTable(new QList<TimeTable*>())
{
}

Group::Group(const Group& obj)
{
}

bool Group::HasConflict(Group* other)
{
	for (auto timeSlot1 : *mGrTimeTable)
	{
		for (auto timeSlot2 : *other->GetGrTimeTables())
		{
			if (timeSlot1->HasConflict(timeSlot2))
				return true;
		}
	}

	return false;
}


