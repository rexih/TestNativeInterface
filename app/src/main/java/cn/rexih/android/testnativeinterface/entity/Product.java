package cn.rexih.android.testnativeinterface.entity;

import java.util.ArrayList;


/**
 * @author huangwr
 * @version %I%, %G%
 * @package cn.rexih.android.testnativereference.entity
 * @file Product
 * @date 2018/12/7
 */
public class Product {

    private long id;
    protected String name = "Raistlin";
    public int quantity;
    private String desc;
    ArrayList<Service> services;

    public String getDesc() {
        return desc;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public Product(int quantity) {
        this.quantity = quantity;
    }


    public Product(String desc) {
        this.desc = desc;
    }

    private long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public ArrayList<Service> getServices() {
        return services;
    }

    public void setServices(ArrayList<Service> services) {
        this.services = services;
    }

    public long getTheId(){
        return id;
    }
    public static String getTheName(){
        return Product.class.getSimpleName();
    }
}
