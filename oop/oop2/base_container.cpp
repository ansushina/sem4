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

base_container::is_empty()
{
    return len == 0;
}

base_container::size()
{
    return len;
}
