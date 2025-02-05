#pragma once
#include <SQLiteCpp/SQLiteCpp.h>
#include "IGenericRepository.hpp"
#include "TypeTraits.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sys/stat.h>
#include <filesystem>

namespace data_access_layer::dal::sqlite
{
    template<typename T>
    concept IsBase = std::is_base_of<dp_business_logic::DayPlanner::BaseEntity, T>::value;

    template<IsBase T>
    class GenericRepository : public virtual dp_business_logic::DayPlanner::IGenericRepository<T>
    {
    public:
        GenericRepository(std::string path);
        std::vector<std::shared_ptr<const T>> GetAll() const override;
        bool Add(std::shared_ptr<const T>) override;
        bool Delete(unsigned int) override;
        bool Update(std::shared_ptr<const T>) override;
        std::shared_ptr<const T> GetById(unsigned int) const override;

    private:
        std::unique_ptr<SQLite::Database> database;   ///< Database connection
    };

    //Definitions ------>
    template<IsBase T>
    GenericRepository<T>::GenericRepository(std::string path)
    {
        try
        {
            std::string table_name = static_cast<std::string>(TypeTraits<T>::table_name);
            std::string database_path = path + "/" + table_name + ".db";
            std::cout << database_path;

            try
            {
                std::filesystem::permissions(path,
                std::filesystem::perms::owner_all | std::filesystem::perms::group_read | std::filesystem::perms::others_read);

                std::cout << "Permissions updated successfully for folder: " << path << std::endl;
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error changing permissions: " << e.what() << std::endl;
            }

            database = std::make_unique<SQLite::Database>(database_path, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
            database -> exec("CREATE TABLE IF NOT EXISTS " + table_name + " (id INTEGER PRIMARY KEY, name TEXT, start INTEGER, end INTEGER)");

        }
        catch (std::exception& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    template<IsBase T>
    std::vector<std::shared_ptr<const T>> GenericRepository<T>::GetAll() const
    {
        std::vector<std::shared_ptr<const T>> events{};
        std::string query_string = "SELECT * FROM " + static_cast<std::string>(TypeTraits<T>::table_name);
        SQLite::Statement query(*database, query_string);

        while (query.executeStep())
        {
            auto id = query.getColumn(0);
            auto name = query.getColumn(1);
            auto start = query.getColumn(2);
            auto end = query.getColumn(3);
            events.emplace_back(std::make_shared<T>(id, name, start, end));
        }

        return events;
    }

    template<IsBase T>
    bool GenericRepository<T>::Add(std::shared_ptr<const T> event)
    {
        std::string query_string =
        "INSERT INTO " + static_cast<std::string>(TypeTraits<T>::table_name) + " (id, name, start, end) VALUES (?, ?, ?, ?)";

        SQLite::Statement db_query(*database, query_string);

        db_query.bind(1, event -> GetId());
        db_query.bind(2, event -> GetName());
        db_query.bind(3, event -> GetStartEpoch());
        db_query.bind(4, event -> GetEndEpoch());

        db_query.exec();
        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Delete(unsigned int id)
    {
        std::string query_string = "DELETE FROM " + static_cast<std::string>(TypeTraits<T>::table_name) + " WHERE id = " + std::to_string(id);
        return false;
    }

    template<IsBase T>
    bool GenericRepository<T>::Update(std::shared_ptr<const T> event)
    {
        std::string query_string = "UPDATE " + static_cast<std::string>(TypeTraits<T>::table_name) + " SET name = ?, start = ?, end = ? WHERE id = ?";

        SQLite::Statement update(*database, query_string);

        update.bind(1, event -> GetName());
        update.bind(2, event -> GetStartEpoch());
        update.bind(3, event -> GetEndEpoch());
        update.bind(4, event -> GetId());
        update.exec();

        return false;
    }

    template<IsBase T>
    std::shared_ptr<const T> GenericRepository<T>::GetById(unsigned int id) const
    {
        std::string query_string = "SELECT * FROM " + static_cast<std::string>(TypeTraits<T>::table_name) + " WHERE id = " + std::to_string(id);
        SQLite::Statement query(*database, query_string);

        query.exec();
        auto name = query.getColumn(1).getText();
        auto start = query.getColumn(2).getInt();
        auto end = query.getColumn(3).getInt();

        return std::make_shared<const T>(id, name, start, end);
    }

}