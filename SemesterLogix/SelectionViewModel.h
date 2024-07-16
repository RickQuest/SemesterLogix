#ifndef SELECTIONVIEWMODEL_H
#define SELECTIONVIEWMODEL_H

// Fichier : SelectionViewModel.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QObject>
#include "ETSSchool.h"
#pragma endregion

class SelectionViewModel : public QObject
{
	Q_OBJECT
		/// <summary>
		/// Two way bind betweeen school QML combobox index and logic layer.
		/// </summary>
		Q_PROPERTY(int selectedSchool READ getSelectedSchool WRITE setSelectedSchool NOTIFY schoolChanged)
		/// <summary>
		/// Bind QML school combobox value to logic layer. 
		/// </summary>
		Q_PROPERTY(QStringList SchoolMapValues READ getSchoolMapValues)
		/// <summary>
		/// Two way bind between PDF fileUrl of QML FileDialog and logic layer
		/// </summary>
		Q_PROPERTY(QString pdfFilepath READ getPdfFilepath WRITE setPdfFilepath NOTIFY pdfFilepathChanged)
		/// <summary>
		/// QProperty used to pass the generated course list to CourseViewModel
		/// </summary>
		Q_PROPERTY(QList<QObject*> Courses READ getCourses)


#pragma region Members
public:
	enum SchoolEnum { ETS, UQAM, POLYTECHNIQUE };

private:
	ISchool* mSchool;
	int mSelectedSchool = ETS;
	QString mPdfFilepath = "";
	/// <summary>
	/// QMap to map school QML combobox index and value to logic layer.
	/// </summary>
	QMap<SchoolEnum, QString> _SchoolMap{ {ETS,"ETS"}, {UQAM, "UQAM" }, {POLYTECHNIQUE, "POLYTECHNIQUE" } };

#pragma endregion

#pragma region Ctor/Dtor
public:
	explicit SelectionViewModel(QObject* parent = nullptr);
	virtual ~SelectionViewModel();
	SelectionViewModel(SelectionViewModel const&) = default;
#pragma endregion

#pragma region Operators
public:
	SelectionViewModel& operator=(SelectionViewModel const&) = default;
#pragma endregion

#pragma region Getters/Setters
public:
	int getSelectedSchool() { return mSelectedSchool; }
	void setSelectedSchool(const int school) {
		if (school != mSelectedSchool)
		{
			mSelectedSchool = school;
			emit schoolChanged();
		}
	}
	QString getPdfFilepath() { return mSchool->mIParser->GetPdfFilepath(); }
	void setPdfFilepath(QString pdfFilepath) {
		if (pdfFilepath != mSchool->mIParser->GetPdfFilepath())
		{
			mSchool->mIParser->SetPdfFilepath(pdfFilepath);
			mSchool->mIParser->PdfToText();
			emit pdfFilepathChanged();
		}
	}
	QList<QObject*> getCourses() { return mSchool->mIParser->ExtractData(); }
	QStringList getSchoolMapValues() {return _SchoolMap.values();}
	QList<SchoolEnum> GetSchoolMapKeys() { return _SchoolMap.keys(); }

#pragma endregion

#pragma region Functions

#pragma endregion

#pragma region Slots/Signals
signals:
	void pdfFilepathChanged();
	void schoolChanged();


public slots:
	/// <summary>
	/// Delete School object at mSchool adress if not null and redirect mSchool to a new School
	/// </summary>
	void ChangeSchool();
#pragma endregion




};

#endif // SELECTIONVIEWMODEL_H

