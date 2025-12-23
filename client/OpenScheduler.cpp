#include "OpenScheduler.h"
#include <QVBoxLayout>

namespace OpenScheduler {
    OpenScheduler::OpenScheduler(QWidget *parent)
        : QMainWindow(parent)
    {
        ui.setupUi(this);
    }

    OpenScheduler::~OpenScheduler() = default;
}