#include <gtest/gtest.h>
#include "order.h"
#include "date.h"
#include "statusCodes.h"
#include "product.h"
#include "orderListElement.h"

// testing date class
TEST(date, date_init_and_getters_1)
{
    date a = date(1, 2, 3);
    ASSERT_EQ(a.getDay(), 1);
    ASSERT_EQ(a.getMonth(), 2);
    ASSERT_EQ(a.getYear(), 3);
}
TEST(date, date_init_and_getters_2)
{
    date a = date(31, 12, 2222);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}

TEST(date, date_init_and_getters_errors)
{
    ASSERT_THROW(date(33, 12, 2222), std::invalid_argument);
    ASSERT_THROW(date(31, 13, 2222), std::invalid_argument);
    ASSERT_THROW(date(33, 13, 2222), std::invalid_argument);
}

TEST(date, date_setDay)
{
    date a = date(31, 12, 2222);
    a.setDay(20);
    ASSERT_EQ(a.getDay(), 20);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setDay_error)
{
    date a = date(31, 12, 2222);
    ASSERT_THROW(a.setDay(32), std::invalid_argument);
}

TEST(date, date_setMonth)
{
    date a = date(31, 12, 2222);
    a.setMonth(1);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 1);
    ASSERT_EQ(a.getYear(), 2222);
}
TEST(date, date_setMonth_error)
{
    date a = date(31, 12, 2222);
    ASSERT_THROW(a.setMonth(13), std::invalid_argument);
}

TEST(date, date_setYear)
{
    date a = date(31, 12, 2222);
    a.setYear(1111);
    ASSERT_EQ(a.getDay(), 31);
    ASSERT_EQ(a.getMonth(), 12);
    ASSERT_EQ(a.getYear(), 1111);
}

TEST(date, date_setDate)
{
    date a = date(31, 12, 2222);
    a.setDate(1, 2, 3);
    ASSERT_EQ(a.getDay(), 1);
    ASSERT_EQ(a.getMonth(), 2);
    ASSERT_EQ(a.getYear(), 3);
}

TEST(date, date_getDateStr)
{
    date a = date(31, 12, 2222);
    ASSERT_EQ(a.getDateStr(), "31.12.2222");
}

// testing order class
// TEST(order, order_init_and_getters_1)
// {
//     date d = date(31, 12, 2012);
//     std::vector<std::pair<std::string, int>> pl = {{"banan", 1}, {"gruszka", 2}, {"kiwi", 3}};

//     order a = order("name", "surname", d, pl, SENT, "Warszawa, plac politechniki 1");
//     ASSERT_EQ(a.getName(), "name");
//     ASSERT_EQ(a.getSurname(), "surname");

//     date storedDate = a.getDate();
//     ASSERT_EQ(storedDate.getDay(), 31);
//     ASSERT_EQ(storedDate.getMonth(), 12);
//     ASSERT_EQ(storedDate.getYear(), 2012);

//     std::vector<std::pair<std::string, int>> storedList = a.getProductList();
//     ASSERT_EQ(storedList[0], std::make_pair("banan", 1));
//     ASSERT_EQ(storedList[1], std::make_pair("gruszka", 2));
//     ASSERT_EQ(storedList[2], std::make_pair("kiwi", 3));

//     ASSERT_EQ(a.getStatusCode(), SENT);
//     ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
// }
// TEST(order, order_init_and_getters_2)
// {
//     date d = date(31, 12, 2012);
//     std::vector<std::pair<std::string, int>> pl = {{"banan", 1}, {"gruszka", 2}, {"kiwi", 3}};

//     order a = order("name", "surname", d, pl, "Warszawa, plac politechniki 1");
//     ASSERT_EQ(a.getName(), "name");
//     ASSERT_EQ(a.getSurname(), "surname");

//     date storedDate = a.getDate();
//     ASSERT_EQ(storedDate.getDay(), 31);
//     ASSERT_EQ(storedDate.getMonth(), 12);
//     ASSERT_EQ(storedDate.getYear(), 2012);

//     std::vector<std::pair<std::string, int>> storedList = a.getProductList();
//     std::string aa = "banan";
//     ASSERT_EQ(storedList[0], std::make_pair("banan", 1));
//     ASSERT_EQ(storedList[1], std::make_pair("gruszka", 2));
//     ASSERT_EQ(storedList[2], std::make_pair("kiwi", 3));

//     ASSERT_EQ(a.getStatusCode(), ORDER_PLACED);
//     ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
// }
// TEST(order, order_init_and_getters_3)
// {
//     date d = date(31, 12, 2012);

