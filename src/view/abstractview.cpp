#include "abstractview.h"

AbstractView::AbstractView(SpriteFlyweightFactoryAbstract *spriteFlyFact)
    : QOpenGLWindow(QOpenGLWindow::NoPartialUpdate)
{
    this->spriteFlyFact = spriteFlyFact;


}

void AbstractView::setDrawingStrat(ViewDrawingStrat *viewDrawingStrat)
{

}

void AbstractView::paintGL()
{

}

void AbstractView::resizeGL(int w, int h)
{

}
