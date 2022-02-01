

using namespace std;
#include "bitmap.h"

bool Bitmap::Load(const std::string& name)
{
    m_file_name = name;

    std::ifstream input(m_file_name, std::ios::binary);
    if (input.bad())
    {
        return false;
    }

    input >> m_file_header;

    const size_t k_info_len = 0x36ul;
    if (k_info_len != m_file_header.offset)
    {
        return false;
    }

    input >> m_info;

    return true;
}

bool Bitmap::Store(const std::string& name)
{
    std::ofstream output(name, std::ios::binary);
    if (output.bad())
    {
        return false;
    }

    output << m_file_header;
    output << m_info;

    return true;
}

void Bitmap::process(std::string& msg,
    pixel_ftor   ftor)
{
    auto t = Hg::make_view<Hg::rgba_t>(m_info.pixels.get());
    auto iter = t.begin();

    // Calculate the number of bytes that can be encoded or extracted
    // from the image and ensure the the message buffer is large enough.
    size_t length = t.end() - iter;
    msg.resize(length);

    for (size_t index = 0; iter != t.end(); ++iter, ++index)
    {
        ftor(*iter, (Hg::byte_t&)(msg[index]));
    }
}

void weave_data(Hg::rgba_t& pixel,
    Hg::byte_t& data)
{
    using Hg::s_data;

    s_data value(data);

    pixel.blue = (pixel.blue & ~k_data_mask)
        | (value.d0 & k_data_mask);
    pixel.green = (pixel.green & ~k_data_mask)
        | (value.d1 & k_data_mask);
    pixel.red = (pixel.red & ~k_data_mask)
        | (value.d2 & k_data_mask);
    pixel.alpha = (pixel.alpha & ~k_data_mask)
        | (value.d3 & k_data_mask);
}