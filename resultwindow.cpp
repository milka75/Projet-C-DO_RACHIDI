#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent, Data *data) :
    QDialog(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);

    // Remplir la liste des scores en %
    ListeScoresPourcent.clear();
    ListeScoresPourcent.resize(7);
    for(int i=0; i<7; i++)
    {
        ListeScoresPourcent[i].resize(data->NCandidats);
        for(int j=0; j<data->NCandidats; j++)
            ListeScoresPourcent[i][j] = data->ListeScores[i][j]*100/data->NVotes;
    }

    QVector<double> ticks;
    for(int i=1; i<=data->NCandidats; i++)
    {
        ticks.append(i);
    }
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, data->ListeNoms.toVector());
    ui->customPlot->xAxis->setTicker(textTicker);

    // Prepare graph
    setBackground();
    setxAxis(data->NCandidats);
    setyAxis();
    addLine(data->NCandidats);
    setLegend();

    // create empty bar chart objects:
    QCPBars *bar1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar2 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar3 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar4 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar5 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar6 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *bar7 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bar1->setAntialiased(false); // gives more crisp, pixel aligned bar borders
    bar2->setAntialiased(false);
    bar3->setAntialiased(false);
    bar4->setAntialiased(false);
    bar5->setAntialiased(false);
    bar6->setAntialiased(false);
    bar7->setAntialiased(false);
    // set names and colors:
    bar7->setName("A rejeter");
    bar7->setPen(QPen(QColor(0, 0, 255).lighter(50)));
    bar7->setBrush(QColor(0, 0, 255).lighter(50));
    bar6->setName("Insuffisant");
    bar6->setPen(QPen(QColor(0, 0, 255).lighter(100)));
    bar6->setBrush(QColor(0, 0, 255).lighter(100));
    bar5->setName("Passable");
    bar5->setPen(QPen(QColor(0, 0, 255).lighter(150)));
    bar5->setBrush(QColor(0, 0, 255).lighter(150));
    bar4->setName("Assez Bien");
    bar4->setPen(QPen(QColor(255, 255, 255).lighter(150)));
    bar4->setBrush(QColor(255, 255, 255).lighter(150));
    bar3->setName("Bien");
    bar3->setPen(QPen(QColor(255, 0, 0).lighter(150)));
    bar3->setBrush(QColor(255, 0, 0).lighter(150));
    bar2->setName("Très Bien");
    bar2->setPen(QPen(QColor(255, 0, 0).lighter(100)));
    bar2->setBrush(QColor(255, 0, 0).lighter(100));
    bar1->setName("Excellent");
    bar1->setPen(QPen(QColor(255, 0, 0).lighter(50)));
    bar1->setBrush(QColor(255, 0, 0).lighter(50));
    // stack bars on top of each other:
    bar6->moveAbove(bar7);
    bar5->moveAbove(bar6);
    bar4->moveAbove(bar5);
    bar3->moveAbove(bar4);
    bar2->moveAbove(bar3);
    bar1->moveAbove(bar2);

    // Add data:
    QVector<double> Data7, Data6, Data5, Data4, Data3, Data2, Data1;
    Data7 = ListeScoresPourcent[6];
    Data6 = ListeScoresPourcent[5];
    Data5 = ListeScoresPourcent[4];
    Data4 = ListeScoresPourcent[3];
    Data3 = ListeScoresPourcent[2];
    Data2 = ListeScoresPourcent[1];
    Data1 = ListeScoresPourcent[0];
    bar7->setData(ticks, Data7);
    bar6->setData(ticks, Data6);
    bar5->setData(ticks, Data5);
    bar4->setData(ticks, Data4);
    bar3->setData(ticks, Data3);
    bar2->setData(ticks, Data2);
    bar1->setData(ticks, Data1);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::setBackground()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));
}

void ResultWindow::setxAxis(int N)
{
    // set x axis
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, N+1);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);
}

void ResultWindow::setyAxis()
{
    // set y axis
    ui->customPlot->yAxis->setRange(0, 100.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Resultats en %");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
}

void ResultWindow::addLine(int N)
{
    // add green line
    QVector<double> x(N+2), y(N+2);
    for (int i=0; i<N+2; ++i)
    {
      x[i] = i;
      y[i] = 50;
    }
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->graph(0)->setPen(QPen(Qt::green));
    ui->customPlot->graph(0)->setName("50 %");
}

void ResultWindow::setLegend()
{
    // setup legend
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
