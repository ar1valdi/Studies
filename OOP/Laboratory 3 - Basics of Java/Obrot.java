<<<<<<< HEAD
package pcg;

public class Obrot implements Transformacja {
    private final double a;
    Obrot(double a){
        this.a = Math.toRadians(a);
    };

    @Override
    public Punkt transformuj(Punkt p){
        double newX = p.getX() * Math.cos(a) - p.getY() * Math.sin(a);
        double newY = p.getX() * Math.sin(a) + p.getY() * Math.cos(a);
        return new Punkt(newX, newY);
    }

    @Override
    public Transformacja getTransformacjaOdwrotna(){
        return new Obrot(Math.toDegrees(-a));
    }

    @Override
    public String toString(){
        return "Obrot o " + Math.toDegrees(a) +" stopni";
    }
}
=======
package pcg;

public class Obrot implements Transformacja {
    private final double a;
    Obrot(double a){
        this.a = Math.toRadians(a);
    };

    @Override
    public Punkt transformuj(Punkt p){
        double newX = p.getX() * Math.cos(a) - p.getY() * Math.sin(a);
        double newY = p.getX() * Math.sin(a) + p.getY() * Math.cos(a);
        return new Punkt(newX, newY);
    }

    @Override
    public Transformacja getTransformacjaOdwrotna(){
        return new Obrot(Math.toDegrees(-a));
    }

    @Override
    public String toString(){
        return "Obrot o " + Math.toDegrees(a) +" stopni";
    }
}
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
