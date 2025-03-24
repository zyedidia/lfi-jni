public class Call {
    static {
        System.loadLibrary("native_lfi");
    }

    public native void nativeMethod();
    public native void hello();

    public void javaMethod(int a) {
        System.out.println("Java method called from C! " + a);
        hello();
    }

    public static void main(String[] args) {
        Call obj = new Call();
        obj.nativeMethod();
    }
}
