#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void digit_num();
  void func();
  void clear_all();
  void operand();
  void dot();
  void eq();
  void plus_minus();
  void left_bracket();
  void right_bracket();
  void graf();
  void x();

 private:
  Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_H
