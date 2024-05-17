// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only
#include <QtGraphs/qgraphs3dnamespace.h>
QT_BEGIN_NAMESPACE
/*!
    \namespace QGraphs3D
    \inmodule QtGraphs
    \ingroup graphs_3D
    \brief The QGraphs3D module provides enums used by QtGraphs' 3D API.

*/

/*!
    \enum QGraphs3D::SelectionFlag

    Item selection modes. Values of this enumeration can be combined with OR
   operator.

    \value SelectionNone
           Selection mode disabled.
    \value SelectionItem
           Selection highlights a single item.
    \value SelectionRow
           Selection highlights a single row.
    \value SelectionItemAndRow
           Combination flag for highlighting both item and row with different colors.
    \value SelectionColumn
           Selection highlights a single column.
    \value SelectionItemAndColumn
           Combination flag for highlighting both item and column with different colors.
    \value SelectionRowAndColumn
           Combination flag for highlighting both row and column.
    \value SelectionItemRowAndColumn
           Combination flag for highlighting item, row, and column.
    \value SelectionSlice
           Setting this mode flag indicates that the graph should take care of the slice view handling
           automatically. If you wish to control the slice view yourself via Q3DScene, do not set this
           flag. When setting this mode flag, either \c SelectionRow or \c SelectionColumn must also
           be set, but not both. Slicing is supported by Q3DBars and Q3DSurface only.
           When this flag is set, slice mode is entered in the following situations:
           \list
           \li When selection is changed explicitly via series API to a visible item
           \li When selection is changed by clicking on the graph
           \li When the selection mode changes and the selected item is visible
           \endlist
    \value SelectionMultiSeries
           Setting this mode means that items for all series at same position are highlighted, instead
           of just the selected item. The actual selection in the other series doesn't change.
           When setting this mode flag, one or more of the basic selection flags (\c {SelectionItem},
           \c {SelectionRow}, or \c SelectionColumn) must also be set.
           Multi-series selection is not supported for Q3DScatter.
*/

/*!
    \enum QGraphs3D::ShadowQuality

    Quality of shadows.

    \value None
           Shadows are disabled.
    \value Low
           Shadows are rendered in low quality.
    \value Medium
           Shadows are rendered in medium quality.
    \value High
           Shadows are rendered in high quality.
    \value SoftLow
           Shadows are rendered in low quality with softened edges.
    \value SoftMedium
           Shadows are rendered in medium quality with softened edges.
    \value SoftHigh
           Shadows are rendered in high quality with softened edges.
*/

/*!
    \enum QGraphs3D::ElementType

    Type of an element in the graph.

    \value None
           No defined element.
    \value Series
           An item in a series.
    \value AxisXLabel
           The x-axis label.
    \value AxisYLabel
           The y-axis label.
    \value AxisZLabel
           The z-axis label.
    \value CustomItem
           A custom item.
*/

/*!
    \enum QGraphs3D::OptimizationHint

    The optimization hint for rendering.

    \value Default
           Provides the full feature set with instancing at a good performance.
    \value Legacy
           Provides the full feature set at a reasonable performance. To be used if
           OptimizationHint.Default performs poorly or does not work.
*/

/*!
 * \enum QGraphs3D::CameraPreset
 *
 * Predefined positions for camera.
 *
 * \value NoPreset
 *        Used to indicate a preset has not been set, or the scene has been rotated freely.
 * \value FrontLow
 * \value Front
 * \value FrontHigh
 * \value LeftLow
 * \value Left
 * \value LeftHigh
 * \value RightLow
 * \value Right
 * \value RightHigh
 * \value BehindLow
 * \value Behind
 * \value BehindHigh
 * \value IsometricLeft
 * \value IsometricLeftHigh
 * \value IsometricRight
 * \value IsometricRightHigh
 * \value DirectlyAbove
 * \value DirectlyAboveCW45
 * \value DirectlyAboveCCW45
 * \value FrontBelow
 *        In Q3DBars from FrontBelow onward these only work for graphs including negative
 *        values. They act as Preset...Low for positive-only values.
 * \value LeftBelow
 * \value RightBelow
 * \value BehindBelow
 * \value DirectlyBelow
 *        Acts as FrontLow for positive-only bars.
 */
QT_END_NAMESPACE
