#include "../include/DateTime.hpp"
#include "date/tz.h"

namespace dp_business_logic::DayPlanner
{

    DateTime::DateTime()
    {
        m_time_point = GetCurrentTimeDate();
    };
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

    DateTime::DateTime(std::chrono::year_month_day ymd)
    {
        std::chrono::system_clock::time_point tp = std::chrono::sys_days{ymd};
        m_time_point = std::chrono::system_clock::to_time_t(tp);
    }

    bool DateTime::SetTimePoint(time_t time_point)
    {
        m_time_point = time_point;
        return true;
    }

    time_t DateTime::GetCurrentTimeDate()
    {
        auto current_moment = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(current_moment);
    }

    long DateTime::GetSecondsFromEpoch()
    {
        auto current_time = std::chrono::system_clock::from_time_t(m_time_point);
        return std::chrono::duration_cast<std::chrono::seconds>(current_time.time_since_epoch()).count();
    }

    std::chrono::year_month_day DateTime::GetCurrentDate_YMDFormat()
    {
        auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());
        auto local_time = now.get_local_time();
        return static_cast<std::chrono::year_month_day>(static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time)));
    }

    std::tuple<unsigned int, uint8_t, uint8_t> DateTime::GetCurrentYearMonthDay()
    {
        auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());
        auto local_time = now.get_local_time();
        auto ymd = static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time));

        auto year = static_cast<unsigned int>(static_cast<int>(ymd.year()));
        auto month = static_cast<uint8_t>(static_cast<unsigned int>(ymd.month()));
        auto day = static_cast<uint8_t>(static_cast<unsigned int>(ymd.day()));

        return std::make_tuple(year, month, day);
    }

    std::tuple<uint8_t, uint8_t> DateTime::GetCurrentHourMinute()
    {
        auto now = date::make_zoned(date::current_zone(), std::chrono::system_clock::now());

        auto local_time = now.get_local_time();
        auto current_local_time = date::floor<std::chrono::minutes>(local_time);
        auto days_passed = date::floor<date::days>(local_time);
        auto time = date::make_time(current_local_time - days_passed);

        uint8_t hours = static_cast<uint8_t>(time.hours().count());
        uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

        return {hours, minutes};
    }

    inline uint8_t DateTime::GetCurrentSecond()
    {
        return  GetSecondsFromEpoch() % 60;
    }

    uint8_t DateTime::GetCurrentDayNumber()
    {
        auto current_ymd = GetCurrentDate_YMDFormat();
        return (std::chrono::weekday(current_ymd)).iso_encoding();
    }

    std::tuple<unsigned int, uint8_t, uint8_t> DateTime::ConvertEpochYearMonthDay(long long epoch_time = 0)
    {
        if(epoch_time == 0)
        {
            epoch_time = m_time_point;
        }

        std::chrono::time_point<std::chrono::system_clock> tp{std::chrono::microseconds(epoch_time)};
        auto zoned_date = date::make_zoned(date::current_zone(), tp);

        auto local_time = zoned_date.get_local_time();
        auto ymd = static_cast<date::year_month_day>(std::chrono::floor<std::chrono::days>(local_time));

        auto year = static_cast<unsigned int>(static_cast<int>(ymd.year()));
        auto month = static_cast<uint8_t>(static_cast<unsigned int>(ymd.month()));
        auto day = static_cast<uint8_t>(static_cast<unsigned int>(ymd.day()));

        return std::make_tuple(year, month, day);
    }

    std::tuple<uint8_t, uint8_t> DateTime::ConvertEpochHourMinute(long long epoch_time = 0)
    {
        if(epoch_time == 0)
        {
            epoch_time = m_time_point;
        }
        std::chrono::time_point<std::chrono::system_clock> tp{std::chrono::microseconds(epoch_time)};
        auto zoned_date = date::make_zoned(date::current_zone(), tp);

        auto local_time = zoned_date.get_local_time();
        auto current_local_time = date::floor<std::chrono::minutes>(local_time);
        auto days_passed = date::floor<date::days>(local_time);
        auto time = date::make_time(current_local_time - days_passed);

        uint8_t hours = static_cast<uint8_t>(time.hours().count());
        uint8_t minutes = static_cast<uint8_t>(time.minutes().count());

        return std::make_tuple(hours, minutes);
    }

    unsigned int DateTime::GetOffsetDayDate(unsigned int days_prev_count)
    //ymd should be owned property, so there is no need to pass ymd, ymd should be known from the moment of DateTime object
    //initialization
    {
        auto time = std::chrono::system_clock::from_time_t(m_time_point);
        auto ymd = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
        date::sys_days target_day = ymd;
        std::chrono::year_month_day day_date = target_day + date::days{days_prev_count};
        return static_cast<unsigned int>(static_cast<date::year_month_day>(day_date).day());
    }

    uint8_t DateTime::GetMonthFromOffset(int days_offset)
    {
        if(days_offset == 0)
        {
            return std::get<1>(GetCurrentYearMonthDay());
        }

        auto curr_date = GetCurrentDate_YMDFormat();
        auto target_date = date::sys_days(curr_date) + date::days(days_offset);
        return static_cast<uint8_t>(static_cast<unsigned int>(static_cast<date::year_month_day>(target_date).month()));
    }

    unsigned int DateTime::GetYearFromOffset(int days_offset)
    {
        if(days_offset == 0)
        {
            return std::get<0>(GetCurrentYearMonthDay());
        }

        auto curr_date = GetCurrentDate_YMDFormat();
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
        return std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(time)};
    }
}