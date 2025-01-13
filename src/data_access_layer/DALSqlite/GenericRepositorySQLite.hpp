#pragma once
#include <SQLiteCpp/SQLiteCpp.h>
#include "IGenericRepository.hpp"
#include "TypeTraits.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

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
        SQLite::Database* database;   ///< Database connection
    };

    //Definitions ------>
    template<IsBase T>
    GenericRepository<T>::GenericRepository(std::string path)
    {
        try
        {
            database = new SQLite::Database(path, SQLite::OPEN_READWRITE|SQLite::OPEN_CREATE);
            database -> exec("CREATE TABLE IF NOT EXISTS " + TypeTraits<T>::table_name + " (id INTEGER PRIMARY KEY, name TEXT, start INTEGER, end INTEGER)");
            std::string query_string = "INSERT INTO " + TypeTraits<T>::table_name + " (name, start, end) VALUES ('Banana', 123, 123)";
            SQLite::Statement query(*database, query_string);
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
        std::string query_string = "SELECT * FROM " + TypeTraits<T>::table_name;
        SQLite::Statement query(*database, query_string);

        while (query.executeStep())
        {
            auto id = query.getColumn(0).getInt();
            auto name = query.getColumn(1).getText();
            auto start = query.getColumn(2).getInt();
            auto end = query.getColumn(3).getInt();
            events.emplace_back(std::make_shared<T>(id, name, start, end));
        }

        return events;
    }

    template<IsBase T>
    bool GenericRepository<T>::Add(std::shared_ptr<const T> event)
    {
        std::string query_string =
        "INSERT INTO " + TypeTraits<T>::table_name +
        " (name, start, end) VALUES ('" + event -> GetName() +
        "', " + std::to_string(event -> GetStart()) +
        ", " + std::to_string(event -> GetEnd()) + ")";

        return true;
    }

    template<IsBase T>
    bool GenericRepository<T>::Delete(unsigned int id)
    {
        std::string query_string = "DELETE FROM " + TypeTraits<T>::table_name + " WHERE id = " + std::to_string(id);
        return false;
    }

    template<IsBase T>
    bool GenericRepository<T>::Update(std::shared_ptr<const T> event)
    {
        std::string query_string = "UPDATE " + TypeTraits<T>::table_name + " SET name = ?, start = ?, end = ? WHERE id = ?";

        SQLite::Statement update(*database, query_string);

        update.bind(1, event -> GetName());
        update.bind(2, event -> GetStart());
        update.bind(3, event -> GetEnd());
        update.bind(4, event -> GetId());
        update.exec();

        return false;
    }

    template<IsBase T>
    std::shared_ptr<const T> GenericRepository<T>::GetById(unsigned int id) const
    {
        std::string query_string = "SELECT * FROM " + TypeTraits<T>::table_name + " WHERE id = " + std::to_string(id);
        SQLite::Statement query(*database, query_string);

        query.exec();
        auto name = query.getColumn(1).getText();
        auto start = query.getColumn(2).getInt();
        auto end = query.getColumn(3).getInt();

        return std::make_shared<const T>(id, name, start, end);
    }

}