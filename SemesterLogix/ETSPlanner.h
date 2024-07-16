#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ETSPlanner.h"

class ETSPlanner : public QMainWindow
{
    Q_OBJECT

public:
    ETSPlanner(QWidget *parent = Q_NULLPTR);

private:
    Ui::ETSPlannerClass ui;
};
