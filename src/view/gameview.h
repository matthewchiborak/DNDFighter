#ifndef BATTLEVIEW_H
#define BATTLEVIEW_H

#include "abstractview.h"

class GameView : public AbstractView
{
public:
    GameView(SpriteFlyweightFactoryAbstract * spriteFlyFact);

protected:
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;

private:
    QMatrix4x4 m_window_normalised_matrix;
    QMatrix4x4 m_window_painter_matrix;
    QMatrix4x4 m_projection;
    QMatrix4x4 m_view;
    QMatrix4x4 m_model_triangle;
    QMatrix4x4 m_model_text;
    QBrush m_brush;
    QFont font;
};

#endif // BATTLEVIEW_H
