//#pragma once
//#ifndef IWEBSCRAPER_H
//#define IWEBSCRAPER_H
//
//// Fichier : IWebScraper.h
//// GPA434 – Laboratoire 3
//// Création :
//// - E. Surprenant
//// - M. Boudreau
//// - 2020/11/01
//// - - - - - - - - - - - - - - - - - - - - - - -
//
//#pragma region Includes
//#include <QNetworkAccessManager>
//#include <QNetworkRequest>
//#include <QNetworkReply>
//#include <QUrl>
//#include <QUrlQuery>
//#include <QVariant>
//#include <QJsonValue>
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QVariantMap>
//#include <QJsonArray>
//#include <iostream>
//#pragma endregion
//
//class IWebScraper
//{
//
//#pragma region Members
//private:
//	QUrl* mSchoolUrl;
//	QNetworkAccessManager* mManager;
//	QNetworkRequest* mRequest;
//	QNetworkReply* mReply;
//	QByteArray* mDataBuffer;
//#pragma endregion
//
//#pragma region Ctor/Dtor
//public:
//	IWebScraper();
//	virtual ~IWebScraper();
//	IWebScraper(IWebScraper const&) = default;
//#pragma endregion
//
//#pragma region Operators
//public:
//	IWebScraper& operator=(IWebScraper const&) = default;
//#pragma endregion
//
//
//#pragma region Functions
//private:
//	/// <summary>
///// Delete the reply and the data buffer after each http request 
///// </summary>
//	void NetworkCleanup();
//#pragma endregion
//
//#pragma region Slots
//private slots:
//	void setUrl();
//	/// <summary>
//	/// Read and store the http reply in the data buffer when it is ready to read
//	/// </summary>
//	void OnDataReadyToRead();
//	/// <summary>
//	/// Manipulate the data when the data read is finished 
//	/// </summary>
//	virtual void OnDataReadFinished() const = 0;
//
//public slots:
//	/// <summary>
//	/// Update the actual temperature of mWeather with httprequest
//	/// </summary>
//	void requestSchoolWebsite();
//#pragma endregion
//
//
//#pragma region Abstract exemple
//	//virtual void AbstractMemberFunction() const = 0; // Pure virtual function, makes this class Abstract class. Override is obligatory in derived class.
//
//	//virtual void NonAbstractMemberFunction1(); // Virtual function. Override is not obligatory in derived class.
//
//	//void NonAbstractMemberFunction2(); //Normal function, do samething in all derived class.
//#pragma endregion
//
//
//};
//
//#endif // IWEBSCRAPER_H