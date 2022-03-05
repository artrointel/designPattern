package artrointel.designpattern.creational.factory_method;

public class NewyorkPizzaStore extends PizzaStore {
    @Override
    public Pizza createPizza() {
        return new NewyorkPizza();
    }
}
