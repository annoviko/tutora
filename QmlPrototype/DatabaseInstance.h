#pragma once

#include "DatabaseConnection.h"
#include "Singletone.h"


class DatabaseInstance : public Singletone<DatabaseConnection> { };
