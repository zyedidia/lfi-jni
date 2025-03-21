public class Sum {
    static {
        System.loadLibrary("native_native");
    }

    public static void main(String[] args) {
        System.out.println("sum: " + new Sum().sum(new int[]{1, 2, 3, 4}));
    }

    private native int sum(int[] array);
}
