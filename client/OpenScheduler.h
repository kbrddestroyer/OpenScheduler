#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenScheduler.h"

class OpenScheduler : public QMainWindow
{
    Q_OBJECT

public:
    OpenScheduler(QWidget *parent = nullptr);
    ~OpenScheduler();
private:
    void handleButtonPressEvent();

private:
    Ui::OpenSchedulerClass ui;
};
