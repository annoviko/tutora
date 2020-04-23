#pragma once

#include <QString>
#include <QSqlDatabase>


class DatabaseConnection {
private:
    const static QString DEFAULT_HOST;
    const static int     DEFAULT_PORT;
    const static QString DEFAULT_DBNAME;
    const static QString DEFAULT_USERNAME;
    const static QString DEFAULT_PASSWORD;

private:
    QSqlDatabase m_connection;

public:
    DatabaseConnection();
    DatabaseConnection(const DatabaseConnection & p_other) = delete;
    DatabaseConnection(DatabaseConnection && p_other) = default;
    ~DatabaseConnection();

public:
    bool IsOpen() const;
    QSqlDatabase & Get();
};
