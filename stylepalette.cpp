#include "stylepalette.h"
#include "ui_stylepalette.h"
#include "tikzit.h"

#include <QDebug>
#include <QIcon>
#include <QSize>
#include <QSettings>
#include <QPainter>
#include <QPixmap>
#include <QPainterPath>

StylePalette::StylePalette(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::StylePalette)
{
    ui->setupUi(this);

    QSettings settings("tikzit", "tikzit");
    QVariant geom = settings.value("style-palette-geometry");
    if (geom != QVariant()) {
        restoreGeometry(geom.toByteArray());
    }

    _model = new QStandardItemModel(this);
    ui->styleListView->setModel(_model);
    ui->styleListView->setViewMode(QListView::IconMode);
    ui->styleListView->setMovement(QListView::Static);

    ui->styleListView->setGridSize(QSize(75,60));
}

StylePalette::~StylePalette()
{
    delete ui;
}

void StylePalette::reloadStyles()
{
    _model->clear();
    QString f = tikzit->styleFile();
    //
    ui->styleFile->setText(f);

    QStandardItem *it;
    QSize sz(60,60);

    foreach(NodeStyle *ns, tikzit->styles()->nodeStyles()) {
        it = new QStandardItem(ns->icon(), ns->name());
        _model->appendRow(it);
    }
}

void StylePalette::on_buttonOpenTikzstyles_clicked()
{
    tikzit->openTikzStyles();
}

void StylePalette::closeEvent(QCloseEvent *event)
{
    QSettings settings("tikzit", "tikzit");
    settings.setValue("style-palette-geometry", saveGeometry());
    QDockWidget::closeEvent(event);
}