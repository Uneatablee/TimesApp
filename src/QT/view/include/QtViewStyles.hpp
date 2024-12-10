#pragma once
#include <QString>


//background-color: #c5bdfe; <--Option


namespace QtViewStyles
{
    const QString Styles = R"(

        *
        {
            font-family: Verdana, sans-serif;
            font-size: 12px;
        }

        .general-background{
            background-color: #ffffff;
        }

        .button-style{
            background-color: #f6f6f6;
            color: #000000;
            border-radius: 10px;
            height: 40px;
        }

        .button-style:hover{
            background-color: #d0d4f3;
            color: black;
        }

        .left-menu-slider{
            background: #f6f6f6;
            border: 2px solid #f4f4f4;
        }

        .button-toggle-menu-left{
            background-color: #f5f5f5;
            border-radius: 10px;
            height: 40px;
            margin-top: 30px;
            margin-bottom: 20px;
        }

        .button-toggle-menu-left:hover{
            background-color: #d0d4f3;
        }

        .calendar-table
        {
            background-color: #ffffff;
            border: none;
        }

        .tasks-view
        {
            background: #f6f6f6;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .tasks-group-view
        {
            background: #f6f6f6;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .month-view
        {
            background: #f6f6f6;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .top-bar-widget1
        {
            background: #d0d4f3;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .top-bar-widget2
        {
            background: #c5bdfe;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .top-bar-widget3
        {
            background: #8474fb;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .top-bar-widget4
        {
            background: #42378f;
            border: 2px solid #f4f4f4;
            border-radius: 10px;
        }

        .event-option-buttons
        {
            border-radius: 5px;
            padding-top: 2px;
            padding-bottom: 2px;
            padding-left: 2px;
            background-color: #f6f6f6;
            text-align: left;
        }

        .event-option-buttons:hover
        {
            background-color: #d0d4f3;x
        }

        .event-options-label
        {
            color: grey;
            font-size: 10px;
        }
    )";
}