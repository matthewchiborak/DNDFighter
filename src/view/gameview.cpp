#include "gameview.h"

GameView::GameView(SpriteFlyweightFactoryAbstract *spriteFlyFact)
    : AbstractView(spriteFlyFact)
{
    resize(1600, 900);
    QSurfaceFormat fmt;
    fmt.setDepthBufferSize(24);
    fmt.setStencilBufferSize(8);
    setFormat(fmt);

    m_brush = QBrush(Qt::red);
    font.setPixelSize(48);

    connect(this, SIGNAL(frameSwapped()), this, SLOT(update()));
}

void GameView::setDrawingStrat(ViewDrawingStrat *viewDrawingStrat)
{
    this->viewDrawingStrat = viewDrawingStrat;

    std::vector<DrawItem> itemsToDraw;
    viewDrawingStrat->predraw(&itemsToDraw);

    for(int i = 0; i < itemsToDraw.size(); i++)
    {
        SpriteFlyweight * focusFlyweight = spriteFlyFact->getFlyweight(itemsToDraw.at(i).key);

        focusFlyweight->generate();
        glEnable(GL_TEXTURE_2D);
        focusFlyweight->bind(0);
        glDisable(GL_TEXTURE_2D);
    }
}

void GameView::paintGL()
{
    emit frameInited();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    QColor theColor(255, 255, 255);
    QPainter p(this);
    p.setFont(font);
    p.setBrush(m_brush);
    QPen thePen(theColor);
    p.setPen(thePen);

    std::vector<DrawItem> itemsToDraw;
    std::vector<TextItem> textsToDraw;
    viewDrawingStrat->draw(&itemsToDraw, &textsToDraw);

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

    for(int i = 0; i < textsToDraw.size(); i++)
    {
        p.drawText((textsToDraw.at(i).x),
                   (textsToDraw.at(i).y),
                   (textsToDraw.at(i).w),
                   (textsToDraw.at(i).h),
                   Qt::AlignCenter,
                   QString::fromStdString(textsToDraw.at(i).content));
    }
}

void GameView::resizeGL(int w, int h)
{
    glOrtho(-1.77f, 1.77f, 0.f, 2.f, -1.f, 1.f);
}
