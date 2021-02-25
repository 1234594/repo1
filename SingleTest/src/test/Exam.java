package test;

import domain.item;
import service.ItemService;


import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author xin
 * @Description:
 * @ProjectName: SingleTest
 * @Package: test
 * @ClassName: Exam
 * @create 2021/2/23-23:17
 * @Version: 1.0
 */
public class Exam {
    public static void main(String[] args) {
        ItemService itemService = new ItemService();
       for (int i = 1; i <= 10; i++) {
            item items1 = itemService.getItems(i);
            System.out.println(items1);
        }
       char[] chars = new char[10];
        for (int i = 1; i <= 10 ; i++) {
            item items1 = itemService.getItems(i);
            chars[i-1] = items1.getAnswer();
        }
       itemService.saveAnswer(chars);
    }
}
