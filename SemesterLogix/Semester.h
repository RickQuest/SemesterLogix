#pragma once
#ifndef SEMESTER_H
#define SEMESTER_H

// Fichier : Semester.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QString>
#include <vector>
#include "Course.h"
#pragma endregion

/// <summary>
/// Model class reprenting training object
/// </summary>
class Semester
{
public:
	/// <summary>
	/// Name of the semester
	/// </summary>
	std::string mName;

	/// <summary>
	/// Courses list of the semester
	/// </summary>
	std::vector<Course> mCourses;



	//public:
	//	void setName(std::string name) { mName = name; }
	//	std::string getName() { return mName; }
	//
	//	void setCourses(std::vector<Course> courses) { mCourses = courses; }
	//	std::vector<Course> getCourses() { return mCourses; }

};

#endif // SEMESTER_H