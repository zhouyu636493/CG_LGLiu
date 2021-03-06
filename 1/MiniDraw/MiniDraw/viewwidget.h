#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QWidget>
#include "ui_viewwidget.h"
#include <vector>
#include "Figure.h"
#include "Line.h"
#include "Ellipse.h"
#include "Rect.h"
#include "Polygon.h"
#include "FreeHand.h"

enum FigureType
{
	kDefault = 0,
	kLine = 1,
	kRectangle = 2,
	kEllipse = 3,
	kPolygon = 4,
    kFreehand = 5,
};


class ViewWidget : public QWidget{
    Q_OBJECT

public:
    ViewWidget(QWidget *parent = 0);
    ~ViewWidget();

    void mousePressEvent(QMouseEvent * mouseEvent);
	void mouseMoveEvent(QMouseEvent * mouseEvent);
	void mouseReleaseEvent(QMouseEvent * mouseEvent);
    void paintEvent(QPaintEvent *);

    void set_figure_type_to_line();
    void set_figure_type_to_rectangle();
    void set_figure_type_to_ellipse();
    void set_figure_type_to_polygon();
    void set_figure_type_to_freehand();
    void undo();

private:
    Ui::ViewWidget ui;
    bool draw_status;
	QPoint start_point, end_point;
    std::vector<Figure *> figureVec;
    FigureType figure_type;
    Figure* current_figure;
};

#endif // VIEWWIDGET_H
