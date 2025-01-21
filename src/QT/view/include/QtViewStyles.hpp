#pragma once
#include <QString>


//background-color: #c5bdfe; <--Option
//left menu slider background #f6f6f6;


namespace QtViewStyles
{
    const QString Styles = R"(

        *
        {
            font-family: "Montserrat";
            font-size: 12px;
        }

        .general-background{
            background-color: #f6f6f6;
        }

        .button-style{
            background-color: #ffffff;
            color: #000000;
            border-radius: 10px;
            height: 40px;
        }

        .button-style:hover{
            background-color: #d0d4f3;
            color: black;
        }

        .left-menu-slider{
            background: #ffffff;
            border-right: 2px solid #f3f3f3;
        }

        .button-toggle-menu-left{
            background-color: #ffffff;
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
            padding: 10px;
            border-radius: 10px;
        }

        .tasks-view
        {
            background: #ffffff;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .tasks-group-view
        {
            background: #ffffff;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .month-view
        {
            background: #ffffff;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .top-bar-widget1
        {
            background: #d0d4f3;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .top-bar-widget2
        {
            background: #c5bdfe;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .top-bar-widget3
        {
            background: #8474fb;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .top-bar-widget4
        {
            background: #42378f;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .event-option-buttons
        {
            border-radius: 5px;
            padding-top: 2px;
            padding-bottom: 2px;
            padding-left: 2px;
            background-color: #ffffff;
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

        .calendar-widget
        {
            background: #ffffff;
            border: 2px solid #f3f3f3;
            border-radius: 10px;
        }

        .calendar-top-bar-buttons
        {
            background-color: #ffffff;
            border-radius: 10px;
            color: #808080;
        }

        .calendar-top-bar-buttons:hover{
            background-color: #d0d4f3;
            color: black;
        }

        .month-label
        {
            font: bold;
            color: #808080;
            font-size: 32px;
        }

        .calendar-options-bar
        {
            background-color: #ffffff;
        }

        .year-label
        {
            font: normal;
            font-size: 32px;
            color: #808080;
            margin-left: 2px;
        }
    )";
}