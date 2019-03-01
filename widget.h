#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include "captchabox.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void checkCode();//展示验证码是否正确

private:
    Ui::Widget *ui;
    QLineEdit *lineEdit;
    CaptchaBox *captchaBox;
    QLabel *label;
    QPushButton *yesBtn;
};

#endif // WIDGET_H