//     order a = order("name", "surname", d, "Warszawa, plac politechniki 1");
//     ASSERT_EQ(a.getName(), "name");
//     ASSERT_EQ(a.getSurname(), "surname");

//     date storedDate = a.getDate();
//     ASSERT_EQ(storedDate.getDay(), 31);
//     ASSERT_EQ(storedDate.getMonth(), 12);
//     ASSERT_EQ(storedDate.getYear(), 2012);

//     ASSERT_EQ(a.getStatusCode(), ORDER_PLACED);
//     ASSERT_EQ(a.getShipmentAddress(), "Warszawa, plac politechniki 1");
// }

// TEST(order, order_init_and_getters_4)
// {
//     // testing if error does not occur
//     order a = order();
// }

// TEST(order, order_setters_1)
// {
//     date d = date(31, 12, 2012);
//     std::vector<std::pair<std::string, int>> pl = {{"banan", 1}, {"gruszka", 2}, {"kiwi", 3}};
//     order a = order("name", "surname", d, pl, SENT, "Warszawa, plac politechniki 1");

//     a.setName("Marek");
//     ASSERT_EQ(a.getName(), "Marek");

//     a.setSurname("Kaganek");
//     ASSERT_EQ(a.getSurname(), "Kaganek");

//     date d1 = date(1, 2, 3);
//     a.setDate(d1);
//     date storedDate = a.getDate();
//     ASSERT_EQ(storedDate.getDay(), 1);
//     ASSERT_EQ(storedDate.getMonth(), 2);
//     ASSERT_EQ(storedDate.getYear(), 3);

//     a.setStatusCode(CANCELED);
//     ASSERT_EQ(a.getStatusCode(), CANCELED);

//     a.setShipmentAddress("inny address");
//     ASSERT_EQ(a.getShipmentAddress(), "inny address");
// }

// testing product
TEST(product, product_init_and_getters_1)
{
    product p = product("banan", 1, 5);
    ASSERT_EQ(p.getName(), "banan");
    ASSERT_EQ(p.getIdNumber(), 1);
    ASSERT_EQ(p.getPriceInGr(), 5);
}

TEST(product, product_setName)
{
    product p = product("jablko", 2, 5);

    p.setName("kiwi");
    ASSERT_EQ(p.getName(), "kiwi");
    ASSERT_EQ(p.getIdNumber(), 2);
    ASSERT_EQ(p.getPriceInGr(), 5);
}

TEST(product, product_setIdNumber)
{
    product p = product("jablko", 5, 15);

    p.setIdNumber(10);
    ASSERT_EQ(p.getName(), "jablko");
    ASSERT_EQ(p.getIdNumber(), 10);
    ASSERT_EQ(p.getPriceInGr(), 15);
}

TEST(product, product_setPriceInGr)
{
    product p = product("jablko", 5, 15);

    p.setPriceInGr(100);
    ASSERT_EQ(p.getName(), "jablko");
    ASSERT_EQ(p.getIdNumber(), 5);
    ASSERT_EQ(p.getPriceInGr(), 100);
}

TEST(product, product_equals_operator_equal)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("jablko", 5, 15);
    ASSERT_EQ(p1 == p2, true);
    // ASSERT_EQ(p1, p2); <- tak nie działa :(
}

TEST(product, product_equals_operator_not_equal)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("gruszka", 10, 15);
    ASSERT_EQ(p1 == p2, false);
    // ASSERT_EQ(p1, p2); <- tak nie działa :(
}

// testing orderListElement
TEST(orderListElement, orderListElement_init_and_getters)
{
    product p = product("jablko", 5, 15);
    orderListElement element = orderListElement(p, 10);

    ASSERT_EQ(element.getProduct() == p, true);
    ASSERT_EQ(element.getQuantitiy(), 10);
    ASSERT_EQ(element.getTotalPriceGr(), 10 * 15);
}

TEST(orderListElement, orderListElement_equals_operator)
{
    product p = product("jablko", 5, 15);
    orderListElement element1 = orderListElement(p, 10);
    orderListElement element2 = orderListElement(p, 10);

    ASSERT_EQ(element1 == element2, true);
}

TEST(orderListElement, orderListElement_set_product)
{
    product p1 = product("jablko", 5, 15);
    product p2 = product("banan", 111, 399);

    orderListElement element = orderListElement(p1, 10);

    element.setProduct(p2);
    ASSERT_EQ(element.getProduct() == p2, true);
}

TEST(orderListElement, orderListElement_setQuantity)
{
    product p1 = product("jablko", 5, 15);
    orderListElement element = orderListElement(p1, 10);

    element.setQuantity(555);
    ASSERT_EQ(element.getQuantitiy(), 555);
}
