public class LZ4Compressor {
    static {
        System.loadLibrary("native_lfi"); // Load the native library
    }

    // Native methods
    public native byte[] compress(byte[] input);
    public native byte[] decompress(byte[] compressed, int originalSize);

    public static void main(String[] args) {
        LZ4Compressor compressor = new LZ4Compressor();

        String inputStr = "This is a test string for LZ4 compression via JNI!";
        byte[] inputData = inputStr.getBytes();

        // Compress
        byte[] compressedData = compressor.compress(inputData);
        System.out.println("Compressed size: " + compressedData.length);

        // Decompress
        byte[] decompressedData = compressor.decompress(compressedData, inputData.length);
        String outputStr = new String(decompressedData);
        System.out.println("Decompressed: " + outputStr);
    }
}
