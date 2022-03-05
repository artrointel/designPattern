package artrointel.designpattern.creational.factory_method;

public class Client {
    public Client() {
        // Creation by the overriden method PizzaStore#createPizza()
        PizzaStore mStore = new NewyorkPizzaStore();
        Pizza myPizza = mStore.createPizza();

        mStore = new ChicagoPizzaStore();
        myPizza = mStore.createPizza();


    }
}
