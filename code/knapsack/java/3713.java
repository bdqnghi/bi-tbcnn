/*****************************************************************************
 * Copyright 2007-2015 DCA-FEEC-UNICAMP
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Contributors:
 *    Patricia Rocha de Toro, Elisa Calhau de Castro, Ricardo Ribeiro Gudwin
 *****************************************************************************/
package model;

/**
 *
 * @author eccastro
 */
import java.util.List;
import java.util.HashMap;
import com.jme.renderer.ColorRGBA;
import java.util.Iterator;
import java.util.Observable;
import util.Constants;

public class Knapsack extends Observable {

    //Crystals:
//    public List<Jewel> jewelPool; //not in use
//    public HashMap<String, Jewel> jewelMap;//not in use
    public HashMap<String, Food> foodMap;
    public HashMap<String, Integer> numberOfJewels;
    public HashMap<String, Integer> numberOfFood;

    public int score;
    Integer g;
    Integer r;
    Integer bl;
    Integer y;
    Integer p;
    Integer m;
    Integer br;
    Integer lg;
    Integer dg;
    Integer or;
    Integer pFood;
    Integer npFood;

    public Knapsack() {

        numberOfJewels = new HashMap();
        foodMap = new HashMap();
//        jewelMap = new HashMap();
        numberOfFood = new HashMap();
        init();
        score = 0;
    }

    public int getScore() {
        return score;
    }

    public void incScore(int pts) {
        score = score + pts;
    }

    public void decScore(int pts) {
        score = score - pts;
    }

    public void resetScore() {
        score = 0;
    }

    public StringBuffer getSackContent() {
        /**
         * Total number of Food   
         * Total number of Crystals 
         * Number of PerishableFood 
         * Number of Non-PerishableFood 
         * Number of crystals of each color in the sequence: 
         * RED, GREEN, BLUE, YELLOW, MAGENTA, WHITE.
         */

        Integer f = new Integer(getNumberOfFood(Constants.PFOOD).intValue() + getNumberOfFood(Constants.NPFOOD).intValue());
        int num = 0;
        Iterator it = numberOfJewels.values().iterator();

        for(String key:  numberOfJewels.keySet()){
            num = num + this.getNumberOfJewels(key).intValue();
//            System.out.println("Key: "+key + " value: "+this.getNumberOfJewels(key).intValue());
        }
        String numJewels = String.valueOf(num);
        StringBuffer ret = new StringBuffer("");
        ret.append(" ");
        ret.append(f.toString());
        ret.append(" ");
        ret.append(numJewels);
        ret.append(" ");
        ret.append(getNumberOfFood(Constants.PFOOD).toString());
        ret.append(" ");
        ret.append(getNumberOfFood(Constants.NPFOOD).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorRED).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorGREEN).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorBLUE).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorYELLOW).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorMAGENTA).toString());
        ret.append(" ");
        ret.append(getNumberOfJewels(Constants.colorWHITE).toString());

        return ret;
    }

    public void removeJewelFromKnapsack(String color) {

        decJewelInKnapsack(color);
    }

