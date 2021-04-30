#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H

#include "abstractview.h"

class GameView : public AbstractView
{
    Q_OBJECT
public:
    GameView(SpriteFlyweightFactoryAbstract * spriteFlyFact);

    void setDrawingStrat(ViewDrawingStrat * viewDrawingStrat);

protected:
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

private:
    QBrush m_brush;
    QFont font;
};

#endif // BATTLEVIEW_H
