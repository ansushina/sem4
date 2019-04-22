#include "base_container.h"

using namespace container;

base_container::base_container():
    count_elements(0)
{

}

base_container::~base_container()
{
    count_elements = 0;
}

base_container::is_empty()
{
    return count_elements == 0;
}

base_container::size()
{
    return count_elements;
}
