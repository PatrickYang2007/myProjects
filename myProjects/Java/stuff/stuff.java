package stuff;

class Beverage

{

private int temperature;

public Beverage(int t)

{

temperature = t;

}

public int getTemperature()

{

return temperature;

}

public boolean equals(Object other)

{

if (other == null)

{

return false;

}

Beverage b = (Beverage) other;

return (b.getTemperature() == temperature);

}

}
public class stuff {
    public static void main(String[] args) {
        int x=70,y=70;
    Beverage hotChocolate = new Beverage(x);

    Beverage coffee = new Beverage(y);

    boolean hi= hotChocolate.equals(coffee);

    System.out.println(hi);
    }
    

}
