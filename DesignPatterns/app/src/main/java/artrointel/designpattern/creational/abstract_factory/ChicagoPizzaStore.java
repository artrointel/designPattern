package artrointel.designpattern.creational.abstract_factory;

import artrointel.designpattern.creational.factory_method.Pizza;
import artrointel.designpattern.creational.factory_method.PizzaStore;

public class ChicagoPizzaStore extends PizzaStore {
    PizzaFactory mFactory = new ChicagoPizzaFactory();
    @Override
    public Pizza createPizza() {
        return mFactory.createPizza();
    }
}
