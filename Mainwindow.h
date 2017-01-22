#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QStandardItemModel>

#include "resultwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Voter();

private slots:
    void slot_open_resultwindow();
    void slot_addCandidat();
    void slot_editCandidat();
    void slot_removeCandidat();
    void slot_vote();

private:
    Ui::MainWindow *ui;

public:
    Data data;
};

#endif // MAINWINDOW_H
