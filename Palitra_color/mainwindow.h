#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QVector>
#include <QMouseEvent>
#include <QPushButton>
#include <QGroupBox>
#include <QComboBox>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void ChooseColor();
private:
    Ui::MainWindow *ui;
    QLineEdit *hexx = new QLineEdit;
    QComboBox *Models = new QComboBox(this);
    QHBoxLayout *_Up = new QHBoxLayout;

    QWidget *Window = new QWidget();
    QPushButton *Button_Color = new QPushButton("Выбрать...");


    void paintEvent(QPaintEvent*);
    bool eventFilter(QObject *obj, QEvent *event);
    void Input();
    QHBoxLayout *_Down = new QHBoxLayout;
    QLabel* Current_Clr = new QLabel(this);
    QColor chosenColor;
};
#endif // MAINWINDOW_H
