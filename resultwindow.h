#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QDialog>
#include "data.h"

namespace Ui {
class ResultWindow;
}

class ResultWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = 0, Data *data = 0);
    ~ResultWindow();

private:
    Ui::ResultWindow *ui;
    void setBackground();
    void setxAxis(int);
    void setyAxis();
    void addLine(int);
    void setLegend();

public:
    QVector<QVector<double> > ListeScoresPourcent ;
};

#endif // RESULTWINDOW_H
