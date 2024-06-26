#include "orderListElement.h"

orderListElement::orderListElement(product orderProduct, unsigned int quantity)
{
    this->orderProduct = orderProduct;
    this->quantity = quantity;
}

void orderListElement::setProduct(product orderProduct)
{
    this->orderProduct = orderProduct;
}
product orderListElement::getProduct() const { return orderProduct; }

void orderListElement::setQuantity(unsigned int quantity)
{
    this->quantity = quantity;
}
unsigned int orderListElement::getQuantitiy() const { return quantity; }

unsigned int orderListElement::getTotalPriceGr() const
{
    return quantity * orderProduct.getPriceInGr();
}

bool orderListElement::operator==(const orderListElement &anotherElement)
{
    return quantity == anotherElement.getQuantitiy() && orderProduct == anotherElement.getProduct();
}

bool orderListElement::operator>(const orderListElement &anotherElement)
{
    return orderProduct.getIdNumber() > anotherElement.getProduct().getIdNumber();
}