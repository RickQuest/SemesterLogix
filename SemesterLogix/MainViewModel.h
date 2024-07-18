#pragma once
#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

// Fichier : MainViewModel.h
// GPA434 – Laboratoire 3
// Création :
// - E. Surprenant
// - M. Boudreau
// - 2020/11/01
// - - - - - - - - - - - - - - - - - - - - - - -

#pragma region Includes
#include <QObject>
#pragma endregion

class MainViewModel : public QObject
{

#pragma region Members
private:

#pragma endregion

#pragma region Ctor/Dtor
public:
	MainViewModel();
	virtual ~MainViewModel();
	MainViewModel(MainViewModel const&) = default;
#pragma endregion

#pragma region Operators
public:
	MainViewModel& operator=(MainViewModel const&) = default;
#pragma endregion

#pragma region Functions

#pragma endregion

#pragma region Slots/Signals
private slots:


public slots:

#pragma endregion




};

#endif // MAINVIEWMODEL_H

