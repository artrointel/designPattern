package artrointel.designpattern.creational.builder;

import artrointel.designpattern.creational.factory_method.Pizza;

public class Client {
    public Client() {
        PizzaChef mChef = new PizzaChef();
        mChef.setBuilder(new ChicagoPizzaBuilder());
        mChef.constructPizza();
        Pizza myPizza = mChef.getPizza();
    }

}
