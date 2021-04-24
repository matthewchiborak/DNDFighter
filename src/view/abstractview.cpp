#include "abstractview.h"

AbstractView::AbstractView()
    : QOpenGLWindow(QOpenGLWindow::NoPartialUpdate)
{

}

void AbstractView::setDrawingStrat(ViewDrawingStrat *viewDrawingStrat)
{
    this->viewDrawingStrat = viewDrawingStrat;
}

void AbstractView::paintGL()
{

}

void AbstractView::resizeGL(int w, int h)
{

}
