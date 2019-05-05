#include "base_container.h"

using namespace container;

base_container::base_container():
    len(0)
{

}

base_container::~base_container()
{
    len = 0;
}

bool base_container::is_empty() const
{
    return len == 0;
}

size_t base_container::size() const
{
    return len;
}
