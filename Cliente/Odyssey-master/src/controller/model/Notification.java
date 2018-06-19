package controller.model;

import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class Notification {


    //*******************************Class fields******************************//


    private final StringProperty from;
    private final StringProperty songName;
    private String message;

    //*******************************Class Methods******************************//


    //Constructor class (Overload)

    public Notification(){

        this.from=new SimpleStringProperty("");
        this.songName=new SimpleStringProperty("");

    }

    public Notification(String from,String songName) {

        this.from = new SimpleStringProperty(from);
        this.songName = new SimpleStringProperty(songName);
        this.message = "Your friend " + from + " recommend you to listen the next song:\n" + songName +
                       "\n Odyssey changing life with music!! ";

    }


    //Setters and Getters

    public String getFrom() {
        return from.get();
    }

    public StringProperty fromProperty() {
        return from;
    }

    public void setFrom(String from) {
        this.from.set(from);
    }

    public String getSongName() {
        return songName.get();
    }

    public StringProperty songNameProperty() {
        return songName;
    }

    public void setSongName(String songName) {
        this.songName.set(songName);
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
