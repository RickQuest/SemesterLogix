#include "ISchool.h"


ISchool::ISchool(IParser* parser)
	:mIParser(nullptr),
	mCourses(new QList<QObject*>)
{
	mIParser = parser;
	qDebug() << "ISchool ctor";
}

ISchool::ISchool()
	: mCourses{ nullptr },
	mIParser(nullptr)
{
	qDebug() << "ISchool ctor";
}


ISchool::~ISchool()
{
	qDebug() << "ISchool dtor";
}



