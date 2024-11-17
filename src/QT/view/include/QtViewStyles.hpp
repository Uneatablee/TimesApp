#pragma once
#include <QString>

namespace QtViewStyles
{
    const QString Styles = R"(

        .general-background{
            background-color: #1b1b1b;
        }

        .button-style{
            background-color: #242323;
            color: #ecebeb;
            border-radius: 5px;
            height: 40px;
        }

        .button-style:hover{
            background-color: #434343;
            color: black;
        }

        .left-menu-slider{
            background: #242323;
            border: 1px solid #575555;
            border-radius: 7px;
        }

        .button-toggle-menu-left{
            background-color: #242323;
            border-radius: 5px;
            height: 40px;
            margin-top: 30px;
            margin-bottom: 20px;
        }

        .button-toggle-menu-left:hover{
            background-color: #434343;
        }
    )";
}