#pragma once
#include "QPainter"
#include "QRect"
#include "QHeaderView"
#include "QColor"

class CalendarCustomHeader : public QHeaderView
{
public:
    explicit CalendarCustomHeader(int current_weekday_number) : QHeaderView(Qt::Horizontal, nullptr)
    {
        m_current_weekday_logical_index = current_weekday_number;
    }

    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override
    {
        QStyleOptionHeader style_mods;
        style_mods.initFrom(this);

        style_mods.rect = rect;
        style_mods.section = logicalIndex;
        style_mods.textAlignment = Qt::AlignCenter;
        style_mods.text = this -> model() -> headerData(logicalIndex, Qt::Horizontal, Qt::DisplayRole).toString();
        style_mods.palette.setColor(QPalette::ButtonText, QColor("#9c9c9c"));
        style_mods.palette.setColor(QPalette::Button, QColor("#ffffff"));

        QFont font{};
        font.setPointSize(16);
        font.setBold(0);
        painter -> setFont(font);


        if(logicalIndex == m_current_weekday_logical_index)
        {
            style_mods.palette.setColor(QPalette::ButtonText, QColor("#8474fb"));
        }

        this -> style()->drawControl(QStyle::CE_Header, &style_mods, painter, this);
    }

    void setDayHighlight(int day_number)
    {
        m_current_weekday_logical_index = day_number;
    }

private:
    int m_current_weekday_logical_index;
};