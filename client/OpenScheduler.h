#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenScheduler.h"

namespace OpenScheduler {
    class OpenScheduler : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit OpenScheduler(QWidget *parent = nullptr);
        ~OpenScheduler() final;
    private:
        Ui::OpenSchedulerClass ui;

        QWidget * widget_;
    };
}