package cn.rexih.android.testnativeinterface.entity;

import java.util.ArrayList;


/**
 * @author huangwr
 * @version %I%, %G%
 * @package cn.rexih.android.testnativereference.entity
 * @file DetailProduct
 * @date 2018/12/7
 */
public class DetailProduct extends Product {

    public static int totalCount = 100;

    public int soldAmount = 1231;
    public int followAmount;
    public String[] promotions;
    public ArrayList<Review> reviews;

    public DetailProduct() {
        super(110);
    }


    @Override
    public String getDesc() {
        return "no desc";
    }



    public int getFollowAmount() {
        return followAmount;
    }

    public void setFollowAmount(int followAmount) {
        this.followAmount = followAmount;
    }

    public static int getTotalCount() {
        return totalCount;
    }
}
