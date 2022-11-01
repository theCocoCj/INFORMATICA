public class Velocita {
    private float veloKmH;

    public Velocita(){
        veloKmH = 0;
    }

    public  void setKmH(float veloKmH){
        if(veloKmH > 0) {
            this.veloKmH = veloKmH;
        }
    }

    public  void setMS(float veloMS ){
        if(veloMS >= 0) {
            this.veloKmH = (veloMS * 3.6f);
        }
    }

    public float getVeloKmH(){
        return  veloKmH;
    }

    public float getVeloMS(){
        return  veloKmH / 3.6f;
    }

    public String toString() { //stampa velocità in km/h e m/s
        return"[Km/h=" + getVeloKmH() + ", m/s=" + getVeloMS() +']';
    }

}
