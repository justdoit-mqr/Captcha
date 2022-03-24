/*
 *@file:   captchabox.h
 *@author: 缪庆瑞
 *@date:   2016.12.10
 *@brief:  存放验证码的区域
 */
#ifndef CAPTCHABOX_H
#define CAPTCHABOX_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

class CaptchaBox : public QWidget
{
    Q_OBJECT

public:
    explicit CaptchaBox(QWidget *parent = 0);
    ~CaptchaBox();
    void generateCaptcha(int count=4);//生成随机验证码,默认4位

    bool checkCaptcha(QString text);//检验输入的验证码是否正确

protected:
    virtual void paintEvent(QPaintEvent *event);//重写绘图事件
    virtual void mousePressEvent(QMouseEvent *event);

private:
    void initCharset();//初始化字符集
    void initColorset();//初始化颜色集
    void initDefaultFont();//初始化字体

    void drawDisturb(QPainter &painter);//绘制干扰元素
    //形态变换
    void rotateAngle(QPainter &painter);//旋转角度
    void scaleSize(QPainter &painter);//放缩大小
    void shearForm(QPainter &painter);//扭曲形态

    void drawCaptcha(QPainter &painter);//绘制验证码

signals:

public slots:

private:
    int boxHeight;//该部件的宽高，由字体自动确定
    int boxWidth;

    QStringList charSetEn;//验证码的字符集-数字、字母
    QStringList charSetCh;//验证码的字符集-汉字
    QStringList captchaChars;//随机产生的若干位字符

    QList<QColor> colorSet;//验证码的颜色集
};

#endif // CAPTCHABOX_H
