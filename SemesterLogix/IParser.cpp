#include "IParser.h"
//#include"TimeTable.h"

IParser::IParser()
{
	qDebug() << "IParser ctor()";
	mAppDataFolder = QCoreApplication::applicationDirPath();
	mPdfToTextProg = SOLUTION_DIR + QString("Xpdf\\pdftotext");
}


IParser::~IParser()
{
	qDebug() << "IParser dtor";

}

void  IParser::PdfToText()
{
	QString txtFilename = mAppDataFolder.replace("/", "\\") + QString("\\SemesterGrid.txt");

	QString test = mPdfToTextProg + " -layout " + mPdfFilepath.replace("/", "\\") + " " + txtFilename;
	QByteArray cmd = test.toUtf8();
	char* command = cmd.data();

	system(command);
	if (QFile::exists(txtFilename))
	{
		mTextfilePath= txtFilename;
	}

}

QList<QObject*> IParser::ExtractData()
{
	CleanTextFile();
	return ParseDataFromText();
}


void IParser::EraseFileLine(std::string path, std::string eraseLine)
{
	std::string line;
	std::ifstream fin;

	fin.open(path);
	// contents of path must be copied to a temp file then
	// renamed back to the path file
	std::ofstream temp;
	temp.open("temp.txt");

	while (getline(fin, line)) {
		// write all lines to temp other than the line marked for erasing
		if (line != eraseLine)
			temp << line << std::endl;
	}

	temp.close();
	fin.close();

	// required conversion for remove and rename functions
	const char* p = path.c_str();
	remove(p);
	rename("temp.txt", p);
}

void IParser::EraseFileLines(std::string path, std::vector< std::string> cleanList)
{
	std::string line;
	std::ifstream fin;

	fin.open(path);
	// contents of path must be copied to a temp file then
	// renamed back to the path file
	std::ofstream temp;
	temp.open("temp.txt");

	while (getline(fin, line)) {

		if (std::none_of(cleanList.cbegin(), cleanList.cend(), containString(line))) {
			temp << line << std::endl;
		}
	}

	temp.close();
	fin.close();

	// required conversion for remove and rename functions
	const char* p = path.c_str();
	remove(p);
	rename("temp.txt", p);
}
void IParser::EraseFileLines(QString path, QList<QString> cleanList)
{
	QFile f(path);
	if (f.open(QIODevice::ReadWrite | QIODevice::Text))
	{
		QString s;
		QTextStream t(&f);
		while (!t.atEnd())
		{
			QString line = t.readLine();
			for (const auto& i : mQCleanList)
			{
				if (!line.contains(i))
					goto  ERASELINE;
			}
			s.append(line + "\n");
		ERASELINE:;
		}
		f.resize(0);
		t << s;
		f.close();
	}
}


void IParser::CropFromString(std::string path, std::string startString, std::string endString)
{
	std::string line;
	std::ifstream fin;
	fin.open(path);
	std::ofstream temp;
	temp.open("temp.txt");
	if (startString.empty() && endString.empty())
	{
		return;
	}
	else if (startString.empty())
	{
		while (getline(fin, line)) {

			if (line.find(endString) != std::string::npos) {
				break;
			}
			temp << line << std::endl;
		}
	}
	else if (endString.empty())
	{
		bool flag = false;
		while (getline(fin, line)) {
			if (flag)
				temp << line << std::endl;

			if (line.find(startString) != std::string::npos)
				flag = true;
		}
	}
	else
	{
		bool flag = true;
		while (getline(fin, line)) {
			if (flag)
			{
				if (line.find(startString) != std::string::npos)
				{
					flag = false;
					continue;
				}
				temp << line << std::endl;
			}
			else
			{
				if (line.find(endString) != std::string::npos)
					flag = true;
			}

		}
		temp.close();
		fin.close();

		// required conversion for remove and rename functions
		const char* p = path.c_str();
		remove(p);
		rename("temp.txt", p);
	}
}

