package controller.model;


public class Wrapper {


    //*******************************Class fields******************************//

    private int opnum;     //Contains the number of operation for the server
    private String CData; //Contains json in String format

    //*******************************Class Methods******************************//

    //Setters and Getters

    public int getOpnum() {
        return opnum;
    }

    public void setOpnum(int opnum) {
        this.opnum = opnum;
    }


    public String getCData() {
        return CData;
    }

    public void setCData(String CData) {
        this.CData = CData;
    }
}
