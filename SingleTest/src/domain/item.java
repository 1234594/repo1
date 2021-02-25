package domain;

import java.util.Arrays;

/**
 * @author xin
 * @Description:
 * @ProjectName: SingleTest
 * @Package: domain
 * @ClassName: item
 * @create 2021/2/23-23:55
 * @Version: 1.0
 */
public class item {
    private String question;
    private String[] options;
    private char answer;

    public item() {
    }

    public item(String question, String[] options, char answer) {
        this.question = question;
        this.options = options;
        this.answer = answer;
    }

    public String getQuestion() {
        return question;
    }

    public void setQuestion(String question) {
        this.question = question;
    }

    public String[] getOptions() {
        return options;
    }

    public void setOptions(String[] options) {
        this.options = options;
    }

    public char getAnswer() {
        return answer;
    }

    public void setAnswer(char answer) {
        this.answer = answer;
    }

    @Override
    public String toString() {
        return "item{" +
                "question='" + question + '\'' +
                ", options=" + Arrays.toString(options) +
                ", answer=" + answer +
                '}';
    }
}
