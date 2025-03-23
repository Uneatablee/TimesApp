#include "../include/DateTime.hpp"
#include "date/tz.h"
#include <chrono>

namespace dp_business_logic::DayPlanner
{

    DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year)
    {
        std::chrono::year_month_day ymd{std::chrono::year{static_cast<int>(year)},
                                        std::chrono::month{month},
                                        std::chrono::day{day}};
        m_time_point = std::chrono::system_clock::to_time_t(std::chrono::sys_days{ymd});
    }

    DateTime::DateTime(std::string date)
    {
        m_time_point = GetSecondsFromEpochFromString(date);
    }

    DateTime::DateTime(time_t time_point)
    {
        m_time_point = time_point;
    }

    DateTime::DateTime(std::chrono::year_month_day ymd)
    {
        std::chrono::system_clock::time_point tp = std::chrono::sys_days{ymd};
        m_time_point = std::chrono::system_clock::to_time_t(tp);
    }

    DateTime::DateTime(time_t time_point, const date::time_zone* zone)
    {
        m_time_point = time_point;
        m_zone = zone;
    }

    long DateTime::GetSecondsFromEpoch()
    {
        auto current_time = std::chrono::system_clock::from_time_t(m_time_point);
        return std::chrono::duration_cast<std::chrono::seconds>(current_time.time_since_epoch()).count();
    }

    std::chrono::year_month_day DateTime::GetDate_YMDFormat()
    {
        if(!m_zone)
        {
            auto time = std::chrono::system_clock::from_time_t(m_time_point);
            return std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
        }

        auto time = std::chrono::system_clock::from_time_t(m_time_point);
        auto zoned_date = date::make_zoned(m_zone, time);
        auto local_time = zoned_date.get_local_time();
        return static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));
    }

    std::tuple<unsigned int, uint8_t, uint8_t> DateTime::GetYearMonthDay()
    {
        std::chrono::year_month_day ymd;
        if(!m_zone)
        {
            auto time = std::chrono::system_clock::from_time_t(m_time_point);
            ymd = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
        }
        else
        {
            auto time = std::chrono::system_clock::from_time_t(m_time_point);
            auto local_time = date::make_zoned(m_zone, time).get_local_time();
            ymd = static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));
        }

        auto year = static_cast<unsigned int>(static_cast<int>(ymd.year()));
        auto month = static_cast<uint8_t>(static_cast<unsigned int>(ymd.month()));
        auto day = static_cast<uint8_t>(static_cast<unsigned int>(ymd.day()));
        return std::make_tuple(year, month, day);
    }

    std::tuple<uint8_t, uint8_t> DateTime::GetHourMinute()
    {
        date::hh_mm_ss<std::__1::chrono::minutes> time;
        if(!m_zone)
        {
            auto current_time = std::chrono::system_clock::from_time_t(m_time_point);
            auto days_passed = std::chrono::floor<std::chrono::days>(current_time);
            auto time_since_midnight = std::chrono::floor<std::chrono::minutes>(current_time - days_passed);
            time = date::make_time(time_since_midnight);
        }
        else
        {

            auto current_time = std::chrono::system_clock::from_time_t(m_time_point);
            auto local_time = date::make_zoned(m_zone, current_time).get_local_time();
            auto current_local_time = date::floor<std::chrono::minutes>(local_time);
            auto days_passed = date::floor<date::days>(local_time);
            time = date::make_time(current_local_time - days_passed);
        }

        uint8_t hours = static_cast<uint8_t>(time.hours().count());
        uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

        return {hours, minutes};
    }

    uint8_t DateTime::GetDayNumber()
    {
        auto current_ymd = GetDate_YMDFormat();
        return (std::chrono::weekday(current_ymd)).iso_encoding();
    }

    std::tuple<unsigned int, uint8_t, uint8_t> DateTime::ConvertEpochYearMonthDay(long long epoch_time = 0)
    {
        std::chrono::year_month_day ymd;
        if(epoch_time == 0)
        {
            epoch_time = m_time_point;
        }

        std::chrono::time_point<std::chrono::system_clock> time_point{std::chrono::microseconds(epoch_time)};

        if(!m_zone)
        {
            ymd = static_cast<std::chrono::year_month_day>(std::chrono::floor<std::chrono::days>(time_point));
        }
        else
        {
            auto local_time = date::make_zoned(m_zone, time_point).get_local_time();
            ymd = static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));
        }

        auto year = static_cast<unsigned int>(static_cast<int>(ymd.year()));
        auto month = static_cast<uint8_t>(static_cast<unsigned int>(ymd.month()));
        auto day = static_cast<uint8_t>(static_cast<unsigned int>(ymd.day()));

        return std::make_tuple(year, month, day);
    }

    std::tuple<uint8_t, uint8_t> DateTime::ConvertEpochHourMinute(long long epoch_time = 0)
    {
        date::hh_mm_ss<std::__1::chrono::minutes> time;
        if(epoch_time == 0)
        {
            epoch_time = m_time_point;
        }

        std::chrono::time_point<std::chrono::system_clock> time_point{std::chrono::microseconds(epoch_time)};

        if(!m_zone)
        {

            auto current_local_time = date::floor<std::chrono::minutes>(time_point);
            auto days_passed = date::floor<date::days>(time_point);
            time = date::make_time(current_local_time - days_passed);
        }
        else
        {
            auto local_time = date::make_zoned(date::current_zone(), time_point).get_local_time();
            auto current_local_time = date::floor<std::chrono::minutes>(local_time);
            auto days_passed = date::floor<date::days>(local_time);
            time = date::make_time(current_local_time - days_passed);
        }

        uint8_t hours = static_cast<uint8_t>(time.hours().count());
        uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

        return std::make_tuple(hours, minutes);
    }

    unsigned int DateTime::GetOffsetDayDate(unsigned int days_prev_count)
    {
        auto time = std::chrono::system_clock::from_time_t(m_time_point);

        if(!m_zone)
        {
            auto ymd = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
            date::sys_days target_day = ymd;
            std::chrono::year_month_day day_date = target_day + date::days{days_prev_count};
            return static_cast<unsigned int>(static_cast<date::year_month_day>(day_date).day());
        }

        auto local_time = date::make_zoned(m_zone, time).get_local_time();
        date::sys_days target_day = static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time));
        std::chrono::year_month_day day_date = target_day + date::days{days_prev_count};
        return static_cast<unsigned int>(static_cast<date::year_month_day>(day_date).day());
    }


    uint8_t DateTime::GetMonthFromOffset(int days_offset)
    {
        if(days_offset == 0)
        {
            return std::get<1>(GetYearMonthDay());
        }

        auto curr_date = GetDate_YMDFormat();
        auto target_date = date::sys_days(curr_date) + date::days(days_offset);
        return static_cast<uint8_t>(static_cast<unsigned int>(static_cast<date::year_month_day>(target_date).month()));
    }

    unsigned int DateTime::GetYearFromOffset(int days_offset)
    {
        if(days_offset == 0)
        {
            return std::get<0>(GetYearMonthDay());
        }

        auto curr_date = GetDate_YMDFormat();
        auto target_date = date::sys_days(curr_date) + date::days(days_offset);
        return static_cast<unsigned int>(static_cast<int>(static_cast<date::year_month_day>(target_date).year()));
    }

    long DateTime::GetSecondsFromEpochFromString(std::string date)
    {
        std::stringstream date_string(date);
        std::tm tm{};
        date_string >> std::get_time(&tm, "%d/%m/%Y %H:%M");

        std::chrono::system_clock::time_point tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
        return tp.time_since_epoch().count();
    }

    std::chrono::year_month_day DateTime::GetYMD()
    {
        auto time = std::chrono::system_clock::from_time_t(m_time_point);
        if(!m_zone)
        {
            return std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
        }

        auto local_time = date::make_zoned(m_zone, time).get_local_time();
        return static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));

    }
}