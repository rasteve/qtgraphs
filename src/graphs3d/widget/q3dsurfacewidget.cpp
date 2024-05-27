// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtGraphsWidgets/q3dsurfacewidget.h>
#include <private/qquickgraphssurface_p.h>

QT_BEGIN_NAMESPACE

/*!
 * \class Q3DSurfaceWidget
 * \inmodule QtGraphs
 * \ingroup graphs_3D
 * \brief The Q3DSurfaceWidget class provides methods for rendering 3D surface plots.
 *
 * This class enables developers to render 3D surface plots and to view them by
 * rotating the scene freely. The visual properties of the surface such as draw
 * mode and shading can be controlled via QSurface3DSeries.
 *
 * The Q3DSurfaceWidget supports selection by showing a highlighted ball on the data
 * point where the user has clicked with the left mouse button (when the default
 * input handler is in use) or selected via QSurface3DSeries. The selection pointer
 * is accompanied by a label, which in the default case shows the value of the data
 * point and the coordinates of the point.
 *
 * The value range and the label format shown on the axis can be controlled
 * through QValue3DAxis.
 *
 * To rotate the graph, hold down the right mouse button and move the mouse.
 * Zooming is done using the mouse wheel. Both actions assume the default input
 * handler is in use.
 *
 * If no axes are set explicitly for Q3DSurfaceWidget, temporary default axes with no
 * labels are created. These default axes can be modified via axis accessors,
 * but as soon as any axis is set explicitly for the orientation, the default
 * axis for that orientation is destroyed.
 *
 * \section1 How to construct a minimal Q3DSurfaceWidget graph
 *
 * First, construct Q3DSurfaceWidget. Since we are running the graph as a top-level
 * window in this example, we need to clear the \c Qt::FramelessWindowHint flag,
 * which is set by default:
 *
 * \snippet doc_src_q3dsurface_construction.cpp 0
 *
 * Now Q3DSurfaceWidget is ready to receive data to be rendered. Create data elements
 * to receive values:
 *
 * \note In the new proxy-series relationship, data is held in series.
 * Therefore, for the proxy to be able to add, delete, or edit the data, it is
 * a prerequisite to create a series first.
 *
 * \snippet doc_src_q3dsurface_construction.cpp 1
 *
 * First feed the data to the row elements and then add their pointers to the
 * data element:
 *
 * \snippet doc_src_q3dsurface_construction.cpp 2
 *
 * Create a new series and set data to it:
 *
 * \snippet doc_src_q3dsurface_construction.cpp 3
 *
 * Finally you will need to set it visible:
 *
 * \snippet doc_src_q3dsurface_construction.cpp 4
 *
 * The complete code needed to create and display this graph is:
 *
 * \snippet doc_src_q3dsurface_construction.cpp 5
 *
 * And this is what those few lines of code produce:
 *
 * \image q3dsurface-minimal.png
 *
 * The scene can be rotated, zoomed into, and a surface point can be selected to
 * view its position, but no other interactions are included in this minimal code
 * example. You can learn more by familiarizing yourself with the examples
 * provided, like the \l{Surface Graph Gallery}.
 *
 *
 * \sa Q3DBarsWidget, Q3DScatterWidget, {Qt Graphs C++ Classes for 3D}
 */

/*!
 * Constructs a new 3D surface graph.
 */
Q3DSurfaceWidget::Q3DSurfaceWidget()
    : QAbstract3DGraphWidget(QStringLiteral("Surface3D"))
{}

/*!
 *  Destroys the 3D surface graph.
 */
Q3DSurfaceWidget::~Q3DSurfaceWidget() {}

/*!
 * Adds the \a series to the graph.  A graph can contain multiple series, but
 * has only one set of axes. If the newly added series has specified a selected
 * item, it will be highlighted and any existing selection will be cleared. Only
 * one added series can have an active selection.
 *
 * \sa  QAbstract3DGraphWidget::hasSeries()
 */
void Q3DSurfaceWidget::addSeries(QSurface3DSeries *series)
{
    graphSurface()->addSeries(series);
}

/*!
 * Removes the \a series from the graph.
 *
 * \sa QAbstract3DGraphWidget::hasSeries()
 */
void Q3DSurfaceWidget::removeSeries(QSurface3DSeries *series)
{
    graphSurface()->removeSeries(series);
}

/*!
 * Returns the list of series added to this graph.
 *
 * \sa QAbstract3DGraphWidget::hasSeries()
 */
QList<QSurface3DSeries *> Q3DSurfaceWidget::seriesList() const
{
    QList<QSurface3DSeries *> surfaceSeriesList;
    for (QAbstract3DSeries *abstractSeries : graphSurface()->m_seriesList) {
        QSurface3DSeries *surfaceSeries = qobject_cast<QSurface3DSeries *>(abstractSeries);
        if (surfaceSeries)
            surfaceSeriesList.append(surfaceSeries);
    }

    return surfaceSeriesList;
}

/*!
 * \property Q3DSurfaceWidget::axisX
 *
 * \brief The active x-axis.
 *
 * Sets \a axis as the active x-axis. Implicitly calls addAxis() to transfer the
 * ownership of the axis to this graph.
 *
 * If \a axis is null, a temporary default axis with no labels and an
 * automatically adjusting range is created.
 *
 * This temporary axis is destroyed if another axis is set explicitly to the
 * same orientation.
 *
 * \sa addAxis(), releaseAxis()
 */
