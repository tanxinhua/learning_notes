#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_qt_slot_test.h"

class qt_slot_test : public QMainWindow
{
    Q_OBJECT

public:
    qt_slot_test(QWidget *parent = Q_NULLPTR);

private:
    Ui::qt_slot_testClass ui;
};
