#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <QOpenGLWindow>
#include <QScreen>
#include <QPainter>
#include <QGuiApplication>
#include <QMatrix4x4>
#include <QStaticText>
#include <QKeyEvent>
#include <QPainterPath>
#include <QQueue>
#include <QDebug>

#include "spriteflyweightfactoryabstract.h"
#include "viewdrawingstrat.h"

class AbstractView : public QOpenGLWindow
{
public:
    AbstractView(SpriteFlyweightFactoryAbstract * spriteFlyFact);

    void setDrawingStrat(ViewDrawingStrat * viewDrawingStrat);

protected:
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

    SpriteFlyweightFactoryAbstract * spriteFlyFact;

    ViewDrawingStrat * viewDrawingStrat;
};

#endif // ABSTRACTVIEW_H