void Q3DSurfaceWidget::setAxisX(QValue3DAxis *axis)
{
    graphSurface()->setAxisX(axis);
}

QValue3DAxis *Q3DSurfaceWidget::axisX() const
{
    return static_cast<QValue3DAxis *>(graphSurface()->axisX());
}

/*!
 * \property Q3DSurfaceWidget::axisY
 *
 * \brief The active y-axis.
 *
 * Sets \a axis as the active y-axis. Implicitly calls addAxis() to transfer the
 * ownership of the axis to this graph.
 *
 * If \a axis is null, a temporary default axis with no labels and an
 * automatically adjusting range is created.
 *
 * This temporary axis is destroyed if another axis is set explicitly to the
 * same orientation.
 *
 * \sa addAxis(), releaseAxis()
 */
void Q3DSurfaceWidget::setAxisY(QValue3DAxis *axis)
{
    graphSurface()->setAxisY(axis);
}

QValue3DAxis *Q3DSurfaceWidget::axisY() const
{
    return static_cast<QValue3DAxis *>(graphSurface()->axisY());
}

/*!
 * \property Q3DSurfaceWidget::axisZ
 *
 * \brief The active z-axis.
 *
 * Sets \a axis as the active z-axis. Implicitly calls addAxis() to transfer the
 * ownership of the axis to this graph.
 *
 * If \a axis is null, a temporary default axis with no labels and an
 * automatically adjusting range is created.
 *
 * This temporary axis is destroyed if another axis is set explicitly to the
 * same orientation.
 *
 * \sa addAxis(), releaseAxis()
 */
void Q3DSurfaceWidget::setAxisZ(QValue3DAxis *axis)
{
    graphSurface()->setAxisZ(axis);
}

QValue3DAxis *Q3DSurfaceWidget::axisZ() const
{
    return static_cast<QValue3DAxis *>(graphSurface()->axisZ());
}

/*!
 * \property Q3DSurfaceWidget::selectedSeries
 *
 * \brief The selected series or null.
 *
 * If selectionMode has \c MultiSeries set, this
 * property holds the series which owns the selected point.
 */
QSurface3DSeries *Q3DSurfaceWidget::selectedSeries() const
{
    return graphSurface()->selectedSeries();
}

/*!
 * \property Q3DSurfaceWidget::flipHorizontalGrid
 *
 * \brief Whether the horizontal axis grid is displayed on top of the graph
 * rather than on the bottom.
 *
 * In some use cases, the horizontal axis grid is mostly covered by the surface,
 * so it can be more useful to display the horizontal axis grid on top of the
 * graph rather than on the bottom. A typical use case for this is showing 2D
 * spectrograms using orthographic projection with a top-down viewpoint.
 *
 * If \c{false}, the horizontal axis grid and labels are drawn on the horizontal
 * background of the graph. If \c{true}, the horizontal axis grid and labels are
 * drawn on the opposite side of the graph from the horizontal background.
 * Defaults to \c{false}.
 */
void Q3DSurfaceWidget::setFlipHorizontalGrid(bool flip)
{
    graphSurface()->setFlipHorizontalGrid(flip);
}

bool Q3DSurfaceWidget::flipHorizontalGrid() const
{
    return graphSurface()->flipHorizontalGrid();
}

/*!
 * Adds \a axis to the graph. The axes added via addAxis are not yet taken to
 * use, addAxis is simply used to give the ownership of the \a axis to the
 * graph. The \a axis must not be null or added to another graph.
 *
 * \sa releaseAxis(), setAxisX(), setAxisY(), setAxisZ()
 */
void Q3DSurfaceWidget::addAxis(QValue3DAxis *axis)
{
    return graphSurface()->addAxis(axis);
}

/*!
 * Releases the ownership of the \a axis back to the caller, if it is added to
 * this graph. If the released \a axis is in use, a new default axis will be
 * created and set active.
 *
 * If the default axis is released and added back later, it behaves as any other
 * axis would.
 *
 * \sa addAxis(), setAxisX(), setAxisY(), setAxisZ()
 */
void Q3DSurfaceWidget::releaseAxis(QValue3DAxis *axis)
{
    return graphSurface()->releaseAxis(axis);
}

/*!
 * Returns the list of all added axes.
 *
 * \sa addAxis()
 */
QList<QValue3DAxis *> Q3DSurfaceWidget::axes() const
{
    QList<QAbstract3DAxis *> abstractAxes = graphSurface()->axes();
    QList<QValue3DAxis *> retList;
    for (QAbstract3DAxis *axis : abstractAxes)
        retList.append(static_cast<QValue3DAxis *>(axis));

    return retList;
}

/*!
 * \internal
 */
QQuickGraphsSurface *Q3DSurfaceWidget::graphSurface()
{
    return static_cast<QQuickGraphsSurface *>(m_graphsItem.data());
}

/*!
 * \internal
 */
const QQuickGraphsSurface *Q3DSurfaceWidget::graphSurface() const
{
    return static_cast<const QQuickGraphsSurface *>(m_graphsItem.data());
}

QT_END_NAMESPACE
