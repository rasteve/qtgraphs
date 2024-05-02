// Copyright (C) 2024 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

//  W A R N I N G
//  -------------
//
// This file is not part of the QtGraphs API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
#ifndef QXYMODELMAPPER_P_H
#define QXYMODELMAPPER_P_H

#include <QtGraphs/QXYModelMapper>
#include <private/qobject_p.h>

QT_BEGIN_NAMESPACE

class QXYModelMapperPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QXYModelMapper)
public:
    QXYModelMapperPrivate();
    ~QXYModelMapperPrivate() override;

public Q_SLOTS:
    // for the model
    void onModelUpdated(QModelIndex topLeft, QModelIndex bottomRight);
    void onModelRowsAdded(QModelIndex parent, int start, int end);
    void onModelRowsRemoved(QModelIndex parent, int start, int end);
    void onModelColumnsAdded(QModelIndex parent, int start, int end);
    void onModelColumnsRemoved(QModelIndex parent, int start, int end);
    void handleModelDestroyed();

    // for the series
    void onPointAdded(int pointPos);
    void onPointRemoved(int pointPos);
    void onPointsRemoved(int pointPos, int count);
    void onPointReplaced(int pointPos);
    void handleSeriesDestroyed();

    void initializeXYFromModel();

private:
    QModelIndex xModelIndex(int xPos);
    QModelIndex yModelIndex(int yPos);
    void insertData(int start, int end);
    void removeData(int start, int end);
    void blockModelSignals(bool block = true);
    void blockSeriesSignals(bool block = true);
    qreal valueFromModel(QModelIndex index);
    void setValueToModel(QModelIndex index, qreal value);

private:
    QXYSeries *m_series = nullptr;
    QAbstractItemModel *m_model = nullptr;
    int m_first = 0;
    int m_count = -1;
    Qt::Orientation m_orientation = Qt::Vertical;
    int m_xSection = -1;
    int m_ySection = -1;
    bool m_seriesSignalsBlock = false;
    bool m_modelSignalsBlock = false;
};

QT_END_NAMESPACE
#endif // QXYMODELMAPPER_P_H
