package artrointel.designpattern.creational.factory_method;

public class ChicagoPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza() {
        return new ChicagoPizza();
    }
}
