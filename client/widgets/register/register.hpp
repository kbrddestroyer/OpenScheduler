#ifndef OPENSCHEDULER_REGISTER_HPP
#define OPENSCHEDULER_REGISTER_HPP

#include <QWidget>

namespace OpenScheduler {
    QT_BEGIN_NAMESPACE
    namespace Ui { class Register; }
    QT_END_NAMESPACE

    class Register : public QWidget {
    Q_OBJECT

    public:
        explicit Register(QWidget *parent = nullptr);

        ~Register() override;

    public slots:
        void registerUser();
    private:
        Ui::Register *ui;
    };
} // OpenScheduler

#endif //OPENSCHEDULER_REGISTER_HPP
