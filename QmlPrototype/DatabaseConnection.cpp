#include <exception>

#include "DatabaseConnection.h"


const QString DatabaseConnection::DEFAULT_HOST = "127.0.0.1";
const int     DatabaseConnection::DEFAULT_PORT = 5433;
const QString DatabaseConnection::DEFAULT_DBNAME = "Tutora";
const QString DatabaseConnection::DEFAULT_USERNAME = "postgres";
const QString DatabaseConnection::DEFAULT_PASSWORD = "812db84b-ab6b-40bc-ab85-a5ebad45d820";


DatabaseConnection::DatabaseConnection() {
    m_connection = QSqlDatabase::addDatabase("QPSQL");

    m_connection.setHostName(DEFAULT_HOST);
    m_connection.setPort(DEFAULT_PORT);
    m_connection.setDatabaseName(DEFAULT_DBNAME);
    m_connection.setUserName(DEFAULT_USERNAME);
    m_connection.setPassword(DEFAULT_PASSWORD);

    if (!m_connection.open()) {
        throw std::runtime_error("Impossible to connect to database.");
    }
}


DatabaseConnection::~DatabaseConnection() {
    if (m_connection.isOpen()) {
        m_connection.close();
    }
}


bool DatabaseConnection::IsOpen() const {
    return m_connection.isOpen();
}


QSqlDatabase & DatabaseConnection::Get() {
    return m_connection;
}
