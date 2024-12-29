#pragma once
#include "QPainter"
#include "QRect"
#include "QHeaderView"
#include "QColor"

class CalendarCustomHeader : public QHeaderView
{
public:
    explicit CalendarCustomHeader() : QHeaderView(Qt::Horizontal, nullptr)
    {}

    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override
    {
        painter -> save();

        if(logicalIndex == 2)
        {
            painter -> setPen(QColor("#8474fb"));
        }

        painter -> drawText(rect, Qt::AlignCenter, model() -> headerData(logicalIndex, Qt::Horizontal, Qt::DisplayRole).toString());
    }
};