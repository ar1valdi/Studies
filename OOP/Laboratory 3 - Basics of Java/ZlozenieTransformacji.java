<<<<<<< HEAD
package pcg;

public class ZlozenieTransformacji implements Transformacja {
    private final int n;
    private int taken;
    private Transformacja[] trans;
    ZlozenieTransformacji(int n){
        this.n = n;
        taken=0;
        trans = new Transformacja[n];
    }

    public boolean dodajTransformacje(Transformacja t){
        if(taken == n)
            return false;
        trans[taken++] = t;
        return true;
    }

    @Override
    public Punkt transformuj(Punkt p){
        for(int i = 0; i < taken; i++){
            p=trans[i].transformuj(p);
        }
        return p;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException{
        ZlozenieTransformacji z = new ZlozenieTransformacji(n);
        z.taken = taken;
        for (int i = 0; i < taken; i++) {
            z.trans[i] = trans[i].getTransformacjaOdwrotna();
        }
        return z;
    }

    @Override
    public String toString(){
        String s = taken + "/" + n + " operacji:\n";
        for (int i = 0; i < taken; i++){
            s += (i+1) + ". " + trans[i] + "\n";
        }
        return s;
    }
}
=======
package pcg;

public class ZlozenieTransformacji implements Transformacja {
    private final int n;
    private int taken;
    private Transformacja[] trans;
    ZlozenieTransformacji(int n){
        this.n = n;
        taken=0;
        trans = new Transformacja[n];
    }

    public boolean dodajTransformacje(Transformacja t){
        if(taken == n)
            return false;
        trans[taken++] = t;
        return true;
    }

    @Override
    public Punkt transformuj(Punkt p){
        for(int i = 0; i < taken; i++){
            p=trans[i].transformuj(p);
        }
        return p;
    }

    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException{
        ZlozenieTransformacji z = new ZlozenieTransformacji(n);
        z.taken = taken;
        for (int i = 0; i < taken; i++) {
            z.trans[i] = trans[i].getTransformacjaOdwrotna();
        }
        return z;
    }

    @Override
    public String toString(){
        String s = taken + "/" + n + " operacji:\n";
        for (int i = 0; i < taken; i++){
            s += (i+1) + ". " + trans[i] + "\n";
        }
        return s;
    }
}
>>>>>>> 422a5de2b8d0b14455e0406f557c5ede1322bc7f
