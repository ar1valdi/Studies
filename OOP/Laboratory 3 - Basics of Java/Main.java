package pcg;
public class Main {
    public static void main(String[] args) {
        System.out.println("\n\n----ZADANIE 1----");
        Punkt p = new Punkt(10, 10);
        Punkt b = new Punkt(10, 10);
        System.out.println("Współrzędne punktu p (toString()): " + p);
        System.out.println("GetY (b): " + b.getY());
        System.out.println("GetX (b): " + b.getX());
        System.out.println("Equales (b.equals(p)): " + (b.equals(p)));
        System.out.println("Equales (b.equals(O)): " + (b.equals(Punkt.O)));
        System.out.println("Hashcode (p): " + p.hashCode());

        try {
            System.out.println("\n\n----ZADANIE 2----");
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja tr = new Translacja(5, 6);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTransformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);

        } catch (BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        try
        {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr2 = new Skalowanie(5, 4);
            System.out.println(tr2);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTransformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();

        /*
        try
        {
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr3 = new Skalowanie(5, 0);
            System.out.println(tr3);
            System.out.println(p1);
            Punkt p2 = tr3.transformuj(p1);
            System.out.println(p2);
            Transformacja trr23 = tr3.getTransformacjaOdwrotna();
            System.out.println(trr3);
            Punkt p3 = trr3.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
        System.out.println();*/
        try
        {
            System.out.println("\n\n----ZADANIE 3----");
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr4 = new Obrot(90);
            System.out.println(tr4);
            System.out.println(p1);
            Punkt p2 = tr4.transformuj(p1);
            System.out.println(p2);
            Transformacja trr4 = tr4.getTransformacjaOdwrotna();
            System.out.println(trr4);
            Punkt p3 = trr4.transformuj(p2);
            System.out.println(p3);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }

        try
        {
            System.out.println("\n\n----ZADANIE 4----");
            Punkt p1 = new Punkt(2, 2);
            ZlozenieTransformacji zt = new ZlozenieTransformacji(4);
            Transformacja t1 = new Translacja(3, 3);
            Transformacja t2 = new Translacja(1, 1);
            Transformacja t3 = new Skalowanie(2,2);
            Transformacja t4 = new Obrot(180);
            Transformacja t5 = new Obrot(90);
            zt.dodajTransformacje(t1);
            zt.dodajTransformacje(t2);
            System.out.println(p1);
            System.out.println(zt);
            Punkt p2 = zt.transformuj(p1);
            System.out.println(p2);
            System.out.println("\n");
            zt.dodajTransformacje(t3);
            zt.dodajTransformacje(t4);
            zt.dodajTransformacje(t5);
            System.out.println(p1);
            System.out.println(zt);
            p2 = zt.transformuj(p1);
            System.out.println(p2);
            System.out.println("\n");
            Transformacja zt2 = zt.getTransformacjaOdwrotna();
            System.out.println(p1);
            System.out.println(zt2);
            p2 = zt2.transformuj(p1);
            System.out.println(p2);
        }
        catch(BrakTransformacjiOdwrotnejException ex)
        {
            ex.printStackTrace();
        }
    }
}