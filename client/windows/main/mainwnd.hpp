
#ifndef MAINWND_HPP
#define MAINWND_HPP

#include <Singleton.hpp>
#include <QMainWindow>

namespace OpenScheduler {
QT_BEGIN_NAMESPACE
namespace Ui { class MainWnd; }
QT_END_NAMESPACE

class MainWnd : public QMainWindow, Utils::Singleton<MainWnd> {
Q_OBJECT

public:
    explicit MainWnd(QWidget *parent = nullptr);
    ~MainWnd() override;
private:
    Ui::MainWnd *ui;
};
} // OpenScheduler

#endif //MAINWND_HPP
