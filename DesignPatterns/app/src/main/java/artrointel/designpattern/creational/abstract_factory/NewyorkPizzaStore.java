package artrointel.designpattern.creational.abstract_factory;

import artrointel.designpattern.creational.factory_method.Pizza;
import artrointel.designpattern.creational.factory_method.PizzaStore;

public class NewyorkPizzaStore extends PizzaStore {
    // composition
    NewyorkPizzaFactory mFactory = new NewyorkPizzaFactory();

    @Override
    public Pizza createPizza() {
        // delegation
        return mFactory.createPizza();
    }
}
