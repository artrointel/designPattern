package artrointel.designpattern.creational.builder;

import artrointel.designpattern.creational.factory_method.Pizza;

public class PizzaChef {
    private PizzaBuilder mPizzaBuilder;
    public void setBuilder(PizzaBuilder builder) {
        mPizzaBuilder = builder;
    }

    public Pizza getPizza() {
        return mPizzaBuilder.build();
    }

    public void constructPizza() {
        mPizzaBuilder.buildFlour();
        mPizzaBuilder.buildDecorations();
        mPizzaBuilder.buildSource();
        mPizzaBuilder.buildBox();
    }
}
