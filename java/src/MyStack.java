import java.util.Arrays;

/**
 * Created by qinbin on 2017/3/15.
 */
public class MyStack<T> {
    private static final int CAPACITY = 10;
    private Object[] stack;
    private int size;
    public MyStack() {
        stack = new Object[10];
        size = -1;
    }

    public T peek() {
        if (size < 0) {
            return null;
        }
        return (T)stack[size];
    }

    public T poll() {
        if (size < 0) {
            return null;
        }
        return (T)stack[size--];
    }

    public void push(T ele) {
        if (size + 1 == stack.length) {
            stack = Arrays.copyOf(stack, stack.length + 2);
        }
        stack[++size] = ele;
    }
}