//    /**
//     * Currently not in use.
//     *
//     * @param o
//     */
//    public void putInKnapsack(Jewel o) {
//        jewelPool.add(o);
//        incKnapsack(o);
//    }
//
//    /**
//     * Currently not in use.
//     *
//     * @param o
//     */
//    public void removeJewelFromKnapsack(Jewel o) {
//        jewelPool.remove(o);
//        decKnapsack(o);
//    }

    public void init() {
        int g_ = 0;
        int r_ = 0;
        int br_ = 0;
        int y_ = 0;
        int p_ = 0;
        int m_ = 0;
        int bl_ = 0;
        int lg_ = 0;
        int dg_ = 0;
        int or_ = 0;

        int pFood_ = 0;
        int npFood_ = 0;

        this.g = new Integer(g_);
        this.r = new Integer(r_);
        this.bl = new Integer(bl_);
        this.y = new Integer(y_);
        this.p = new Integer(p_);
        this.m = new Integer(m_);
        this.br = new Integer(br_);
        this.lg = new Integer(lg_);
        this.dg = new Integer(dg_);
        this.or = new Integer(or_);

        this.pFood = new Integer(pFood_);
        this.npFood = new Integer(npFood_);

        numberOfJewels.put(Constants.colorGREEN, this.g);
        numberOfJewels.put(Constants.colorRED, this.r);
        numberOfJewels.put(Constants.colorBLUE, this.bl);
        numberOfJewels.put(Constants.colorYELLOW, this.y);
        //numberOfObstacles.put("Pink", this.p);
        numberOfJewels.put(Constants.colorMAGENTA, this.m);
        //numberOfObstacles.put("Brown", this.br);
        numberOfJewels.put(Constants.colorWHITE, this.lg);
//        numberOfJewels.put(Constants.colorDARKGRAY, this.dg);
//        numberOfJewels.put(Constants.colorORANGE, this.or);

        numberOfFood.put(Constants.PFOOD, this.pFood);
        numberOfFood.put(Constants.NPFOOD, this.npFood);
    }
    
  public void incJewelInKnapsack(Jewel jewel) {

//        jewelMap.put(jewel.getMyName(), jewel);
        incJewelInKnapsack(jewel.getMaterial().getColorName());
    }

    public void incJewelInKnapsack(String color) {

        //System.out.println("======= Color is " + color);
        numberOfJewels.put(color, new Integer(this.getNumberOfJewels(color).intValue() + 1));
        notifyMyObservers();
    }

    public void decJewelInKnapsack(String color) {
        if (numberOfJewels.get(color).intValue() > 0) {
            numberOfJewels.put(color, new Integer(this.getNumberOfJewels(color).intValue() - 1));
            //System.out.println("======= Color " + color + " delivered.");
            notifyMyObservers();
        }
    }

