package controller.model;

import javafx.beans.property.IntegerProperty;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.beans.property.StringProperty;

public class PlayList {


    //*******************************Class fields******************************//


    private final StringProperty name;
    private final StringProperty creator;
    private final IntegerProperty year;
    private Song root;
    private int length;
    private String image64;


    //*******************************Class Methods******************************//


    //Constructor

    public PlayList(){
        this.name=new SimpleStringProperty("");
        this.creator=new SimpleStringProperty("");
        this.year=new SimpleIntegerProperty(0);

    }

    public PlayList(String name,String creator,int year){

        this.name=new SimpleStringProperty(name);
        this.creator=new SimpleStringProperty(creator);
        this.year=new SimpleIntegerProperty(year);
    }

    //List Management

    public int getLength(){
        return  this.length;
    }

    public Song getRoot(){
        return this.root;
    }
    
    public void setImage64(String image64) {
        this.image64 = image64;
    }

    public void add(Song newSong){
        if(this.root!=null){
            Song currentSong=root;
            while (currentSong.getNext()!=null){
                currentSong=currentSong.getNext();
            }
            currentSong.setNext(newSong);

        }else{
            this.root=newSong;
        }

        this.length++;
    }

    public void delete(Song song){

        if(this.root!=null){
            Song temp=root;
            if(this.root.equals(song)){
                this.root=this.root.getNext();
                temp.setNext(null);

            }else{
                while(temp.getNext()!=null){
                    if(temp.getNext().equals(song)){
                        Song temp2=temp.getNext();
                        temp.setNext(temp.getNext().getNext());
                        temp2.setNext(null);
                    }else{
                        temp=temp.getNext();
                    }
                }

            }
            this.length--;
        }else{
            System.out.print("no hay datos");
        }
    }


    //Setters and Getters

    public String getImage64() {
        return image64;
    }

    public String getName() {
        return name.get();
    }

    public StringProperty nameProperty() {
        return name;
    }

    public void setName(String name) {
        this.name.set(name);
    }

    public String getCreator() {
        return creator.get();
    }

    public StringProperty creatorProperty() {
        return creator;
    }

    public void setCreator(String creator) {
        this.creator.set(creator);
    }

    public int getYear() {
        return year.get();
    }

    public IntegerProperty yearProperty() {
        return year;
    }

    public void setYear(int year) {
        this.year.set(year);
    }

}
