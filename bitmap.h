#pragma once

#include <string>
#include <iostream>

class Bitmap
{
public:
    bool Load(const std::string& name);
    bool Store(const std::string& name);

    void process(std::string& msg,
        pixel_ftor   ftor);
private:
    std::string   m_file_name;

    file_t        m_file_header;
    info_t        m_info;
};