//    public void decJewelInKnapsack(String name) {
//
//        String jewelColor = jewelMap.get(name).getMaterial().getColorName();
//        jewelMap.remove(name);
//        decJewelInKnapsack(jewelColor);
//    }
        

    /**
     * Keep track of food objects in order to maintain its characteristics such as
     * if it is rotten or not and consequently its energy (calories) and appearance
     * in the world.
     * @param food 
     */
    public void incPerishableFoodInKnapsack(Food food) {

        foodMap.put(food.getMyName(), food);
        numberOfFood.put(Constants.PFOOD, new Integer(this.getNumberOfFood(Constants.PFOOD).intValue() + 1));
        notifyMyObservers();

    }

    public void decPerishableFoodInKnapsack() {
        numberOfFood.put(Constants.PFOOD, new Integer(this.getNumberOfFood(Constants.PFOOD).intValue() - 1));
        notifyMyObservers();

    }

    /**
     *
     * @param name Name of the food to be removed.
     */
    public void decPerishableFoodInKnapsack(String name) {

        foodMap.remove(name);
        numberOfFood.put(Constants.PFOOD, new Integer(this.getNumberOfFood(Constants.PFOOD).intValue() - 1));
        notifyMyObservers();

    }

    /**
     * Currently, it does not have a validity period. But it could be much longer 
     * than the Perishable Food.
     * @param food 
     */
    public void incNonPerishableFoodInKnapsack(Food food) {
        //System.out.println("======= Put NPFood: " + food.getMyName() + " in knapsack.");
        foodMap.put(food.getMyName(), food);
        numberOfFood.put(Constants.NPFOOD, new Integer(this.getNumberOfFood(Constants.NPFOOD).intValue() + 1));
        notifyMyObservers();

    }

    public void decNonPerishableFoodInKnapsack() {
        numberOfFood.put(Constants.NPFOOD, new Integer(this.getNumberOfFood(Constants.NPFOOD).intValue() - 1));
        notifyMyObservers();

    }

    public void decNonPerishableFoodInKnapsack(String name) {
        //System.out.println("======= Remove NPFood: " + name + " from knapsack.");
        foodMap.remove(name);
        numberOfFood.put(Constants.NPFOOD, new Integer(this.getNumberOfFood(Constants.NPFOOD).intValue() - 1));
        notifyMyObservers();

    }

    private void incKnapsack(Jewel o) {

        if (o.getMaterial().getColor() == ColorRGBA.green) {
            numberOfJewels.put(Constants.colorGREEN, new Integer(numberOfJewels.get(Constants.colorGREEN).intValue() + 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.red) {
            numberOfJewels.put(Constants.colorRED, new Integer(numberOfJewels.get(Constants.colorRED).intValue() + 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.blue) {
            numberOfJewels.put(Constants.colorBLUE, new Integer(numberOfJewels.get(Constants.colorBLUE).intValue() + 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.yellow) {
            numberOfJewels.put(Constants.colorYELLOW, new Integer(numberOfJewels.get(Constants.colorYELLOW).intValue() + 1));
        } //            else if (o.getMaterial().getColor() == ColorRGBA.pink)
        //                numberOfObstacles.put("Pink", new Integer(numberOfObstacles.get("Pink").intValue() +1));
        else if (o.getMaterial().getColor() == ColorRGBA.magenta) {
            numberOfJewels.put(Constants.colorMAGENTA, new Integer(numberOfJewels.get(Constants.colorMAGENTA).intValue() + 1));
        } //            else if (o.getMaterial().getColor() == ColorRGBA.brown)
        //                numberOfObstacles.put("Brown", new Integer(numberOfObstacles.get("Brown").intValue() +1));
        else if (o.getMaterial().getColor() == ColorRGBA.white) {
            numberOfJewels.put(Constants.colorWHITE, new Integer(numberOfJewels.get(Constants.colorWHITE).intValue() + 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.darkGray) {
            numberOfJewels.put(Constants.colorDARKGRAY_SPOILED, new Integer(numberOfJewels.get(Constants.colorDARKGRAY_SPOILED).intValue() + 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.orange) {
            numberOfJewels.put(Constants.colorORANGE, new Integer(numberOfJewels.get(Constants.colorORANGE).intValue() + 1));
        }

        notifyMyObservers();
    }

    private void decKnapsack(Jewel o) {

        if (o.getMaterial().getColor() == ColorRGBA.green) {
            numberOfJewels.put(Constants.colorGREEN, new Integer(numberOfJewels.get(Constants.colorGREEN).intValue() - 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.red) {
            numberOfJewels.put(Constants.colorRED, new Integer(numberOfJewels.get(Constants.colorRED).intValue() - 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.blue) {
            numberOfJewels.put(Constants.colorBLUE, new Integer(numberOfJewels.get(Constants.colorBLUE).intValue() - 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.yellow) {
            numberOfJewels.put(Constants.colorYELLOW, new Integer(numberOfJewels.get(Constants.colorYELLOW).intValue() - 1));
        } //            else if (o.getMaterial().getColor() == ColorRGBA.pink)
        //                numberOfObstacles.put("Pink", new Integer(numberOfObstacles.get("Pink").intValue() -1));
        else if (o.getMaterial().getColor() == ColorRGBA.magenta) {
            numberOfJewels.put(Constants.colorMAGENTA, new Integer(numberOfJewels.get(Constants.colorMAGENTA).intValue() - 1));
        } //            else if (o.getMaterial().getColor() == ColorRGBA.brown)
        //                numberOfObstacles.put("Brown", new Integer(numberOfObstacles.get("Brown").intValue() -1));
        else if (o.getMaterial().getColor() == ColorRGBA.white) {
            numberOfJewels.put(Constants.colorWHITE, new Integer(numberOfJewels.get(Constants.colorWHITE).intValue() - 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.darkGray) {
            numberOfJewels.put(Constants.colorDARKGRAY_SPOILED, new Integer(numberOfJewels.get(Constants.colorDARKGRAY_SPOILED).intValue() - 1));
        } else if (o.getMaterial().getColor() == ColorRGBA.orange) {
            numberOfJewels.put(Constants.colorORANGE, new Integer(numberOfJewels.get(Constants.colorORANGE).intValue() - 1));
        }

        notifyMyObservers();
    }

    public Integer getNumberOfJewels(String color) {

        Integer aux = numberOfJewels.get(color);
        if(aux == null) aux = new Integer(0);
        return aux;
    }

    public Integer getNumberOfFood(String name) {

        Integer aux = numberOfFood.get(name);
        if(aux == null) aux = new Integer(0);
        return aux;
    }

    public void notifyMyObservers() {
        setChanged();
        notifyObservers(new Long(0));
    }

}
