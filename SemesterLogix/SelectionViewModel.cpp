#include "SelectionViewModel.h"
#include <QStandardPaths>



SelectionViewModel::SelectionViewModel(QObject* parent)
	:QObject(parent),
	mSchool{ nullptr }
{
	initializeSchoolMapValues();
	// Get the path to the Downloads directory
	mDownloadsPath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
	//Init mSchool to the first school type in the school combobox.
	ChangeSchool();
	//Use this connection to change mSchool school type when the selected item of school combobox change.
	connect(this, &SelectionViewModel::schoolChanged, this, &SelectionViewModel::ChangeSchool);
}

SelectionViewModel::~SelectionViewModel()
{
}

QString SelectionViewModel::downloadsPath() const
{
	return mDownloadsPath;
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

QMap<SelectionViewModel::SchoolEnum, QString> SelectionViewModel::getSchoolMapValues() const
{
	return m_schoolMapValues;
}
void SelectionViewModel::setSchoolMapValues(const QMap<SelectionViewModel::SchoolEnum, QString>& values)
{
	if (m_schoolMapValues != values) {
		m_schoolMapValues = values;
		emit schoolMapValuesChanged();
	}
}

QStringList SelectionViewModel::getSchoolMapKeys() const
{
	QStringList keys;
	QMetaEnum metaEnum = QMetaEnum::fromType<SelectionViewModel::SchoolEnum>();
	for (auto key : m_schoolMapValues.keys()) {
		keys.append(metaEnum.valueToKey(key));
	}
	return keys;
}

void SelectionViewModel::initializeSchoolMapValues()
{
	// Add more schools as needed
	setSchoolMapValues(_SchoolMap);  // This will set the value and emit the signal
}