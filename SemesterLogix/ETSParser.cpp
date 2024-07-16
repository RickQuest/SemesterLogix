#include "ETSParser.h"

ETSParser::ETSParser()
	:IParser()
{
	//SetQCleanList();
}


ETSParser::~ETSParser()
{
	qDebug() << "ETSParser dtor";

}



void ETSParser::CleanTextFile()
{
	IParser::EraseFileLines(mTextfilePath, mQCleanList);

}


QList<QObject*> ETSParser::ParseDataFromText()
{
	QList<QObject*> courses = QList<QObject*>();
	
	QRegularExpression re1("^(?<code>\\w{3}\\d{3})(.)*");
	


	QRegularExpression re2("^(?:\\s{8})(?<name>\\w{4,}( {1,3}\\w+)*)?(\\s{60,}(?<prior>\\w(.+)))?");

	QRegularExpression re3("^(?:\\s+)(?<groupid>\\d{2})?(?:\\s)?(?<day>\\w{3})(?:\\s{3,12})(?<start>\\d{2}:\\d{2}) - (?<end>\\d{2}:\\d{2}) (?<type>\\w+)\\s+(?<loc>\\w)(.*)");

	
		QFile file(mTextfilePath);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
			throw "Problem opening file, see debug for more info.";

		QTextStream textStream(&file);
		QString line = textStream.readLine();

		while (!textStream.atEnd())
		{
		NEWCOURSE:
			Course tempCourse("", "", "", "", "");
			QRegularExpressionMatch match = re1.match(line);

			if (!match.captured("code").isNull())
			{
				tempCourse.SetCode(match.captured("code"));


				while (!textStream.atEnd())
				{
					line = textStream.readLine();
					if (!re3.match(line).captured(0).isNull())
					{
						QRegularExpressionMatch match = re3.match(line);
						if (!match.captured("groupid").isNull())
						{
						
							tempCourse.GetGroupsTimeTables()->push_back(new Group());
							tempCourse.GetGroupsTimeTables()->back()->GetGrTimeTables()->push_back(new TimeTable(new TimeModel(match.captured("start")), new TimeModel(match.captured("end")), match.captured("day"), match.captured("type"), match.captured("loc"), tempCourse.Code()));
						}
						else
							tempCourse.GetGroupsTimeTables()->back()->GetGrTimeTables()->push_back(new TimeTable(new TimeModel(match.captured("start")), new TimeModel(match.captured("end")), match.captured("day"), match.captured("type"), match.captured("loc"), tempCourse.Code()));
						
					}
					else if (!re1.match(line).captured(0).isNull())
					{
						courses.append(new Course(tempCourse));
						goto NEWCOURSE;
					}


				}
			}
			line = textStream.readLine(); //read one line at a time
		}
		return courses;
	
}





