#include "SelectionViewModel.h"




SelectionViewModel::SelectionViewModel(QObject* parent)
	:QObject(parent),
	mSchool{ nullptr }
{
	//Init mSchool to the first school type in the school combobox.
	ChangeSchool();
	//Use this connection to change mSchool school type when the selected item of school combobox change.
	connect(this, &SelectionViewModel::schoolChanged, this, &SelectionViewModel::ChangeSchool);
}

SelectionViewModel::~SelectionViewModel()
{
}


void SelectionViewModel::ChangeSchool()
{
	//Delete current school pointed at mSchool adress before construct new school
	if (mSchool != nullptr)
	{
		delete mSchool;
		mSchool = nullptr;
	}
	//Construct new school in function of the current index of school combobox
	switch (mSelectedSchool) {
	case ETS:
		mSchool = new ETSSchool();
		break;

	case UQAM:
		qDebug() << "ChangeSchool working";
		break;
	}



}

