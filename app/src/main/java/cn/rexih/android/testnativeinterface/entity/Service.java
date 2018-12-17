package cn.rexih.android.testnativeinterface.entity;

/**
 * @author huangwr
 * @version %I%, %G%
 * @package cn.rexih.android.testnativereference.entity
 * @file Service
 * @date 2018/12/7
 */
public class Service {
    public long sid;
    public String sName;

    public static Service buildA(){
        Service service = new Service();
        service.sName="AAA";
        return service;
    }
    public static Service buildB(){
        Service service = new Service();
        service.sName="BBB";
        return service;
    }

    @Override
    public String toString() {
        return sName;
    }
}
