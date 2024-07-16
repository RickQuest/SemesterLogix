#include "ETSSchool.h"

ETSSchool::ETSSchool()
	:ISchool(new ETSParser())
{

	qDebug() << "ETSSchool ctor";
}


ETSSchool::~ETSSchool()
{
	qDebug() << "ETSSchool dtor";

}
