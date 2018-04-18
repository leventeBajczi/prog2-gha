#include "jsonobject.hpp"

int main()
{
    JSONObject obj("{}"), obj2("{}");
    obj.put("name", 12);
    obj2.put("asd", "hello");
    obj.put("obj2", obj2);
    std::cout<<obj;
}