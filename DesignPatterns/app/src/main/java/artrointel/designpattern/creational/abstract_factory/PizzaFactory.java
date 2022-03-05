package artrointel.designpattern.creational.abstract_factory;

import artrointel.designpattern.creational.factory_method.Pizza;

// PizzaStore creates Pizza using factory as composition & delegation.
public abstract class PizzaFactory {
    abstract Pizza createPizza();
    // OCP
    // whenever creation method is added, all of the other inherit factory should be updated.
    // in opposite, creating many style of pizza factory can be easily done.
}
