package service;

import domain.item;

import javax.annotation.processing.Filer;
import java.io.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * @author xin
 * @Description:
 * @ProjectName: SingleTest
 * @Package: service
 * @ClassName: ItemService
 * @create 2021/2/23-23:55
 * @Version: 1.0
 */
public class ItemService {

    private item[] items;//题目数组

    private final String ITEM_FILENAME = "src\\Items.txt";//读取的文件位置
    private final String ANSWER_FILENAME = "src\\answer.dat";//文件输出的位置
    private final int LINES_PER_ITEM = 6;//每题占用的行数
    public final int TOTAL_ITEMS ;//题目数

    public  ItemService() {
       List<String> list = readTextFile(ITEM_FILENAME);
        TOTAL_ITEMS = list.size()/LINES_PER_ITEM;
        items  = new item[TOTAL_ITEMS];
        for (int i = 0; i < TOTAL_ITEMS; i++) {
            String question = list.get(i * LINES_PER_ITEM);
            String options[] = {
                list.get(i * LINES_PER_ITEM + 1),
                list.get(i * LINES_PER_ITEM + 2),
                list.get(i * LINES_PER_ITEM + 3),
                list.get(i * LINES_PER_ITEM + 4)
            };
            char answer = list.get(i * LINES_PER_ITEM + 5).charAt(0);
            items[i] = new item(question,options,answer);
        }
    }


    private List<String> readTextFile(String filename) {
        BufferedReader bufferedReader = null;
        List<String> list = new ArrayList<>();
        try {
            bufferedReader = new BufferedReader(new FileReader(filename));
            String line;
            while( (line = bufferedReader.readLine()) != null) {
                if(!line.trim().equals("")) {
                    list.add(line);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(bufferedReader != null) {
                try {
                    bufferedReader.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return list;
        }
    }


    public item getItems(int index) {
        if(index <= 0 || index > TOTAL_ITEMS) {
            return null;
        }
        return items[index - 1];
    }


    public void saveAnswer(char[] answer) {
        ObjectOutputStream oos = null;
        try {
            FileOutputStream fos = new FileOutputStream(ANSWER_FILENAME);
            oos = new ObjectOutputStream(fos);

            oos.writeObject(answer);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (oos != null) {
                try {
                    oos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}



