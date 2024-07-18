#pragma once
#ifndef SINGLETONPROVIDER_H
#define SINGLETONPROVIDER_H

#include <QObject>
#include "CourseViewModel.h"
#include "ScheduleViewModel.h"

class SingletonProvider : public QObject
{
	Q_OBJECT

public:
	static SingletonProvider& instance()
	{
		static SingletonProvider instance;
		return instance;
	}

	CourseViewModel* getCourseViewModel() { return &m_courseViewModel; }
	ScheduleViewModel* getScheduleViewModel() { return &m_scheduleViewModel; }

private:
	SingletonProvider() = default;
	~SingletonProvider() = default;
	SingletonProvider(const SingletonProvider&) = delete;
	SingletonProvider& operator=(const SingletonProvider&) = delete;

	CourseViewModel m_courseViewModel;
	ScheduleViewModel m_scheduleViewModel;
};

#endif // SINGLETONPROVIDER_H
