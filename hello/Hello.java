public class Hello {
    static {
        System.loadLibrary("native_lfi");
    }
    
    public static void main(String[] args) {
        new Hello().sayHello();
    }

    // Declare a native method sayHello() that receives no arguments and returns void
    private native void sayHello();
}
