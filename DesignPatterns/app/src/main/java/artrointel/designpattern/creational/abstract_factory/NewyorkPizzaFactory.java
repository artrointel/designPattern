package artrointel.designpattern.creational.abstract_factory;

import artrointel.designpattern.creational.factory_method.NewyorkPizza;
import artrointel.designpattern.creational.factory_method.Pizza;

public class NewyorkPizzaFactory extends PizzaFactory {
    @Override
    Pizza createPizza() {
        return new NewyorkPizza();
    }
}
