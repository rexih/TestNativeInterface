package cn.rexih.android.testnativeinterface;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

import cn.rexih.android.testnativeinterface.entity.DetailProduct;
import cn.rexih.android.testnativeinterface.entity.Product;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {


    private Button btn_main_test_class_method;
    private Button btn_main_test_alloc;
    private Button btn_main_test_alloc_no_default;
    private Button btn_main_test_new;
    private Button btn_main_test_new_no_def_wrong_mid;
    private Button btn_main_test_new_no_def_wrong_mid_check;
    private Button btn_main_test_new_no_def_right_param;
    private Button btn_main_test_new_no_def_wrong_string_param;
    private Button btn_main_test_method_call;
    private Button btn_main_test_field;
    private Button btn_main_test_reflection;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();

    }

    private void initView() {
        btn_main_test_class_method = (Button) findViewById(R.id.btn_main_test_class_method);
        btn_main_test_alloc = (Button) findViewById(R.id.btn_main_test_alloc);
        btn_main_test_alloc_no_default = (Button) findViewById(R.id.btn_main_test_alloc_no_default);
        btn_main_test_new = (Button) findViewById(R.id.btn_main_test_new);
        btn_main_test_new_no_def_wrong_mid = (Button) findViewById(R.id.btn_main_test_new_no_def_wrong_mid);
        btn_main_test_new_no_def_wrong_mid_check = (Button) findViewById(R.id.btn_main_test_new_no_def_wrong_mid_check);
        btn_main_test_new_no_def_right_param = (Button) findViewById(R.id.btn_main_test_new_no_def_right_param);
        btn_main_test_new_no_def_wrong_string_param = (Button) findViewById(R.id.btn_main_test_new_no_def_wrong_string_param);

        btn_main_test_class_method.setOnClickListener(this);
        btn_main_test_alloc.setOnClickListener(this);
        btn_main_test_alloc_no_default.setOnClickListener(this);
        btn_main_test_new.setOnClickListener(this);
        btn_main_test_new_no_def_wrong_mid.setOnClickListener(this);
        btn_main_test_new_no_def_wrong_mid_check.setOnClickListener(this);
        btn_main_test_new_no_def_right_param.setOnClickListener(this);
        btn_main_test_new_no_def_wrong_string_param.setOnClickListener(this);
        btn_main_test_method_call = (Button) findViewById(R.id.btn_main_test_method_call);
        btn_main_test_method_call.setOnClickListener(this);
        btn_main_test_field = (Button) findViewById(R.id.btn_main_test_field);
        btn_main_test_field.setOnClickListener(this);
        btn_main_test_reflection = (Button) findViewById(R.id.btn_main_test_reflection);
        btn_main_test_reflection.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
        case R.id.btn_main_test_class_method:
            DetailProduct entity = new DetailProduct();
            testNativeApi(entity);
            break;
        case R.id.btn_main_test_alloc:

            DetailProduct detailProduct = testAllocObjectHasDefaultCtor();
            if (null != detailProduct) {
                int quantity = detailProduct.getQuantity();
                System.out.println("testAllocObjectHasDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_alloc_no_default:
            Product product = testAllocObjectNoDefaultCtor();
            if (null != product) {
                int quantity = product.getQuantity();
                System.out.println("testAllocObjectNoDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_new:
            DetailProduct detailProduct1 = testNewObjectHasDefaultCtor();
            if (null != detailProduct1) {
                int quantity = detailProduct1.getQuantity();
                System.out.println("testNewObjectHasDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_new_no_def_wrong_mid:
            Product product1 = testNewObjectNoDefaultCtor(false, false, false);
            if (null != product1) {
                int quantity = product1.getQuantity();
                //                System.out.println(product1.getDesc());
                System.out.println("testNewObjectNoDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_new_no_def_wrong_mid_check:
            Product product2 = testNewObjectNoDefaultCtor(true, false, false);
            if (null != product2) {
                //                System.out.println(product2.getDesc());
                int quantity = product2.getQuantity();
                System.out.println("testNewObjectNoDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_new_no_def_right_param:
            Product product3 = testNewObjectNoDefaultCtor(true, true, false);
            if (null != product3) {
                int quantity = product3.getQuantity();
                //                System.out.println(product3.getDesc());
                System.out.println("testNewObjectNoDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_new_no_def_wrong_string_param:
            Product product4 = testNewObjectNoDefaultCtor(true, true, true);
            if (null != product4) {
                int quantity = product4.getQuantity();
                //                System.out.println(product4.getDesc());
                System.out.println("testNewObjectNoDefaultCtor quantity:" + quantity);
            }
            break;
        case R.id.btn_main_test_method_call:
            DetailProduct detailProduct2 = new DetailProduct();
            detailProduct2.setDesc("12.12");
            testMethods(detailProduct2);
            break;
        case R.id.btn_main_test_field:
            DetailProduct detailProduct3 = new DetailProduct();
            testFields(detailProduct3);
            System.out.println("testFields:name:" + detailProduct3.getName() + ";totalCount:" + detailProduct3.totalCount);
            break;
        case R.id.btn_main_test_reflection:
            Product beauty = new Product("beauty");
            try {
                Field idField = Product.class.getDeclaredField("id");
                Method setQuantityMethod = Product.class.getMethod("setQuantity", int.class);
                Field descField = testReflection(beauty, idField, setQuantityMethod);
                descField.setAccessible(true);
                System.out.println(descField.get(beauty));
            } catch (NoSuchFieldException e) {
                e.printStackTrace();
            } catch (NoSuchMethodException e) {
                e.printStackTrace();
            } catch (IllegalAccessException e) {
                e.printStackTrace();
            }
            System.out.println("testReflection:Quantity:" + beauty.getQuantity() + ";id:" + beauty.getTheId());
            break;
        }
    }


    static {
        System.loadLibrary("native-lib");
    }


    public native int testNativeApi(DetailProduct entity);

    public native DetailProduct testAllocObjectHasDefaultCtor();

    public native Product testAllocObjectNoDefaultCtor();

    public native DetailProduct testNewObjectHasDefaultCtor();

    public native Product testNewObjectNoDefaultCtor(boolean supressError, boolean rightParam, boolean testWrongStringCtor);

    public native void testMethods(DetailProduct entity);

    public native void testFields(DetailProduct entity);

    public static native Field testReflection(Product entity, Field idField,Method setQuantityMethod);

}
