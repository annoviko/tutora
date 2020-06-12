#pragma once


template <typename Instance>
class Singletone {
public:
    Singletone() = delete;

public:
    static Instance & Get() {
        static Instance m_instance;
        return m_instance;
    }
};
