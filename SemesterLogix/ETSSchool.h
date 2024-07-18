#pragma once
#ifndef ETSSCHOOL_H
#define ETSSCHOOL_H

// Fichier : ETSSchool.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#pragma warning(push ,2)

#pragma warning(pop)
#include "ISchool.h"
#include "ETSParser.h"
#include "ETSWebScraper.h"
#pragma endregion

class ETSSchool : public ISchool
{
#pragma region Members
private:

	std::vector<Course*> mCourseListETS;

#pragma endregion

#pragma region Ctor/Dtor
public:
	ETSSchool();
	virtual ~ETSSchool();
	ETSSchool(ETSSchool const&) = default;
#pragma endregion

#pragma region Operators
public:
	ETSSchool& operator=(ETSSchool const&) = default;
#pragma endregion

#pragma region Functions

#pragma endregion

#pragma region Slots
private slots:


public slots:

#pragma endregion




};

#endif // ETSSCHOOL_H