package artrointel.designpattern.creational.abstract_factory;

public class ChicagoPizzaFactory extends PizzaFactory {
    @Override
    Pizza createPizza() {
        return new ChicagoPizza();
    }
}
