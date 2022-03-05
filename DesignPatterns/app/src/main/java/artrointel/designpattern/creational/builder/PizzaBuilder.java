package artrointel.designpattern.creational.builder;

import artrointel.designpattern.creational.factory_method.Pizza;

public abstract class PizzaBuilder {
    public abstract Pizza build();
    public abstract void buildFlour();
    public abstract void buildDecorations();
    public abstract void buildSource();
    public abstract void buildBox();
}
