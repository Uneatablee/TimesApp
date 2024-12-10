#pragma once
#include <QString>

namespace QtViewStyles
{
    const QString Styles = R"(

        *
        {
            font-family: Verdana, sans-serif;
            font-size: 12px;
        }

        .general-background{
            background-color: #c5bdfe;
        }

        .button-style{
            background-color: #f6f6f6;
            color: #000000;
            border-radius: 5px;
            height: 40px;
        }

        .button-style:hover{
            background-color: #d0d4f3;
            color: black;
        }

        .left-menu-slider{
            background: #f6f6f6;
            border: 2px solid #ffffff;
        }

        .button-toggle-menu-left{
            background-color: #f5f5f5;
            border-radius: 5px;
            height: 40px;
            margin-top: 30px;
            margin-bottom: 20px;
        }

        .button-toggle-menu-left:hover{
            background-color: #d0d4f3;
        }

        .calendar-table
        {
            padding: 10px;
            background-color: #ffffff;
            border: none;
        }

        .tasks-view
        {
            background: #f6f6f6;
            border: 2px solid #ffffff;
            border-radius: 5px;
        }
    )";
}