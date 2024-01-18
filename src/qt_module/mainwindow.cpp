#include "mainwindow.h"

#include "ui_mainwindow.h"
extern "C" {
#include "../smart_calc.c"
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->Button_0, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_1, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_2, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_3, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_4, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_5, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_6, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_7, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_8, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_9, SIGNAL(clicked()), this, SLOT(digit_num()));
  connect(ui->Button_cos, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_sin, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_tan, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_atan, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_acos, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_asin, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_sqrt, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_ln, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_log, SIGNAL(clicked()), this, SLOT(func()));
  connect(ui->Button_Clear_all, SIGNAL(clicked()), this, SLOT(clear_all()));
  connect(ui->Button_plus, SIGNAL(clicked()), this, SLOT(plus_minus()));
  connect(ui->Button_minus, SIGNAL(clicked()), this, SLOT(plus_minus()));
  connect(ui->Button_div, SIGNAL(clicked()), this, SLOT(operand()));
  connect(ui->Button_mul, SIGNAL(clicked()), this, SLOT(operand()));
  connect(ui->Button_dot, SIGNAL(clicked()), this, SLOT(dot()));
  connect(ui->Button_step, SIGNAL(clicked()), this, SLOT(operand()));
  connect(ui->Button_eq, SIGNAL(clicked()), this, SLOT(eq()));
  connect(ui->Button_left_brackets, SIGNAL(clicked()), this,
          SLOT(left_bracket()));
  connect(ui->Button_right_brackets, SIGNAL(clicked()), this,
          SLOT(right_bracket()));
  connect(ui->Button_x, SIGNAL(clicked()), this, SLOT(x()));
  connect(ui->Button_graf, SIGNAL(clicked()), this, SLOT(graf()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::digit_num() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (ui->result_show->text() == '0') {
      label = (button->text());
      ui->result_show->setText(label);
    } else {
      if (label.at(label.length() - 1) == 'x') {
        ui->result_show->setText(label);
      } else {
        label = (ui->result_show->text() + button->text());
        ui->result_show->setText(label);
      }
    }
  }
}

void MainWindow::func() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (ui->result_show->text() == '0') {
      label = (button->text() + "(");
      ui->result_show->setText(label);
    } else {
      if (label.at(label.length() - 1) == '.' ||
          label.at(label.length() - 1) == '0' ||
          label.at(label.length() - 1) == '1' ||
          label.at(label.length() - 1) == '2' ||
          label.at(label.length() - 1) == '3' ||
          label.at(label.length() - 1) == '4' ||
          label.at(label.length() - 1) == '5' ||
          label.at(label.length() - 1) == '6' ||
          label.at(label.length() - 1) == '7' ||
          label.at(label.length() - 1) == '8' ||
          label.at(label.length() - 1) == '9') {
        ui->result_show->setText(label);
      } else {
        label = (ui->result_show->text() + button->text() + "(");
        ui->result_show->setText(label);
      }
    }
  }
}

void MainWindow::clear_all() { ui->result_show->setText("0"); }

void MainWindow::operand() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (label.at(label.length() - 1) == '.' ||
        label.at(label.length() - 1) == '(' ||
        label.at(label.length() - 1) == '+' ||
        label.at(label.length() - 1) == '-' ||
        label.at(label.length() - 1) == '*' ||
        label.at(label.length() - 1) == '/' ||
        label.at(label.length() - 1) == '^') {
      ui->result_show->setText(label);
    } else {
      label = (ui->result_show->text() + button->text());
      ui->result_show->setText(label);
    }
  }
}
void MainWindow::plus_minus() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (label.at(label.length() - 1) == '.' ||
        label.at(label.length() - 1) == '+' ||
        label.at(label.length() - 1) == '-' ||
        label.at(label.length() - 1) == '*' ||
        label.at(label.length() - 1) == '/') {
      ui->result_show->setText(label);
    } else {
      label = (ui->result_show->text() + button->text());
      ui->result_show->setText(label);
    }
  }
}
void MainWindow::dot() {
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (label.at(label.length() - 1) == '.' ||
        label.at(label.length() - 1) == '(' ||
        label.at(label.length() - 1) == '^') {
      ui->result_show->setText(label);
    } else {
      label = (ui->result_show->text() + '.');
      ui->result_show->setText(label);
    }
  }
}
void MainWindow::left_bracket() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (label.at(label.length() - 1) == '.' ||
        label.at(label.length() - 1) == ')' ||
        label.at(label.length() - 1) == '0' ||
        label.at(label.length() - 1) == '1' ||
        label.at(label.length() - 1) == '2' ||
        label.at(label.length() - 1) == '3' ||
        label.at(label.length() - 1) == '4' ||
        label.at(label.length() - 1) == '5' ||
        label.at(label.length() - 1) == '6' ||
        label.at(label.length() - 1) == '7' ||
        label.at(label.length() - 1) == '8' ||
        label.at(label.length() - 1) == '9') {
      ui->result_show->setText(label);
    } else {
      label = (ui->result_show->text() + button->text());
      ui->result_show->setText(label);
    }
  }
}
void MainWindow::right_bracket() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.length() < 255) {
    if (label.at(label.length() - 1) == '.' ||
        label.at(label.length() - 1) == '(' ||
        label.at(label.length() - 1) == '+' ||
        label.at(label.length() - 1) == '-' ||
        label.at(label.length() - 1) == '*' ||
        label.at(label.length() - 1) == '/' ||
        label.at(label.length() - 1) == '^') {
      ui->result_show->setText(label);
    } else {
      label = (ui->result_show->text() + button->text());
      ui->result_show->setText(label);
    }
  }
}

