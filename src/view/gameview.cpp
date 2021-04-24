#include "gameview.h"

GameView::GameView(SpriteFlyweightFactoryAbstract *spriteFlyFact)
    : AbstractView(spriteFlyFact)
{
    resize(450, 600);
    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    setFormat(fmt);

    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));
}

void GameView::paintGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    QColor theColor(0, 0, 0);
    QPainter p(this);
    p.setFont(font);
    p.setBrush(m_brush);

    QMatrix4x4 mvp = m_projection * m_view;

    std::vector<DrawItem> itemsToDraw;
    viewDrawingStrat->draw(&itemsToDraw);

    //Now need to actually draw because i have to do it in this glass apparently
    for(int i = 0; i < itemsToDraw.size(); i++)
    {
        SpriteFlyweight * focusFlyweight = spriteFlyFact->getFlyweight(itemsToDraw.at(i).key);

        focusFlyweight->generate();
        glEnable(GL_TEXTURE_2D);
        focusFlyweight->bind(0);
        glBegin(GL_QUADS);

        if(itemsToDraw.at(i).flip)
            glTexCoord2f(1, 1);
        else
            glTexCoord2f(0, 1);
        glVertex3f(itemsToDraw.at(i).x,
                   itemsToDraw.at(i).y, 0.0f);

        if(itemsToDraw.at(i).flip)
            glTexCoord2f(0, 1);
        else
            glTexCoord2f(1, 1);
        glVertex3f(itemsToDraw.at(i).x + itemsToDraw.at(i).w,
                   itemsToDraw.at(i).y, 0.0f);

        if(itemsToDraw.at(i).flip)
            glTexCoord2f(0, 0);
        else
            glTexCoord2f(1, 0);
        glVertex3f(itemsToDraw.at(i).x + itemsToDraw.at(i).w,
                   itemsToDraw.at(i).y + itemsToDraw.at(i).h, 0.0f);

        if(itemsToDraw.at(i).flip)
            glTexCoord2f(1, 0);
        else
            glTexCoord2f(0, 0);
        glVertex3f(itemsToDraw.at(i).x,
                   itemsToDraw.at(i).y + itemsToDraw.at(i).h, 0.0f);

        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
}

void GameView::resizeGL(int w, int h)
{
    m_window_normalised_matrix.setToIdentity();
    m_window_normalised_matrix.translate(w / 2.0, h / 2.0);
    m_window_normalised_matrix.scale(w / 2.0, -h / 2.0);

    m_window_painter_matrix.setToIdentity();
    m_window_painter_matrix.translate(w / 2.0, h / 2.0);

    m_projection.setToIdentity();
    m_projection.ortho(-7.5f, 8.5f, -4.f, 5.f, -1.f, 1.f);

    glOrtho(-7.5f, 8.5f, -4.f, 5.f, -1, 1);
}
