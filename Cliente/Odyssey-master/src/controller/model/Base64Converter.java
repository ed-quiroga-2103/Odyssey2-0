package controller.model;

import java.io.*;
import java.util.Base64;


public class Base64Converter {

    public String encode64(File file){
        try {
            byte[] encodeFile = Base64.getEncoder().encode(this.loadFile(file));
            return new String(encodeFile);
        }catch (IOException e){
            e.printStackTrace();
            return null;
        }

    }


    public byte[] decode64(String encodeFile){

        byte[] decodeFile=Base64.getDecoder().decode(encodeFile);
        return decodeFile;

    }

    private static byte[] loadFile(File file) throws IOException {
        InputStream is = new FileInputStream(file);

        long length = file.length();
        if (length > Integer.MAX_VALUE) {
            // File is too large
        }
        byte[] bytes = new byte[(int)length];

        int offset = 0;
        int numRead = 0;
        while (offset < bytes.length
                && (numRead=is.read(bytes, offset, bytes.length-offset)) >= 0) {
            offset += numRead;
        }

        if (offset < bytes.length) {
            throw new IOException("Could not completely read file "+file.getName());
        }

        is.close();
        return bytes;
    }

}