void MainWindow::eq() {
  QString label;
  label = (ui->result_show->text());
  char rpn[255];
  if (label.count('x') != 1) {
    if (error_input(label.toStdString().c_str())) {
      in_rpn(label.toStdString().c_str(), rpn);
      //           int size = strlen(rpn);
      //           for (int i = 0; i < size; i++) {
      //               if(rpn[i] == '.') {
      //                   rpn[i] = ',';
      //               }
      //           }
      double result = calc_rpn(rpn);
      if (std::isinf(result) || std::isnan(result)) {
        ui->result_show->setText("error");
      } else {
        ui->result_show->setText(QString::number(result, 'f', 7));
      }
    } else {
      ui->result_show->setText("error");
    }
  }
}

void MainWindow::x() {
  QPushButton *button = (QPushButton *)sender();
  QString label;
  label = (ui->result_show->text());
  if (label.count('x') != 1) {
    if (label.length() < 255) {
      if (ui->result_show->text() == '0') {
        label = (button->text());
        ui->result_show->setText(label);
      } else {
        if (label.at(label.length() - 1) == '.' ||
            label.at(label.length() - 1) == ')' ||
            label.at(label.length() - 1) == '0' ||
            label.at(label.length() - 1) == '1' ||
            label.at(label.length() - 1) == '2' ||
            label.at(label.length() - 1) == '3' ||
            label.at(label.length() - 1) == '4' ||
            label.at(label.length() - 1) == '5' ||
            label.at(label.length() - 1) == '6' ||
            label.at(label.length() - 1) == '7' ||
            label.at(label.length() - 1) == '8' ||
            label.at(label.length() - 1) == '9') {
          ui->result_show->setText(label);
        } else {
          label = (ui->result_show->text() + button->text());
          ui->result_show->setText(label);
        }
      }
    }
  }
}
void MainWindow::graf() {
  ui->plot->clearGraphs();
  ui->plot->addGraph();
  ui->plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);

  QString tmp_label = ui->result_show->text();

  QVector<double> x;
  QVector<double> y;
  double x1 = -100;
  double x2 = 100;
  double step = 0.01;
  if (x1 < x2) {
    while (x1 <= x2) {
      QString label = tmp_label;
      label.replace("x", QString::number(x1, 'f', 7));
      char rpn[255];
      in_rpn(label.toStdString().c_str(), rpn);
      //        int size = strlen(rpn);
      //        for (int i = 0; i < size; i++) {
      //            if(rpn[i] == '.') {
      //                rpn[i] = ',';
      //            }
      //        }
      double result = calc_rpn(rpn);
      x.push_back(x1);
      y.push_back(result);
      x1 += step;
    }

    ui->plot->graph(0)->addData(x, y);
    ui->plot->xAxis->setRange(-10, 10);
    ui->plot->yAxis->setRange(-10, 10);

    QCPAxisRect *rect = ui->plot->axisRect();
    rect->setRangeZoomAxes(ui->plot->xAxis, ui->plot->yAxis);
    rect->setRangeDragAxes(ui->plot->xAxis, ui->plot->yAxis);
    rect->setRangeZoom(Qt::Horizontal | Qt::Vertical);

    ui->plot->replot();
  }
}
